/**
从输入任意个整型数，统计其中的负数个数并求所有非负数的平均值

*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int num = 0;
    int d_num = 0;
    double d_sum = 0;
    while(cin >> n)
    {
        if(n<0)
            num++;
        else
        {
            d_num++;
            d_sum += n;
        }
    }
    cout << num <<endl;
    cout << showpoint << (d_sum / d_num) <<endl;
    
    return 0;
}