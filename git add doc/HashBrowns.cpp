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
  int counter=0;
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
    //names.push_back(vector<string>());
    cout<<i<<"-"<<endl;
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
  for (int i = 0; i < names.size(); i++) {
       for (int j = 0; j < names[i].size(); j++)
           cout << names[i][j] << endl;
   }
   for(int j=0; j<doubles.size(); j++){
     cout<<doubles[j]<<endl;
   }
}
//Frisbee,Studying,SpikeBall,Swimming,WorkingOut,Biking,Running,Gaming,Climbing
int main(int argc, char const *argv[]){
  //argv[1]=messages.txt
  //argv[2]=interests.txt
  //argv[3]=number of interests(9)
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
