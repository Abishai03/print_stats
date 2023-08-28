#include "csv_parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<double>> parse_csv(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::vector<double>> data;

    // Skip the header row containing column names
    std::getline(file, line);
    
    size_t row_number = 0;
    while (std::getline(file, line)) {
        row_number++;
        std::istringstream ss(line);
        std::string cell;
        std::vector<double> row;
        size_t col_number = 0;
        
        while (std::getline(ss, cell, ',')) {
            col_number++;
            try {
                row.push_back(std::stod(cell));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error parsing CSV at row " << row_number << 
                ", column " << col_number << ". Invalid data: '" << cell << 
                "'." << std::endl;
                throw;  // Re-throw the exception after printing the error message
            }
        }
        data.push_back(row);
    }
    
    return data;
}
