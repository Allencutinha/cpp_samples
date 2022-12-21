#include <fstream>
#include <iostream>

int main() {
    // Open the input file for reading
    std::ifstream input_file("../../data/input_sum.txt");

    // Open the output file for writing
    std::ofstream output_file("../../data/output_sum.txt");

    // Check if the input file was successfully opened
    if (!input_file) {
        std::cerr << "Error: failed to open input file" << std::endl;
        return 1;
    }

    // Check if the output file was successfully opened
    if (!output_file) {
        std::cerr << "Error: failed to open output file" << std::endl;
        return 1;
    }

    // Read two numbers from the input file, one on each line,
    // and write the sum of those numbers to the output file
    // until we reach the end of the input file
    int a, b;
    while (input_file >> a >> b) {
        output_file << a + b << std::endl;
    }

    // Close the input and output files
    input_file.close();
    output_file.close();

    return 0;
}
