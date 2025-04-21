/*
Description: Seven different symbols represent Roman numerals with the following values:
                Symbol	Value
                I	1
                V	5
                X	10
                L	50
                C	100
                D	500
                M	1000

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules: 
1)    If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
2)    If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
3)    Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.

Given an integer, convert it to a Roman numeral.

Example 1:
    Input: num = 3749
    Output: "MMMDCCXLIX"        
    Explanation:
        3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
        700 = DCC as 500 (D) + 100 (C) + 100 (C)
        40 = XL as 10 (X) less of 50 (L)
        9 = IX as 1 (I) less of 10 (X)
        Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places

Example 2:
    Input: num = 58
    Output: "LVIII"
    Explanation:
        50 = L
        8 = VIII

Example 3:
    Input: num = 1994
    Output: "MCMXCIV"
    Explanation:
        1000 = M
        900 = CM
        90 = XC
        4 = IV

Constraints:
    1 <= num <= 3999

*/

#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
    public:
        string roman_value(int N) {
            map<int, string> mappings = {{1000, "M"}, {500, "D"}, {100, "C"}, {50, "L"}, {10, "X"}, {5, "V"}, {1, "I"}};
            int roman_staple_values[] = {1000, 500, 100, 50, 10, 5, 1};
            string roman_number = "";
            while (N > 0) {
                for (auto i: roman_staple_values) {
                    if (N - i >= 0) {
                        roman_number.append((mappings.at(i)));
                        N = N - i;
                        break;
                    }
                }
            }
            return roman_number;
        }

        string intToRoman(int num) {
            map<int, string> mapp_fours_nines = {{4, "IV"}, {40, "XL"}, {400, "CD"}, 
                                                {9, "IX"}, {90, "XC"}, {900, "CM"}};
            int n, N;
            string roman_number = "";
            stack<int> digits;
            while (num > 0) {
                digits.push(num%10);
                num = num/10;
            }
            while (!digits.empty()) {
                n = digits.top();
                cout << "Number : " << n << endl;
                if (n !=4 && n!=9) {
                    N = n * pow(10, digits.size()-1);
                    roman_number.append(roman_value(N));
                } else {
                    N = n * pow(10, digits.size()-1);
                    roman_number.append(mapp_fours_nines.at(N));
                }
                digits.pop();
            }          
            return roman_number;
        }

        string intToRoman_single_function_mode(int num) {
            map<int, string> mappings = {{1000, "M"}, {500, "D"}, {100, "C"}, {50, "L"},
                                         {10, "X"}, {5, "V"}, {1, "I"}};
            map<int, string> mapp_fours_nines = {{4, "IV"}, {40, "XL"}, {400, "CD"}, 
                                                {9, "IX"}, {90, "XC"}, {900, "CM"}};           
            int roman_staple_values[] = {1000, 500, 100, 50, 10, 5, 1};
            string roman_number = "";
            int i=3, digit;

            while (i>=0) {
                if (num/pow(10, i) !=0) {
                    digit = num / pow(10, i);
                    // If digit is neither 4 nor 9
                    if (digit!=4 && digit!=9) {
                        digit = digit*pow(10, i);
                        // cout << digit << "\n";
                        while (digit > 0) {
                            for (auto symbols: roman_staple_values) {
                                if (digit - symbols >= 0) {
                                    roman_number.append((mappings.at(symbols)));
                                    digit = digit - symbols;
                                    break;
                                }
                            }
                        }
                    } else {    // digit is 4 or 9
                        roman_number.append(mapp_fours_nines.at(digit*pow(10, i)));
                    }
                    num = num % int(pow(10, i));
                }
                i--;
            }

            return roman_number;
        }
};

int main() {
    Solution obj;
    cout << obj.intToRoman_single_function_mode(3749) << "\n";
    return 0;
}