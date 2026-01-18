/*
 * Description:
 *
 *
 */ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int result = -1, startIndex = 0, total_size = nums.size();
			
			if (total_size == 1 )
				return (nums[0] == target)? 0: -1;

			// Handle the case where target may be found in the second half of the array
			if (target <= nums[total_size-1]) {
				startIndex = total_size-1;
				while (true) {
					if (target == nums[startIndex])
					   return startIndex;
					if (target > nums[startIndex] || startIndex == 0)	// End if not found
						return -1;	
					startIndex--; 
				}	
			}

			//Handle the case where target may be found in the first half of the array 
			else {
				while (true) {
					if (target == nums[startIndex])
						return startIndex;
					if (target < nums[startIndex] || startIndex+1 == total_size )	// End if not found 
						return -1;
					startIndex++;
				}
			}
			return result;			
		}
};

int main() {
	vector<vector<int>> testCases;

	testCases.push_back({4, 5, 6, 7, 0, 1, 2, 3});
	testCases.push_back({5, 6, 7, 0, 1, 2, 3});
	testCases.push_back({1});
	testCases.push_back({1, 3});
	
	auto printCase = [](vector<int> v) {
		for (auto x: v)
			cout << x << " "; 
	};

	Solution obj;
	
	for (auto tc: testCases) {
		cout << "Testcase: ";
		printCase(tc);
		cout << "\t Target: 4";
		cout << "\t Result: " << obj.search(tc, 4) << endl;
	}
	
	return 0;
}
