#include <iostream>
#include <cmath>

/*
  This program takes two numbers and an operator, 
  and outputs the calculation.
*/

int main() {

    const char BLANK = ' ';
    const int STOP = 0;


    double x, y, result,
    /* Function Prototyping */
    radd(double,double),
    rsub(double,double),
    rmul(double,double),
    rdiv(double,double),
    rrem(double,double);

    void showResult(double);
    
    char opr = BLANK;

    while (opr != STOP){
        std::cout << "enter an expression:\n";
        std::cin >> x >> opr;

        if (opr != 'r' && opr !='x' && opr != STOP){
            std::cin >> y;
        }

        /* added input sanitation to prevent infinite loops on bad input */
        if (std::cin.fail()){
            std::cin.clear();
            char next_char;
            while (std::cin.get(next_char)){
                if (next_char == 'x'){
                    opr = STOP;
                    break;
                }
                if (next_char == '\n'){
                    break;
                }
            }
        }

        switch (opr){
            case '+':
                showResult(radd(x,y));
                break;
            case '-':
                showResult(rsub(x,y));
                break;
            case '*':
                showResult(rmul(x,y));
                break;
            case '/':
                showResult(rdiv(x,y));
                break;
            case 'r':
                showResult(std::sqrt(x));
                break;
            case '^':
                showResult(std::pow(x,y));
                break;
            case '%':
                showResult(rrem(x,y));
                break;
            case 'x': // cheap trick x is the 2nd letter in exit.
                opr = STOP;
                break;
            default:
                std::cout <<"ERR: operator not yet implemented!\n";
                break;
        }

        std::cout << '\n';
    }

    return 0;
}


/* Function Definitions */
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

double rrem(double a, double b){
    return fmod(a,b);
}

void showResult(double r){
    std::cout << '=' << r;
}