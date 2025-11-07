//Fill out this comment with your names and which bullet points you did
//Partners:
//Bullet Points: 
//Extra Credit: 
//URL to cover art and music: 


#include </public/colors.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string BLUE;
    string RED;
    string YELLOW;
    string GREEN;
    string PURPLE;
    string CYAN;

    cout << BLUE << "Blue" << RESET << endl;
    cout << RED << "Red" << RESET << endl;
    cout << YELLOW << "Yellow" << RESET << endl;
    cout << GREEN << "Green" <<  RESET << endl;
    cout << PURPLE << "Purple" << RESET << endl;
    cout << CYAN << "Cyan" << RESET << endl;

 BigScreen();
    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            cout << GREEN << "Let's Do This!" << RESET << "\n\n";
            break;
        }

        else if (choice == 2) {
            showControls();
        }

    else if (choice == 3) {
        cout << RED << "Exiting Program.\n" << RESET;
        return 0;
    }
        else (
                cout << RED << "Invalid Choice,m try agaian.\n" << RESET;
                }
            }
            cout << CYAN << "Your doomed....\n" << RESET;
            cout << GREEN << "Something Is watching you.\n" << RESET;
            COUT << YELLOW << "Your journey begins here.\n" << RESET;
            return 0;
        }


