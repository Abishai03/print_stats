#include "csv_parser.h"
#include "stats.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << "\n";
        return 1;
    }
    
    std::cout << "Statistics for 'column_number': [count, mean, std, min, max]\n";

    // Store the data as 2-D vector
    std::vector<std::vector<double>> data = parse_csv(argv[1]);

    size_t max_columns = 0;
    for (const auto& row : data) {
        if (row.size() > max_columns) {
            max_columns = row.size();
        }
    }

    for (size_t col = 0; col < max_columns; ++col) {
        std::vector<double> column_data;
        
        for (size_t row = 0; row < data.size(); ++row) {
            if (col < data[row].size()) {
                column_data.push_back(data[row][col]);
            }

        }
        
        stats column_stats;
        column_stats.compute(column_data);
        std::cout << "Statistics for column " << col+1 << ": ";
        column_stats.print();
    }
    
    return 0;
}
