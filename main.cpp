#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "user.h"
using namespace std;

 
//prototype
void Menu(user clients[]);
void ReadClientList(ifstream &clientlist, user clients[], int numClients);
void Register(user clients[]);



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
  ReadClientList(inFile, allClients, MAX_CLIENTS);
  inFile.close();

  Menu(allClients);

  return 0;

}

void Menu(user clients[])
{
  int choice;
 // char cont;
  //ask user what they want to do
 // do
  //{
    cout << "What would you like to do?\n\n";
    cout << "1. Login \n2. Register\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "You chose login!\n";
      break;

    case 2:
      Register(clients);
      break;
    default:
      cout << "invalid entry\n";
      break;
    }
  //  cout << "Would you like to continue? (Y/N): ";
  //  cin >> cont;
  //} while (cont == 'y' || cont == 'Y');
  
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

void Register(user clients[])
{ 

  if(clients[MAX_CLIENTS - 1].m_balance == -1)
  {
  int i;
  char username[MAX_CHAR_LENGTH];
  char password[MAX_CHAR_LENGTH];
  int balance;
  bool usernameAvail;
  //open ofstream as append to add new user
  ofstream outFile("clients.txt", ios::app);
  
 do
  {
    usernameAvail = true;
    cout << "Enter a username: ";
    cin >> username;

  //check if username is already taken
  for ( i = 0; i < MAX_CLIENTS ; ++i)
  {    
    if(clients[i].m_balance == -1)
    {
      break;
    }

    if(strcmp(username, clients[i].m_username) == 0 )
    {
      cout << "username already taken! Choose another one...\n";
      usernameAvail = false;
      break;

    }
  }
  }while(usernameAvail == false);

  cout << "Enter a password: ";
  cin >> password;

  cout << "Enter initial deposit: $";
  cin >> balance;

  outFile << username << "\t\t\t\t\t\t\t\t\t\t"
          << password << "\t\t\t\t\t\t\t\t\t\t"
          << balance  << endl;
  
  outFile.close();

  cout << "Welcome "<< username <<" please restart the program and login! ";
  }
  else
  {
    cout << "Maximum clients already reached. Sorry for the inconvience...";
  }
  //potentially could return a user object and use that to login in the same session
}