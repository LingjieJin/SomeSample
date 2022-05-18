#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::iostream;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::ostringstream;


class TStringHelper
{
public:
    TStringHelper();
    ~TStringHelper();

    static string& catString(string& str_1, string& str_2);
};


class TFileEditer
{
private:
    /* data */
public:
    TFileEditer(/* args */);
    virtual ~TFileEditer();

    static uint32_t writeLineToFileEnd(string &file_path, string &content);
    static uint32_t writeCharToFileEnd(string &file_path, char ch);

    static string readFileAll(string &file_path);
    static uint32_t readFileByLine(string &file_path);
    static uint32_t readFileFromEndByLine(string &file_path, int line_counts);

    static bool isFileExist(string file_path);

};

#include "cJSON.h"

class JSONFileEditer : public TFileEditer
{
private:
    /* data */
public:
    JSONFileEditer(/* args */);
    ~JSONFileEditer();

    static cJSON* readJSONFile(string file_path);
    static int getJSONIntItem(cJSON* root, string search);
    static string getJSONStringItem(cJSON* root, string search);

};
