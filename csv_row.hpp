#include <vector>
#include <string>

class CsvRow
{
public:
    CsvRow(std::string const & _line, char _delimeter)
    {
        size_t prevPos = 0;
        size_t pos = _line.find(_delimeter);
        
        while (pos != std::string::npos)
        {
            m_values.push_back(_line.substr(prevPos, pos));
            
            prevPos = pos+1;
            size_t pos = _line.find(_delimeter, prevPos);
        }
        m_values.push_back(_line.substr(prevPos));
    }
    
    size_t size() const noexcept
    {
        return m_values.size();
    }
    
    std::string const & getValueByIndex(int _index) const
    {
        if (_index >= m_values.size())
            throw "The index is more than a row size!";
            
        return m_values[_index];
    }
    
private:
    std::vector<std::string> m_values;
};