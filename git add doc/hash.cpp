#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include "hash.hpp"

// node* HashTable::createNode(string key)
// {
//     node* nw = new node;
//     nw->key = key;
//     nw->next = nullptr;
//     return nw;
// }

HashTable::HashTable(int bsize)
{
    this->tableSize= bsize;
    hashTable = new node*[tableSize];
    for(int i=0;i<bsize;i++)
        hashTable[i] = nullptr;
}

unsigned int HashTable::hashFunction(int key)
{
  //cout<<key<<endl;
  return (key % tableSize);
    // unsigned int hashValue = 5381;
    // int length = key.length();
    // for (int i=0;i<length;i++)
    // {
    //   hashValue=((hashValue<<5)+hashValue) + key[i];
    // }
    // hashValue %= tableSize;
    // return hashValue;

}

node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int a=0;
    int index = hashFunction(key);
    node* temp=hashTable[index];
    return temp;
    // while(temp!=nullptr){
    //   if(temp->key==key){
    //     return temp;
    //   }
    //   else{
    //     if(temp->next==nullptr){
    //       return nullptr;
    //     }
    //     temp=temp->next;
    //   }
    // }
    // return nullptr;

    //TODO: Search the list at that specific index and return the node if found
}
node* HashTable::searchItem2(int key)
{
    //Compute the index by using the hash function
    int a=0;
    int index = hashFunction(key);
    node* temp=hashTable[index];
    return temp;
    // while(temp!=nullptr){
    //   if(temp->key==key){
    //     return temp;
    //   }
    //   else{
    //     if(temp->next==nullptr){
    //       return nullptr;
    //     }
    //     temp=temp->next;
    //   }
    // }
    // return nullptr;

    //TODO: Search the list at that specific index and return the node if found
}

bool HashTable::insertItem(string key)
{

        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        //cout<<key[0]<<endl;
        int a=key[0]-'0';
        int z=key.length();
        string newstring=key.substr(2,z);
        int index = hashFunction(a);
        node* newnode= new node;
        node* temp= hashTable[index];
        node* prev=nullptr;
        newnode->key=newstring;
        newnode->next=nullptr;
        if(temp==nullptr){
          hashTable[index]=newnode;
          return true;
        }
        while(temp!=nullptr){
          prev=temp;
          temp=temp->next;
        }
        prev->next=newnode;
        return true;



}
bool HashTable::insertItem2(string key, string name)
{

        // TODO :
        // Use the hash function on the key to get the index/slot,
        // create a new node with the key and insert it in this slot's list
        //cout<<key[0]<<endl;
        int a=key[0]-'0';
        int index = hashFunction(a);
        node* newnode= new node;
        node* temp= hashTable[index];
        node* prev=nullptr;
        newnode->key=name;
        newnode->next=nullptr;
        if(temp==nullptr){
          hashTable[index]=newnode;
          return true;
        }
        while(temp!=nullptr){
          prev=temp;
          temp=temp->next;
        }
        prev->next=newnode;
        return true;



}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        node* temp=hashTable[i];
        while(temp!=nullptr){
          cout<<temp->key<<" ";
          temp=temp->next;

        }
          cout<<endl;

        //TODO
    }

 }

// bool HashTable::findThreeSum(int arr[], HashTable &ht){

// }
