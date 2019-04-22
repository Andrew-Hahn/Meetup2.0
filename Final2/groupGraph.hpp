#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

struct vertex;

/*This is the struct for the adjacent vertices for each
vertex in the graph. */

struct Edge
{
    vertex *v;
};

/*this is the struct for each vertex in the graph. */
struct vertex
{
    //stores name
    std::string name;
    //stores visited value
    bool visited;
    //intitialize type as neither user or group
    bool isGroup=false;
    bool isUser=false;
    //stores groups description if vertex is of type group
    std::string Description;
    //stores groups meeting time/date if vertex is of type group
    std::string MeetTime;
    //stores groups members if vertex is of type group
    std::vector<std::string> Members;
    //stores groups or users interests regardless of type
    std::vector<std::string> Interests;
    //stores groups meeting location if vertex is of type group
    std::string MeetLocation;
    //stores edges to adjacent vertices
    std::vector<Edge> Edges;
};
//define class Graph
class Graph
{
  public:
    //initialze public methods of class graph
    Graph();
    ~Graph();
    void addUser(std::string userName,std::vector<std::string> interests);
    void addGroup(std::string groupName, std::string description,std::vector<std::string> interests,std::string timeInfo, std::string locInfo);
    void addUserToGroup(std::string user, std::string group);
    void setAllVerticesUnvisited();
    void findGroups(std::string user);
    void printGroups(std::string user);
    void printGroupInfo(std::string groupName);
    void addUserInterest(std::string userName, std::string interest);
    void removeUserInterest(std::string user, std::string interest);

  private:
    //inititialize private methods and variables of class Graph
    std::vector<vertex> vertices; //stores vertices
    vertex *findVertex(std::string name);

};

#endif // GRAPH_HPP
