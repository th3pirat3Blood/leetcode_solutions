/*
Description: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You must write an algorithm with O(log n) runtime complexity.
 
Example 1:
    Input: nums = [1,3,5,6], target = 5
    Output: 2

Example 2:
    Input: nums = [1,3,5,6], target = 2
    Output: 1

Example 3:
    Input: nums = [1,3,5,6], target = 7
    Output: 4

Constraints:
    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums contains distinct values sorted in ascending order.
    -104 <= target <= 104

*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int start_index = 0, end_index = nums.size()-1;
            int i, result_index = -1;
            while (start_index <= end_index) {
                i = (start_index + end_index) / 2;
                if (target == nums[i]) { 
                    result_index = i;
                    break;
                } else if (target < nums[i]) {
                    // result_index = [start_index, i)
                    result_index = i;
                    end_index = i-1;
                } else {
                    // result_index = (i, end_index]
                    result_index = i+1;
                    start_index = i+1;
                }
            }
            return result_index;
        }
};

int main() {
    vector<int> N = {1,3,5,6};
    int target = 4;
    Solution obj;
    cout << obj.searchInsert(N, target) << endl;
    return 0;
}

