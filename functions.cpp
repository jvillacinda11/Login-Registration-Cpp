#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "user.h"
using namespace std;

void CreateClientList()
{
  ofstream outFile("clients.txt");
  outFile << "Username\t\t\t\t\t\t\t\t\t\t"
          << "Password\t\t\t\t\t\t\t\t\t\t"
          << "Balance"
          << endl;
  outFile.close();
}

void Menu(user clients[])
{
  int choice;

  cout << "What would you like to do?\n\n";
  cout << "1. Login \n2. Register\n";
  cin >> choice;

  switch (choice)
  {
  case 1:

    Login(clients);
    break;

  case 2:
 
    Register(clients);
    break;

  default:

    cout << "invalid entry\n";
    break;
  }
}

void ReadClientList(ifstream &clientlist, user clients[], int numClients)
{
  // to ignore the first line of the client.txt
  char buff[MAX_CHAR_LENGTH];
  clientlist.getline(buff, MAX_CHAR_LENGTH);

  int i;
  // copy info from client.txt to user array
  for (i = 0; i < MAX_CLIENTS; ++i)
  {
    clientlist >> clients[i].m_username;
    clientlist >> clients[i].m_password;
    clientlist >> clients[i].m_balance;

    // if you have less than MAX_CLIENTS in you clients.txt then you exit the foor loop
    if (clientlist.eof())
    {
      break;
    }
  }
}

void Register(user clients[])
{
  //check if you have enough space in clients.txt
  if (clients[MAX_CLIENTS - 1].m_balance == -1)
  {
    int i;
    char username[MAX_CHAR_LENGTH];
    char password[MAX_CHAR_LENGTH];
    int balance;
    bool usernameAvail;
    // open ofstream as append to add new user
    ofstream outFile("clients.txt", ios::app);

    do
    {
      //User enters the username they want
      usernameAvail = true;
      cout << "Enter a username: ";
      cin >> username;

      // check if username is already taken
      for (i = 0; i < MAX_CLIENTS; ++i)
      {
        //stops the loop if you reach an empty entry
        if (clients[i].m_balance == -1)
        {
          break;
        }

        if (strcmp(username, clients[i].m_username) == 0)
        {
          cout << "username already taken! Choose another one...\n";
          usernameAvail = false;
          break;
        }
      }
    } while (usernameAvail == false);

    cout << "Enter a password: ";
    cin >> password;

    cout << "Enter initial deposit: $";
    cin >> balance;

    outFile << username << "\t\t\t\t\t\t\t\t\t\t"
            << password << "\t\t\t\t\t\t\t\t\t\t"
            << balance << endl;

    outFile.close();
  
    cout << "Welcome "<< username <<"! Please restart and login.\n";
  }
  else
  {
    cout << "Maximum clients already reached. Sorry for the inconvience...";
  }
}

void Login(user clients[])
{
  int i;
  char un[MAX_CHAR_LENGTH];
  char pw[MAX_CHAR_LENGTH];
  bool usernameCheck;
  bool passwordCheck;
    
do
 { 
  
  cout << "Enter your username: ";
  cin >> un;
  cout << "Enter you password: ";
  cin >> pw;

   for(i = 0; i < MAX_CLIENTS; ++i)
   {
     if (strcmp(clients[i].m_username, un) == 0)
     {
       usernameCheck = true;

       if(strcmp(clients[i].m_password, pw) == 0)
       {
         passwordCheck = true;
         break;
       }
     }    
   }

  if(usernameCheck == false)
  {
    cout << "\nUsername does not Exist! Try again!\n\n";

  }
  if(usernameCheck == true && passwordCheck == false)
  {
   cout << "\nIncorrect password! Try again!\n\n";
   usernameCheck = false;
  }

 }while(usernameCheck == false && passwordCheck == false);

  if (usernameCheck == true && passwordCheck == true)
  {
    cout << "\nYour current balance is "<< clients[i].m_balance <<".\n";
  }
}