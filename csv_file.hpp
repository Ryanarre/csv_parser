#include "csv_row.hpp"

class CsvFile
{
public:
    CsvFile(std::string const & _path, char _delimeter)
    {
        std::ifstream infile(_path);
        std::string line;
        
        while (std::getline(infile, line))
            m_rows.push_back(CsvRow(line, _delimeter));
    }
    
    size_t size() const noexcept
    {
        return m_rows.size();
    }
    
    // TODO: Add some possibility to iterate rows instead of this, so we not display internal logic
    CsvRow const & getRowByIndex(int _index) const
    {
        if (_index >= m_rows.size())
            throw "The index is more than a row size!";
            
        return m_rows[_index];
    }
    
private:
    std::vector<CsvRow> m_rows;
};