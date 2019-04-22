#include "groupGraph.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <list>

using namespace std;

Graph::Graph(){
  ;
}
Graph::~Graph(){
  ;
}
//This method adds a user to the Graph structure
//Method takes is users name and a vector of the users interests
void Graph::addUser(std::string userName,vector<string>interests){
  //search the graph to see if the user already exists
  bool found=false;
  for(int i=0; i< vertices.size(); i++){
    if(vertices[i].name == userName){
      found=true;
    }
  }
  //If user does not exists, intialize a vertex of type User and add to the graph
  if (found==false){
    //initialze vertex
    vertex lilUziVert;
    //name vertex
    lilUziVert.name=userName;
    //give vertex type user
    lilUziVert.isUser=true;
    //add interests to users interests vector
    for(int j=0; j<interests.size(); j++){
      lilUziVert.Interests.push_back(interests.at(j));
    }
    //add user vertex to the vertices vector of the graph
    vertices.push_back(lilUziVert);
  }
}

//method to add and Interest to an existing user
//method takes in the users name and an interests to add
void Graph::addUserInterest(std::string userName, std::string interest){
  //find the users vertext in the vertices vecotr with method findVertex
  vertex* userVert=findVertex(userName);
  //break if user is not in graph
  if(userVert==NULL){
    return;
  }
  //add input interest to users Interests vector
  userVert->Interests.push_back(interest);
}

//method to add a new group vertex to the graph
//method takes in name of group, desciption of group, a vector of the groups interests, and info on the date,time,and location of group meetings
void Graph::addGroup(std::string groupName,std::string descript, vector<string> interestType, std::string timeInfo, std::string meetInfo){
  bool found=false;
  //search graph to see if group already exists
  for(int i=0; i< vertices.size(); i++){
    if(vertices[i].name == groupName){
      found=true;
    }
  }
  //if group doesn't already exists, intitialze vertex of type group
  if (found==false){
    vertex lilUziVert;
    //name vertex
    lilUziVert.name=groupName;
    //give vertex type group
    lilUziVert.isGroup=true;
    //give vertex Description
    lilUziVert.Description=descript;
    //add Interests to groups interest vector
    for(int j=0;j<interestType.size();j++){
      lilUziVert.Interests.push_back(interestType.at(j));
    }
    //set vertex meeting information
    lilUziVert.MeetTime=timeInfo;
    lilUziVert.MeetLocation=meetInfo;
    //add vertex to the graph
    vertices.push_back(lilUziVert);
  }
}

//method to add an existing user to an existing group
//method takes in users name and groups name
void Graph::addUserToGroup(std::string user, std::string group){
  //loops to iterate through all vertices
  for(int i=0; i<vertices.size(); i++){
    if(vertices[i].name==user){
      for(int j=0; j< vertices.size(); j++){
        //once group is found create new Edge and add to groups edge vector
        if(vertices[j].name==group && i!=j){
          Edge addV;
          addV.v= &vertices[j];
          vertices[i].Edges.push_back(addV);
          //add user to groups Members vector
          vertices[j].Members.push_back(vertices[i].name);
        }
      }
    }
  }
}

//method to remove an interest from a user
//takes in users name and interest to delete
void Graph::removeUserInterest(std::string user, std::string interest){
  //find users vertex using findVertex method
  vertex* userVert=findVertex(user);
  if(userVert==NULL){
    return;
  }
  //search the users Interests vector for the interest to delete
  for(int i=0; i<userVert->Interests.size(); i++){
    //if found, remove that interest from users Interest Vector
    if(userVert->Interests.at(i)==interest){
      userVert->Interests.erase(userVert->Interests.begin()+i);
    }
  }
}

//method to print the groups that a user belongs to
//method takes in users name
void Graph::printGroups(std::string user){
  //find users vertex using findVertex method
  vertex* userVert=findVertex(user);
  if(userVert==NULL){
    return;
  }
  //Print names of all groups connected to user
  cout<<"User: "<<user<<" belongs to groups:"<<endl;
  for(int i=0; i<userVert->Edges.size(); i++){
    cout<<userVert->Edges[i].v->name<<endl;
  }
}

//method to print The Information of a group
//method takes in groups name
void Graph::printGroupInfo(std::string groupName){
  //find groups vertex using findVertex method
  vertex* groupVert=findVertex(groupName);
  if(groupVert==NULL){
    cout<<"Group: "<<groupName<<" not found"<<endl;
    return;
  }
  //print groups information
  cout<<groupName<<":"<<endl;
  cout<<"Description: "<<endl;
  cout<<groupVert->Description<<endl;
  cout<<"Meeting Time"<<endl;
  cout<<groupVert->MeetTime<<endl;
  cout<<"Meeting Location"<<endl;
  cout<<groupVert->MeetLocation<<endl;
  cout<<"Related Interests:"<<endl;
  //iterate through groups intersts vector and print
  for(int i=0; i<groupVert->Interests.size(); i++){
    cout<<groupVert->Interests.at(i);
  }
  //iterate through groups members vector and print
  cout<<"Members:"<<endl;
  for(int j=0; j<groupVert->Members.size();j++){
    cout<<groupVert->Members.at(j);
  }
}

//method to recommend groups to a user based on similar interests
//method takes in users name
void Graph::findGroups(std::string user){
  //find users vertex using findVertex method
  vertex* userVert=findVertex(user);
  if(userVert==NULL){
    return;
  }
  //initialze temporary vector of users interests and populate using users vertex
  vector<string> checkInterests;
  for(int i=0; i<userVert->Interests.size(); i++){
    checkInterests.push_back(userVert->Interests.at(i));
  }
  //initialze vector of groupNames to output to the user
  vector<string> outGroups;
  //iterate through all vertices
  for(int j=0; j<vertices.size(); j++){
    //iterate through users interests
    for(int k=0; k<checkInterests.size(); k++){
      //iterate through each vertices interests
      for(int l=0; l<vertices[j].Interests.size(); l++){
        //if a group is found that matches a users interests, add that name to the outGroups vector
        if(vertices[j].Interests.at(l)==checkInterests.at(k) && vertices[j].isGroup==true){
          outGroups.push_back(vertices[j].name);
        }
      }
    }
  }
  //allow users to view descriptions of recommended groups
  bool doneDescript=false;
  while(!doneDescript){
    //output recommended groups
    cout<<"Here are some Groups you may like:"<<endl;
    for(int z=0; z<outGroups.size(); z++){
      cout<<outGroups.at(z)<<endl;
    }
    string userRep;
    cout<<"Enter Group Name for more info or enter \"done\" to move on"<<endl;
    getline(cin,userRep);
    //take in users response
    //print groups info with printGroupInfo method
    if(userRep!="done"){
      printGroupInfo(userRep);
    }
    if(userRep=="done"){
      doneDescript=true;
      break;
    }
  //allow users to add themselves to groups
  bool doneAdding=false;
  //output recommended groups
  while(!doneAdding){
    cout<<"Groups:"<<endl;
    for(int z=0; z<outGroups.size(); z++){
      cout<<outGroups.at(z)<<endl;
    }
    string userRep;
    cout<<"Enter Group Name to join or enter \"done\" to exit"<<endl;
    getline(cin,userRep);
    //take in user input and add user to group
    if(userRep!="done"){
      addUserToGroup(user,userRep);
    }
    if(userRep=="done"){
      doneDescript=true;
      break;
    }
  }
  }
}

//method to set vertices as unvistited
void Graph::setAllVerticesUnvisited(){
  //iterate through vertices vector and mark vertices as unvisited
  for(int i=0; i< vertices.size(); i++){
    vertices[i].visited=false;
  }
}

//method to find a vertex in the graph
//method takes in name of the vertex
vertex* Graph::findVertex(std::string name){
  //iterate through vertices vector
  for(int i=0; i< vertices.size(); i++){
    //if vertex has matching name, return vertex
    if(vertices[i].name == name){
      return &vertices[i];
    }
  }
  //if vertex not found return null
  return NULL;
}
