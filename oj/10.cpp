/**
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)，换行表示结束符，不算在字符里。不在范围内的不作统计。

输入描述:
输入N个字符，字符在ACSII码范围内。

输出描述:
输出范围在(0~127)字符的个数。
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    int num;
    int sum[128] = {0};
    getline(cin,a);
    
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>=0 && a[i]<=127)
           sum[a[i]]=1; 
    }
    
    for(int i=0;i<128;i++)
    {
        if(sum[i])
            num++;
    }
    cout<<num;
    
    return 0;
}