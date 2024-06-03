/*
 * Description:
 * Given an integer n, return true if it is a power of two. Otherwise, return false. 
 * An integer n is a power of two, if there exists an integer x such that n == 2^x.
 * 
 * Example 1:
 *  Input: n = 1
 *  Output: true
 *  Explanation: 20 = 1
 * 
 * Example 2:
 *  Input: n = 3
 *  Output: false
 * 
 * Constraints:
 *      -231 <= n <= 231 - 1
 *  */

#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=0; long power_number;
        while (true) {
            power_number = pow(2, i);
            if (power_number == n) 
                return true;
            if (power_number > n) 
                return false;
            i++;
        }
    }
};

int main() {
    Solution obj;
    std::cout << obj.isPowerOfTwo(3) << "\n";
    return 0;
}