#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "hash.hpp"

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


void createHash1(string fileName, HashTable &will){
  int name=0;
  int order=0;
  string order0;
  int distance=0;
  ifstream myfile(fileName);
  if(myfile.is_open()){
    string line;
    while(getline(myfile, line)){
          will.insertItem(line);
        }
    }
    else{
      cout<<"Filed failed to Open"<<endl;
    }
}

void createHash2(string fileName2, HashTable &will0){
  int order=0;
  string name;
  ifstream myfile(fileName2);
  if(myfile.is_open()){
    string line;
    while(getline(myfile,line)){
      //cout<<line<<endl;
    stringstream ss{line};
    while(getline(ss, line, ',')){
      if(order==0){
        name=line;
        order++;
      }
      else{
        will0.insertItem2(line, name);
      }

    }
    order=0;
  }
  }

}

void createFinalTable(vector<string>& doubles,vector<vector<string>>& names, HashTable &will, HashTable &will0, int const size){
  string name;
  int counter=0;
  string message;
  int j=0;
  //string names[100][10];
  node* temp;
  node* temp1;
  bool repeat=false;
  for(int i=0; i<size; i++){
    node* temp=will0.searchItem(i);
    //cout<<i<<endl;
    //names.push_back(vector<string>());
    //cout<<i<<"-"<<endl;
    while(temp!=nullptr){
        //cout<<name<<endl;
        repeat=false;
        name=temp->key;
        for(int k=0; k< doubles.size(); k++){
           //cout<<doubles[k]<<endl<<name<<"-"<<endl;
          if(doubles[k]==name){
            //cout<<"Yo"<<endl;
            repeat=true;
            j=k;
          }
        }
        if(repeat==false){
        doubles.push_back(name);
        names.push_back(vector<string>());
        //cout<<"andrew"<<endl;
        names[counter].push_back(name);
        //cout<<"andrew is in"<<endl;
          }
        temp1=will.searchItem(i);
        while(temp1!=nullptr){
          message=temp1->key;
          if(repeat==false){
            //cout<<"i"<<endl;
            //cout<<counter<<endl;
            names[counter].push_back(message);
            //cout<<"j"<<endl;
          }
          else{
            names[j].push_back(message);
           }
           if(temp1->next==nullptr){
             //repeat=false;
             break;
           }
           temp1=temp1->next;
          }
        if(temp->next==nullptr){
            if(repeat==false){
              //cout<<"are u the bad"<<endl;
              counter++;
            }
            //repeat=false;
            break;
        }
        if(repeat==false){
            counter++;
        }
        temp=temp->next;
        //repeat=false;
    }
  }
  // for (int i = 0; i < names.size(); i++) {
  //      for (int j = 0; j < names[i].size(); j++)
  //          cout << names[i][j] << endl;
  //  }
   // for(int j=0; j<doubles.size(); j++){
   //   cout<<doubles[j]<<endl;
   // }
}

void sortVector(vector<vector<string>> &names){
  string temp;
  for (int i = 0; i < names.size(); i++){
      for (int j = 1; j < names[i].size()-1; j++){
        for(int k=1; k<names[i].size()-j; k++){
        // cout<<names[i][j]<<"-"<<names[i][j].substr(2,2)<<endl<<names[i][j+1]<<"-"<<names[i][j+1].substr(2,2)<<endl;
        // cout<<i<<"-"<<j<<endl;
        // cout<<names[i].size()<<endl;
        if(stoi(names[i][k].substr(0,2))>stoi(names[i][k+1].substr(0,2))){
          temp=names[i][k];
          names[i][k]=names[i][k+1];
          names[i][k+1]=temp;
        }
        else if(stoi(names[i][k].substr(0,2))==stoi(names[i][k+1].substr(0,2))){
          if(stoi(names[i][k].substr(3,2))>stoi(names[i][k+1].substr(3,2))){
            temp=names[i][k];
            names[i][k]=names[i][k+1];
            names[i][k+1]=temp;
          }
        }
      }
      }
    }

        // else if(names[i][j].substr(2,2)==names[i][j+1].substr(2,2)){
        //   if(names[i][j].substr(5,2)<names[i][j+1].substr(5,2)){
        //     temp=names[i][j];
        //     names[i][j]=names[i][j+1];
        //     names[i][j+1]=temp;
        //   }
        // }

  //   for (int i = 0; i < names.size(); i++) {
  //        for (int j = 0; j < names[i].size(); j++){
  //            cout << names[i][j] << endl;
  //
  //     }
  // }
}

void standardTime(vector<vector<string>> &names){
  for(int i = 0; i < names.size(); i++){
    for(int j = 1; j < names[i].size(); j++){
      if(stoi(names[i][j].substr(0,2)) > 12){
        int toChange = stoi(names[i][j].substr(0,2)) - 12;
        string str = to_string(toChange);
        names[i][j].replace(0,2,str);
        if(stoi(names[i][j].substr(0,2)) >= 10){
          names[i][j].insert(5," PM ");
        }
        else{
          names[i][j].insert(4," PM ");
        }

      }
      else if(names[i][j].substr(0,2) == "12"){
        names[i][j].insert(5, " PM ");
      }
      if(names[i][j].substr(0,1) == "0"){
        names[i][j].erase(0,1);
        names[i][j].insert(4," AM ");
      }
    }
  }
  for(int k = 0; k < names.size(); k++){
    for(int h = 0; h < names[k].size(); h++){
      cout << names[k][h] << endl;
    }
  }
}
void deleteInterest(HashTable &will0, string name, int interest){
  int a=0;
  bool isDeleted=false;
  node* temp=will0.searchItem(interest);
  node* head=will0.searchItem(interest);
  while(temp!=nullptr&&isDeleted==false ){
    if(temp->key==name&& a==0){
      will0.deleteAtHead(a);
      isDeleted=true;
    }
    else if(temp->next==nullptr){
      will0.deleteAtIndex(a, interest);
      isDeleted=true;
    }
    else if(temp->key==name){
      will0.deleteAtIndex(a, interest);
      cout<<"Yo"<<endl;
      isDeleted=true;
    }
    else{
      temp=temp->next;
      a++;
      cout<<"??"<<endl;
    }

  }

}

void addInterest(string name, HashTable &will0){
  bool done = false;
  string interest;
  while(done == false){
    cout << "What interest would you like to add? Enter 'back' if you would like to exit." << endl;
    cout << "Frisbee(1),Studying(2),SpikeBall(3),Swimming(4),Working Out(5),Biking(6),Running(7),Gaming(8),Climbing(9)" << endl;
    getline(cin,interest);
    if(interest == "back"){
      done = true;
    }
    else{
      node* newNode = new node;
      newNode->key = name;
      node* temp = will0.searchItem(stoi(interest));
      while(temp->next != nullptr){
        temp = temp->next;
      }
      temp->next = newNode;
      newNode->next = nullptr;
    }
  }
}

void deleteNames(vector<vector<string>> &names, vector<string> &doubles){
  for (int i = 0; i < names.size(); i++){
    names[i].clear();
  }
  doubles.clear();
}

void changeName(vector<vector<string>> &names, string currName, string newName, HashTable &will0){

  for(int a=0; a<names.size(); a++){
    node* temp=will0.searchItem(a);
    while(temp!=nullptr){
      if(temp->key==currName){
        temp->key=newName;
        break;
      }
          temp=temp->next;
    }

  }

  for(int i = 0; i < names.size(); i++){
    if(names[i][0] == currName){
      //cout << names[i][0] << endl;
      names[i][0].replace(names[i][0].begin(),names[i][0].end(),newName);
    }
  }

  // for(int h = 0; h < names.size(); h++){
  //   for(int j = 0; j < names[h].size(); j++){
  //     cout << names[h][j] << endl;
  //   }
  // }
}

void printInterests(vector<vector<string>> &names, string name){
  for(int i = 0; i < names.size(); i++){
    if(names[i][0] == name){
      for(int j = 0; j < names[i].size(); j++){
        cout << names[i][j] << endl;
      }
    }
  }
}

bool isInTable(vector<vector<string>> &names, HashTable& will0, string name){
  for(int a=0; a<names.size(); a++){
    node* temp=will0.searchItem(a);
    while(temp!=nullptr){
      if(temp->key==name){
        return true;
      }
          temp=temp->next;
    }
  }
  return false;
}

  //Frisbee,Studying,SpikeBall,Swimming,WorkingOut,Biking,Running,Gaming,Climbing
  int main(int argc, char const *argv[]){
    //argv[1]=messages.txt
    //argv[2]=interests.txt
    //argv[3]=number of interests(9)
    //g++ -std=c++11 HashBrowns.cpp hash.cpp
    //./a.out messages.txt interests.txt 9
    vector<vector<string>> names;
    vector<string> doubles;
    int const size=stoi(argv[3]);
    HashTable will(size);
    string fileName=argv[1];
    createHash1(fileName, will);
    HashTable will0(size);
    string fileName2=argv[2];
    createHash2(fileName2, will0);
    createFinalTable(doubles, names, will, will0, size);
    sortVector(names);
    standardTime(names);
    // string name="Andrew";
    // int interest=9;
    // deleteInterest(will0, name, interest);
    // cout<<"deleting"<<endl;
    // will0.printTable();
    // addInterest("Ryan",will0);
    // will0.printTable();
    // changeName(names,"Ryan","Steve", will0);
    // will0.printTable();
    // printInterests(names, "Steve");
    // bool exit=false;
    // string user_input;
    // int numerical_input;
    // string currentUser="defualt";
    bool exit = false;
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
          cout<<"Welcome new user!"<<endl;
          cout<<"What is your name?: "<<endl;
          getline(cin, name);
          cout<<"Welcome "<<name<<" you have been added"<<endl;
          addInterest(name,will0);
        }

        break;

        case 2:{
          bool exitLogin=false;
          while(!exitLogin){
          string name;
          cout<<"Enter Your Name: (Or enter \"back\" to exit login)"<<endl;
          getline(cin, name);
          if(isInTable(names,will0,name) || name=="back" || name=="Back"){
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
              changeName(names,currentUser,newName,will0);
              cout<<"Name changed from: "<<currentUser<<" to: "<<newName<<endl;
              currentUser=newName;
            }
            else if(userInput=="2"){
              addInterest(currentUser,will0);
            }

            else if(userInput=="3"){
              while(true){
              string delInterest;
              cout<<"Your current Interests are:";
              printInterests(names, currentUser);
              cout<<endl;
              cout<<"Which would you like to remove?"<<endl;
              cout << "Frisbee(1),Studying(2),SpikeBall(3),Swimming(4),Working Out(5),Biking(6),Running(7),Gaming(8),Climbing(9)" << endl;
              getline(cin, delInterest);
              deleteInterest(will0,currentUser,stoi(delInterest));
            }

            }
            else if(userInput=="4"){
              break;
            }
          }

        }
        break;

        case 4:{
          printInterests(names,currentUser);
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
