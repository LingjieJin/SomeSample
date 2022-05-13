/**
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。

输入描述:
 输入一个整数（int类型）

输出描述:
 这个数转换成2进制后，输出1的个数
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a;
    cin>> a;
    
    int num =0;
    while(a)
    {
        if(a&0x1)
            num++;
        a = a >> 1;
    }
    
    cout << num;
    
    return 0;
}