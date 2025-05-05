/* 
Description: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0. Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
    Input: x = 123
    Output: 321

Example 2:
    Input: x = -123
    Output: -321

Example 3:
    Input: x = 120
    Output: 21

Constraints:
    -231 <= x <= 231 - 1

*/

#include <iostream>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            const int max_value = 2147483647, min_value = -2147483648;
            int reverse_number = 0;
            bool is_negative_number = false;

            if (x == min_value)
                return 0;
            if (x < 0) {
                is_negative_number = true;
                x = 0-x;
            }

            while (x > 0) {
                reverse_number = reverse_number * 10 + (x % 10);
                x = x / 10;
                if (reverse_number > max_value/10 && x > 0) {
                    return 0;
                }
            }
            
            reverse_number = (is_negative_number) ? 0-reverse_number : reverse_number;
            
            if (reverse_number >= min_value && reverse_number <= max_value)
                return reverse_number;
            else 
                return 0;
        }
};

int main() {
    Solution obj;
    cout << obj.reverse(-2147483648) << endl;
}