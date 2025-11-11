#include "dialogue.h"
#include <iostream>
#include "/public/colors.h"

//WOW!

// Storage for all dialogues
std::map<std::string, Dialogue> dialogues;
std::map<std::string, Dialogue> locations;

// Initialize all dialogues - CALL THIS ONCE AT GAME START
void initializeDialogues() {

    //=================================
    // EXAMPLE DIALOGUES
    //=================================

    //EX. 1:
    dialogues["TEST"] = {
        {
            {"speech", "Test", ""}
        }
    };

    dialogues["RANDOM_BRO"] = {
        {
            {"speech", "Bro", "WAZZZZUP, MY GUUUUY?"},
            {"action", "", "*The bro takes a hit from the jay, then offeres it to you*"},
            {"speech", "Bro", "You want some of this?"},
            {"action", "", "*He nods to the roll in his fingers*"},
            {"speech", "Bro", "Home grown. Fresh off the rack. My special recipie"}
        }
    };
    
    //=================================
    // LOCATION DESCRIPTIONS
    //=================================

    locations["MIDDLE_OF_FOREST"] = {
        {
            {"speech", "", "Way off the beaten path now."},
            {"action", "", "*The sounds of the forest should be alive, but it is silent right now*"},
            {"speech", "", "You are not alone."}
        }
    };

    //===================================
    // ADD MORE DIALOGUES BELOW THIS LINE
    //===================================
    //Follow this pattern:
    //dialogues["YOUR_DIALOGUE_ID"] = {
    //     {
    //          {"speech", "Character Name", "What they say"},
    //          {"action", "", "*What happens*"},
    //          {"speech", "Character Name", "More dialogue"},
    //          {"danger", "", "*Dangerous action*"},
    //     }
    //}

    // TYPE OPTIONS:
    // "speech" - Normal character dialogue (CYAN)
    // "action" - Normal narration/actions (YELLOW)
    // "danger" - Combat/danger narration (RED)
}

// Display a dialogue by ID
void showDialogue(string dialogueID) {
    cout << "\n";
    cout << "hello" << endl;

    //Check if dialogue exists
    if (dialogues.find(dialogueID) == dialogues.end()) {
        cout << RED << "Error Dialogue '" << dialogueID << "' not found!" << RESET << endl;
        cout << endl;
        return;
    }

    // Get the dialogue
    Dialogue d = dialogues[dialogueID];

    // Display each line with appropriate formatting
    for (size_t i = 0; i < d.lines.size(); ++i) {
        Line line = d.lines[i];

        if (line.type == "speech") {
            if (line.speaker != "") {
                cout << CYAN << line.speaker << ": " << RESET << line.text << endl;
            } else {
                cout << line.text << endl;
            }
        }
        else if (line.type == "action") {
            cout << YELLOW << line.text << RESET << endl;
        }
        else if (line.type == "danger") {
            cout << RED << line.text << RESET << endl;
        }
    }

    cout << endl;
}

// Display a location description
void showLocDescrip(string location) {
    cout << "\n";
    cout << GREEN << "=== " << location << " ===" << RESET << endl;
    
    // Check if location exists
    if (locations.find(location) == locations.end()) {
        cout << "You are in " << location << "." << endl;
        cout << endl;
        return;
    }

    //Get the location description
    Dialogue d = locations[location];

    //Display each line
    for (size_t i = 0; i < d.lines.size(); ++i) {
        Line line = d.lines[i];

        if (line.type == "speech") {
            cout << line.text << endl;
        }
        else if (line.text == "action") {
            cout << YELLOW << line.text << RESET << endl;
        }
        else if (line.type == "danger") {
            cout << RED << line.text << RESET << endl;
        }
    }

    cout << endl;
}