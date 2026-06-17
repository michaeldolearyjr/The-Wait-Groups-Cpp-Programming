#include <iostream>
#include <cstring>
#include <cstdlib>

/*
  Instead of waiting for us to type the numbers into the console, we pass numbers as command line arguments i.e. using the run command: `./mean2 1 2 3 4`
  
*/

// in modern c++ you don't need to explicitly declare that a function is overloaded. So we removed the line: overload mean;
double mean(double, char*[], int);
long mean(long, char*[], int);

int main(int argc, char* argv[])
{
    if (argc == 1){
        std::cout << "Enter values on command line\n";
        exit(1);
    }

    if (strchr(argv[1],'.') == 0) {
        long i = atol(argv[1]);
        long x = mean(i,argv,argc);
        std::cout << "mean = " << x << "\n";
    } else {
        double j = atof(argv[1]);
        double x = mean(j, argv, argc);
        std::cout << "mean = " << x << "\n";
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

