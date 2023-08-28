# Print Stats

## Overview

`Print Stats` is a command-line tool designed to read CSV files and print statistical information about each column in the data. For each column, the program outputs the count, mean, standard deviation, minimum, and maximum values.

## Prerequisites

- A modern C++ compiler (C++17 or newer recommended)
- CMake (version 3.10 or newer)
- Ubuntu 20.04

## Building

To build the project, follow these steps:

1. Clone the repository or extract the project files to a directory.
2. Open a terminal and navigate to the project directory.
3. Create a build directory named `./build`.
4. cd into build and run CMake to generate build files: `cmake ..`
5. Build the project: `make`


## Usage

After building, you can run the program using: `./print_stats ../data/random_numbers.csv`<br>
Note: replace the random_numbers.csv with the csv file you want to analize.

## ToDo

Add unit tests.