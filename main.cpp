#include <iostream>
#include <fstream>
#include <cstdlib>
#include "user.h"
using namespace std;

 
//prototype
void Menu();
void ReadClientList(ifstream &clientlist, user clients[], int numClients);



int main()
{
  user allClients[MAX_CLIENTS];

  ifstream inFile("clients.txt");
  //check if clients.txt exists if not we make one.
  if (inFile.fail())
  {
    //create and close a clients.txt
    ofstream outFile("clients.txt");
    outFile << "Username\t\t\t\t\t\t\t\t\t\t" 
            << "Password\t\t\t\t\t\t\t\t\t\t" 
            << "Balance" 
            << endl;
    outFile.close();
    ifstream inFile("clients.txt");

    //check if it failed to open
    if (inFile.fail())
    {
      cerr << "Could not open file...";
      exit(EXIT_FAILURE);
    }   
  }
  
  Menu();

  inFile.close();
  return 0;

}

void Menu()
{
  int choice;
  char cont;
  //ask user what they want to do
  do
  {
    cout << "What would you like to do?\n\n";
    cout << "1. Login \n2. Register\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "You chose login!";
      break;

    case 2:
      cout << "You chose register!";
      break;
    default:
      cout << "invalid entry";
      break;
    }
    cout << "Would you like to continue? (Y/N): ";
    cin >> cont;
  } while (cont == 'y' || cont == 'Y');
  
}

void ReadClientList(ifstream &clientlist, user clients[], int numClients)
{
  //to ignore the first line of the client.txt
  char buff[MAX_CHAR_LENGTH];
  int index;
  clientlist.getline(buff, MAX_CHAR_LENGTH);

  //copy info from client.txt to user array
  for (index = 0; index < MAX_CLIENTS; ++index)
  {
    clientlist >> clients[index].m_username;
    clientlist >> clients[index].m_password;
    clientlist >> clients[index].m_balance;

  // if you have less than MAX_CLIENTS in you clients.txt then you exit the foor loop  
    if(clientlist.eof())
    {
      break;
    }
  }
  
}
