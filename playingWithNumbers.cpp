#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// function prototypes
void getValidUserInputPosNumGT0(long int &);
long double factorial(long int);
long double computeCombination(long int, long int);
long double computePermutation(long int, long int);

int main()
{
    // assigning values for menu
    const int COMBINATION_CHOICE = 1,
              PERMUTATION_CHOICE = 2,
              QUIT_CHOICE = 3;
    int option;
    long int n, k;
    long double combinationAnswer,
                permutationAnswer;
    do
    {
        // welcome message
        cout << "Welcome to the playing with numbers program!" << endl;

        //displaying menu + choices
        cout << "\n\t\tChoices Menu\n\n"
            << "1) Compute the number of Combinations\n"
            << "2) Compute the number of Permutations\n"
            << "3) Quit" << endl;
        
       cout << "\nSelect an option: ";
       cin >> option;

       // validating menu selection
       while (option < COMBINATION_CHOICE || option > QUIT_CHOICE)
       {
           cout << "\nYou've chosen an invalid option. "
                << "Please enter a valid option: ";
           cin >> option;
       }

        switch (option)
        {
        case COMBINATION_CHOICE:
            // get n
            cout << "\nEnter in n" << endl;
            getValidUserInputPosNumGT0(n);
            // get k
            cout << "\nEnter in k" << endl;
            getValidUserInputPosNumGT0(k);

            // CALCULATE COMBINATIONS
            combinationAnswer = computeCombination(n, k);
            cout << fixed << setprecision(0);
            cout << "\nNumber of combinations: "
                << combinationAnswer << "\n\n";
            break;

        case PERMUTATION_CHOICE:
            // get n
            cout << "\nEnter in n" << endl;
            getValidUserInputPosNumGT0(n);
            // get k 
            cout << "\nEnter in k" << endl;
            getValidUserInputPosNumGT0(k);

            // CALCULATE PERMUTATIONS
            permutationAnswer = computePermutation(n, k);
            cout << fixed << setprecision(0);
            cout << "\nNumber of permutations: "
                 << permutationAnswer << "\n\n";
            break;


        }
    } while (option != 3); // exits program
 
    return 0;
}

// function allows user to enter in an int and validates int
void getValidUserInputPosNumGT0(long int &num)
{
    cout << "Enter in a positive number "
         << "greater than 0...";
    cin >> num;

    while (num <= 0)
    {
        cout << "Enter in a positive number "
            << "greater than 0...";
        cin >> num;  
    }

}

// factorial function
long double factorial(long int num)
{
    int count = 1;
    long double factorial = 1;
    for (count; count <= num; count++)
    {
        // calculating factorial
        factorial *= count;
    }
    return factorial;
}

// combination function
long double computeCombination(long int n, long int k)
{
    long double factorialN, factorialK,
                parentheses, factorialParentheses,
                combination;
    // calculating factorial of n
    factorialN = factorial(n);
    // calculating factorial of k
    factorialK = factorial(k);

    parentheses = (n - k);
    factorialParentheses = factorial(parentheses);

    //calculating combinations
    combination = (factorialN) / (factorialK * (factorialParentheses));
    return combination;  
}

//permutation function
long double computePermutation(long int n, long int k)
{
    long double factorialN, parentheses,
                factorialParentheses, permutation;

    // calculating factorial of n
    factorialN = factorial(n);

    // n - k
    parentheses = (n - k);
    factorialParentheses = factorial(parentheses);

    //calculating permutation
    permutation = (factorialN) / (factorialParentheses);
    return permutation;

}
