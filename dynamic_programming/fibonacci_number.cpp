/* 
 * Description: 
 * The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci 
 * sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
 * Given n, calculate F(n)
 * 
 * Constraints:
 * 0 <= n <= 30
 * 
 * Example:
 * F(2) = F(1) + F(0) = 1
 * F(4) = F(3) + F(2) = 3
 * Date: 15-May-2024
 * 
 * */

#include <iostream>

using namespace std;

class Solution {
    public:
        int fib(int n) {
            if (n==1 || n ==0)
                return n;
            int prev_1 = 1, prev_2 = 0, fib = 0;
            
            for (int i=2; i<=n; i++) {
                fib = prev_2 + prev_1;
                prev_2 = prev_1;
                prev_1 = fib;
            }
            return fib;
        }
};

int main() {
    int N;
    cout << "Enter N: "; cin >> N;
    Solution obj;
    cout << obj.fib(N) << endl;
    return 0;
}