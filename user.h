#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
using namespace std;

// constants
const int MAX_CLIENTS = 10;
const int MAX_CHAR_LENGTH = 256;

struct user
{
  public:
  //Constructors
  user();
  user(char un[], char pw[], int bal = -1);
  user(const user &obj);

 //member values
  char m_username[MAX_CHAR_LENGTH] = "";
  char m_password[MAX_CHAR_LENGTH] = "";
  int m_balance;
};

//nonmember functions
void CreateClientList();
void Menu(user clients[]);
void ReadClientList(ifstream &clientlist, user clients[], int numClients);
void Register(user clients[]);
void Login(user clients[]);

#endif