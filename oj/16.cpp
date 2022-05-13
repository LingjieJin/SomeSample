/* c++
最小公倍数 = 两数之积除以最大公约数
*/
#include<iostream>
using namespace std;
 
int gcd(int a, int b) // greatest common divisor
{
    while(a%b){
        int tmp = a;
        a = b;
        b = tmp%b;
    }
    return b;
 
}
int main()
{
    int a,b;
    while(cin >> a >> b){
        cout << a*b/gcd(a,b) <<endl;
    }
    return 0;
}