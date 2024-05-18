/* 
 * Description:
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 * 
 *               1
 *             1 2 1
 *            1 3 3 1
 *           1 4 6 4 1
 *         1 5 10 10 5 1
 * 
 * Example:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * Constraints:
 *  1 <= numRows <= 30
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<int> row;
            vector<vector<int>> return_value;
            int value;
            for (int i=0; i<numRows; i++) {
                value = int(pow(11, i));
                [&]() {
                    while (value) {
                        row.push_back(value%10);
                        value = value/10;
                    }
                }();
                return_value.push_back(row);
                row.clear();
            } 
            return return_value;
        }
};

int main() {
    Solution obj;
    int numrows = 4;
    auto return_value = obj.generate(numrows);
    
    for(auto &itr: return_value) {
        for(auto &v: itr) 
            cout << v << " ";
        cout << endl;
    }
    return 0;
}
