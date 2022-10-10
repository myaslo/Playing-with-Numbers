/* Name: Mya Saint-Louis
Date: 10/06/2022
Section: 0015
Assignment: Module 6 Playing wit Numbers Program
Due Date: 10/09/2022
About this project: A menu-driven program that allows the user to enter in int n
and int k to compute combinations or permutations. When user chooses 3, the 
program ends.
Assumptions: User enters in valid integer input.
All work below was performed by Mya Saint-Louis */

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
/* linprog test runs
* saintlou@linprog3.cs.fsu.edu:~/COP3363>cd playingWithNumbers
saintlou@linprog3.cs.fsu.edu:~/COP3363/playingWithNumbers>g++ playingWithNumber
s.cpp
saintlou@linprog3.cs.fsu.edu:~/COP3363/playingWithNumbers>ls
a.out  playingWithNumbers.cpp
saintlou@linprog3.cs.fsu.edu:~/COP3363/playingWithNumbers>a.out
Welcome to the playing with numbers program!

                Choices Menu

1) Compute the number of Combinations
2) Compute the number of Permutations
3) Quit

Select an option: 1

Enter in n
Enter in a positive number greater than 0...-9
Enter in a positive number greater than 0...-10
Enter in a positive number greater than 0...0
Enter in a positive number greater than 0...-23
Enter in a positive number greater than 0...52

Enter in k
Enter in a positive number greater than 0...-10
Enter in a positive number greater than 0...-64
Enter in a positive number greater than 0...5

Number of combinations: 2598960

Welcome to the playing with numbers program!

                Choices Menu

1) Compute the number of Combinations
2) Compute the number of Permutations
3) Quit

Select an option: 2

Enter in n
Enter in a positive number greater than 0...-75
Enter in a positive number greater than 0...0
Enter in a positive number greater than 0...52

Enter in k
Enter in a positive number greater than 0...5

Number of permutations: 311875200

Welcome to the playing with numbers program!

                Choices Menu

1) Compute the number of Combinations
2) Compute the number of Permutations
3) Quit

Select an option: 3
saintlou@linprog3.cs.fsu.edu:~/COP3363/playingWithNumbers>

*/