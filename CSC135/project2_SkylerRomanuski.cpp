/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     October 18, 2022                          */
/*   Due Date:          October 20, 2022                          */
/*   Course:            CSC_135_030                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #2                                        */
/*   Filename:          project2_SkylerRomanuski.cpp              */
/*   Purpose:           This program will take in inputs,         */
/*                      and calculates the city's water bill      */
/*                      depending on what it is being used for    */
/******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main(){

  //Declare Variables

  int accountnumber, water;
  float cost;
  char code;
  string type;
  
  //Inputs

  cout << "Enter the account number: " << endl;
  cin >> accountnumber;
  cout << "Ender the service code: " << endl;
  cin >> code;
  cout << "Enter the amount of water used (gallons): " << endl;
  cin >> water;

  //setw
  
  cout.setf(ios::left);

  //Code type
  
  if(code == 'c')
    {
      type = "Commercial";
    }
  if(code == 'h')
    {
      type = "Home";
    }
  if(code == 'i')
    {
      type = "Industrial";
    }

  //Switch statement

  switch(code)
    {
      case 'h':
        if(water <= 100)
          {
            cost = 10;
          }
        if(water > 100 && water <= 200)
          {
            cost = 10 + ((water - 100) * .05);
          }
        if(water > 200)
          {
            cost = 15 + ((water - 200) * .02);
          }
        break;
      case 'c':
        if(water <= 1000)
          {
            cost = 500;
          }
        if(water > 1001 && water <= 2500)
          {
            cost = 500 + ((water - 1000) * .08);
          }
        if(water > 2500)
          {
            cost = 620  + ((water - 2500) * .06);
          }
        break;
      case 'i':
        if(water <= 5000)
          {
            cost = 1500;
          }
        if(water > 5000)
          {
            cost = 1500 + ((water - 5000) * .07);
          }
        break;
      default:
        cout << "Not an Option" << endl;
    }
  //Final Output

  cout << "Water Bill Calculater" << endl;
  cout << "==========================================================" << endl;
  cout << setw(30) << "Account number: " << accountnumber << endl;
  cout << setw(30) << "Service: " << type << endl;
  cout << setw(30) << "Gallons of water used: " << water << endl;
  cout << setw(30) << "Amount due: ";

  //Decimal
  
  cout.setf(ios::fixed);
  cout << setprecision(2);

  //Final amount due
  
  cout << "$" << cost << endl;

  return 0;
  
}


    
