#include "stats.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>


// Initialize the values to 0
stats::stats() : count(0), mean(0), std_dev(0), min(0), max(0) {}

void stats::compute(const std::vector<double>& data) {
    count = data.size();
    if (count == 0)
        return;
    
    mean = std::accumulate(data.begin(), data.end(), 0.0) / count;

    // Calculate the sum of squared differences
    double sum_sq = 0.0;
    for (const double& value : data) {
        double difference = value - mean;
        sum_sq += difference * difference;
    }

    std_dev = std::sqrt(sum_sq / count);
    min = *std::min_element(data.begin(), data.end());
    max = *std::max_element(data.begin(), data.end());
}


void stats::print() const {
    std::cout << "[" << count << ", " << mean << ", " << std_dev << ", " << min << ", " << max << "]\n";
}
