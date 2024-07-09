/* 
 * Description:
 * Find if a number is pallindrom or not
 * */


#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        long new_number = 0, old_number = x;
        int r;
        while (x>0) {
            new_number = new_number*10 + x%10;
            x /= 10;
        }
        if (new_number == old_number)
            return true;
        else
            return false;
    }
};

int main() {
    Solution obj;
    std::cout << "Answer: " << obj.isPalindrome(121) << "\n";
    return 0;
}