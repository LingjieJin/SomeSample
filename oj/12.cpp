/**
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述:
输入N个字符

输出描述:
输出该字符串反转后的字符串
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin>>a;
    
    for(int i=a.size()-1;i>=0;i--)
    {
        cout << a[i];
    }
    
    return 0;
}