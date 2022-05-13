/**
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

输入描述:
第一行输入一个有字母和数字以及空格组成的字符串，第二行输入一个字符。

输出描述:
输出输入字符串中含有该字符的个数。

输入
ABCDEF
A

输出
1
*/
#include <iostream>
#include <string>

using namespace std;

int getCharNum(string &str, char a);

int main()
{
    string get_str;
    char a;
    
    getline(cin,get_str);
    
    std::cin >> a;
    
    std::cout<< getCharNum(get_str,a);
}

int getCharNum(string &str, char a)
{
    int num =0;
    for(int i=0; i <= (int)str.size();i++)
    {
        if(str[i] == a)
            num++;
        else if((str[i] >= 'a' && str[i] <= 'z')&&(str[i]==a+32))
            num++;
        else if((str[i] >= 'A' && str[i] <= 'Z')&&(str[i]==a-32))
            num++;
    }
    return num;
}