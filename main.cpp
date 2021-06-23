// TODO: Create a lib and move this to examples

#include <iostream>
#include "csv_file.hpp"

int main(int argc, char** argv)
{
    const std::string listing = "BE0003801181_EUR";
    CsvFile csvFile("history.csv", ',');
    
    for (size_t i = 0; i < csvFile.size(); ++i)
    {
        const std::string timeStamp = csvFile.getRowByIndex(i).getValueByIndex(2);
        const std::string party = csvFile.getRowByIndex(i).getValueByIndex(1);
        
        std::cout << timeStamp << "," << timeStamp << ","
                  << party << ","
                  << csvFile.getRowByIndex(i).getValueByIndex(4) << ","
                  << csvFile.getRowByIndex(i).getValueByIndex(3) << ","
                  << csvFile.getRowByIndex(i).getValueByIndex(13) << ","
                  << csvFile.getRowByIndex(i).getValueByIndex(14) << ","
                  << party << std::endl;
    }

    return 0;
}