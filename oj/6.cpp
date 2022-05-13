/**
功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（如180的质因子为2 2 3 3 5 ）

最后一个数后面也要有空格


*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
string getResult(long ulDataInput);

int main()
{
    long a;
    cin>>a;
    
    cout << getResult(a);
}

string getResult(long ulDataInput)
{
    ostringstream os;
    for(int i=2;i<=ulDataInput;i++)
    {
        if(ulDataInput%i==0)
        {
            ulDataInput = ulDataInput /i;
            os << i << " ";
            --i;
        }
    }
    
    return os.str();
}