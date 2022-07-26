#include <iostream>
#include <fstream>
using namespace std;

//prototype
void Menu();

int main()
{

  Menu();
  return 0;

}

void Menu()
{
  int choice;
  char cont;
  //ask user what they want to do
  do
  {
    cout << "What would you like to do?\n\n";
    cout << "1. Login \n2. Register\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "You chose login!";
      break;

    case 2:
      cout << "You chose register!";
      break;
    default:
      cout << "invalid entry";
      break;
    }
    cout << "Would you like to continue? (Y/N): ";
    cin >> cont;
  } while (cont == 'y' || cont == 'Y');
  


}