#ifndef STATS_H
#define STATS_H

#include <vector>

struct stats {
    int count;
    double mean;
    double std_dev;
    double min;
    double max;
    
    stats(); // Constructor to initialize values
    void compute(const std::vector<double>& data);
    void print() const;
};

#endif // STATS_H
