/*
Description: Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

Example 2:
    Input: head = [1], n = 1
    Output: []

Example 3:
    Input: head = [1,2], n = 1
    Output: [1]

Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

*/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *new_head = head, *temp = head, *temp2;
        // find total length, then delete the last n'th element
        int total_length = 0, counter = 1;

        while (temp!=nullptr) {
            total_length++;
            temp = temp->next;
        }
        temp = new_head;
        while (true) {
            // delete node if nth from last
            if (counter == total_length - n) {
                temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
            }
            counter++;
            temp = temp->next;
        }

        return new_head;
    }
};

void display(ListNode *list) {
    while (list!=nullptr) {
        cout << list->val << " -> ";
        list = list->next;
    }
    cout << "nullptr\n";
}

int main() {
    ListNode *head = new ListNode(5);
    head = new ListNode(4, head);
    head = new ListNode(3, head);
    head = new ListNode(2, head);
    head = new ListNode(1, head);
    
    display(head);
    
    Solution obj;
    display(obj.removeNthFromEnd(head, 2));

}