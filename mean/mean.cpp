#include <iostream>
#include <string.h>

int main(){
    int temp;
    double get_value(int&),
        mean(double, int),
        accum;
    
    accum = get_value(temp);
    std::cout << "mean =" << mean(accum, temp) << "\n";

    return 0;
}

////////////////////////////////////////////////

double get_value(int& t){
    char x[50];
    double accum = 0;

    std::cout << "enter values below:\n";

    for(t = 0;;t++){
        std::cin >> x;
        if(!strcmp(x,"stop"))
            break;
        accum += atof(x);
    }

    return accum;
}

double mean(double x, int total){
    if (total == 0){
        std::cout << "error--attempted division by zero\n";
        return 0;
    }

    return x / total;
}