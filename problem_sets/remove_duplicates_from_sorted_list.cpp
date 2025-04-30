/*
Description: Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Example 1:
    Input: head = [1,1,2]
    Output: [1,2]

Example 2:
    Input: head = [1,1,2,3,3]
    Output: [1,2,3]

Constraints:
    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.

*/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == nullptr)
                return head;
            ListNode *temp = head, *temp2;
            while (temp->next!=nullptr) {
                // iterate ahead if only values of next node are not same as current node
                // else repeat the deletion process continously.
                if (temp->val == temp->next->val) {
                    temp2 = temp->next->next;
                    delete temp->next;
                    temp->next = temp2;
                } else {
                    temp = temp->next;
                }
            }          
            return head;
        }
};

void display(ListNode *node) {
    // Display_function
    while (node!=nullptr) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "nullptr\n";
}

int main() {
    Solution obj;
    ListNode *node1, *node2, *node;

    node1 = new ListNode(2);
    node2 = new ListNode(1, node1);
    node1 = new ListNode(1, node2);
    
    node = new ListNode(1, node1);

    display(node);
    struct ListNode *result = obj.deleteDuplicates(node);  
    display(result);

    return 0;
}
