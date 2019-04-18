#ifndef FINAL_PROJECT_HASH_TABLE
#define FINAL_PROJECT_HASH_TABLE

#include <string>
#include <vector>

// struct to store word + count combinations
struct User
{
    std::vector<std::string> Interests;
    std::vector<std::string> Messages;
    float xPosition;
    float yPosition;
    std::string Name;
    float radius;
    User* next;
};

class HashTable {
  public:
    HashTable(int hashTableSize);
    ~HashTable();
    bool isInTable(std::string word);
    void addName(std::string Name, float x, float y, float r);
    void addInterests(std::string Name, std::string Interest);
    void removeInterests(std::string user, std::string interest);
    void changeName(std::string user, std::string name);
    void printInterests(std::string user);

  private:
    /* member functions */
    unsigned int getHash(std::string word);
    User* searchTable(std::string word);

    /* instance variables */
    User** hashTable;
    int hashTableSize;

};



#endif
