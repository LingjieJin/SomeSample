/**
 * Lambda表达式完整的声明格式如下：
 * [capture list] (params list) mutable exception-> return type { function body }
 * 
 * capture list：捕获外部变量列表
 * params list：形参列表
 * mutable指示符：用来说用是否可以修改捕获的变量
 * exception：异常设定
 * return type：返回类型
 * function body：函数体
 * 
 * 此外，我们还可以省略其中的某些成分来声明“不完整”的Lambda表达式，常见的有以下几种：
 * 
 * 格式1声明了const类型的表达式，这种类型的表达式不能修改捕获列表中的值。
 * [capture list] (params list) -> return type {function body}
 * 
 * 格式2省略了返回值类型，但编译器可以根据以下规则推断出Lambda表达式的返回类型:
 * 1:如果function body中存在return语句，则该Lambda表达式的返回类型由return语句的返回类型确定
 * 2:如果function body中没有return语句，则返回值为void类型
 * [capture list] (params list) {function body}
 * 
 * 格式3中省略了参数列表，类似普通函数中的无参函数.
 * [capture list] {function body}
 * 
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    vector<int> myvec{3, 2, 5, 7, 3, 2};
    vector<int> lambda(myvec);

    sort(myvec.begin(), myvec.end(), cmp);
    for (int i : myvec)
    {
        cout << i << " ";
    }
    cout << endl;

    sort(lambda.begin(), lambda.end(), [](int a, int b) -> bool { return a < b; });
    for (int i : lambda)
    {
        cout << i << " ";
    }
    cout << endl;

    
    return 0;
}