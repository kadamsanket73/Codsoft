#include<iostream> // Include the input-output stream library for basic I/O operations.
#include<cstdlib>  // Include the standard library for functions like rand() and srand().
#include<ctime>     // Include the time library to get the current time
using namespace std;
int main()
{
    //Here we passing time value to srand() function but time return its value on time based so we have to do explicit typecast in int thats why we use unsigned int to convert time value into integer.
    srand((unsigned int)time(NULL));   // Seed the random number generator with the current time.
    
    int number=(rand()%100)+1;  //0-99 + 1 -> 1 to 100  // Generate a random number between 1 and 100.

    int guess=0;         // Initialize the variable to store user guesses.

    do                   // Start a do-while loop to repeatedly prompt the user for guesses. 
    {
        cout<<"Enter the Guess Between 1 to 100 :"<<endl;
        cin>>guess;

        if(guess < number)   // Check if the guess is lower than the generated number.
        {
             cout << "Try guessing higher!" << endl;   // Provide feedback to guess higher
        }
        else if(guess > number)  // Check if the guess is higher than the generated number.
        {
           cout << "Try guessing lower!" << endl;  // Provide feedback to guess lower.
        }
        else  // The guess is correct, and the user wins.
        {
            cout << "Congratulations! You guessed it right!" << endl;
        }

    }while(guess!=number);   // Continue the loop until the user's guess matches the generated number.

    return 0;
}