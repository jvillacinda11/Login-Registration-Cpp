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

user::user(const user &obj)
{
  cout << "copy Constructor!\n";
  strcpy(m_username, obj.m_username);
  strcpy(m_password, obj.m_password);
  m_balance = obj.m_balance;
}
