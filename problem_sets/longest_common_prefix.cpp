/*
Description: Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.

*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string prefix = strs[0];
            bool not_this_prefix = false;

            while (!prefix.empty()) {
                
                // Traverse each string and check if prefix works for it if not then adjust prefix size
                for (auto search:strs) {
                    if (string::npos == search.find(prefix, 0) || 0 != search.find(prefix, 0)) {
                        not_this_prefix = true;
                        break;
                    }
                }
                if (not_this_prefix) {
                    prefix = prefix.substr(0, prefix.size()-1);
                    not_this_prefix = false;
                }
                else
                    break;
            }
            return prefix;
        }
};


int main() {
    vector<string> strings;
    strings.push_back("c"); strings.push_back("acc"); strings.push_back("ccc");

    Solution obj;
    cout << "Longest prefix: " << obj.longestCommonPrefix(strings) << "\n";

    return 0;
}
