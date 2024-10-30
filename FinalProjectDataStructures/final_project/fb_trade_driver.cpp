#include "football_DList.hpp"
#include <iostream>
#include <string>
#include <iomanip> 
#include <limits>
#include <stdexcept>

using namespace  std;

// Helper function that outputs price values with commas
std::string formatWithComma(int value) {
    std::string numStr = std::to_string(value);
    int insertPosition = numStr.length() - 3;
    while (insertPosition > 0) {
        numStr.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    return numStr;
}

// MAIN FUNCTION
int main()
{    
    // Variable dependencies
    int ready = 0;              // 1 if user is ready
    int selection;              // user selection
    int budget = 100000000;     // starting budget
    FootballDList myTeam;           // DLL for users team
    string myPlayers[5] = {"-", "-", "-", "-", "-"};
    int teamIndex = 0;          
    int positionLimits[4] = {1, 1, 2, 1}; // Limits for GK, DEF, FW, MID respectively
    int positionCounts[4] = {0, 0, 0, 0}; // Current counts for GK, DEF, FW, MID

    // Double liked list object that stores players available for trade
    FootballDList DraftOptionsList;

    // Inserting Goalkeepers Into List
    DraftOptionsList.insertInOrder(1,"A. Becker", "GK", "BRZ", 89, 12500000);
    DraftOptionsList.insertInOrder(2,"T. Courtois", "GK", "BLG", 92, 18000000);
    DraftOptionsList.insertInOrder(3,"J. Oblak", "GK", "SLV", 90, 15500000);
    DraftOptionsList.insertInOrder(4,"S. Paul", "GK", "IND", 72, 4575000);
    DraftOptionsList.insertInOrder(5,"E. Santana", "GK", "BRZ", 94, 22500000);

    // Inserting Defenders Into List
    DraftOptionsList.insertInOrder(6,"V. van Dijk", "DEF", "NET", 96, 32500000);
    DraftOptionsList.insertInOrder(7,"J. Stones", "DEF", "ENG", 87, 16250000);
    DraftOptionsList.insertInOrder(8,"A. Rudiger", "DEF", "GER", 89, 17500000);
    DraftOptionsList.insertInOrder(9,"W. Saliba", "DEF", "FRA", 86, 16000500);
    DraftOptionsList.insertInOrder(10,"A. Davies", "DEF", "CAN", 92, 24500000);

    // Inserting Midfielders Into List
    DraftOptionsList.insertInOrder(11,"L. Modric", "MID", "CRO", 91, 7250000);
    DraftOptionsList.insertInOrder(12,"Neymar Jr", "MID", "BRZ", 92, 9500000);
    DraftOptionsList.insertInOrder(13,"C. Casemero", "MID", "BRZ", 90, 7250500);
    DraftOptionsList.insertInOrder(14,"S. Chhetri", "MID", "IND", 76, 3500000);
    DraftOptionsList.insertInOrder(15,"W. Rooney", "MID", "ENG", 97, 29500000);

    // Inserting Forwards Into List
    DraftOptionsList.insertInOrder(16,"L. Messi", "FW", "ARG", 96, 42500000);
    DraftOptionsList.insertInOrder(17,"C. Ronaldo", "FW", "POR", 95, 39250000);
    DraftOptionsList.insertInOrder(18,"D. Beckham", "FW", "ENG", 94, 27500000);
    DraftOptionsList.insertInOrder(19,"K. Mbappe", "FW", "FRA", 92, 14500000);
    DraftOptionsList.insertInOrder(20,"j. Altidore", "FW", "USA", 84, 7500000);

    // MENU
    cout<< "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<< "                  WELCOME TO THE DRAFT                 "<< endl;
    cout<< "                   MANCHESTER UNITED                   "<<endl;
    cout<< "- - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<< " "<<endl;
    cout<< "     5 MORE PLAYERS ARE NEEDED FOR THIS YEARS ROSTER"<<endl;
    cout<< " "<<endl;
    cout<< "- - - - - - - - - POSITIONS NEEDED - - - - - - - - -"<<endl;
    cout<< "                   1 GOALKEEPER                     "<<endl;
    cout<< "                   1 DEFENDERS                      "<<endl;
    cout<< "                   1 MIDFIELDERS                    "<<endl;
    cout<< "                   2 FORWARD                        "<<endl;
    cout<< " "<<endl;
    cout<< "         |X| marks the positions mentioned above    "<<endl;
    cout<< "   -----------------------------------------------"<<endl;
    cout<< "  |                       |                       |"<<endl;
    cout<< "  |            O          | O        |X|          |"<<endl;
    cout<< "  |------                 |                 ------|"<<endl;
    cout<< "  |     |                 | O               |     |"<<endl;
    cout<< "  | |X| |      O      |X| |          |X|    |     |"<<endl;
    cout<< "  |     |                 | O               |     |"<<endl;
    cout<< "  |------                 |                 ------|"<<endl;
    cout<< "  |           |X|         | O         O           |"<<endl;
    cout<< "  |                       |                       |"<<endl;
    cout<< "   -----------------------------------------------"<<endl;
    cout<< " "<<endl;
    cout<< "- - - - - - - - - - - - BUDGET - - - - - - - - - - - -"<<endl;
    cout<< "         YOU HAVE A BUDGET OF  $100,000,000  "<<endl;
    cout<< " "<<endl;
    cout<< "   AFTERWARDS YOU WILL BE GIVEN A RANKING BASED ON "<<endl;
    cout<< "                  YOUR SELECTIONS                  "<<endl;
    cout<< " "<<endl;
    cout<< "                     GOOD LUCK!                    "<<endl;
    cout<< "- - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;

    // Prompting user to start draft 
    while (ready != 1) {
        cout << " Ready? Press 1 to start draft:  ";
        cin >> ready;

        // Check if the input was not an integer or if it was not 1.
        if (!cin || ready != 1) {
            cout << "Invalid Entry, select 1 to start draft. " << endl;

            // Clear the error flag on cin
            cin.clear();

            // Ignore the incorrect input so the user can try again
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    string input;

    // while loop which iterates after a team member is added.
    while (teamIndex < 5) {
        cout<< " \n\n"<<endl;
        cout<< "                                SELECTIONS                                         "<<endl;
        cout<< "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
        cout<< "POSITION:   [1] GOALKEEPER   [2] DEFENDERS   [3] FORWARDS   [4] MIDFIELDERS       "<<endl;
        cout << "PLAYERS:     ";
        cout << setw(17) << left << myPlayers[0];  // Set a width of 20 characters for the name
        cout << setw(16) << left << myPlayers[1];
        cout << setw(15) << left << myPlayers[2];
        cout << setw(17) << left << myPlayers[4] << endl;
        cout << "                                              ";
        cout << setw(20) << left << myPlayers[3] << endl;
        cout << "\nBUDGET:   $ " << formatWithComma(budget) << endl;
        cout<< "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
        cout<< " Please Select The Position You Would Like To Fill [1,2,3,4] : ";
        cin >> selection;

        string positionNeeded;

        // Check if the input was not an integer or if it was an integer outside the allowed range
        if (!cin || selection < 1 || selection > 4) {
            cout << "Invalid Entry, please select a valid position number [1,2,3,4]. " << endl;

            // Clear the error flag on cin
            cin.clear();

            // Ignore the incorrect input so the user can try again
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;  // Skip the rest of the loop iteration and prompt again
        }

        int posIndex = selection - 1; // Convert selection to 0-based index for arrays

        // Checking if position has already been selected
        if (positionCounts[posIndex] >= positionLimits[posIndex]) {
            cout << "You have already selected the maximum number of players for this position." << endl;
            continue; // Skip to the next iteration of the loop
        }

        cout << " " << endl;    // Breaking space

        // Switch statements to handle user position selection
        switch (selection) {
            case 1:
                positionNeeded = "GK";
                positionCounts[posIndex]+=1;
                break;
            case 2:
                positionNeeded = "DEF";
                positionCounts[posIndex]+=1;
                break;
            case 3:
                positionNeeded = "FW";
                positionCounts[posIndex]+=1;
                break;
            case 4:
                positionNeeded = "MID";
                positionCounts[posIndex]+=1;
                break;
        }

        // Displaying list of players
        DraftOptionsList.displayPlayers();

        cout << "\n" << endl;

        // Variable to handle user selection
        bool validSelection = false;

        // While loop that prevents user error
        while (!validSelection) {
            cout << "\n- - - - - - - - - - PLEASE SELECT A PLAYER BY THEIR NUMBER  - - - - - - - - - - -  " << endl;
            cout << " SORT BY:         Price (P)        Rating (R)        Position (C)                  " << endl;
            cout << "                                                                                   " << endl;
            cout << "        enter a number for player selection or a letter above for sorting          " << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << "  ENTRY: ";
            cin >> input;

            // Check if the input is a single letter for sorting
            if (input.length() == 1 && isalpha(input[0])) {
                char option = tolower(input[0]);
                switch (option) {
                    case 'p':
                        DraftOptionsList.sortPlayersByCost();
                        cout << "" << endl;
                        DraftOptionsList.displayPlayers();
                        break;
                    case 'c':
                        DraftOptionsList.prioritizePosition(positionNeeded);\
                        cout << "" << endl;
                        DraftOptionsList.displayPlayers();
                        break;
                    case 'r':
                        DraftOptionsList.sortPlayersByRating();
                        cout << "" << endl;
                        DraftOptionsList.displayPlayers();
                        break;
                    default:
                        cout << "Invalid sort option, please enter P, C, or R." << endl;
                }
            } else { // Assume the input should be a number
                try {
                    int playerChoice = stoi(input);
                    if (playerChoice >= 1 && playerChoice <= (20 - teamIndex)) {
                        myTeam.addPlayerToTeam(playerChoice, DraftOptionsList, budget, teamIndex, myPlayers, positionNeeded);
                        validSelection = true;  // Exit loop after a valid player selection
                    } else {
                        cout << "Please select a number between 1 and " << (20 - teamIndex) << "." << endl;
                    }
                } catch (const invalid_argument&) {
                    cout << "Invalid input, please enter a valid number or a sorting letter (P, C, R)." << endl;
                } catch (const out_of_range&) {
                    cout << "Number out of range, please select a valid number." << endl;
                }
            }

            // Clear the error flag on cin in case of failures and prepare for next input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    // Storing the average of the drafted team
    double averageRating = myTeam.calculateAverageRating();

    // Completion menu
    cout << "\n\n" << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "                YOU HAVE COMPLETED THE TRADE                  " << endl;
    cout << "                     ! CONGRATULATIONS !                      " << endl;
    cout << "                                                              " << endl;
    cout << "- - - - - - - - - - - - - OVERVIEW - - - - - - - - - - - - - -" << endl;
    cout << "                                                              " << endl;
    myTeam.displayPlayers();
    cout << "                                                              " << endl;
    cout << "  AVERAGE RATING: " << averageRating << "           TOTAL SPENT: $" << formatWithComma(100000000 - budget) << endl;
    cout << "                                                              " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

}