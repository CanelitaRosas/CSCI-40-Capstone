#include "dialogue.h"
#include <iostream>
#include "/public/colors.h"

using namespace std;
//WOW!

// Storage for all dialogues
map<string, Dialogue> dialogues;
map<string, Dialogue> locations;

// TEXT WRAPPING FUNCTION
//Adds text to fit within maxWidth characters
//Add indent string to continuation lines
void printWrapped(string text, int maxWidth, string indent) {
    size_t currentPos = 0;
    bool firstLine = true;

    while (currentPos < text.length()) {
        //Add indentation for continued lines
        if (!firstLine && !indent.empty()) {
            cout << indent;
        }

        // If remaining text fits on one line, print all
        if (text.length() - currentPos <= (size_t)maxWidth) {
            cout << text.substr(currentPos) << endl;
            break;
        }

        // Find the last space wthin maxWidth
        size_t breakPos = currentPos + maxWidth;
        size_t lastSpace = text.rfind(' ', breakPos);

        // If no space found within range, break at maxWidth
        if (lastSpace <= currentPos || lastSpace == string::npos) {
            lastSpace = breakPos;
        }

        // Print the line
        cout << text.substr(currentPos, lastSpace - currentPos) << endl;
        currentPos = lastSpace + 1; // Move past the space
        firstLine = false; 
    }
}

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
    //showDialogue("NARRATOR" "VILLAIN")
    dialogues["TEST_2"] = {
        {
            {"narration", "", "You walk into a billiard ball room this is strange!"},
            {"speech", "Unknown Voice", "what you will do is go to the screen between them and pick a number for each scale and that number will represent the amount of balls it will randomly select from, so if you choose 1 on the right scale and 1 on the left then they will be randomly selected now here's an importnat part so listen up. The screen will then flash and ask you how many balls for the second weigh in, if you try for a third time you will die here. oh and Just so luck does not play a factor in your solution the computer in the screen will then simulate your solution 100 times and if your percent accuracy of finding the imposter isnt 100 percent guess what? you die here. If I deem your solution smart enough you earn your freedom.... to the next room and test that is BAHAHAHA\n"},
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
    dialogues["PZL1_PT1"] = {
        {
            {"narration", "", "You walk into a dank billiard ball room. Mositure and woft of mildew threatened to choke your windpipe."}, 
            {"narration", "", "Going back wasn't an option. The only way is forward"},
            {"narration", "", "Slowly you stepped inside. As soon as your rear foot crossed the threshold, the heavy metal door slammed shut behnd you. Muffled clicks and clacks crawled along the inside of the door."},
            {"narration", "", "With a final thud, the locks slid home, and you were trapped."},
            {"narration", "", "At the other end of the room stood a large machine with two platforms on top of it. Connected between the two platforms is a large touchscreen display."},
            {"narration", "", "On the floor just before the platforms sits a large glass box. Inside the box are nine unmarked billiard balls, all seemingly identicle to each other."}
        }
    };

    dialogues["PZL1_PT1_BAD_GUY"] = {
        {
            {"speech", "Mysterious_Voice", "GOT YOU!!! You walked righ tinto my trap! BAHAHAHA!"}
        }
    };
    dialogues["PZL1_PT1_BAD_GUY1"] = {
        {
            {"speech", "Mysterious Voice", "You simpelton! How could you possibly fall for such an elementary trap. Just how dull are you?"},
            {"speech", "", "Well, if you want out of here. You're going to have to use that excuse for a mind you've got, and not be a boneheaded brute for a change"},
            {"speech", "", "Best to try and keep up!"},
            {"speech", "", "In front of you is a puzzle of my own making! You need to solve it in order to leave. Simple!"},
            {"speech", "Mysterious Voice", "But if you even try to cheat... The room is rigged to explode! Heh heh."},
            {"speech", "", "That glass box has a handful of billiard balls. They are all perfectly identicle. Except for one. It is an imposter, a fake, an odd one out. Just like so many of your pathetic species nowadays. I mean, that why you're here and all."},
            {"speech", "", "The imposter ball has a slgihtly different mass to all the others. They will all feel the same if you pick them up, but the scale, over there, is specially calibrated to detect this impostor."}
        }
    };
    dialogues["PLZ1_PT1_BAD_GUY2"] = {
        {
            {"speech", "Mysterious Voice", "Now, simpleton, the rules are as follows:"},
            {"speech", "", "First, you get two attempts to weight the billard balls"},
            {"speech", "", "Second, displayed on the touchscreen are two boxes. Chose a number for each box. This number will represent how many balls are randomly placed on either scale."}
        }
    };
    dialogues["BAD_GUY_FALIURE"] = {
        {
            {"speech", "Mysterious Voice", "YOU PERISHED! HAHA!"}
        }
    };

    // TYPE OPTIONS:
    // "speech" - Normal character dialogue (CYAN)
    // "action" - Normal narration/actions (YELLOW)
    // "danger" - Combat/danger narration (RED)
    // "narrator" - Narrator dialogue (BOLDWHITE)
}

// Display a dialogue by ID
void showDialogue(string dialogueID) {
    cout << "\n";

    //Check if dialogue exists
    if (dialogues.find(dialogueID) == dialogues.end()) {
        cout << RED << "Error Dialogue '" << dialogueID << "' not found!" << RESET << endl;
        cout << endl;
        return;
    }

    // Get the dialogue
    Dialogue d = dialogues[dialogueID];
    string currentIndent = "";

    // Display each line with appropriate formatting
    for (size_t i = 0; i < d.lines.size(); ++i) {
        Line line = d.lines[i];

        if (line.type == "speech") {
            if (line.speaker != "") {
                cout << RED << line.speaker << ": " << RESET;
                printWrapped(line.text, 90, "     "); // 90 char whidth, 5-space indent
            } else {
                // No speaker - use fixed five space indent
                cout << "     ";
                printWrapped(line.text, 90, "     ");
            }
        }
        else if (line.type == "narration") {
            cout << BOLDWHITE;
            printWrapped(line.text, 90);
            cout << endl << RESET;
        }
        else if (line.type == "action") {
            cout << YELLOW;
            printWrapped(line.text, 90); 
            cout << RESET;
        }
        else if (line.type == "danger") {
            cout << RED;
            printWrapped(line.text, 90); 
            cout << RESET;
        }
    }

    cout << endl;
}

// Display a location description
void showDialogueWithPause(string dialogueID) {
    showDialogue(dialogueID); 

    cout << YELLOW << "\n[Press Enter to continue...]" << RESET << endl;
    cin.get();
}
 
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
            printWrapped(line.text, 70);
        }
        else if (line.type == "action") {
            cout << YELLOW;
            printWrapped(line.text, 70);
            cout << RESET;
        }
        else if (line.type == "danger") {
            cout << RED;
            printWrapped(line.text, 70);
            cout << RESET;
        }
    }

    cout << endl;
}