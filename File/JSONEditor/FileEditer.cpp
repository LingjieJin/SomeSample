#include "FileEditer.hpp"

/***************************************************************************************/

string& TStringHelper::catString(string& str_1, string& str_2)
{

}



/****************************************************************************************/


/****************************************************************************************/

TFileEditer::TFileEditer(/* args */)
{
}

TFileEditer::~TFileEditer()
{
}

uint32_t TFileEditer::writeLineToFileEnd(string &file_path, string &content)
{
    ofstream file;

    file.open(file_path, fstream::out | fstream::app | fstream::binary);

    if( !file )
    {
        std::cout << "Error: no such file."<< std::endl;
        return -1;
    }

    if ( !file.is_open())
    {
        std::cout << "Error: can't open file."<< std::endl;
        return -1;
    }

    if ( file.bad())
    {
        std::cout << "Error."<< std::endl;
        return -1;
    }

    file << content << std::endl;

    file.close();

    return content.size();
}

uint32_t TFileEditer::writeCharToFileEnd(string &file_path, char ch)
{
    ofstream file;

    file.open(file_path, fstream::out | fstream::app | fstream::binary);

    if( !file )
    {
        std::cout << "Error: no such file."<< std::endl;
        return -1;
    }

    if ( !file.is_open())
    {
        std::cout << "Error: can't open file."<< std::endl;
        return -1;
    }

    if ( file.bad())
    {
        std::cout << "Error."<< std::endl;
        return -1;
    }

    file << ch << std::endl;

    file.close();

    return 1;
}

/*
读取全部的文件数据流
*/
string TFileEditer::readFileAll(string &file_path)
{
    std::ifstream file;
    std::ostringstream temp;

    file.open(file_path, std::ios::binary | std::ios::in);
    temp << file.rdbuf();

    string data = temp.str();
    file.close();
    
    return data;
}


uint32_t TFileEditer::readFileByLine(string &file_path)
{
    ifstream file;

    file.open(file_path);

    if( !file )
    {
        std::cout << "Error: no such file."<< std::endl;
        return 0;
    }

    if ( !file.is_open())
    {
        std::cout << "Error: can't open file."<< std::endl;
        return 0;
    }

    string line;
    while ( getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();

    return 0;
}


uint32_t TFileEditer::readFileFromEndByLine(string &file_path, int line_counts)
{

}


bool TFileEditer::isFileExist(string file_path)
{
    fstream file;
    file.open(file_path, fstream::in);

    if( file.is_open() )
    {
        file.close();
        return true;
    }
    
    return false;
}


/**********************************************************/

JSONFileEditer ::JSONFileEditer(/* args */)
{
}

JSONFileEditer ::~JSONFileEditer()
{
}

cJSON* JSONFileEditer::readJSONFile(string file_path)
{
    string temp = readFileAll(file_path);

    cJSON* root;
    root = cJSON_Parse(temp.c_str());
    
    return root;
}

int JSONFileEditer::getJSONIntItem(cJSON* root, string search)
{
    cJSON* item = cJSON_GetObjectItem(root, search.c_str());
    int temp = item->valueint;

    return temp;
}

string JSONFileEditer::getJSONStringItem(cJSON* root, string search)
{
    cJSON* item = cJSON_GetObjectItem(root, search.c_str());
    char* temp = cJSON_Print(item);
    string ret = temp;
    free(temp);

    return temp;
}

/************************************************************/

