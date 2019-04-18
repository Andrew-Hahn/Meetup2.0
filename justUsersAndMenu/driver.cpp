#include <iostream>
#include "userHash.hpp"

using namespace std;

void displayMainMenu()
{
    cout << "Welcome to Meetup 2.0:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Add New User " << endl;
    cout << " 2. Sign In " << endl;
    cout << " 3. Edit Profile"<<endl;
    cout << " 4. View Feed " << endl;
    cout << " 5. Send Message " << endl;
    cout << " 6. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

int main(){
  HashTable master= HashTable(100);

  bool exit=false;
  string user_input;
  int numerical_input;
  string currentUser="defualt";

  while(exit!=true){
    displayMainMenu();
    getline(cin, user_input);
    numerical_input=stoi(user_input);
    switch(numerical_input){
      case 1:{

        string name;
        string userLong;
        string userLat;
        string userRad;
        float longitude;
        float lattitude;
        float radius;

        cout<<"Welcome new user!"<<endl;
        cout<<"What is your name?: "<<endl;
        getline(cin, name);
        //Longitude and lattitude are simulating using a built in location finder
        //They will be used to determine distance between users
        cout<<"What is your longitude?"<<endl;
        getline(cin, userLong);
        cout<<"What is your lattitude?"<<endl;
        getline(cin, userLat);
        cout<<"What is the farthest distance you would like to see notifications from?"<<endl;
        getline(cin, userRad);
        cout<<"Welcome "<<name<<" you have been added"<<endl;
        cout<<"To add activities your interested in, log in and then select \"Edit Profile\""<<endl;
        longitude=stof(userLong);
        lattitude=stof(userLat);
        radius=stof(userRad);
        master.addName(name,longitude,lattitude,radius);
      }

      break;

      case 2:{
        bool exitLogin=false;
        while(!exitLogin){
        string name;
        cout<<"Enter Your Name: (Or enter \"back\" to exit login)"<<endl;
        getline(cin, name);
        if(master.isInTable(name) || name=="back" || name=="Back"){
          if(name!="back" && name!="Back"){
            cout<<"Welcome: "<<name<<endl;
            currentUser=name;
          }
          exitLogin=true;
        }

        else{
          cout<<"Sorry we couldn't find user: "<< name <<endl;
        }
      }
      }
      break;

      case 3:{
        bool exitEdit=false;
        if(currentUser=="defualt"){
          cout<<"Must Login to Edit a Profile"<<endl;
          break;
        }
        while(!exitEdit){
          string userInput;
          cout << "Welcome to Profile Editor:" << endl;
          cout << " 1. Change UserName " << endl;
          cout << " 2. Add Interests " << endl;
          cout << " 3. Remove Interests"<<endl;
          cout << " 4. Exit Profile Editor"<<endl;
          getline(cin, userInput);

          if(userInput=="1"){
            string newName;
            cout<<"Enter new name: "<<endl;
            getline(cin, newName);
            master.changeName(currentUser, newName);
            cout<<"Name changed from: "<<currentUser<<" to: "<<newName<<endl;
            currentUser=newName;
          }
          else if(userInput=="2"){
            bool exitAdd=false;
            while(!exitAdd){
            string userInterest;
            cout<<"Pick one of these Interests to add or enter \"back\" to exit"<<endl;
            getline(cin, userInterest);
            if(userInterest=="back"){
              exitAdd=false;
              break;
            }
            master.addInterests(currentUser,userInterest);
          }
          }

          else if(userInput=="3"){
            while(true){
            string delInterest;
            cout<<"Your current Interests are:";
            master.printInterests(currentUser);
            cout<<endl;
            cout<<"Which would you like to remove?"<<endl;
            getline(cin, delInterest);
            master.removeInterests(currentUser,delInterest);
          }

          }
          else if(userInput=="4"){
            break;
          }
        }

      }
      break;

      case 4:{
        cout<<"Case 4"<<endl;
      }
      break;

      case 5:{
        cout<<"Case 5"<<endl;
      }
      break;

      case 6:
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
