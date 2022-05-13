#include <iostream>
#include <stdio.h>

/**
 * 1.定义const常量
 * 相比宏定义，const常量定义可以进行类型安全检查
 * 比宏定义只进行字符替换要安全
 * 而且常量定义可以提高性能
 * 
 * const在修饰全局变量时限定全局变量的作用范围到其定义时所在的编译单元
 */
const double PI = 3.14159;

/**
 * 全局声明一个常量
 */
extern const int global_val;

/**
 * 2.修饰函数传入参数，防止修改
 * 
 * const int a 对于这种修饰时无意义的，因为参数是形参
 * const char* a 参数指针所指内容为常量不可变
 * char* const a 无意义，参数本身就是形参
 * const int &a 参数是引用，const防止修改
 */
void func(const int &a)
{
    // const 修饰 无法修改
    // a = 10;
    return;
}

/**
 * 3.修饰函数返回值
 * 
 * const int fun() 这个其实无意义，因为参数返回本身就是赋值
 * const int* fun() 调用时 const int *pValue = fun2();可以把fun2()看作成一个变量，即指针内容不可变
 * int* const fun() 调用时 int * const pValue = fun2();可以把fun2()看作成一个变量，即指针本身不可变
 * 
 * 一般情况下，函数的返回值为某个对象时，如果将其声明为const时，多用于操作符的重载。
 * 通常，不建议用const修饰函数的返回值类型为某个对象或对某个对象引用的情况。
 * 原因如下：
 * 如果返回值为某个对象为const（const A test = A 实例）
 * 或某个对象的引用为const（const A& test = A实例），
 * 则返回值具有const属性，
 * 则返回实例只能访问类A中的公有（保护）数据成员和const成员函数，
 * 并且不允许对其进行赋值操作，这在一般情况下很少用到。
 */

/**
 * 4.
 * 对于const类对象/指针/引用，只能调用类的const成员函数，
 * 因此，const修饰成员函数的最重要作用就是限制对于const对象的使用。
 * a. const成员函数不被允许修改它所在对象的任何一个数据成员。
 * b. const成员函数能够访问对象的const成员，而其他成员函数不可以。
 * c. 如果const成员函数想修改成员变量值，可以用mutable修饰目标成员变量。
 */
class A
{
public:
    const int m_val = 0; // const定义的成员常量 不可被修改
    int m_val_1;

public:
    // A(){} // 有const 成员变量，无法默认初始化

    A(int a) : m_val(a)
    {
        // m_val = 10;
        m_val_1 = 10;
    } // 只能在初始化列表赋值
    ~A() {}
    void f(int a) {}
    void f(int a) const {} // 函数重载
    void ff(int a) {}

    /**
     * 常成员函数, 它不改变对象的成员变量
     * 也不能调用类中任何非const成员函数
     */
    void function() const
    {
        // 无法调用非const函数
        // ff(1);
        f(1);
    }
};

/**
 * 如果const位于*的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量
 * 如果const位于*的右侧，const就是修饰指针本身，即指针本身是常量。
 */
void constPtrFunc(void)
{
    char arr[100];
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i;
    }

    // const 修饰指针
    // 该指针是常量指针，指针值不可修改，
    // 同时需要初始化时候就赋值
    char *const pContent = arr;
    const char *pContent_1;
    pContent_1 = arr;

    // 兼具两者的特性
    const char *const pContent_2 = arr;

    // 无法修改
    // pContent = pContent_1;

    *pContent = 99;
    // 指针指向的对象无法修改
    // *pContent_1 = 12;

    printf("const char*:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%c ", *pContent_1++);
    }
    printf("\n");

    printf("const char* const:\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%c ", *(pContent_2 + i));
    }
    printf("\n");
}




int main()
{
    constPtrFunc();

    /**
     * const修饰类对象/对象指针/对象引用
     * 1.const修饰类对象表示该对象为常量对象，其中的任何成员都不能被修改。
     * 对于对象指针和对象引用也是一样。
     * 
     * 2.const修饰的对象，该对象的任何非const成员函数都不能被调用，
     * 因为任何非const成员函数会有修改成员变量的企图。
     */
    const A a(10);
    a.f(10); // 只能调用const函数
    printf("a:mem:%d\n", a.m_val_1);
    // a.m_val_1 = 10; // 无法修改

    const A &b = a;

    /**
     * 使用const_cast 进行转换
     */
    A &c = const_cast<A &>(b);
    c.m_val_1 = 99;
    printf("a:mem:%d\n", a.m_val_1);

    return 0;
}