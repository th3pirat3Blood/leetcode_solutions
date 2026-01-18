/*
 * Description:
 * Given an integer n, return true if it is a power of two. Otherwise, return false.
 * An integer n is a power of two, if there exists an integer x such that n == 2^x.

Example 1:
	Input: n = 1
	Output: true
	Explanation: 20 = 1

Example 2:
	Input: n = 16
	Output: true
	Explanation: 24 = 16

Example 3:
	Input: n = 3
	Output: false

Constraints:
    -2^31 <= n <= 2^31 - 1

 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if (n == 1)
			return true;
    	long int current_number = 1;
		while (current_number <= n) {
			current_number *= 2;
			if (current_number == n)
				return true;
		}
		return false; 
    }
	bool isPowerOfTwo_otherMethod(int n) {
		return (n & (n-1)) && (n != 0);	
	}
};

int main() {
	vector<int> testCases{1,16,3};
	Solution obj;
	string result;
	for (auto v : testCases) {
		cout << "Input: " << v << "\t Output: ";
		result = obj.isPowerOfTwo(v)? "True": "False";
		cout << result << endl;	
	}

	return 0;
}

