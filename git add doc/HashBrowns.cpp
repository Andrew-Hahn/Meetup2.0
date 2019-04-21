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

void createFinalTable(HashTable &will, HashTable &will0, int const size){
  string name;
  string message;
  vector<string> doubles;
  int j=0;
  vector<vector<string>> names;
  //string names[100][10];
  node* temp;
  node* temp1;
  bool repeat=false;
  for(int i=0; i<size; i++){
    node* temp=will0.searchItem(i);
    //cout<<i<<endl;
    names.push_back(vector<string>());
    while(temp!=nullptr){
        if(temp->next==nullptr){
          break;
        }
        name=temp->key;
        for(int k=0; k< doubles.size(); k++){
          if(doubles[k]==name){
            repeat=true;
          }
        }
        doubles.push_back(name);
        if(repeat==false){
      //cout<<name<<endl;
        names[i].push_back(name);//might be fucked
      //cout<<"is this fucked"<<endl;
        temp1=will.searchItem(i);
        while(temp1!=nullptr){
          if(temp->next==nullptr){
            break;
          }
          message=temp1->key;
          j++;
          names[i].push_back(message);
          temp1=temp1->next;
          }
        }
        temp=temp->next;
        j=0;
        repeat=false;
    }
  }
  for (int i = 0; i < names.size(); i++) {
       for (int j = 0; j < names[i].size(); j++)
           cout << names[i][j] << endl;
   }

}
//Frisbee,Studying,SpikeBall,Swimming,WorkingOut,Biking,Running,Gaming,Climbing
int main(int argc, char const *argv[]){
  //argv[1]=messages.txt
  //argv[2]=interests.txt
  //argv[3]=number of interests(9)
  //g++ -std=c++11 HashBrowns.cpp hash.cpp 
  //./a.out messages.txt interests.txt 9
  int const size=stoi(argv[3]);
  HashTable will(size);
  string fileName=argv[1];
  createHash1(fileName, will);
  will.printTable();
  HashTable will0(size);
  string fileName2=argv[2];
  createHash2(fileName2, will0);
  will0.printTable();

  createFinalTable(will, will0, size);

}
