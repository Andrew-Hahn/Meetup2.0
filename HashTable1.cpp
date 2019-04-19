#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
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
//Frisbee,Studying,SpikeBall,Swimming,WorkingOut,Biking,Running,Gaming,Climbing
int main(int argc, char const *argv[]){
  HashTable will(9);
  string fileName=argv[1];
  createHash1(fileName, will);
  will.printTable();
}
