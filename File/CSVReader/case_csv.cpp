#include "CSVReader.hpp"

int main()
{
    CCSVReader reader;
    std::string file = "./csv.csv";


    std::vector<std::vector<std::string>> content;

    if(reader.isCSVFile(file))
    {
        std::cout << "read csv ..." << std::endl;
        reader.readCSVFile(file,&content);
    }

    for (int i = 0; i < content.size(); i++)
    {
        for (int j = 0; j < content[i].size(); j++)
        {
            std::cout<< content[i][j] << ',';
        }
        std::cout << std::endl;
    }
    
    return 0;
}