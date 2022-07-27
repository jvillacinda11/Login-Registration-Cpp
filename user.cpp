#include <iostream>
#include <cstring>
#include "user.h"
using namespace std;

user::user()
{
  //cout << "Default Constructor!\n";
  m_balance                   = -1;
}

user::user(char un[], char pw[], int bal)
{
  cout << "Type Constructor!\n";
  strcpy(m_username,un);
  strcpy(m_password, pw);
  m_balance = bal;
}

