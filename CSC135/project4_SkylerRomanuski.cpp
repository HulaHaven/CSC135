/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     November 16, 2022                         */
/*   Due Date:          November 17, 2022                         */
/*   Course:            CSC_135_030                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #4                                        */
/*   Filename:          project4_SkylerRomanuski.cpp              */
/*   Purpose:           This program will call functions,         */
/*                      and calculate the current and past        */
/*			inflation                                 */
/******************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void getPrices(double&, double&, double&);

double calculateInflation(double, double);

void printResult(double, double);

int main()
{

  //Declare variables for current, priceOneYAgo, priceTwoYAgo
  double x, y, z;
  //Declare variables for current inflation and inflation 1 year ago
  double a, b;
  
  getPrices(x, y, z);
  a = calculateInflation(x, y);
  b = calculateInflation(y, z);
  printResult(a, b);

  return 0;
}

/*********************************************************************************/
/*                                                                               */
/*   Function name:      getPrices                                               */
/*   Description:        Take in current and past prices                         */
/*   Parameters:         double current: current price - input                   */
/*                       double priceOneYAgo: price from 1 year ago - input      */
/*                       double priceTwoYAgo: price from 2 years ago - input     */
/*   Return Value:       No return since its a void                              */
/*                                                                               */
/*********************************************************************************/

void getPrices(double& current, double& priceOneYAgo, double& priceTwoYAgo)
{
  cout << endl << "Enter the current price of the item: ";
  cin >> current;
  cout << endl << "Enter the price of the item one year ago: ";
  cin >> priceOneYAgo;
  cout << endl << "Enter the price of the item two years ago: ";
  cin >> priceTwoYAgo;
}

/*******************************************************************************************/
/*                                                                                         */
/*   Function name:      calculateInflation                                                */
/*   Description:        Pass in current and past prices & calculate inflation             */
/*   Parameters:         double current: current price - for calculation                   */
/*                       double yearOne: price from year one - for calculation             */
/*                       double yearTwo: price from year two - for calculation             */
/*   Return Value:       double - inflation for the inputed years                          */
/*                                                                                         */
/*******************************************************************************************/

double calculateInflation(double yearOne, double yearTwo)
{
  return (yearOne - yearTwo) / yearTwo;
}

/*******************************************************************************************/
/*                                                                                         */
/*   Function name:      printResult                                                       */
/*   Description:        Pass in current and past inflation and output the values          */
/*   Parameters:         double infCurrentY: current inflation - output                    */
/*                       double infOneYAgo: Inflation one year ago - output                */
/*   Return Value:       No return since its a void                                        */
/*                                                                                         */
/*******************************************************************************************/

void printResult(double infCurrentY, double infOneYAgo)
{
  //Format to 2 decimal place
  cout.setf(ios::fixed);
  cout << setprecision(2);

  //output statments
  cout << "Current year infaltion: " << infCurrentY << endl;
  cout << "Inflation one year ago: " << infOneYAgo << endl;

  //if statements for whether inflation is increasing or not
  if(infCurrentY > infOneYAgo)
  {
    cout << "Inflation is increasing." << endl;
  }
  else
  {
    cout << "Inflation is not increasing." << endl;
  }
}


