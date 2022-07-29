#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "user.h"
using namespace std;

int main()
{
  user allClients[MAX_CLIENTS];

  ifstream inFile("clients.txt");
  //check if clients.txt exists if not we make one.
  if (inFile.fail())
  {
    //create and close a clients.txt
    CreateClientList();

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
  
  Menu(allClients);

  return 0;

}
