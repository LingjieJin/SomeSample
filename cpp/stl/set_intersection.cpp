#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;

int main()
{
    {
        std::vector<int> set1 {1, 2, 3, 4, 5, 6};
        std::vector<int> set2 {4, 5, 6, 7, 8, 9};
        std::vector<int> result;
        std::set_union(std::begin (set1), std::end(set1), // Range for set that is left operand
        std::begin(set2), std::end(set2), // Range for set that is right operand
        std::back_inserter(result));    // Destination for the result:1 2 3 4 5 6 7 8 9

        //如果不保存运算结果；可以用一个流迭代器输出这些元素：
        std::set_union(std::begin(set1), std::end(set1), std::begin(set2), std::end(set2),std::ostream_iterator<int> {std::cout, " "});
    }

    {
        std:: set<int, std::greater<int>>set1 {1, 2, 3, 4, 5, 6}; // Contains 6 5 4 3 2 1
        std:: set<int, std:: greater<int>>set2 {4, 5, 6, 7, 8, 9}; // Contains 9 8 7 6 5 4
        std::set<int, std::greater<int>>result; // Elements in descending sequence
        std::set_union(std::begin(set1), std::end(set1),std::begin(set2), std::end(set2),std::inserter(result, std::begin(result)), // Result destination: 9 8 7 6 5 4 3 2 1
        std::greater<int>()); // Function object for comparing elements
    }

    {
        // 交集算法
        std::set<string> words1 {"one", "two", "three", "four", "five", "six"};
        std::set<string> words2 {"four","five", "six", "seven", "eight", "nine"};
        std::set<string> result;
        std::set_intersection(std::begin(words1), std::end(words1), std::begin(words2), std::end(words2),std::inserter(result, std::begin(result)));
        // Result: "five" "four" "six"
    }
    return 0;
}