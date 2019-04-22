#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "hash.hpp"
#include "groupGraph.hpp"

//Method to display main choice menu to users
void displayMainMenu()
{
    cout << "Welcome to Meetup 2.0:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Add New User " << endl;
    cout << " 2. Sign In " << endl;
    cout << " 3. Edit Profile"<<endl;
    cout << " 4. View Feed " << endl;
    cout << " 5. Groups " << endl;
    cout << " 6. Quit " <<endl;
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
    /*
    else{
      cout<<"File failed to Open"<<endl;
    }
    */
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

//method to intialize groups graph from input files
//method takes in 3 filenames and address of Graph
void intitializeGraph(string fileName2, string fileName3, string fileName4, Graph& graph){
  //initialze variables for placekeeping and storage of information from files
  int order=0;
  int order2=0;
  int order3=0;
  string name;
  string description;
  string meetingDAndT;
  string meetingLocation;
  vector<string> userInterests;
  vector<string> groupInterests;
  vector<string> groupMembers;
  //open file correlating users names and interests
  ifstream myfile(fileName2);
  //check if file is open
  if(myfile.is_open()){
    string line;
    //iterate through each complete line
    while(getline(myfile,line)){
    stringstream ss{line};
    //iterate through each line delimted by commas
    while(getline(ss, line, ',')){
      //if this is the first part of the line, it is the users name
      if(order==0){
        name=line;
        order++;
      }
      //else add this interest to the users Interest vector
      else{
        if(line=="1"){
          userInterests.push_back("Frisbee");
        }
        else if(line=="2"){
          userInterests.push_back("Studying");
        }
        else if(line=="3"){
          userInterests.push_back("SpikeBall");
        }
        else if(line=="4"){
          userInterests.push_back("Swimming");
        }
        else if(line=="5"){
          userInterests.push_back("Working Out");
        }
        else if(line=="6"){
          userInterests.push_back("Biking");
        }
        else if(line=="7"){
          userInterests.push_back("Running");
        }
        else if(line=="8"){
          userInterests.push_back("Gaming");
        }
        else if(line=="9"){
          userInterests.push_back("Climbing");
        }
      }
      //add the user to the graph
      graph.addUser(name,userInterests);
    }
    //for each new line reset order to 0
    order=0;
  }
  }
  //close file
  myfile.close();
  //open file correlating groups names with information about the group
  ifstream myfile2(fileName3);
  if(myfile2.is_open()){
    string line2;
    //iterate through each full line
    while(getline(myfile2,line2)){
      stringstream ss{line2};
      //iterate through each comma break
      while(getline(ss,line2,',')){
        //first element is groups name
        if(order2==0){
          name=line2;
          order2++;
        }
        //second element is groups description
        else if(order2==1){
          description=line2;
          order2++;
        }
        //third element is groups meeting date and time
        else if(order2==2){
          meetingDAndT=line2;
          order2++;
        }
        //fourth elemnt is groups meeting location
        else if(order2==3){
          meetingLocation=line2;
          order2++;
        }
        //all following elements are groups interests
        else{
          groupInterests.push_back(line2);
        }
        //add group to graph with addGroup Method
        graph.addGroup(name,description,groupInterests,meetingDAndT,meetingLocation);
      }
      order2=0;
    }
  }
  //closer file
  myfile2.close();
  //open file correlating groups names with members names
  ifstream myfile3(fileName4);
  if(myfile3.is_open()){
    string line3;
    //iterate through full lines
    while(getline(myfile,line3)){
    stringstream ss{line3};
    //iterate through , delimters
    while(getline(ss, line3, ',')){
      //first element is groups name
      if(order3==0){
        name=line3;
        order++;
      }
      else{
        //all other elements are members names
        groupMembers.push_back(line3);
      }

      //iterate through found members and add an edge to each group
      for(int z=0; z<groupMembers.size(); z++){
        graph.addUserToGroup(groupMembers.at(z),name);
      }
    }
    order3=0;
  }
  }
  myfile3.close();

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
        if(stoi(names[i][k].substr(2,2))>stoi(names[i][k+1].substr(2,2))){
          temp=names[i][k];
          names[i][k]=names[i][k+1];
          names[i][k+1]=temp;
        }
        else if(stoi(names[i][k].substr(2,2))==stoi(names[i][k+1].substr(2,2))){
          if(stoi(names[i][k].substr(5,2))>stoi(names[i][k+1].substr(5,2))){
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
      if(stoi(names[i][j].substr(2,2)) > 12){
        int toChange = stoi(names[i][j].substr(2,2)) - 12;
        string str = to_string(toChange);
        names[i][j].replace(2,2,str);
        if(stoi(names[i][j].substr(2,2)) >= 10){
          names[i][j].insert(7," PM ");
        }
        else{
          names[i][j].insert(6," PM ");
        }

      }
      else if(names[i][j].substr(2,2) == "12"){
        names[i][j].insert(7, " PM ");
      }
      if(names[i][j].substr(2,1) == "0"){
        names[i][j].erase(2,1);
        names[i][j].insert(6," AM ");
      }
    }
  }
  cout<<"Loading all users"<<endl;
  for(int k = 0; k < names.size(); k++){
    for(int h = 0; h < names[k].size(); h++){
      cout << names[k][h] << endl;
    }
  }
}

void deleteInterest(HashTable &will0, string name, int interest, vector<vector<string>> &names){
  int a=0;
  bool isDeleted=false;
  node* temp=will0.searchItem(interest);
  node* head=will0.searchItem(interest);
  while(temp!=nullptr&&isDeleted==false ){
    if(temp->key==name&& a==0){
      will0.deleteAtHead(a);
      isDeleted=true;
      //delete in vector
    }
    else if(temp->next==nullptr){
      will0.deleteAtIndex(a, interest);
      isDeleted=true;
    }
    else if(temp->key==name){
      will0.deleteAtIndex(a, interest);
      isDeleted=true;
    }
    else{
      temp=temp->next;
      a++;
    }
  }
  for(int i=0; i<names.size(); i++){
    if(names[i][0]==name){
      for(int j=1; j<names[i].size(); j++){
        if(stoi(names[i][j].substr(0,1))==interest){
          names[i].erase(names[i].begin()+j);
          j--;
        }
      }
    }
  }
}

void addInterest(string name, HashTable &will0, Graph &graphOfGroups, vector<vector<string>> &names, HashTable &will, bool new0){
  bool done = false;
  string message;
  string interest;
  int zz=0;
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
      graphOfGroups.addUserInterest(name,interest);

      if(new0==false){
      for(int i=0; i<names.size(); i++){
        if(names[i][0]==name){
          node* temp0=will.searchItem(stoi(interest));
          while(temp0!=nullptr){
            message=temp0->key;
            names[i].push_back(message);
            temp0=temp0->next;
          }
        }
      }
    }
    else{
      node* temp1=will.searchItem(stoi(interest));
      int z=names.size();
      names.push_back(vector<string>());
      names[z].push_back(name);
      while(temp1!=nullptr){
        //cout<<"hello"<<endl;
          message=temp1->key;
          temp1=temp1->next;
          names[z].push_back(message);
          new0=false;
      }

    }

  }
}
  sortVector(names);
  standardTime(names);

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
    //cout<<"looking"<<endl;
    if(names[i][0] == name){
      cout<<"found"<<endl;
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
//Method to display group menu
void displayGroupMenu(){

  cout << "+=====Group Menu=========+" << endl;
  cout << " 1. Create a Group " << endl;
  cout << " 2. Join new groups"<<endl;
  cout << " 3. View my groups"<<endl;
  cout << " 4. Quit " <<endl;
  cout << "+-----------------------+" << endl;
  cout << "#> ";

}

void addUser(HashTable &will, HashTable &will0, vector<vector<string>> &names, string name, Graph &graphOfGroups){
  bool new0=true;
  addInterest(name,will0,graphOfGroups, names, will, new0);
}
//main method
  //Frisbee,Studying,SpikeBall,Swimming,WorkingOut,Biking,Running,Gaming,Climbing
  int main(int argc, char const *argv[]){
    //argv[1]=messages.txt
    //argv[2]=interests.txt
    //argv[3]=number of interests(9)
    //argv[4]=allGroups.txt
    //argv[5]=groupMembers.txt
    //g++ -std=c++11 HashBrowns.cpp hash.cpp
    //./a.out messages.txt interests.txt 9
    if(argc!=6){
      cout<<"Usage is ./a.out messages.txt interests.txt 9 allGroups.txt groupMembers.txt"<<endl;
      return EXIT_FAILURE;
    }

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

    //groups stuff
    string fileName3=argv[4];
    string fileName4=argv[5];
    Graph groups;
    intitializeGraph(fileName2,fileName3,fileName4,groups);
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
          cout<<"Welcome "<<name<<" you have been added:"<<endl;
          addUser(will, will0, names, name, groups);
        }

        break;

        case 2:{
          //this case allows a user to login using their userName
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

        //allows a user to change their name and add/remove interests
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
              bool new0=false;
              addInterest(currentUser,will0,groups,names, will, new0);
            }

            else if(userInput=="3"){
              bool stay=true;
              while(stay==true){
              string delInterest;
              cout<<"Your current Interests are:";
              printInterests(names, currentUser);
              cout<<endl;
              cout<<"Which would you like to remove?"<<endl;
              cout << "Frisbee(1),Studying(2),SpikeBall(3),Swimming(4),Working Out(5),Biking(6),Running(7),Gaming(8),Climbing(9)" << endl;
              getline(cin, delInterest);
              if(delInterest=="back"){
                stay=false;
              }
              else{
                int delInterestNum=stoi(delInterest);
                deleteInterest(will0,currentUser,delInterestNum, names);
                groups.removeUserInterest(currentUser,delInterest);
              }

            }
            }
            else if(userInput=="4"){
              break;
            }
          }

        }
        break;

        //prints a users current feed
        case 4:{
          printInterests(names,currentUser);
        }
        break;
        //this case opens the groups interface
        case 5:{
          bool exitGroups=false;

          while(!exitGroups){
            string userChoice;
            displayGroupMenu();
            getline(cin,userChoice);
            int userChoiceNum=stoi(userChoice);
            switch(userChoiceNum){
              //case 1 allows a user to create a new group
              case 1:
              {
                string gName;
                string gDescript;
                string meetDays;
                string meetTime;
                string meetLoc;
                vector<string> gInterests;
                cout<<"Enter group name: "<<endl;
                getline(cin, gName);
                cout<<"Enter group description: "<<endl;
                getline(cin,gDescript);
                cout<<"What day(s) of the week will your group be meeting?"<<endl;
                getline(cin, meetDays);
                cout<<"What time of day will your group meet?"<<endl;
                getline(cin, meetTime);
                cout<<"Where will your group meet?"<<endl;
                getline(cin,meetLoc);

                while(true){
                  string intChoice;
                  cout<<"Enter numbers of interests related to your group (ONE AT A TIME), or enter \"done\" or \"0\" to finish entering interests"<<endl;
                  cout<<"Frisbee(1),Studying(2),SpikeBall(3),Swimming(4),Working Out(5),Biking(6),Running(7),Gaming(8),Climbing(9)" <<endl;
                  getline(cin,intChoice);
                  if(intChoice=="1" || intChoice=="Frisbee"){
                    gInterests.push_back("Frisbee");
                  }
                  else if(intChoice=="2" || intChoice=="Studying"){
                    gInterests.push_back("Studying");
                  }
                  else if(intChoice=="3" || intChoice=="SpikeBall"){
                    gInterests.push_back("SpikeBall");
                  }
                  else if(intChoice=="4" || intChoice=="Swimming"){
                    gInterests.push_back("Swimming");
                  }
                  else if(intChoice=="5" || intChoice=="Working Out"){
                    gInterests.push_back("Working Out");
                  }
                  else if(intChoice=="6" || intChoice=="Biking"){
                    gInterests.push_back("Biking");
                  }
                  else if(intChoice=="7" || intChoice=="Running"){
                    gInterests.push_back("Running");
                  }
                  else if(intChoice=="8" || intChoice=="Gaming"){
                    gInterests.push_back("Gaming");
                  }
                  else if(intChoice=="9" || intChoice=="Climbing"){
                    gInterests.push_back("Climbing");
                  }
                  else if(intChoice=="0" || intChoice=="done" || intChoice=="Done"){
                    break;
                  }
                  else{
                    cout<<"Invalid Input"<<endl;
                  }
                }
                string tInfo="Days: "+meetDays+" Times: "+meetTime;
                groups.addGroup(gName, gDescript, gInterests, tInfo, meetLoc);
                break;
              }
              //case 2 shows the groups that a user is in and then recommends them
              //new groups to join
              case 2:
              {
                if(currentUser=="defualt"){
                  cout<<"Must Login to Join Groups"<<endl;
                  break;
                }
                cout<<"You are currently a member of these groups"<<endl;
                groups.printGroups(currentUser);
                groups.findGroups(currentUser);
                break;
              }
              //case 3 shows groups user is a member of
              case 3:
              {
                if(currentUser=="defualt"){
                  cout<<"Must Login to Join Groups"<<endl;
                  break;
                }
                cout<<"You are currently a member of these groups"<<endl;
                groups.printGroups(currentUser);
                break;
              }
              //case 4 exits groups menu
              case 4:
              {
                exitGroups=true;
                break;
              }
              //defualt case
              defualt:
              {
                break;
              }
          }
        }
        break;
        }

        //this case exits the program
        case 6:
        {
        cout<<"Quitting... "<<endl;
        cout<<"Goodbye!"<<endl;
        exit=true;
        break;
        }
        //defualt main case
        default:
        {
        cout<<"Invalid Input, Please Enter a  number between 1 and 5"<<endl;
        break;
        }
      }
    }

  }

