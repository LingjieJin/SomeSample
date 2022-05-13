/**
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    double a;
    int temp;
    cin>>a;
    temp = static_cast<int>(a);
    if((a-temp)>=0.5)
    {
        cout << temp+1 << endl;
    }else
    {
        cout << temp <<endl;
    }
    
    return 0;
}