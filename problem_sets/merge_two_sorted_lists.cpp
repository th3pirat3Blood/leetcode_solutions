/*
Description:
You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list.
The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.

Example 1:
    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

Example 2:
    Input: list1 = [], list2 = []
    Output: []

Example 3:
    Input: list1 = [], list2 = [0]
    Output: [0]

Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.

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

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode *merged = nullptr, *temp = merged, *prev;
            if (list1 == nullptr && list2 == nullptr)
                return merged;

            while (list1!=nullptr || list2!=nullptr) {
                 // In case one of list reaches its ends just copy the second list as it is
                 if (list1 == nullptr) {
                    temp->next = list2;
                    break;
                }
                if (list2 == nullptr) {
                    temp->next = list1;
                    break;
                }

                // In case none of the list is nullptr
                if (list1->val < list2->val) {
                    temp = new ListNode(list1->val, temp);
                    list1 = list1->next;                    
                } else if (list2->val < list1->val) {
                    temp = new ListNode(list2->val, temp);
                    list2 = list2->next;
                } else {
                    temp = new ListNode(list1->val, temp);
                    // temp = temp->next;
                    temp = new ListNode(list2->val, temp);
                    list1 = list1->next;
                    list2 = list2->next;
                }
            }
            
            // Reverse list for correct order
            while (temp!=nullptr) {
                merged = new ListNode(temp->val, merged);
                temp = temp->next;
            }
            
            return merged;        
        }
};

void display(ListNode *list){
    while (list!=nullptr) {
        cout << list->val << " -> ";
        list = list->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    ListNode *list1, *list2;
    list1 = new ListNode(4);
    list1 = new ListNode(2, list1);
    list1 = new ListNode(1, list1);

    list2 = new ListNode(4);
    list2 = new ListNode(3, list2);
    list2 = new ListNode(1, list2);

    display(list1);
    display(list2);

    Solution obj;
    display(obj.mergeTwoLists(list1, list2));

    return 0;
}