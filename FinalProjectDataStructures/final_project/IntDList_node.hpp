#ifndef INTDLISTNODE_H
#define INTDLISTNODE_H
#include <string>
using namespace std;

class IntDLLNode 
{
public:
    int info;
    string name;
    string position;
    string nationality;
    int rating;
    int cost;
    class IntDLLNode *next;
    class IntDLLNode *prev;
    

    IntDLLNode( int id , 
                string name ,
                string position ,
                string nationality ,
                int rating ,
                int cost ,
                IntDLLNode *ptr1=0 , 
                IntDLLNode *ptr2=0
                ) 
    {
        info = id; 
        this->name = name;
        this->position = position;
        this->cost = cost;
        this->nationality = nationality;
        this->rating = rating;
        next = ptr1; 
        prev = ptr2;
    }
};
#endif /* INTDLISTNODE_H */