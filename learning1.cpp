#include <iostream>
#include <cmath>
using namespace std;
double power(double base, double exponent) {
    double resultE = 1;
    for (int i = 0; i < exponent; ++i) {
        resultE = resultE*base;
    }
    if (exponent < 0) {
        resultE = 1 / resultE;
    }
    return resultE;
}

int factorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*factorial(n-1);
}

double sin(double x){
    double initialval = 0;
    for(int i = 0; i<7; ++i){
        double element = power(-1, i)*power(x, (2 * i)+1)/factorial((2 * i)+1);
        initialval = initialval + element;
    }
    return initialval;
}

double cos(double x){
    double initialval2 = 0;
    for(int i = 0; i<7; ++i){
        double element2 = power(-1, i) * power(x, 2 * i) / factorial(2 * i);
        initialval2 = initialval2 + element2;
    }
    return initialval2;
}

double tan(double x){

        return sin(x)/cos(x);
    }
         
    

double sqrt(double number){
    double i;
    for(i = 0.001; i*i<number; i=i+0.001){
    }
     return i-0.001;
}

double discriminant(double a, double b, double c){
    double D = (b*b - 4*a*c);
    return (b*b - 4*a*c);
}
void solvingtheD(double a, double b, double c){
    double D = (b*b - 4*a*c);
    if (D >= 0){
        double firstroot = (-b + sqrt(D))/(2*a);
        double secondroot = (-b - sqrt(D))/(2*a);
        cout<<"The first root is "<<firstroot<<endl;
        cout<<"The second root is "<<secondroot<<endl;
    }
    else if (D < 0){
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-D) / (2 * a);
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << endl;
    }
    }
    
double logarithm(double z){
z = (z-1)/(z+1);
double logresult = 0.0;
for(int i=0; i<11; ++i){
        double result1 = power(z, 2*i + 1)/(2*i + 1);
        logresult = logresult + result1;
    }
 return 2*logresult;
}

int main(){
    int choose;
    double x, a, b, c, resultD, y;
        cout << "\nCalculator Menu:\n";
        cout << "1. Sine\n";
        cout << "2. Cosine\n";
        cout << "3. Tangent\n";
        cout << "4. Natural Logarithm\n";
        cout << "5. Solve Quadratic Equation\n";
        cout << "6. Addition\n";
        cout << "7. Subtraction\n";
        cout << "8. Multiplication\n";
        cout << "9. Division\n";
        cout << "Enter your serial number: ";
        cin >> choose;

        switch (choose) {
            case 1:
                cout << "Enter the angle in degrees: ";
                cin >> x;
                y = x*(M_PI/180);
                cout << "sin(" << x << ") = " << sin(y) << endl;
                break;
            case 2:
                cout << "Enter the angle in degrees: ";
                cin >> x;
                y = x*(M_PI/180);
                cout << "cos(" << x << ") = " << cos(y) << endl;
                break;
            case 3:
                cout << "Enter the angle in degrees: ";
                cin >> x;
                y = x*(M_PI/180);
                if(x == 90){
                    cout << "tan 90 tends to inifite bruh" << endl;
                } else {
                    cout << "tan(" << x << ") = " << tan(y) << endl;
                }
                break;
            case 4:
                cout << "Enter the number: ";
                cin >> x;
                cout << "ln(" << x << ") = " << logarithm(x) << endl;
                break;
            case 5:
                cout << "Enter coefficients a, b, and c: " << endl;
                cin >> a >> b >> c;
                solvingtheD(a, b, c);
                break;
            case 6:
                cout << "Enter two numbers" << endl;
                cin >> a >> b;
                cout << "The sum is: " << (a+b);
                break;
            case 7:
                cout << "Enter two numbers" << endl;
                cin >> a >> b; 
                cout << "The subtraction is: " << (a-b);
                break;
            case 8: 
                cout << "Enter two numbers" << endl;
                cin >> a >> b;
                cout << "The multiplication is: " << a*b;;
                break;
            case 9:
                cout << "Enter two numbers" << endl;
                cin >> a >> b;
                if (b == 0) {
        cout << "Error! Division by zero is not allowed." << endl;
    } else {
        resultD = a / b;
        cout << "The result of " << a << " / " << b << " is: " << resultD << endl;}                                    
            default:
                cout << "Exiting...\n";
                break;
        }
        return 0;
    } 