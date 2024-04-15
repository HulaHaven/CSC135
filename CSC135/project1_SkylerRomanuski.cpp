/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     September 22, 2022                        */
/*   Due Date:          September 29, 2022                        */
/*   Course:            CSC_135_030                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #1                                        */
/*   Filename:          project1_SkylerRomanuski.cpp              */
/*   Purpose:           This program will take in inputs,         */
/*                      calculates new amount in savings, and     */
/*			total interest for your savings account   */
/*			balance                                   */
/******************************************************************/



#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){

  //Declare Variables

  float Principal, Interest_Rate, Amount, Total_Interest, Interest_Percent;
  int Times_Compounded;
  
  //Welcome Statement
  
  cout << "Welcome to Saving Account Balance Calculator!" << endl;
  cout << "---------------------------------------------------" << endl;
  
  //Input Statements

  cout << endl << "Please enter your initial balance(without the $ symbol): ";
  cin >> Principal;
  cout << endl << "Please enter the interest rate: ";
  cin >> Interest_Rate;
  cout << endl << "Please enter the number of times the interest is compunded a year: ";
  cin >> Times_Compounded;cout << endl;

  //Decimals

  cout.setf(ios::fixed);
  cout << setprecision(2);
  
  //Calculations

  Amount = Principal * pow(1 + Interest_Rate / Times_Compounded, Times_Compounded);
  Total_Interest = Amount - Principal;
  Interest_Percent = Interest_Rate * 100;
  
  //Output Statements

  cout << "Report" << endl;
  cout << "------------------------------------" << endl;
  cout << "Interest Rate:" << setw(13) << Interest_Percent  << "%"  << endl;
  cout << "Times Compounded:" << setw(8) << Times_Compounded << endl;
  cout << "Principal:" << setw(15) << "$ " << Principal << endl;
  cout << "Interest:" << setw(16) << "$ " << Total_Interest << endl;
  cout << "Amount In Savings:" << setw(7) << "$ " << Amount << endl;


 
  return 0;
}
