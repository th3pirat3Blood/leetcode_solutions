/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example 1:
 *  Input: l1 = [2,4,3], l2 = [5,6,4]
 *  Output: [7,0,8]
 *  Explanation: 342 + 465 = 807.
 * 
 * Example 2:
 *  Input: l1 = [0], l2 = [0]
 *  Output: [0]
 * 
 * Example 3:
 *  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *  Output: [8,9,9,9,0,0,0,1]
 * 
*/ 

#include <iostream>

using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void display(ListNode* l1) {
    while (l1 != nullptr) {
        cout << l1->val << " -> ";
        l1 = l1->next;
    }
    cout << "NULL\n";  
}   // end of display()..

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0, carry_over = 0;
        ListNode *l3 = nullptr, *temp;
        while ((l1 != nullptr) || (l2 != nullptr)) {
            // temp = (ListNode*)malloc(sizeof(ListNode));
            temp =  new ListNode();          
            // Doing operation 
            if (l1 != nullptr && l2 != nullptr)
                carry_over = l1->val + l2->val + carry_over;
            else if (l1 != nullptr && l2 == nullptr) 
                carry_over = l1->val + carry_over;
            else if (l2 != nullptr && l1 == nullptr )
                carry_over = l2->val + carry_over;
            
            temp->val = (carry_over >= 10)? carry_over-10: carry_over;
            carry_over = (carry_over >= 10)? 1: 0;
            
            if (l1!= nullptr)
                l1 = l1->next;
            if (l2!= nullptr)
                l2 = l2->next;
            
            temp->next = l3;
            l3 = temp;
        }
        if (carry_over>0) 
            l3 = new ListNode(carry_over, l3);
        ListNode *head = nullptr;
        while (l3!=nullptr) {
            temp =  new ListNode();
            temp->val = l3->val;
            temp->next = head;
            head = temp;
            l3 = l3->next;
        }
        return head;
    }
};


class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int value, carry_over = 0;
        ListNode *l3, *temp = nullptr;
        while ((l1 != nullptr) || (l2 != nullptr)) {
            // Operation
            if (l1 != nullptr && l2 != nullptr)
                carry_over = l1->val + l2->val + carry_over;
            else if (l1 != nullptr && l2 == nullptr) 
                carry_over = l1->val + carry_over;
            else if (l2 != nullptr && l1 == nullptr )
                carry_over = l2->val + carry_over;
            value = (carry_over >= 10)? carry_over-10: carry_over;
            carry_over = (carry_over >= 10)? 1: 0;
            
            l3 = new ListNode(value, temp);
            temp = l3;

            // Loop control
            if (l1!= nullptr)
                l1 = l1->next;
            if (l2!= nullptr)
                l2 = l2->next;
        }
        display(l3);
        // Reversing link list
        if (carry_over>0) 
            l3 = new ListNode(carry_over, l3);
        ListNode *head = nullptr;
        while (l3!=nullptr) {
            temp =  new ListNode();
            temp->val = l3->val;
            temp->next = head;
            head = temp;
            l3 = l3->next;
        }
        return head;
    }
};

ListNode* create_sample_list(int size) {
    ListNode *temp, *head = nullptr;
    for (int i=0; i<size; i++) {
        temp = (ListNode*) malloc(sizeof(ListNode));
        temp->val = 1+i;
        temp->next = head;
        head = temp;
    }
    return head;
}   // end of create_sample_list()..

int main() {
    Solution2 obj;
    ListNode *l1 = create_sample_list(3), *l2 = create_sample_list(4);
    ListNode *l3 = obj.addTwoNumbers(l1, l2);
    display(l1);
    display(l2);
    display(l3);
    return 0;
}
