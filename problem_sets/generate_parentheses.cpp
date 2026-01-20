/*
 * Description:
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
	Input: n = 3
	Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
	Input: n = 1
	Output: ["()"]

Constraints:
    1 <= n <= 8
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> possibleResult = "";


			return possibleResult;
		}
};

int main() {
	vector<int> TestCases {1, 2, 3};
	auto displayResult = [](vector<string> V) {
		cout << "[ ";
		for (auto v : V)
			cout << v  << " ";
		cout << "]" << endl;
	};

	Solution obj;
	for (auto test : TestCases) {
		cout << "Input: " << test << "\t Output: ";
		displayResult(obj.generateParenthesis(test));
	}

	return 0;
}
