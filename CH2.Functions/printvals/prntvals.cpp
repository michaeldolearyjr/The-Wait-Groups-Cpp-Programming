#include <iostream>
#include <string.h>
#include <cstdarg>

using namespace std;

/* 
 
 This is a program that illustraters a function that uses a variable number of arguments. 
 
 va_list, va_start, va_arg and va_end are imported from cstdarg and used to step through memory to handle the unknown nunmber of variables.
 va_list is a special datatype that acts like a pointer, and keeps track of where we are in the list of extra arguments.
 va_start initializes the va_list pointer.
 va_arg extracts the current value from va_list and converts it (in this case) to an int.
 va_end is our cleanup function, freeing the memory.

 A note about modern C++: Although this exercise helps in understanding how memory works,
 using c-style ellipses are notoriously unsafe in modern production code, because they are
 type un-safe, and they don't automatically stop executing. You must pass a count or
 a sentinel value (like a nullptr or 0) so the function knows when it hits the end of the stack.

*/

int main() {
    void print_many(int ...);
    print_many(3,1,2,3); // the first argument indicates there will be 3 more arguments in the function call.

    return 0;
}

void print_many(int n ...) {
    va_list ap;
    va_start(ap, n);

    for(int i = 0; i < n; i++){
        int temp = var_arg(ap,int);
        if (temp != 0)
            cout << temp << "\n";
        else 
            break;
    }
    va_end(ap);
}
