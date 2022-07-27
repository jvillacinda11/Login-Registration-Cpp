#ifndef USER_H
#define USER_H

// constants
const int MAX_CLIENTS = 10;
const int MAX_CHAR_LENGTH = 256;

struct user
{
  public:
  //Constructors
  user();
  user(char un[], char pw[], int bal = 0);

 //member values
  char m_username[MAX_CHAR_LENGTH] = "";
  char m_password[MAX_CHAR_LENGTH] = "";
  int m_balance;
};


#endif