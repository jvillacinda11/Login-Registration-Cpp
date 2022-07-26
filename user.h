#ifndef USER_H
#define USER_H
class user
{
  public:
  //Constructors
  user(char un[], char pw, int bal = 0);
  
  //functions
  char* GetUsername(){return m_username;}
  private:
  char m_username[256];
  char m_password[256];
  int m_balance;
};

#endif