#include <iostream>
#include <cstring>
#include "user.h"
using namespace std;

//default constructor
user::user()
{
  m_balance = -1;
}

//Type consntructor
user::user(char un[], char pw[], int bal)
{
  strcpy(m_username,un);
  strcpy(m_password, pw);
  m_balance = bal;
}

//copy constructor
user::user(const user &obj)
{
  strcpy(m_username, obj.m_username);
  strcpy(m_password, obj.m_password);
  m_balance = obj.m_balance;
}
