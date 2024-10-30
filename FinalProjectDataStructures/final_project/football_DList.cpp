
#include "football_DList.hpp"
#include "IntDList_node.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>  // For reverse function
#include <cctype>
#include <vector>
#include <string.h>  // Include string.h for strcpy



FootballDList::FootballDList() : ListHead(nullptr) {}       // Constructor
FootballDList::~FootballDList() {                           // Destructor
    IntDLLNode* current = ListHead;
    while (current != nullptr) {
        IntDLLNode* temp = current;
        current = current->next;
        delete temp;
    }
}


void FootballDList::insertInOrder(int val, string name, string position, string nation, int rating, int cost) {
    IntDLLNode* newNode = new IntDLLNode(val, name, position, nation, rating, cost);              // 1. Allocate memory for new node

    if (ListHead == nullptr || val < ListHead->info) {      // 2. Checks to see if the list is empty or if newNode should be first node.
        newNode->next = ListHead;                           // 3. Puts newNode at the head of list.
        if (ListHead != nullptr) {                          // 4. If the head of list is not null but inserted value is less than head value
            ListHead->prev = newNode;                       //    - Point the head previous node to newNode
        }
        ListHead = newNode;                                 // 5. newNode becomes head of list.
    }
    else {                                                                  // ELSE
        IntDLLNode* current = ListHead;                                     // Initialize current variable to head of list
        while (current->next != nullptr && current->next->info < val) {     // While current doesn't point to null and currents next value is less than the value.    
            current = current->next;                                        // Traverse 
        }

        newNode->next = current->next;                                      // Inserting newNode
        if (current->next != nullptr) {                                     // If the node after current is not null
            current->next->prev = newNode;                                  // - Node after current previous pointer points to newNode
        }   
        newNode->prev = current;                                            // NewNode previous pointer points to current
        current->next = newNode;                                            // Current node points to the newNode
    }
}


int FootballDList::deleteFromHead() {
    if (ListHead == nullptr) {                              // 1. List is empty
        return 0;                       
    }
    else if (ListHead->next == nullptr) {                   // 2. If list only has one node
        int temp = ListHead->info;                          //    a. Temp value to store the first nodes value
        ListHead = nullptr;                                 //    b. Set first node to null
        return temp;                                        //    c. Return value 
    }
    else {                                                  // 3. List has multiple nodes
        IntDLLNode* temp = ListHead;                        //    a. Temp value to store first nodes value
        ListHead = ListHead->next;                          //    b. Set the first node to the second node
        ListHead->prev = nullptr;                           //    c. Set the new first nodes previous node to null
        int tempValue = temp->info;                         //    d. Temp int value to store the value to return
        delete temp;                                        //    d. Delete the first node
        return tempValue;                                   //    e. Return the value of the deleted node.
    }
} // delete the head and return its info;


int FootballDList::deleteFromTail() {
    if (ListHead == nullptr) {                              // 1. List is empty
        return 0;
    }
    else if(ListHead->next == nullptr) {                    // 2. If list only has one node
        int temp = ListHead->info;                          //    a. Temp value to store the first nodes value
        ListHead = nullptr;                                 //    b. Set first node to null
        return temp;                                        //    c. Return value 
    }
    else {                                                  // 3. List has multiple nodes
        IntDLLNode* current = ListHead;                     //    a. Temp value to store first nodes value
        while (current->next->next != nullptr) {            //    b. Set the first node to the second node
            current = current->next;                        //    c. Traverse
        }
        int tempValue = current->next->info;                //    d. Temp value to store the value in the tail node
        IntDLLNode* toBeDeleted = current->next;
        current->next = nullptr;                            //    e. Setting the new last nodes previous value to null
        delete toBeDeleted;                               //    f. Deteling the last node.
        return tempValue;                                   //    g. return
    }
} // delete the tail and return its info;


void FootballDList::deleteNode(int val) {
    if (ListHead == nullptr) {                              // 1. List is empty
        return;
    }

    IntDLLNode* current = ListHead;                         // 2. Current node made to traverse through list

    while (current != nullptr) {                            // WHILE
        if (current->info == val) {                         //  Current node has the value we want to delete.
            if (current->next == nullptr){                  //    Node to delete is at END of list
                deleteFromTail();
            }
            else if (current->prev == nullptr){             //    Node to delete is at the START of the list
                deleteFromHead();
            }
            else {                                          //    Node to delete is not at the edge
                current->prev->next = current->next;        //      Pointing the previous node to the node after the deleted node
                current->next->prev = current->prev;        //      Pointing the next node to the node before the deleted node.
                delete current;
            }
            return;
        }
        current = current->next;                            // Traverse
    }
}

double FootballDList::calculateAverageRating() {            // Calculating the average of the team
    IntDLLNode* current = ListHead;                         // Head pointer
    int sum = 0;                
    int count = 0;

    while (current != nullptr) {                            // Summing up all ratings
        sum += current->rating;
        count++;
        current = current->next;
    }

    if (count == 0) return 0; // To avoid division by zero if the list is empty.
    return static_cast<double>(sum) / count;                // Calculating average
}

bool FootballDList::isInList(int val) const {               // Method to see if a value is in the list
    if (ListHead == nullptr) {                          // List is empty, has no values
        return false;
    }

    IntDLLNode* current = ListHead;                     // Initialze current variable to traverse

    while (current != nullptr) {                
        if (current->info == val) {                     // Looping until a value matches a value in the list
            return true;
        }
        current = current->next;                        
    }
    return false;                                       // Value not found
}



// Helper function to find the last node of the list
IntDLLNode* lastNode(IntDLLNode* root) {
    while (root && root->next) {
        root = root->next;
    }
    return root;
}

// Insertion Sort That Sorts Available Players By Cost
void FootballDList::sortPlayersByCost() {
    if (ListHead == nullptr || ListHead->next == nullptr) {
        return; // The list is already sorted if it contains 0 or 1 element.
    }

    IntDLLNode* sorted = nullptr; // This will be the new head of the sorted list.

    // Extract each node from the original list and insert into the sorted list.
    IntDLLNode* current = ListHead;
    while (current != nullptr) {
        IntDLLNode* next = current->next; // Remember the next item because we're re-linking current.

        // Find the right place to insert 'current' in 'sorted' list (sorted in descending order by cost).
        if (sorted == nullptr || sorted->cost < current->cost) {
            // Insert at the beginning (new head).
            current->next = sorted;
            current->prev = nullptr;
            if (sorted != nullptr) {
                sorted->prev = current;
            }
            sorted = current;
        } else {
            // Insert somewhere after the head of 'sorted' list.
            IntDLLNode* temp = sorted;
            while (temp->next != nullptr && temp->next->cost > current->cost) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            current->prev = temp;
            temp->next = current;
        }

        current = next; // Move to the next item in the original list.
    }

    ListHead = sorted; // Update the head to the new sorted list.
}

// Insertion Sort That Sorts Available Players By Rating
void FootballDList::sortPlayersByRating() {
    if (ListHead == nullptr || ListHead->next == nullptr) {
        return; // The list is already sorted if it contains 0 or 1 element.
    }

    IntDLLNode* sorted = nullptr; // This will be the new head of the sorted list.

    // Extract each node from the original list and insert into the sorted list.
    IntDLLNode* current = ListHead;
    while (current != nullptr) {
        IntDLLNode* next = current->next; // Remember the next item because we're re-linking current.

        // Find the right place to insert 'current' in 'sorted' list (sorted in descending order by rating).
        if (sorted == nullptr || sorted->rating < current->rating) {
            // Insert at the beginning (new head).
            current->next = sorted;
            current->prev = nullptr;
            if (sorted != nullptr) {
                sorted->prev = current;
            }
            sorted = current;
        } else {
            // Insert somewhere after the head of 'sorted' list.
            IntDLLNode* temp = sorted;
            while (temp->next != nullptr && temp->next->rating > current->rating) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            current->prev = temp;
            temp->next = current;
        }
        current = next; // Move to the next item in the original list.
    }

    ListHead = sorted; // Update the head to the new sorted list.
}

// Sorting function for position
void FootballDList::prioritizePosition(const string& position) {
    if (ListHead == nullptr || ListHead->next == nullptr) {
        return; // No need to sort if the list is empty or has only one element.
    }

    IntDLLNode* current = ListHead;
    IntDLLNode* end = nullptr; // This will mark the end of the region to sort.

    // First, find the last node of the list to mark the boundary
    while (current->next != nullptr) {
        current = current->next;
    }
    end = current;

    current = ListHead;

    // Traverse from head to the marked end and reorder
    while (current != nullptr && current != end->next) {
        IntDLLNode* next = current->next;
        if (current->position == position) {
            if (current != ListHead) {
                // Detach current from its place
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }

                // Move current to the front
                current->next = ListHead;
                current->prev = nullptr;
                ListHead->prev = current;
                ListHead = current;
            }
        }
        current = next;
    }
}


void FootballDList::addPlayerToTeam(int selection, FootballDList& draftOptionsList, int& budget, int& teamIndex,  string* myPlayers, string& positionNeeded) {
    IntDLLNode* current = draftOptionsList.ListHead;
    string confirm;

    // Traverse to the nth node in the list where n is the selection
    int count = 1;  // Start counting from 1 since selection is 1-based
    while (current != nullptr && count < selection) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Invalid selection. No such player exists." << endl;
    } else if (budget < current->cost) {
        cout << "\nYOU DON'T HAVE THE FUNDS TO PURCHASE " << current->name << endl;
    } else {
        cout << "- - - - - - CONFIRM TRADE - - - - - -" << endl;
        cout << " Player:             " << current->name << endl;
        cout << " Price:              " << current->cost << endl;
        cout << " Position:           " << current->position << "\n" << endl;
        do {
            cout << " Confirm Purchase (y/n): ";
            cin >> confirm;

            // Convert the input to lowercase to handle both 'Y' and 'y'
            std::transform(confirm.begin(), confirm.end(), confirm.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            if (confirm == "y") {
                // Add the found player to the team
                this->insertInOrder(current->info, current->name, current->position, current->nationality, current->rating, current->cost);
                budget -= current->cost;
                teamIndex++;
                cout << "PLAYER PURCHASED: " << current->name << " (New Budget: $" << budget << ")" << endl;
                string tempName= current->name;
                cout<< "TEST:: "<< tempName <<endl;
                // Update based on position
                if (positionNeeded == "GK") {
                    myPlayers[0].assign(tempName);
                } else if (positionNeeded == "DEF") {
                    myPlayers[1].assign(tempName); 
                } else if (positionNeeded == "FW") {
                    if (myPlayers[2] == "-") {
                        myPlayers[2].assign(tempName); 
                    } else {
                        myPlayers[3].assign(tempName); 
                    }
                } else if (positionNeeded == "MID") {
                    myPlayers[4].assign(tempName); 
                }
                draftOptionsList.deleteNode(current->info);
                break;
            } else if (confirm == "n") {
                cout << "Transaction cancelled." << endl;
                break;
            } else {
                cout << "Invalid entry, please enter 'y' for yes or 'n' for no." << endl;
            }
        } while (true);  // Keep asking until a valid response is given
    }
}

// Function to formation price amounts with commas
std::string formatWithCommas(int value) {
    std::string numStr = std::to_string(value);
    int insertPosition = numStr.length() - 3;

    while (insertPosition > 0) {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    return numStr;
}

void FootballDList::displayPlayers() const {
    IntDLLNode* current = ListHead;
    int displayId = 1;

    // Display the headers
    std::cout << std::left 
              << std::setw(4) << "ID" << "|   "
              << std::setw(18) << "Player" << "| "
              << std::setw(9) << "Position" << "| "  // Increased width for position
              << std::setw(7) << "Rating" << "| "
              << std::setw(11) << "Price" << "|"
              << std::endl;
    std::cout << std::string(60, '-') << std::endl; // Adjusted width for separator line

    // Loop through the nodes and print details in formatted columns
    while (current != nullptr) {
        std::cout << std::left 
                  << std::setw(4) << displayId << "|   "
                  << std::setw(18) << current->name << "|    "
                  << std::setw(6) << current->position << "|   "  // Corrected width
                  << std::setw(5) << current->rating << "| "
                  << std::setw(11) << formatWithCommas(current->cost) << "|"
                  << std::endl;

        current = current->next;
        displayId++;
    }
}