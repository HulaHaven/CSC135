/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     October 25, 2022                          */
/*   Due Date:          November 1, 2022                          */
/*   Course:            CSC_135_030                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #3                                        */
/*   Filename:          project3_SkylerRomanuski.cpp              */
/*   Purpose:           This program will take in inputs,         */
/*                      and calculate the profit at a pawn shop   */
/******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  //Declare Variables
  
  string name;
  int num = 1;
  float sellingprice, cost, gross, tax, netprofit;

  //Loop

  while(name != "fine")
  {
    //For second run through it will reset the values

    gross = 0;
    tax = 0;
    netprofit = 0;

    //Inputs
    
    cout << "Enter name of the item: ";
    cin >> name;
    cout << endl;
    if(name != "fine")
      {
	cout << "Enter the number of items sold: ";
	cin >> num;
	cout << endl;
    
	while(num != 0)
	  {
	    cout << "Enter the selling price: ";
	    cin >> sellingprice;
	    cout << endl;
	    cout << "Enter the cost: ";
	    cin >> cost;
	    cout << endl;

	    num = num - 1;

	    //Calculate gross profit
	    
	    gross = gross + (sellingprice - cost);
	  }

	//Calculate Tax and net profit
	
	tax = gross * .06;
	netprofit = gross - tax - (gross * .1);

	//Left align
	
	cout.setf(ios::left);
	
	//Final Outputs
	
	cout << setw(16) << "Name:" << fixed << setprecision(2) << name << endl;
	cout << left << setw(16) << "Gross Profit:" << "$" << fixed << setprecision(2) << gross << endl;
	cout << left << setw(16) << "Tax" << "$" << fixed << setprecision(2) << tax << endl;
	cout << left << setw(16) << "Net Profit:" << "$" <<  fixed << setprecision(2) << netprofit << endl << endl;

	
      }
  }

  //Statement after end command

  cout << "Bye." << endl;
  
  return 0;
}
