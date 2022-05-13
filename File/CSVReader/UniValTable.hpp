#ifndef __UNIVALTABLE_HPP__
#define __UNIVALTABLE_HPP__

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <memory>

using std::string;
using std::vector;

namespace table_t
{

    class CUniValTable
    {
        // value
        class CUniVariable
        {
        public:
            int type;
            double m_dVal;
            string m_strVal;

        public:
            CUniVariable() {}
            ~CUniVariable() {}

            void setValue(const double &val)
            {
                m_dVal = val;
            }

            void setValue(const string &val)
            {
                m_strVal = val;
            }

            void setValue(const string &val, int type);

            /* 效率高 */
            int getStringValueType(const char *val, int size)
            {
            }

            int getStringValueType(const string &val)
            {
                /* 1. 比较慢 */
                std::stringstream sin(val);
                double t;
                char p;
                if (!(sin >> t))
                    return false;
                else
                    return true;

                /* 2. 稍微快 */
                /*
            for (int i = 0; i < val.size(); i++)
            {
                char tmp = val[i];
                if (tmp >= '0' && tmp <= '9' || tmp == '.')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
            */
            }
        };

        // cell
        class CCell
        {
        public:
            CUniVariable m_val;

        public:
            CCell() {}
            ~CCell() {}
        };

        // row
        class CRow
        {
        public:
            vector<CCell> m_vecCells;

        public:
            CRow() {}
            ~CRow() {}
        };

    public:
        // table name
        string m_strTableName;
        // head
        bool hasHeader;
        vector<string> m_vecHead;
        // content
        vector<CRow> m_vecContent;

    public:
        CUniValTable() {}
        ~CUniValTable() {}
        //
        /* 
        表格函数功能函数
        */
        // 获取表名
        string GetTableName()
        {
            return this->m_strTableName;
        }
        // 获取表头
        vector<string> &GetTableHeader()
        {
            return this->m_vecHead;
        }
        // 获取表内容
        vector<CRow> &GetTableContent()
        {
            return this->m_vecContent;
        }
        // 获取表头的索引
        int GetColumnIndex(const string &str)
        {
            vector<string>::iterator it;
            it = std::find(m_vecHead.begin(), m_vecHead.end(), str);
            if (it != m_vecHead.end())
            {
                return std::distance(m_vecHead.begin(), it);
            }
        }
        // 获取行
        CRow *GetRow(int row)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return NULL;

            return &this->m_vecContent[row];
        }
        // 获取列
        vector<CCell> *GetColumn(int col)
        {
            std::shared_ptr<vector<CCell>> pVec;

            pVec = std::make_shared<vector<CCell>>();

            if (col < 0 || col >= this->m_vecHead.size())
                return NULL;
            if (this->m_vecContent.size() <= 0)
                return NULL;

            return pVec.get();
        }
        // 获取单元格元素
        CCell *GetCell(int row, int col)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return false;
            if (col < 0 || col >= this->m_vecHead.size())
                return false;

            return &this->m_vecContent[row].m_vecCells[col];
        }
        // 获取单元格值
        CUniVariable *GetCellValue(int row, int col)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return false;
            if (col < 0 || col >= this->m_vecHead.size())
                return false;

            return &this->m_vecContent[row].m_vecCells[col].m_val;
        }
        //
        // 修改表名
        bool SetTableName(const string &tableName)
        {
            this->m_strTableName = tableName;
            return true;
        }
        // 修改表头字段
        bool SetTableHeaderString(int index, const string &headName)
        {
            if (index < 0 || index >= this->m_vecHead.size())
                return false;
            this->m_vecHead[index] = headName;
            return true;
        }
        // 修改单元格
        bool SetTableContent(int row, int col, const CCell &val)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return false;
            if (col < 0 || col >= this->m_vecHead.size())
                return false;

            this->m_vecContent[row].m_vecCells[col] = val;

            return true;
        }
        // 修改单元格值
        bool SetTableContentValue(int row, int col, const CUniVariable &val)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return false;
            if (col < 0 || col >= this->m_vecHead.size())
                return false;

            this->m_vecContent[row].m_vecCells[col].m_val = val;

            return true;
        }
        bool SetTableContentValue(int row, int col, double val)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return false;
            if (col < 0 || col >= this->m_vecHead.size())
                return false;

            this->m_vecContent[row].m_vecCells[col].m_val.m_dVal = val;

            return true;
        }
        bool SetTableContentValue(int row, int col, const string &val)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return false;
            if (col < 0 || col >= this->m_vecHead.size())
                return false;

            this->m_vecContent[row].m_vecCells[col].m_val.m_strVal = val;

            return true;
        }
        //
        // 删除指定行
        int DelTableRow(int row)
        {
            if (row < 0 || row >= this->m_vecContent.size())
                return NULL;

            this->m_vecContent.erase(this->m_vecContent.begin() + row);

            return true;
        }
    };

} // namespace table_t

#endif