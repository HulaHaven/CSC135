/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     November 17, 2022                         */
/*   Due Date:          December 1, 2022                          */
/*   Course:            CSC_135_030                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #5                                        */
/*   Filename:          project5_SkylerRomanuski.cpp              */
/*   Purpose:           This program will input a file and        */
/*                      find the average movie rating, average    */
/*                      reviews, # of movies made in the US,      */
/*                      highest earning, and most reviewed        */
/******************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
  //file variable
  ifstream fp;
  
  //Strings to take in the 6 differnt things from the file
  string title, director, country, earning, rating, totalReviews;
  
  //Counter varaibles for # of movies made in USA and counter to help calcualte the average
  int counter = 0, USA_counter = 0;
  
  //Variable to store the strings into these floats
  float movieRating, movieEarning, movieReview;
  
  //Variables to store the totals 
  float totalRating, totalReview;
  
  //Variables to help find the highest reviewed and earning films
  float highestReviewed = 0, highestEarning = 0;
  
  //Variables to store highest reviewed and earning movie
  string highestReviewedMovie, highestEarningMovie;
  
  fp.open("movie.csv");

  if(!fp)
    {
      cout << "Error" << endl;
      return 0;
    }

  //read and discard the first line
  getline(fp, title);

  while(getline(fp, title, ','))
  {
    getline(fp, director, ',');
    getline(fp, country, ',');
    getline(fp, earning, ',');
    getline(fp, rating, ',');
    getline(fp, totalReviews);

    //Convert the strings into float
    movieRating = stof(rating);
    movieEarning = stof(earning);
    movieReview = stof(totalReviews);

    //counter to find averages
    counter++;

    //Calculate average rating
    totalRating = totalRating + movieRating;

    //Calculate average reviews
    totalReview = totalReview + movieReview;

    //Count number of movies from United States
    if(country == "United States")
    {
      USA_counter++;
    }

    //find movie with the highest earning                                                                                                                                                                           
    if(movieEarning > highestEarning)
    {
      highestEarning = movieEarning;
      highestEarningMovie = title;
    }

    //find movie with the highest rating
    if(movieReview > highestReviewed)
    {
      highestReviewed = movieReview;
      highestReviewedMovie = title;
    }

  }

  //For alignment
  cout.setf(ios::left);
  
  cout << setw(40) << "The average rating: " << fixed << setprecision(2) << totalRating / counter << endl;
  cout << left << setw(40) << "The average number of reviews: " << fixed << setprecision(0) << totalReview / counter << endl;
  cout << left << setw(40) << "The number of movies made in the US: " << USA_counter << endl;
  cout << left << setw(40) << "The movie with highest earning: " << highestEarningMovie << endl;
  cout << left << setw(40) << "The movie with most reviews: " << highestReviewedMovie << endl;

  fp.close();
}
