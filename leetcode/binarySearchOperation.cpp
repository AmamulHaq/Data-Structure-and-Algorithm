#include <iostream>
#include <map>
using namespace std;

struct Node {
    int d;
    Node* L;
    Node* R;
    Node* P;
    Node(int v) : d(v), L(nullptr), R(nullptr), P(nullptr) {}
};

class BST {
public:
    Node* r;
    map<Node*, int> idx;

    BST() : r(nullptr) {}

    void upd(Node* n, int i) {
        if (!n) return;
        idx[n] = i;
        upd(n->L, 2 * i + 1);
        upd(n->R, 2 * i + 2);
    }

    void ins(int v) {
        Node* n = new Node(v);
        if (!r) {
            r = n;
            idx[n] = 0;
            return;
        }
        Node* c = r;
        Node* p = nullptr;
        int i = 0;
        while (c) {
            p = c;
            if (v < c->d) {
                if (!c->L) {
                    i = 2 * idx[p] + 1;
                    break;
                }
                c = c->L;
            } else if (v > c->d) {
                if (!c->R) {
                    i = 2 * idx[p] + 2;
                    break;
                }
                c = c->R;
            } else {
                return;
            }
        }
        n->P = p;
        idx[n] = i;
        if (v < p->d)
            p->L = n;
        else
            p->R = n;
        upd(r, 0);
    }

    void print() {
        cout << "|Index | Node |Parent|\n";
        cout << "-------------\n";
        for (int i = 0; i < 15; i++) {
            bool f = false;
            for (auto it : idx) {
                if (it.second == i) {
                    int p = it.first->P ? it.first->P->d : -1;
                    cout << "| " << i << "  |  " << it.first->d << "  | " << p << "  |\n";
                    f = true;
                    break;
                }
            }
            if (!f)
                cout << "| " << i << "  |  _   |  _  |\n";
        }
    }

    Node* min(Node* n) {
        while (n && n->L) n = n->L;
        return n;
    }

    Node* find(Node* n, int v) {
        if (!n || n->d == v) return n;
        if (v < n->d) return find(n->L, v);
        return find(n->R, v);
    }

    void del(int v) {
        Node* d = find(r, v);
        if (!d) return;

        if (!d->L && !d->R) {
            if (!d->P) r = nullptr;
            else if (d->P->L == d) d->P->L = nullptr;
            else d->P->R = nullptr;
        } else if (!d->L || !d->R) {
            Node* ch = d->L ? d->L : d->R;
            if (!d->P) r = ch;
            else if (d->P->L == d) d->P->L = ch;
            else d->P->R = ch;
            ch->P = d->P;
        } else {
            Node* s = min(d->R);
            d->d = s->d;
            if (s->P->L == s) s->P->L = s->R;
            else s->P->R = s->R;
            if (s->R) s->R->P = s->P;
            d = s;
        }
        idx.erase(d);
        delete d;
        upd(r, 0);
    }
};

int main() {
    int sz;
    cout << "Enter number of nodes: ";
    cin >> sz;
    BST t;
    cout << "Enter sequence of nodes: " << endl;
    for (int i = 0; i < sz; i++) {
        int v;
        cin >> v;
        t.ins(v);
    }
    t.print();
    int insVal, delVal;
    cout << "Enter a node to insert: ";
    cin >> insVal;
    t.ins(insVal);
    t.print();
    cout << "Enter a node to delete: ";
    cin >> delVal;
    t.del(delVal);
    t.print();
    return 0;
}