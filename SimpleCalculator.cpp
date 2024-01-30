#include<iostream>
#include<cmath>      // Include the cmath header for the fmod function.
using namespace std;
int main()
{

    double num1,num2;

    cout<<"Enter the Number1 :"<<endl;
    cin>>num1;
    cout<<"Enter the Number2 :"<<endl;
    cin>>num2;

    cout<<"Enter + for Addition:"<<endl;
    cout<<"Enter - for Substraction:"<<endl;
    cout<<"Enter * for Multiplication:"<<endl;
    cout<<"Enter / for Division:"<<endl;
    cout<<"Enter % for Modulus(Remainder):"<<endl;

    char ch;
    cin>>ch;

    switch(ch)
    {
        case '+':
                cout<<"Addition of "<<num1<<" and "<<num2<<" is "<<num1+num2<<endl;
                break;

        case '-':
               cout<<"Substraction of "<<num1<<" and "<<num2<<" is "<<num1-num2<<endl;
                break;

        case '*':
                cout<<"Multiplication of "<<num1<<" and "<<num2<<" is "<<num1*num2<<endl;
                break;

        case '/':
                if (num2 != 0)
                {
                    cout << "Division of " << num1 << " and " << num2 << " is " << num1 / num2 << endl;
                }
                else
                {
                    cout << "Cannot divide by zero!" << endl;
                }
                break;

        case '%':
                if (num2 != 0)
                {
                    cout << "Modulus of " << num1 << " and " << num2 << " is " << fmod(num1, num2) << endl;
                }
                else
                {
                    cout << "Cannot calculate modulus with zero!" << endl;
                }
                break;

        
        default:
               cout<<"Invalid Choice!"<<endl;
               break;
    }

    return 0;

}