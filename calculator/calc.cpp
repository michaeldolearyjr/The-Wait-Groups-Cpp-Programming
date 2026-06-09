#include <iostream>

int main() {

    const char BLANK = ' ';
    const int STOP = 0;

    double x,y,
    radd(double,double),
    rsub(double,double),
    rmul(double,double),
    rdiv(double,double),
    rpow(double,double=2);
    
    char opr = BLANK;

    while (opr != STOP){
        std::cout << "enter an expression:\n";
        std::cin >> x >> opr >> y;

        switch (opr){
            case '+':
                std::cout << "=" << radd(x,y);
                break;
            case '-':
                std::cout << "=" << rsub(x,y);
                break;
            case '*':
                std::cout << "=" << rmul(x,y);
                break;
            case '/':
                std::cout << "=" << rdiv(x,y);
                break;
            case '^':
                if (y == 2)
                    std::cout << " = " << rpow(x);
                else 
                    std::cout << " = " << rpow(x,y);
                break;
            case 'x': // cheap trick x is the 2nd letter in exit.
                opr = STOP;
                break;
            default:
                std::cout << "operator not yet implemented!\n";
                break;
        }

        std::cout << '\n';
    }

    return 0;
}

double radd(double a, double b){
    return a+b;
}

double rsub(double a, double b){
    return a-b;
}

double rmul(double a, double b){
    return a*b;
}

double rdiv(double a, double b){
    if (b==0){ 
        return 0; 
    }
    return a/b;
}

double rpow(double a, double b){
    double t = 1;
    
    if (b == 0)
        return 1;

    for (double i = 1; i < b; i++){
        t*=a;
    }

    return t;
}

