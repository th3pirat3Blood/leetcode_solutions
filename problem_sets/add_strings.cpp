/* 
 * Description:
 * Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string. 
 * You must solve the problem without using any built-in library for handling large integers (such as BigInteger).
 * You must also not convert the inputs to integers directly.
 *
 * Example 1:
 * 		Input: num1 = "11", num2 = "123"
 * 		Output: "134"
 *
 * Example 2:
 * 		Input: num1 = "456", num2 = "77"
 * 		Output: "533"
 *
 * Example 3:
 * 		Input: num1 = "0", num2 = "0"
 * 		Output: "0"
 *
 * Constraints:
 * 		1 <= num1.length, num2.length <= 104
 * 		num1 and num2 consist of only digits.
 * 		num1 and num2 don't have any leading zeros except for the zero itself.
 *
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	// Idea : Take a char from last of both strings then add them.. check if sum is above 57
	// if sum > 57 -> Number is 2 digit and carry = 1 while result digit= (sum -57)
	// Continue this process till both strings are empty
	// Note: '0' = 48 in ascii, '9' = 57 in ascii.

    string addStrings(string num1, string num2) {
		int length1 = num1.size(), length2 = num2.size(), digit1, digit2;
		int current_sum, carry = 0;
		string result = "";

		while (length1 > 0 || length2 > 0) {
			digit1 = (length1 < 1)? 0 : num1[length1-1] - 48;
			digit2 = (length2 < 1)? 0 : num2[length2-1] - 48;
			
			// cout << "Length: [" << length1 << " , " << length2 << "]" << endl;
			// cout << "Digits: [" << digit1 << " , " << digit2 << "]" << endl;
			
			current_sum =  digit1 + digit2 + carry;
			
			// cout << "sum, carry: " << current_sum << " , " << carry << endl;

			carry = (current_sum >= 10)? 1: 0;

			result = (current_sum + carry >= 10)? 
						to_string(current_sum - 10) + result :
						to_string(current_sum ) + result;
			
			// cout << "Result: " << result << endl;

			length1--; length2--;
		}

		result = (carry > 0)? to_string(carry) + result : result;
		return result;
	}
};

int main() {
	vector<vector<string>> testCases;
	testCases.push_back({"11", "123"});
	testCases.push_back({"456", "77"});
	testCases.push_back({"0", "0"});
	testCases.push_back({"9", "9"});
	testCases.push_back({"123456789", "987654321"});

	auto print = [](vector<string> v) {
		cout << "S1: " << v[0] << "\t S2: " << v[1]  << "\t";
	};

	Solution obj;
	for (auto v : testCases) {
		print(v);
		cout <<	obj.addStrings(v[0], v[1]) << endl;
	}


	return 0;
}
