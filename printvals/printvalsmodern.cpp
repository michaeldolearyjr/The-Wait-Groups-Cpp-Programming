/* 
  
  Since the example of prntvals.cpp from the book is not best practice,
  I am opting to write my own version using a "Parameter Pack"

*/

#include <iostream>

using namespace std;

template<typename... Args>
auto sum_numbers(Args... args) {
    // This is a fold expression. It expands to: (arg1 + arg2 + arg3 + ...)
    return (... + args);
}

int main() {
    // The compiler automatically counts and ensures they are numbers.
    cout << sum_numbers(10,20,30,40) << "\n";
    cout << sum_numbers(1.5,2.5,3.5) << "\n";
    
    return 0;
}