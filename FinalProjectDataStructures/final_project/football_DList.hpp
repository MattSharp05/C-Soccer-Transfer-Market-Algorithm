
#ifndef INTDLIST_H
#define INTDLIST_H
#include "IntDList_node.hpp"
#include <string>
#include <cctype>
#include <vector>

using namespace std;
class FootballDList 
{
public:
    FootballDList(); 
    ~FootballDList();
    int isEmpty() const 
    {
        return ListHead==nullptr;
    }
    
    void insertInOrder (int, string, string, string, int, int);
    int  deleteFromHead(); // delete the head and return its info;
    int  deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;
    void displayPlayers() const;
    void sortPlayersByCost();
    void sortPlayersByRating();
    void prioritizePosition(const string& position);
    void addPlayerToTeam(int, FootballDList&, int&, int&, string* myPlayers, string&);
    double calculateAverageRating();

private:
    IntDLLNode* ListHead;
};

#endif /* INTDLIST_H */
