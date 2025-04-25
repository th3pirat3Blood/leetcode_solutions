/*
Description: Given two binary strings a and b, return their sum as a binary string.

Example 1:
    Input: a = "11", b = "1"
    Output: "100"

Example 2:
    Input: a = "1010", b = "1011"
    Output: "10101"

Constraints:
    1 <= a.length, b.length <= 104
    a and b consist only of '0' or '1' characters.
    Each string does not contain leading zeros except for the zero itself.

    // 0 + 0 = 0
    // 0 + 1 = 1
    // 1 + 1 = 10
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            int total_size = (a.length() >= b.length())? a.length() : b.length();
            int i = 0, carry = 0, sum = 0, bit_a, bit_b;
            string result;

            while (i!=total_size) {
                bit_a = (a.length()-i>=0)? 
                            ((a[a.length()-i]=="0")? 0 : 1)
                            : 0;
                bit_b = (b.length()-i>=0)? 
                            ((b[b.length()-i]=="0")? 0 : 1)
                            : 0;
                
                // If handles the case of 1+1, while else handles 0+1, 0+0, 1+0 (without carry)
                if (bit_a + bit_b == 2) { 
                    sum = 2 + carry;
                    carry = 1;
                    result = ((sum==2)? "0": "1" ) + result; 
                } else {
                    sum = bit_a + bit_b + carry;
                    carry = 0;
                }
                
                i++;
            }

            return result;
        }
};

int main() {
    Solution obj;
    cout << obj.addBinary("10", "1") << endl;

    return 0;
}