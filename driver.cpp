#include <iostream>

using namespace std;

void displayMenu()
{
    cout << "Welcome to Meetup 2.0:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Add New User " << endl;
    cout << " 2. Sign In " << endl;
    cout << " 3. View Feed " << endl;
    cout << " 4. Send Message " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

int main(){
  
  bool exit=false;
  string user_input;
  int numerical_input;

  while(exit!=true){
    displayMenu();
    getline(cin,user_input);
    numerical_input=stoi(user_input);
    switch(numerical_input){
      case 1:
      {
        ;
      }
      case 2:
      {
        ;
      }
      case 3:
      {
        ;
      }
      case 4:
      {
        ;
      }
      case 5:
      {
      cout<<"Quitting... "<<endl;
      cout<<"Goodbye!"<<endl;
      exit=true;
      break;
      }

      default:
      {
      cout<<"Invalid Input, Please Enter a  number between 1 and 5"<<endl;
      break;
      }
    }
  }
}
