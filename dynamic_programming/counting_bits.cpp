/*
 * Description:
 * Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n),
 *  ans[i] is the number of 1's in the binary representation of i.
 * 
 * Example:
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation: 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 
 * Constraints:
 *  0 <= n <= 10^5
 * 
 * Date: 18-May-2024
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> return_value;
            string binary_number;
            int counter = 0;
            auto convertToBinary = [&](int number) {
                while (number) {
                    if (number &1)
                        counter++;
                    number >>= 1 ;
                }
            };
            for (int i = 0; i<=n; i++) {
                convertToBinary(i);
                return_value.push_back(counter);
                counter=0;
            }
            return return_value;
        }
};

int main() {
    Solution obj;
    int n = 5;
    vector<int> return_Value(n+1);
    return_Value = obj.countBits(n);
    
    cout << "[ ";
    for(auto &f : return_Value) 
        cout << f << " ";
    cout << " ]" << endl;
    return 0;
}
