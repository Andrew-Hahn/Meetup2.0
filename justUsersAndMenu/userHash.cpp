#include <iostream>
#include "userHash.hpp"
#include <fstream>
#include <sstream>
using namespace std;

HashTable::HashTable(int hashTableSize){
  this->hashTableSize=hashTableSize;
  hashTable=new User* [hashTableSize];
  for(int i=0; i<hashTableSize; i++){
    hashTable[i]=nullptr;
  }
}

HashTable::~HashTable() {
  for (int i=0; i<hashTableSize; i++){
    User* temp=hashTable[i];
    User* prev=hashTable[i];
    while(temp!=nullptr){
      prev=temp;
      temp=temp->next;
      delete prev;
    }
  }
  delete [] hashTable;
}
void HashTable::addInterests(string user, string interest){
  User* temp=searchTable(user);
  temp->Interests.push_back(interest);
}

void HashTable::removeInterests(string user, string interest){
  User* temp=searchTable(user);
  for(int i=0; i<temp->Interests.size();i++){
    if(temp->Interests.at(i)==interest){
      //TODO
      /*implement deletion from vector*/
      cout<<interest<<" removed"<<endl;
    }
  }
}

void HashTable::changeName(string user, string name){
  User* temp=searchTable(user);
  if(temp!=NULL){
    temp->Name=name;
  }
}

void HashTable::printInterests(string user){
  User* temp=searchTable(user);
  if(temp!=NULL){
    for(int i=0; i<temp->Interests.size(); i++)
    cout<<temp->Interests.at(i)<<",";
  }
}


void HashTable::addName(string Name, float x, float y, float rad){
    User* prev=NULL;
    User* newUser = new User;
    int value= getHash(Name);
    User* temp=hashTable[value];
    if(searchTable(Name)==nullptr){
      newUser->Name=Name;
      newUser->xPosition=x;
      newUser->yPosition=y;
      newUser->radius=rad;
      newUser->Messages.push_back("Welcome to Meetup 2.0!");
      newUser->next=nullptr;
      if(hashTable[value]==nullptr){
        hashTable[value]=newUser;
      }
      else{
        while(temp!=nullptr){
          prev=temp;
          temp=temp->next;
        }
        prev->next=newUser;
        newUser->next=nullptr;
      }
    }
    else{
      cout<<"User already exists!"<<endl;
    }
}

unsigned int HashTable::getHash(string word){
  unsigned int hashValue = 5381;
  int length = word.length();
  for (int i=0;i<length;i++)
  {
    hashValue=((hashValue<<5)+hashValue) + word[i];
  }
  hashValue %= hashTableSize;
  return hashValue;
}

User* HashTable::searchTable(string user)
{
    int index = getHash(user);
    User* temp=hashTable[index];
    while(temp!=nullptr){
      if(temp->Name==user){
        return temp;
      }
      temp=temp->next;
    }
    return temp;
}

bool HashTable::isInTable(std::string word){
  User *temp=searchTable(word);
  if (temp==nullptr){
    return false;
  }
  return true;
}
