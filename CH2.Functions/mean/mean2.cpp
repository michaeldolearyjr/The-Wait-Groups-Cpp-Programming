/*

In mean2 we introduce the concept of function overloading. 
In c++ we can have multiple functions with the same name, which get identified by their input parameter types, not their return type.

In this version of mean.cpp we can pass arguments to the program in the command line, as we invoke the program, like ./mean2 1 2 3 4

*/


#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

/*
  Instead of waiting for us to type the numbers into the console, we pass numbers as command line arguments i.e. using the run command: `./mean2 1 2 3 4`
*/

// in modern c++ you don't need to explicitly declare that a function is overloaded. So we removed the next line: 
// overload mean;
double mean(double, char*[], int);
long mean(long, char*[], int);

int main(int len, char* buffer[]) //command line arguments setup. The compiler knows these are command lines by their position & types in the main function parameters.
{   

    if (len == 1) {
        cout << "Enter values on command line\n";
        exit(1);
    }

    if (strchr(buffer[1],'.') == 0) {
        long i = atol(buffer[1]);
        long x = mean(i, buffer, len);
        cout << "mean = " << x << "\n";
    } else {
        double j = atof(buffer[1]);
        double x = mean(j, buffer, len);
        cout << "mean = " << x << "\n";
    }

    return 0;
}

//////////////////////////////////////

long mean(long x, char* buffer[], int len){
    long temp = x;
    for (int i = 2; i < len; i++){
        temp += atol(buffer[i]);
    }
    return temp / (len - 1);
}

//////////////////////////////////////

double mean(double x, char* buffer[], int len){
    double temp = x;
    for(int i = 2; i < len; i++){
        temp += atof(buffer[i]);
    }
    return temp / (len -1);
}

