#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <regex>

using namespace std;

using Polynomial = map<int, map<int, double>>;

Polynomial integrate_fxy(const Polynomial& f_xy) {
    Polynomial result;
    for (const auto& x_term : f_xy) {
        int a = x_term.first;
        for (const auto& y_term : x_term.second) {
            int b = y_term.first;
            double c = y_term.second;

            if (a == -1) {
                throw runtime_error("Integral of 1/x is log(x), not polynomial.");
            }

            int new_a = a + 1;
            double new_c = c / (a + 1);
            result[new_a][b] = new_c;
        }
    }
    return result;
}

string polynomial_to_string(const Polynomial& poly) {
    string s;
    for (const auto& x_term : poly) {
        int a = x_term.first;
        for (const auto& y_term : x_term.second) {
            int b = y_term.first;
            double c = y_term.second;

            if (abs(c) < 1e-10) continue;

            if (!s.empty()) {
                s += (c >= 0) ? " + " : " - ";
            } else if (c < 0) {
                s += "-";
            }

            if (abs(abs(c) - 1.0) > 1e-10 || (a == 0 && b == 0)) {
                string coeff_str = to_string(abs(c));
                coeff_str.erase(coeff_str.find_last_not_of('0') + 1, string::npos);
                coeff_str.erase(coeff_str.find_last_not_of('.') + 1, string::npos);
                s += coeff_str;
            }

            if (a != 0) {
                s += "x";
                if (a != 1) s += "^" + to_string(a);
            }
            if (b != 0) {
                s += "y";
                if (b != 1) s += "^" + to_string(b);
            }
        }
    }
    return s.empty() ? "0" : s;
}

Polynomial make_polynomial(const vector<tuple<int, int, double>>& terms) {
    Polynomial poly;
    for (const auto& term : terms) {
        int a = get<0>(term);
        int b = get<1>(term);
        double c = get<2>(term);
        poly[a][b] = c;
    }
    return poly;
}

enum LimitType { CONSTANT, LINEAR_X, LINEAR_Y, OTHER };

struct LimitInfo {
    LimitType type;
    double coefficient;
    char variable;
};

LimitInfo parse_limit(const string& limit) {
    LimitInfo info{CONSTANT, 1.0, 'x'};
    
    if (limit.empty()) return info;
    
    regex rx_num("([+-]?\\d*\\.?\\d+)");
    regex rx_var("([xy])");
    
    smatch match_num;
    smatch match_var;
    
    if (regex_search(limit, match_var, rx_var)) {
        info.variable = match_var.str(1)[0];
        string num_part = limit.substr(0, limit.find(info.variable));
        
        if (regex_search(num_part, match_num, rx_num)) {
            info.coefficient = stod(match_num.str(1));
        } else if (!num_part.empty()) {
            if (num_part == "+") info.coefficient = 1.0;
            else if (num_part == "-") info.coefficient = -1.0;
        }
        
        if (info.variable == 'x') info.type = LINEAR_X;
        else if (info.variable == 'y') info.type = LINEAR_Y;
    } 
    else if (regex_search(limit, match_num, rx_num)) {
        info.coefficient = stod(match_num.str(1));
        info.type = CONSTANT;
    }
    else {
        info.type = OTHER;
    }
    
    return info;
}

Polynomial evaluate_at_limit(const Polynomial& poly, const LimitInfo& limit) {
    Polynomial result;
    
    for (const auto& x_term : poly) {
        int a = x_term.first;
        for (const auto& y_term : x_term.second) {
            int b = y_term.first;
            double c = y_term.second;
            
            double value = c;
            
            if (limit.type == CONSTANT) {
                value *= pow(limit.coefficient, a);
            }
            else if (limit.type == LINEAR_X) {
                value *= pow(limit.coefficient, a);
            }
            else if (limit.type == LINEAR_Y) {
                value *= pow(limit.coefficient, a);
            }
            
            if (abs(value) > 1e-10) {
                if (limit.type == LINEAR_X) {
                    result[a][b] = value;
                } else {
                    result[0][b] += value;
                }
            }
        }
    }
    
    return result;
}

Polynomial subtract_polynomials(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result = p1;
    
    for (const auto& x_term : p2) {
        int a = x_term.first;
        for (const auto& y_term : x_term.second) {
            int b = y_term.first;
            double c = y_term.second;
            result[a][b] -= c;
        }
    }
    
    return result;
}

int main() {
    Polynomial f1 = make_polynomial({
        {1, 0, 1},  // x term
        {0, 1, 1}    // y term
    });

    Polynomial f3 = make_polynomial({
        {1, 0, 3},   // 3x term
        {0, 1, 0.5}   // 0.5y term
    });

    string lower, upper;
    cout << "Enter variable integral lower limit expression: ";
    getline(cin, lower);
    cout << "Enter variable integral upper limit expression: ";
    getline(cin, upper);

    Polynomial antideriv1 = integrate_fxy(f1);
    Polynomial antideriv3 = integrate_fxy(f3);

    LimitInfo lower_info = parse_limit(lower);
    LimitInfo upper_info = parse_limit(upper);

    Polynomial upper_eval1 = evaluate_at_limit(antideriv1, upper_info);
    Polynomial lower_eval1 = evaluate_at_limit(antideriv1, lower_info);
    Polynomial result1 = subtract_polynomials(upper_eval1, lower_eval1);

    Polynomial upper_eval3 = evaluate_at_limit(antideriv3, upper_info);
    Polynomial lower_eval3 = evaluate_at_limit(antideriv3, lower_info);
    Polynomial result3 = subtract_polynomials(upper_eval3, lower_eval3);

    // Special handling for odd functions integrated over symmetric limits
    if (lower_info.type == LINEAR_Y && upper_info.type == LINEAR_Y && 
        lower_info.coefficient == -upper_info.coefficient) {
        // For odd functions (x terms), the integral will be zero
        // For even functions (constant terms), we double the upper evaluation
        for (auto& x_term : result1) {
            if (x_term.first % 2 == 1) { // Odd powers of x
                for (auto& y_term : x_term.second) {
                    y_term.second = 0;
                }
            } else { // Even powers of x
                for (auto& y_term : x_term.second) {
                    y_term.second *= 2;
                }
            }
        }
        for (auto& x_term : result3) {
            if (x_term.first % 2 == 1) { // Odd powers of x
                for (auto& y_term : x_term.second) {
                    y_term.second = 0;
                }
            } else { // Even powers of x
                for (auto& y_term : x_term.second) {
                    y_term.second *= 2;
                }
            }
        }
    }

    cout << "∫ (x + y) dx from " << lower << " to " << upper << " = ";
    cout << polynomial_to_string(result1) << endl;

    cout << "∫ (3x + 0.5y) dx from " << lower << " to " << upper << " = ";
    cout << polynomial_to_string(result3) << endl;

    return 0;
}