/* 
 * Description: 
 * You are climbing a staircase. It takes n steps to reach the top. Each time you 
 * can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * 
 * Constraints:
 * 1 <= n <= 45
 * 
 * Example:
 * N = 2
 *      1+1, 2 = Total 2
 * N = 3
 *      1+1+1, 1+2, 2+1 = Total 3
 * N = 4
 *      1+1+1+1, 1+2+1, 1+1+2, 2+2, 2+1+1 = Total 5
 * */

#include <iostream>
#include <vector>

using namespace std;

int total_ways = 0;

class Solution {
    public:
        // Takes a long time as time complexity is O(2^n)
        // int climbStairs(int n) {
        //     if (n==1)
        //         return 1;
        //     if (n==2)
        //         return 2;
        //     return climbStairs(n-1) + climbStairs(n-2);            
        // }

        int climbStairs(int n) {
            if (n == 0 || n == 1)
                return 1;
            vector<int> ways(n+1);
            ways[0] = ways[1] = 1;
            for (int i=2; i<=n; i++) 
                ways[i] = ways[i-1] + ways[i-2];
            
            return ways[n];
        }
};

int main() {
    cout << "Enter N: ";
    int N;
    cin >> N;
    Solution obj;
    cout << obj.climbStairs(N) << endl;
    return 0;
}