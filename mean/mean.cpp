#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>

/*

 Concepts:
    a. Reference Variables: The '<type>&' syntax is used to declare a reference variable, which is essentially an alias of another variable, or a reference to that variable in memory.
    This works similar to pointers, but requires no special dereferencing operators. Dereferencing is automatic.

    Example: 
 
    int x = 10;
    int& y = x;

    Note the value of a reference variable must be set at declaration and the memory address referenced cannot be changed during the program run,
    i.e like a const memory location.

    ////////////

    b. "pass by reference", as apposed to pass by value, the parameters of a function can use a reference variable instead of a standard variable.

Questions:

    Why does the mean() function below work, even though 'accum' and 'total' have already been declared above in the main block?

    A. In C++ even nested functions do not share variables in the scope of their code block. The only exception are global variables (declared above main).
    We can safely use these variable names as function parameters to preserve readability of the code.
    
    Note: This is something I refactored because I feel the book uses poor (undescriptive and inconsistent) variable naming conventions.

Challenges:

    1. Add error handling.

*/

enum ExitCode {
    SUCCESS = 0,
    GENERIC_ERROR = 1
};

int main(){
    
    double accum;
    int total;

    double get_value(int&),
        mean(double, int);

    accum = get_value(total);
    
    try {
        std::cout << "mean =" << mean(accum, total) << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
        return ExitCode::GENERIC_ERROR;
    }

    return ExitCode::SUCCESS;
}

////////////////////////////////////////////////

double get_value(int& countReference){
    std::string inputBuffer;   //hold user input
    double accum = 0;

    std::cout << "Enter values, press enter after each value." 
              << "Enter 'stop' to calculate the mean of the values entered:\n";

    for(countReference = 0;;countReference++){ //as countReference is incremented, since it is a reference to total, it permanently updates total without the need to return 
        if (!(std::cin >> inputBuffer)) {
            // Handle unexpected EOF or stream errors
            break;
        }

        if(inputBuffer == "stop") 
            break;
        
        try {
            // std::stod is safer than std::atof because it throws on invalid inputs
            accum += std::stod(inputBuffer);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input. Please enter a valid number or 'stop'.\n";
            countReference--; // Don't count this invalid input
        } catch (const std::out_of_range& e) {
            std::cerr << "Input number out of range. Please enter a smaller/larger number.\n";
            countReference--; // Don't count this invalid input
        }
    }

    return accum;
}

double mean(double accum, int total){ 
    if (total == 0){
        throw std::invalid_argument("error--attempted division by zero");
    }

    return accum / total;
}