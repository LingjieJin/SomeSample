/**
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。

输入描述:
输入一个int型整数

输出描述:
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int a[10] = {0};
    int temp;
    
    cin>>n;
    while(n)
    {
        if(a[n%10]==0)
        {
            a[n%10]++;
            temp = temp*10+n%10;
        }
        n /= 10;
    }
    cout << temp;
    
    return 0;
}