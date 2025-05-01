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
            ListNode *merged = nullptr, *temp = merged, *prev = merged;
            // If both lists are empty
            if (list1 == nullptr && list2 == nullptr)
                return nullptr;

            while (list1!=nullptr || list2!=nullptr) {
                // Handle if one of the list is nullptr
                if (list1 == nullptr) {
                    if (prev != nullptr)
                        prev->next = list2;
                    else
                        merged = list2;
                    break;
                } 
                if (list2 == nullptr) {
                    if (prev != nullptr)
                        prev->next = list1;
                    else
                        merged = list1;
                    break;
                }

                // Whichever list value is smaller add that into merged list
                if (list1->val < list2->val) {
                    temp = new ListNode(list1->val);
                    if (prev !=nullptr)
                        prev->next = temp;
                    list1 = list1->next;
                } else if (list2->val < list1->val) {
                    temp = new ListNode(list2->val);
                    if (prev !=nullptr)
                        prev->next = temp;
                    list2 = list2->next;
                } else {
                    temp = new ListNode(list1->val);
                    // For those special cases where duplicates are at the start
                    if (merged == nullptr)
                        merged = temp;
                    if (prev !=nullptr)
                        prev->next = temp;
                    prev = temp;
                    temp = new ListNode(list2->val);
                    prev->next = temp;
                    list1 = list1->next;
                    list2 = list2->next;
                }

                prev = temp;
                
                if (merged == nullptr)
                    merged = temp;

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