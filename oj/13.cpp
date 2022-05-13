/**
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

输入描述:
将一个英文语句以单词为单位逆序排放。

输出描述:
得到逆序的句子
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string a;
    stack<string> s;
    
    while(cin>>a)
    {
        s.push(a);
    }
    
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
        if(!s.empty())
            cout <<" ";
    }
    
    return 0;
    
}