#include <iostream>
#include <memory>

int main()
{

    // shard ptr
    int a = 10;
    std::shared_ptr<int> ptr_a = std::make_shared<int>(a);
    std::shared_ptr<int> ptr_a2 = (ptr_a);// copy
    std::cout << ptr_a.use_count() << std::endl;

    int b = 20;
    int *p_b = &a;
    // 指针无法直接赋值给 shard ptr
    // std::shared_ptr<int> ptr_b = p_b;
    std::shared_ptr<int> ptr_b = std::make_shared<int>(b);
    ptr_a2 = ptr_b; // assign 委派
    p_b = ptr_b.get(); // get获取原始指针

    std::cout << ptr_a.use_count() << std::endl;

    return 0;
}