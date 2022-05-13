#include <iostream>
#include <map>

int main()
{

    std::map<int, std::string> mapStu;
    mapStu.insert(std::pair<int, std::string>(1, "1"));
    mapStu.insert(std::map<int, std::string>::value_type(2, "2"));
    mapStu[10] = "10";

    printf("map size:%d\n", mapStu.size());
    for (auto i = mapStu.begin(); i != mapStu.end(); i++)
    {
        std::cout << i->first << " " << i->second << std::endl;
    }

    auto temp = mapStu.insert(std::pair<int, std::string>(1, "1"));
    if(temp.second ==true)
    {
        std::cout << "Insert success!" << std::endl;
    }
    else
    {
        std::cout << "Insert fail!" << std::endl;
    }

    auto result = mapStu.find(1);
    if(result != mapStu.end())
    {
        std::cout << "Find, the value is " << result->second << std::endl;
    }
    else
    {
        std::cout << "Can`t find!" << std::endl;
    }

    mapStu[10] = "reset 10";
    std::cout << mapStu[10] <<std::endl;
    std::cout << mapStu[9] << std::endl;

    return 0;
}