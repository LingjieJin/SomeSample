#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

using std::string;

int main()
{
    {
        std::set<string> words1{"one", "two", "three", "four", " five", "six"};
        std::set<string> words2{"four", "two", " seven"};
        std::multiset<string> words3;

        /* word1 是否包含 word2  false 没有seven*/
        /* boolalpha的作用是使bool型变量按照false、true的格式输出 */
        std::cout << std::boolalpha << std::includes(std::begin(words1), std::end(words1), std::begin(words2), std::end(words2)) << std::endl; //Output: false

        /* wordl 是否包含一个空的  true */
        std::cout << std::boolalpha << std::includes(std::begin(words1), std::end(words1), std::begin(words2), std::begin(words2)) << std::endl; //Output: true

        /*set_union() 函数会通过 inserter_iterator 将 words1 和 words2 中的并集复制 word3 中*/
        std::set_union(std::begin(words1), std::end(words1), std::begin(words2), std::end(words2), std::inserter(words3, std::begin(words3)));
        /* word3 是否包含 word2 true */
        std::cout << std::boolalpha << std::includes(std::begin(words3), std::end(words3), std::begin(words2), std::end(words2)) << std::endl; //Output: true
        //
        std::copy(std::begin(words3), std::end(words3), std::ostream_iterator<string>{std::cout, " "});
    }
    //
    {
        std::multiset<string> words1{"one", "two", "nine", "nine", "one", "three", "four", "five", "six"};
        std::multiset<string> words2{"four", "two", "seven", "seven", "nine", "nine"};
        std::multiset<string> words3;

        /* 输出结果：
    five four nine nine one one seven seven six three two 
    */
        std::set_union(std::begin(words1), std::end(words1), std::begin(words2), std::end(words2), std::inserter(words3, std::begin(words3)));
        std::copy(std::begin(words3), std::end(words3), std::ostream_iterator<string>{std::cout, " "});
    }

    return 0;
}