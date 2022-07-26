#include <iostream>
#include <cstring>
#include "user.h"
using namespace std;

user::user()
{
  cout << "Default Constructor!\n";
  m_username[MAX_CHAR_LENGTH] = {};
  m_password[MAX_CHAR_LENGTH] = {};
  m_balance                   = 0;
}

user::user(char un[], char pw[], int bal)
{
  cout << "Type Constructor!\n";
  strcpy(m_username,un);
  strcpy(m_password, pw);
  m_balance = bal;
}

