/* 
    This program calculates the average of 
    numbers passed as command line 
    arguments in the terminal.

    The compiler recognizes the argument pattern
    as a program that takes command line arguments,
    argc == argument count
    argv == argument vector

    Execute: ./main 1 2 3 4 5
    Output: 3
*/

#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {

    // The book suggests you do not need to check for division by zero.
    // I disagree. Passing no arguments returns 'nan' in the output.
    
    if (argc < 2){ 
        std::cout << "Error: Please provide at least one number." << std::endl;
        return 1;
    }
    
    double total = 0;

    for (int i = 1; i < argc ; i++)
        total += atof(argv[i]);

    std::cout << "mean=" << total/(argc-1) << "\n";
    return 0;
}