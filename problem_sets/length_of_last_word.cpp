/*
Description: Given a string s consisting of words and spaces, return the length of the last word in the string. A word is a maximal consisting of non-space characters only.

Example 1:
    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.

Example 2:
    Input: s = "   fly me   to   the moon  "
    Output: 4
    Explanation: The last word is "moon" with length 4.

Example 3:
    Input: s = "luffy is still joyboy"
    Output: 6
    Explanation: The last word is "joyboy" with length 6.

Constraints:
    1 <= s.length <= 104
    s consists of only English letters and spaces ' '.
    There will be at least one word in s.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            bool word_start = false;
            int count = 0;
            for (int i=s.size()-1; i>=0; i--) {
                // Start counting if characters encountered at the end else wait
                if (!word_start && ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)))                    
                    word_start = true; 

                if (word_start) {
                    if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
                        count++;
                    else
                        break;
                }             
            }

            return count;
        }
};

int main() {
    string s = "   fly me   to   the moon  ";
    Solution obj;
    cout << obj.lengthOfLastWord(s) << endl;
    return 0;
}