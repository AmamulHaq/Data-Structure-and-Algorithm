
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* current = dummy;
//         int carry = 0;

//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int sum = carry;
//             if (l1 != nullptr) {
//                 sum += l1->val; 
//                 l1 = l1->next;
//             }
//             if (l2 != nullptr) {
//                 sum += l2->val; 
//                 l2 = l2->next;
//             }
//             carry = sum / 10;
//             current->next = new ListNode(sum % 10);  
//             current = current->next;
//         }

//         return dummy->next;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void display(Node* &head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseList(Node* &head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node* convertToDigits(Node* &head) {
    Node* dummy = new Node(0);
    Node* current = dummy;

    while (head != nullptr) {
        string value = to_string(head->data);
        for (char digit : value) {
            current->next = new Node(digit - '0');
            current = current->next;
        }
        head = head->next;
    }

    return dummy->next;
}

Node* addTwoNumbers(Node* &l1, Node* &l2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        current->next = new Node(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

int main() {
    Node* l1_link1 = new Node(10);
    Node* l1_head = l1_link1;

    Node* l1_link2 = new Node(30);
    l1_link1->next = l1_link2;

    Node* l1_link3 = new Node(40);
    l1_link2->next = l1_link3;

    Node* l2_link1 = new Node(12);
    Node* l2_head = l2_link1;

    Node* l2_link2 = new Node(32);
    l2_link1->next = l2_link2;

    Node* l2_link3 = new Node(42);
    l2_link2->next = l2_link3;

    Node* l1_digits = convertToDigits(l1_head);
    Node* l2_digits = convertToDigits(l2_head);

    Node* l3_head = addTwoNumbers(l1_digits, l2_digits);

    l3_head = reverseList(l3_head);

    cout << "Reversed Resultant Linked List:" << endl;
    display(l3_head);

    return 0;
}
