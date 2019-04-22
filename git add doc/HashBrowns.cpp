#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "hash.hpp"


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
    will.printTable();
    HashTable will0(size);
    string fileName2=argv[2];
    createHash2(fileName2, will0);
    will0.printTable();

    createFinalTable(doubles, names, will, will0, size);
    sortVector(names);
    standardTime(names);

  }
