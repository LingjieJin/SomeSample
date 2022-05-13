#ifndef __CSV_FILE_HPP__
#define __CSV_FILE_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>

#include <vector>

typedef void* __VEC_VEC__; 

class CCSVReader
{
public:
    CCSVReader(){}
    virtual ~CCSVReader(){}

    bool isCSVFile(std::string &fileName);
    virtual bool readCSVFile(std::string &fileName, __VEC_VEC__ inFile);
    virtual bool writeCSVFile(std::string &fileName, __VEC_VEC__ outFile);
};

bool CCSVReader::isCSVFile(std::string &fileName)
{
    int index = fileName.rfind('.');
    std::string suffix = fileName.substr(index+1);
    if(!(suffix.compare("csv") == 0))
        return false;
    return true;
}

bool CCSVReader::readCSVFile(std::string &fileName, void *inFile)
{
    //error catch
    if (inFile == NULL || fileName.size() <= 0)
        return false;

    std::stringstream ss;
    std::string lineStr;
    std::string str;

    std::ifstream readFile(fileName, std::ios::in);
    if (!readFile)
        return false;

    std::vector<std::vector<std::string>> *pFile = (std::vector<std::vector<std::string>>*)inFile;

    // 读取
    while (std::getline(readFile, lineStr))
    {
        std::vector<std::string> row;

        ss = std::stringstream(lineStr);
        while (std::getline(ss, str, ','))
        {
            row.push_back(str);
        }

        pFile->push_back(row);
    }

    readFile.close();

    return true;
}

bool CCSVReader::writeCSVFile(std::string &fileName, void *outFile)
{
    int i, j;
    //error catch
    if (outFile == NULL || fileName.size() <= 0)
        return false;

    std::ofstream writeFile(fileName, std::ios::out);
    std::vector<std::vector<std::string>> *pFile = (std::vector<std::vector<std::string>> *)outFile;

    //write by row
    for (i = 0; i < pFile->size(); i++)
    {
        std::vector<std::string> &row = pFile->at(i);

        for (j = 0; j < row.size(); j++)
        {
            if (j == row.size() - 1)
            {
                writeFile << row[j] << std::endl;
            }
            else
            {
                writeFile << row[j] << ',';
            }
        }
    }

    // visited by pointer
    // //write by row
    // for (i = 0; i < pFile->size(); i++)
    // {
    //     for (j = 0; j < pFile[i].size(); j++)
    //     {
    //         if (j == pFile[i].size() - 1)
    //         {
    //             writeFile << &(pFile[i][j]) << std::endl;
    //         }
    //         else
    //         {
    //             writeFile << &(pFile[i][j]) << ',';
    //         }
    //     }
    // }

    writeFile.close();

    return true;
}


#endif