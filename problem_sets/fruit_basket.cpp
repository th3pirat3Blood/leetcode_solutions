/*
Description: You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.  You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
    1) You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
    2) Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
    3) Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
    Input: fruits = [1,2,1]
    Output: 3
    Explanation: We can pick from all 3 trees.

Example 2:
    Input: fruits = [0,1,2,2]
    Output: 3
    Explanation: We can pick from trees [1,2,2]. If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
    Input: fruits = [1,2,3,2,2]
    Output: 4
    Explanation: We can pick from trees [2,3,2,2]. If we had started at the first tree, we would only pick from trees [1,2].

Constraints:
    1 <= fruits.length <= 105
    0 <= fruits[i] < fruits.length
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if (fruits.size() <= 2)
            return fruits.size();

        int maxFruits = 0, fruitType1, fruitType2, count, next_i;

        auto chooseFruits = [&](int index) {
            fruitType1 = fruits[index];
            int index2 = index + 1;
            while (fruitType1 == fruits[index2]) {
                index2++;
                if (index2 == fruits.size()) {
                    index2 = index;
                    break;
                }
            }
            fruitType2 = fruits[index2];
            return index2;
        };
        
        int i = 0, cursor;
        while (i < fruits.size()-1) {
            next_i = chooseFruits(i);
            count = 2;
            for (int j = i+2; j < fruits.size(); j++) {
                if (j == fruits.size()-1) 
                    next_i = j;
                cursor = fruits[j];
                if (cursor == fruitType1 || cursor == fruitType2)
                    count++;
                else 
                    break;
            }
            i = (next_i > i++? next_i: i++);
            if (maxFruits < count)
               maxFruits = count;
        }
        
        return maxFruits;
    }
};



int main() {
    vector<vector<int>>testCases;
    testCases.push_back({0,0,1,1});
    testCases.push_back({0,0,0,0});
    testCases.push_back({1,2,3,2,2});
    testCases.push_back({0,1,2,2});
    testCases.push_back({1,2,1});
    testCases.push_back({0});
    testCases.push_back({0,1,6,6,4,4,6});
    testCases.push_back({1,0,1,0,1,0,1});

    auto printer = [](const vector<int> &fruits) {
        for (auto v: fruits)
            cout << v << " ";
    };

    Solution obj;

    for (auto test: testCases) {
        cout << "Testcase: [ "; printer(test); cout << "] \t Result:" ;
        cout << obj.totalFruit(test) << endl;
    }
    
    return 0;
}
