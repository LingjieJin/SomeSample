/**
计算字符串最后一个单词的长度，单词以空格隔开。

输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。

输入
hello world

输出
5
*/

#include <iostream>

using namespace std;

int getLastWordLength(const char* in);

int main()
{
    char input[5000];
    
    std::cin.getline(input, 5000);
    
    int num = getLastWordLength(input);
    
    std::cout << num;
}

int getLastWordLength(const char* in)
{
    int num = 0;
    while((*in) != '\0')
    {
        num++;
        if((*in) == ' ')
            num =0;
        in++;
    }
    return num;
}