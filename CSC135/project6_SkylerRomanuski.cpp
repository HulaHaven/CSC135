/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     December 1, 2022                          */
/*   Due Date:          December 8, 2022                          */
/*   Course:            CSC_135_030                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #6                                        */
/*   Filename:          project6_SkylerRomanuski.cpp              */
/*   Purpose:           This program will ask to encrypt or       */
/*                      decrypt a code and then use a key to      */
/*                      encrypt or decrypt the message            */
/******************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void encrypt(char [], char [], int key);

void decrypt(char [], char [], int key);

int main()
{

  //Declare the arrays and placeholder for each letter entering the arrays
  char plaintext[100], ciphertext[100], letter;
  //variable for the key and choice of encryption or decryption
  int key, choice;

  cout << "Enter your choice (1: Encryption 2: Decryption): ";
  cin >> choice;
  cin.ignore();

  //if encryption, stores text into plaintext array
  if(choice == 1)
  {
    cout << "Enter plaintext: ";
    
    for(int i = 0; i < 100; i++)
    {
      cin.get(letter);

      if(letter == '\n')
      {
	plaintext[i] = letter;
	break;
      }
      else
      {
	plaintext[i] = letter;
      }
    }
    cout << endl << "Enter Key [1-25]: ";
    cin >> key;
    //encrypts the message
    encrypt(plaintext, ciphertext, key);
    cout << "Ciphertext: ";
    //outputs the encrypted message
    for(int i = 0; i < 100; i++)
    {
      if(ciphertext[i] == '\n')
      {
        break;
      }
      else
      {
        cout << ciphertext[i];
      }
    }
    cout << endl;
  }

  //if decryption, stores coded text into ciphertext array
  if(choice == 2)
  {
    cout << "Enter ciphertext: ";

    for(int i = 0; i < 100; i++)
    {
      cin.get(letter);

      if(letter == '\n')
      {
        ciphertext[i] = letter;
        break;
      }
      else
      {
	ciphertext[i] = letter;
      }
    }
    cout << endl << "Enter Key [1-25]: ";
    cin >> key;
    //decrypts the message
    decrypt(plaintext, ciphertext, key);
    cout << "Plaintext: ";
    //outputs the decrypted message
    for(int i = 0; i < 100; i++)
    { 
      if(plaintext[i] == '\n')
      {
        break;
      }
      else
      {
        cout << plaintext[i];
      }
    }
    cout << endl;
  }
}

/*********************************************************************************/
/*                                                                               */
/*   Function name:      encrypt                                                 */
/*   Description:        converts plaintext into an encrypted message            */
/*   Parameters:         char plaintext[]: decrypted text - input                */
/*                       char ciphertext[]: encrypted text - output              */
/*                       int key: key for the encryption - input                 */
/*   Return Value:       No return since its a void                              */
/*                                                                               */
/*********************************************************************************/

void encrypt(char plaintext[], char ciphertext[], int key)
{
  for(int i = 0; i < 100; i++)
  {
    if(plaintext[i] == '\n')
    {
      ciphertext[i] = plaintext[i];
      break;
    }
    if(plaintext[i] == ' ')
    {
      ciphertext[i] = plaintext[i];
    }
    else
    {
      ciphertext[i] = (((plaintext[i] - 97) + key) % 26) + 65;
    }
  }
}

/*********************************************************************************/
/*                                                                               */
/*   Function name:      decrypt                                                 */
/*   Description:        converts encrypted message into plaintext               */
/*   Parameters:         char plaintext[]: decrypted text - output               */
/*                       char ciphertext[]: encrypted text - input               */
/*                       int key: key for the encryption - input                 */
/*   Return Value:       No return since its a void                              */
/*                                                                               */
/*********************************************************************************/

void decrypt(char plaintext[], char ciphertext[], int key)
{
  for(int i = 0; i < 100; i++)
  {
    if(ciphertext[i] == '\n')
    { 
      plaintext[i] = ciphertext[i];
      break;
    }
    if(ciphertext[i] == ' ')
    {
      plaintext[i] = ciphertext[i];
    }
    else
    {
      plaintext[i] = ((ciphertext[i] - 65 - key + 26) % 26) + 97;
    }
  }
}
