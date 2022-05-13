#ifndef __STRINGTable_HPP__
#define __STRINGTable_HPP__

#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::vector;

namespace table_t
{

    class CStringTable
    {
    public:
        // table name
        string m_strTableName;
        // head
        bool hasHeader;
        vector<string> m_vecHead;
        // content
        vector<vector<string>> m_vecContent;
        //
    public:
        CStringTable() {}
        ~CStringTable() {}
        //
        /* 
        表格函数功能函数
        */
        // 获取表名
        string GetTableName()
        {
            return this->m_strTableName;
        }
        // 有无表头
        bool hasTableHead()
        {
            return hasHeader;
        }
        // 获取表头
        vector<string> &GetTableHeader()
        {
            return this->m_vecHead;
        }
        // 获取表内容
        vector<vector<string>> &GetTableContent()
        {
            return this->m_vecContent;
        }
        // 获取表头的索引
        int GetColumnIndex(const string &str)
        {
            for (int i = 0; i < this->m_vecHead.size(); i++)
            {
                if (str.compare(m_vecHead[i]) == 0)
                {
                    return i;
                }
            }
            return -1;
        }
        // 获取行
        vector<string> &GetRow(int row)
        {
            if (row < 0 || row > this->m_vecContent.size())
            {
                return vector<string>();
            }

            return this->m_vecContent[row];
        }
        // 获取列
        vector<string> &GetColumn(int col)
        {
        }
        // 获取单元格
        string &GetCell(int row, int col)
        {
            if (row < 0 || row > this->m_vecContent.size())
                return string();
        }
        //
        // 修改表名
        bool SetTableName(const string &tableName);
        // 修改表头字段
        bool SetTableHeaderString(int index, const string &headName);
        // 修改单元格
        bool SetTableContent(int row, int col, const string &val);
        //
        // 删除指定行
        int DelTableRow(int row);
    };

} // namespace table_t

#endif