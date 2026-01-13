/*
Description: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position. Return true if you can reach the last index, or false otherwise.

Example 1:
    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
    Input: nums = [3,2,1,0,4]
    Output: false
    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
    1 <= nums.length <= 104
    0 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        
        if (nums[0] == 0)
            return false;

        int endIndex = nums.size() - 1;
        
        vector<bool> can_reach(endIndex + 1, false);
        can_reach[0] = true;

        auto printState = [&]() {
            int i = 0;
            for (auto x: can_reach) {
                cout << i << ": " << ((x)?"True": "False") << endl;
                i++;
            }    
        };

        auto updateState = [&](int i, int jumps) {
            for (int index = 0; index <= jumps; index++)
                can_reach[index + i] = true;
        };

        for (int currentIndex = 0; currentIndex <= endIndex-1; currentIndex++) {
            // cout << currentIndex << " : " << nums[currentIndex] << " : " << endIndex << endl;
            if (currentIndex + nums[currentIndex] >= endIndex)
                return true;
            else {
                updateState(currentIndex, nums[currentIndex]);
            }
            // printState();
        }

        return can_reach[endIndex];
    }
};

int main() {
    vector<vector<int>> testcases;
	testcases.push_back({2,3,1,1,4});
    testcases.push_back({3,2,1,0,4});
    testcases.push_back({0,2,3});
    testcases.push_back({1,0,1,0});
    testcases.push_back({2,0,1,0});

    
    auto printer = [](const vector<int> test) {
        cout << "Testcase: [ ";
        for (auto v: test) 
            cout << v << " " ;
        cout << "] \t Result: ";
    };

    Solution obj;
    
    for (auto test : testcases) {
        printer(test);
        cout << (obj.canJump(test)? "True" : "False") << endl;
    }


    return 0;
}
