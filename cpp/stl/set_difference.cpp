#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

using std::string;

int main()
{
    {
        /* set_difference() 算法可以创建两个集合的差集，它也有两个版本的函数并且参数集和 set_union() 相同。 */
        std::set<string, std::greater<string>> words1{"one", "two", "three", "four", "five", "six"};
        std::set<string, std::greater<string>> words2{"four", "five", "six", "seven", "eight", "nine"};
        std::set<string, std::greater<string>> result;
        std::set_difference(std::begin(words1), std::end(words1),
                            std::begin(words2), std::end(words2),
                            std::inserter(result, std::begin(result)),
                            std::greater<string>());
        // Result: "two", "three", "one"
        std::copy(std::begin(result), std::end(result), std::ostream_iterator<string>{std::cout, " "});
    }
    std::cout << std::endl;
    //
    {   
        /* set_symmetric_difference() 算法和先前的集合算法遵循同一种模式 */
        std::set<string> words1{"one", "two", "three", "four", "five", "six"};
        std::set<string> words2{"four", "five", "six", "seven", "eight", "nine"};
        std::set_symmetric_difference(std::begin(words1), std::end(words1), std::begin(words2), std::end(words2), std::ostream_iterator<string>{std::cout, " "});
        // Result: eight nine one seven three two
    }
    //
    return 0;
}