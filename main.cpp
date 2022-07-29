#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "user.h"
using namespace std;

int main()
{
  //create empty user array 
  user allClients[MAX_CLIENTS];

  //attempt to open clients.txt
  ifstream inFile("clients.txt");

  //if clients.txt doesn't exist, we create one
  if (inFile.fail())
  {
    //create and close a clients.txt
    CreateClientList();

    //open new clients.txt
    ifstream inFile("clients.txt");

    //check if it failed to open
    if (inFile.fail())
    {
      cerr << "Could not open file...";
      exit(EXIT_FAILURE);
    }   
  }
  //copy info from clients.txt to user array
  ReadClientList(inFile, allClients, MAX_CLIENTS);
  inFile.close();

  //open login/registration menu
  Menu(allClients);

  return 0;

}
