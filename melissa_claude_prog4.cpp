/*=====================================================================
Program: Project 4: The Piggy Bank
Author: Melissa Claude
Class: Computer Science Honors 1428
Instructor: Ziliang Zong
Date: October 17, 2017
Description: A piggy bank that shows the balance of the user and allows the user to deposit, withdrawal,
            or view the amount of coins present
Input: case number that represents a set of actions
Output: the balance of the viewer and stats
Compilation instructions:
Usage: To control the user's money and a description of it
Modifications: 10/14/2017
Date Comment: adding comments, adding loops
---- ------------------------------------------------
======================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

   bool bank = 0;
   float balance = 0.00;
   float new_balance; // will display remaining balance from set of coins
   float deposit, withdrawal;
   int num_quarters =0;
   int num_dimes =0;
   int num_nickels =0;
   int num_pennies =0;
   float quartes, nickels, pennies, dimes;
   int choice;

   cout.setf(ios::showpoint | ios::fixed );

   while (bank == 0)// will continue to display menu and allow the user to use it
       {
            cout.fill('*'); // border
            cout << setw(50) << '*' << endl;
            cout << setprecision(2);

            cout.fill(' ');
            cout << "*" << setw(31)<< "Piggy Bank Menu" << setw(18) << "*" << endl;
            cout << "*" << setw(49)<< "*" << endl;
            cout << "*" << setw(29)<< "The balance is: $ " << setw(6) << balance;
            cout << setw(14) << "*" << endl;
            cout.fill('*');
            cout << setw(50) << '*' << endl;

            cout.fill(' ');// leave inside of the border empty
            cout << "*" << setw(49)<< "*" << endl;
            cout << "*" << setw(30)<< "1) Make Deposit" << setw(19) << "*" << endl;
            cout << "*" << setw(33)<< "2) Make Withdrawal" << setw(16) << "*" << endl;
            cout << "*" << setw(28)<< "3) View Coins" << setw(21) << "*" << endl;
            cout << "*" << setw(30)<< "4) Exit Program" << setw(19) << "*" << endl;
            cout << "*" << setw(49)<< "*" << endl;
            cout.fill('*');// border
            cout << setw(50) << '*' << endl;




       cout << "Enter Choice" << endl; //asking user for choice
       cin >> choice;
       while (choice < 1 || choice > 4) //if choice is invalid, it will continue to ask until a valid choice
            {
                cout << "Invalid Option - Try Again" << endl;
                cin >> choice;

            }

        switch(choice)
        {
            case 1: //deposit
                {
                    cout << "Enter the amount to be deposited: $" << endl;
                    cin >> deposit;
                    if (deposit + balance > 900.00) // limit on how much could be deposited
                {
                    cout << "The piggybank will not hold that much." << endl;
                    cout << "You may deposit up to " << (900.00 -balance)<< endl;
                }
                else if (deposit < 0) //negative values not allowed
                {
                    cout << "Invalid amount -- Negative values are not allowed " << endl;
                }
                else // deposit accepted
                {
                    balance = balance + deposit;
                    cout << "Balance updated." << endl;
                }}
                break;
            case 2: //withdrawal
                {
                    cout << "Enter the amount to be withdrawn: $" << endl;
                    cin >> withdrawal;
                    if (withdrawal < 0) // can't withdrawal negative values
                    {
                        cout << "Invalid amount -- Negative values are not allowed." << endl;
                    }
                    else if (balance < withdrawal) //can't take out more than what you have
                    {
                        cout << "The piggybank does not contain that much. You may withdraw up to $" << balance << "." << endl;
                    }
                    else //withdrawal successful
                    {
                        balance = balance -withdrawal;
                        cout << "Balance updated." << endl;
                    }
                    }
                    break;
            case 3: //coin stats
                {
                    new_balance = balance; // switch over so it will show the correct balance at the end of the stats
                    num_quarters = new_balance/0.25;
                    new_balance -= num_quarters * 0.25;
                    num_dimes = new_balance/0.10;
                    new_balance -= num_dimes *.10;
                    num_nickels = new_balance/0.05;
                    new_balance -= num_nickels * 0.05;
                    num_pennies = new_balance / 0.01;

                    cout.fill('*'); //border
                    cout << setw(50) << '*' << endl;
                    cout << setprecision(2);

                    cout.fill(' '); //leave inside empty
                    cout << "*" << setw(31)<< "Statistics" << setw(18) << "*" << endl;

                    cout.fill('*'); //border
                    cout << setw(50) << '*' << endl;

                    cout.fill(' '); //leave inside empty
                    cout << "*" << setw(49)<< "*" << endl;
                    //show stats of each coin
                    cout << "*" << setw(20)<< "Quarters"<< setw(10) << num_quarters << setw(5) << "$" << setw(10) << (num_quarters * 0.25) <<setw(4)<< "*" << endl;
                    cout << "*" << setw(20)<< "Dimes"<< setw(10) << num_dimes << setw(5) << "$" << setw(10) <<(num_dimes * 0.10) << setw(4) << "*" << endl;
                    cout << "*" << setw(20)<< "Nickels"<< setw(10) << num_nickels << setw(5) << "$" << setw(10) <<(num_nickels * 0.05) << setw(4)<< "*" << endl;
                    cout << "*" << setw(20)<< "Pennies"<< setw(10) << num_pennies << setw(5) << "$" << setw(10) <<(num_pennies * 0.01)<< setw(4) << "*" << endl;
                    cout << "*" << setw(49)<< "*" << endl;

                    cout.fill('*'); //border
                    cout << setw(50) << '*' << endl;
                    break;
                }
            case 4: //exit the bank
                {
                    cout << "Thank you. The piggybank will now close." << endl;
                    bank = 1; //breaks loop
                    break;
                }


                }
   }
return 0; //ends program


}













