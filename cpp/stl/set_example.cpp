#include <iostream>
#include <set>
#include <unordered_set>

int main()
{
    // 标准set
    // 默认用 less<T> 对象比较。可以用相等、不相等来判断对象是否相同
    std::set<std::string> setString;
    // 保存多个值的set 保存重复的对象
    std::multiset<std::string> multisetString;
    // 而且对象是唯一的。元素在容器中的位置由元素的哈希值决定。
    // 默认用 equal_to<T> 对象来判断元素是否相等
    std::unordered_set<std::string> unordersetString;
    // 
    std::unordered_multiset<std::string> multiunordersetString;

    //
    // 当 set 中有大量元素时，在无序 set 上执行的随机插入和检索操作要比有序 set 快
    // 这里使用有序 set 进行测试
    //
    // 标准初始化
    std::set<int> numbers {8, 7, 6, 5, 4, 3, 2, 1};
    std::copy(  std::begin(numbers), 
                std::end(numbers), 
                std::ostream_iterator<int>{std::cout," "}
                );
    //
    // 提供比较函数的初始化
    std::set<std::string, std::greater<std::string>> words {"one", "two", "three", "four", "five", "six", "seven" , "eight"};
    // 列表初始化
    std::set<std::string> words2 {std::begin(words), std::end(words)};
    std::set<std::string, std::greater<std::string>> words3 {++std::begin(words2), std::end(words2)};
    //
    setString.insert("A");
    setString.insert("B");
    setString.insert("C");
    setString.insert("D");
    setString.insert("E");
    std::cout << "Now Set counts:" << setString.size() << std::endl;
    std::cout << "Now Set max counts:" << setString.max_size() << std::endl;

    // 寻找set中的元素
    std::set<std::string>::iterator it;

    it = setString.find("GG"); // 如果找到 返回当前迭代器 否则是end
    if(it != setString.end())
    {
        // find
        std::cout << " Find Element:"<< (*it) << std::endl;
    }
    else
    {
        std::cout << " Can`t Find Element"<< std::endl;
    }
    
    it = setString.find("A");
    if(it != setString.end())
    {
        // find
        std::cout << " Find Element:"<< (*it) << std::endl;
    }
    else
    {
        std::cout << " Can`t Find Element:"<< (*it) << std::endl;
    }
    
    // 删除set中的元素
    it = setString.erase(it); // 通过迭代器删除
    std::cout << " Erase Element:"<< (*it) << std::endl;

    //setString.erase(it, setString.end()); // 范围删除

    


    return 0;
}