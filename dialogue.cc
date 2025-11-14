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
    dialogues["UTILITY_PAUSE"] = {
        {
            {"narration", "", ""}
        }
    };
    dialogues["GENERAL_FALIURE"] = {
        {
            {"danger", "", "YOU PERISHED"}
        }
    };

    dialogues["INTRO_PT1"] = {
        {
            {"narration", "", "You wake in a pit, rays of sunshine blind your retinas. Slowly your vision adjusts revealing the situation before you."},
            {"narration", "", "You don't know where you are. You stand and try to gather your bearings."},
            {"narration", "", "You look up and see a crowd of spectators. They shower you with laughter, deriding your current helpessness."}
        }
    };

    dialogues["INTRO_PT2"] = {
        {
            {"narration", "", "Amidst your confusion and humiliation, you look around the pit. On the nearby wall is a single metal door. Next to the door growing out of a crack in the wall was a lone rose. A trickle of water from the crack above lapped at its petals making it glisten in the sunshine."},
            {"narration", "", "Such an object of beauty and innocence. Why is it here of all places? It surely won't survive here."},
            {"narration", "", "Do you take the rose? Y/N:"}
        }
    };
    dialogues["INTRO_ACCEPTED"] = {
        {
            {"narration", "", "You gently pluck the rose from the crack in the wall and cradle it close."}
        }
    };
    dialogues["INTRO_DECLINED"] = {
        {
            {"narration", "", "You were never one to commit selfless acts... Mayde that is why you are here in the first place?"}
        }
    };

    dialogues["PZL1_PT1"] = {
        {
            {"narration", "", "The locks on the metal door unlatch with a loud clanky thunk, then the door swings open towards you. It is too bright in the pit to see inside the door, so it just looks light a rectangular void, swalloing the light."}, 
            {"narration", "", "You walk into the doorway into what seems to be a dank billiard ball room. Mositure and woft of mildew threatened to choke your windpipe."}, 
            {"narration", "", "Going back wasn't an option. The only way is forward"},
            {"narration", "", "Slowly you stepped inside. As soon as your rear foot crossed the threshold, the heavy metal door slammed shut behnd you. Muffled clicks and clacks crawled along the inside of the door."},
            {"narration", "", "With a final thud, the locks slid home, and you were trapped."},
            {"narration", "", "At the other end of the room stood a large machine with two platforms on top of it. Connected between the two platforms is a large touchscreen display."},
            {"narration", "", "On the floor just before the platforms sits a large glass box. Inside the box are nine unmarked billiard balls, all seemingly identicle to each other."}
        }
    };

    dialogues["PZL1_PT1_BAD_GUY"] = {
        {
            {"speech", "Mysterious_Voice", "GOT YOU!!! You walked right into my trap! BAHAHAHA!"}
        }
    };
    dialogues["PZL1_PT1_BAD_GUY1"] = {
        {
            {"speech", "Mysterious Voice", "You simpelton! How could you possibly fall for such an elementary trap. Just how dull are you?"},
            {"speech", "", "Well, if you want out of here. You're going to have to use that excuse for a mind you've got, and not be a boneheaded brute for a change"},
            {"speech", "", "Best to try and keep up!"},
            {"speech", "", "In front of you is a puzzle of my own making! You need to solve it in order to leave. Simple!"}
        }
    };
    dialogues["PZL1_PT1_BAD_GUY2"] = {
        {
            {"speech", "Mysterious Voice", "But if you even try to cheat... The room is rigged to explode! Heh heh."},
            {"speech", "", "That glass box has a handful of billiard balls. They are all perfectly identicle. Except for one. It is an imposter, a fake, an odd one out. Just like so many of your pathetic species nowadays. I mean, that why you're here and all."},
            {"speech", "", "The imposter ball has a slgihtly different mass to all the others. They will all feel the same if you pick them up, but the scale, over there, is specially calibrated to detect this impostor."}
        }
    };
    dialogues["PLZ1_PT1_BAD_GUY3"] = {
        {
            {"speech", "Mysterious Voice", "Now, simpleton, you get two attempts to weigh the billard balls."},
            {"speech", "", "What you must do is go to the touchscreen and chose a number for each scale. This number will represent the nmumber of balls the scale will randomly pick. So, for exapmle, you pick two for the right cale and left scale. It will then randomly pick two balls for the rights scale and two balls for the left scale."},
            {"speech", "", "This next part is important, so LISTEN TO ME, OKAY!? The screen will then flash and ask you to make another choice for the second weigh-in. If you try for a third, then BOOM! Bye bye, I wish I could miss you... NOT!"}
        }
    };
    dialogues["PLZ1_PT1_BAD_GUY4"] = {
        {
            {"speech", "BAD_GUY", "Oh, and just so you do not manage to get lucky, somehow. The scale will run your entries one-hundred times to make sure your choices are properly accurate. No getting saved by margin of error here. "},
            {"speech", "", "If you pass, you will get a special prize. AND YOUR FREEDOM..."},
            {"speech", "", "To the next chamber, at least. NOW, GO!"}
        }
    };
    dialogues["PLZ1_PT2_CHOICE"] = {
        {
            {"narration", "", "AN orchestra of laughter erupts from above the pit walls."}, 
            {"narration", "", "This is your chance."},
            {"narration", "", "Something within your mind tell you that if you crush the rose, it wopuld be to your gain."},
            {"narration", "", "Will you do it? Y/N:"}
        }
    };
    dialogues["PLZ1_PT2_ACCEPTED1"] = {
        {
            {"narration", "", "You smother the rose in your fist. Inflicting harm always came easy to you."},
            {"narration", "", "Right?"}
        }
    };
    dialogues["PLZ1_PT2_ACCEPTED2"] = {
        {
            {"narration", "", "Laughter again erupts from above. The observers were throwing a raucous fit at your choice."},
            {"narration", "", "They clinked their drink glasses together in celebration. Then they all started shouting in unison."},
            {"speech", "Audience", "LESS IS MORE! LESS IS MORE! LESS IS MORE!"}
        }
    };
    dialogues["PLZ1_PT2_DECLINED"] ={
        {
            {"narration", "", "You keep the rose, its thorns teariing into your palm."},
            {"narration", "", "Those thorns; it devloped them to protect itself from the very world you try to shelter it from."}
        }
    };
    dialogues["PLZ1_FAIL_"] = {
        {
            {"narration", "", "The lights pop and darkness floods the room. Did you die? Or can you not see?"},
            {"danger", "", "The room flashed with light and heat. For an instant that lasted an ternity, you felt your body burn and rip apart."}
        }
    };
    dialogues["PLZ1_WIN_W/ROSE"] = {
        {
            {"narration", "", "The intercom screeches to life."},
            {"speech", "Mysterious Voice", "You are not a good person, are you?"},
            {"speech", "", "What use is life without love?"},
            {"speech", "", "And what use is it to be a warrior in a garden without knowing how to be a gardener?"},
            {"speech", "", "Is it better to die a gardener, or live as a warrior?"},
            {"speech", "", "They say that a person show who they really are when their life is threatened. I think you showed us who you really are."}
            {"speech", "", " "},
            {"narration", "", "The audience starts laughing again at you."},
            {"narration", "", "The exit door unlocks and opens."}
        }
    };
    dialogues["PLZ1_WIN_W/O_ROSE"] = {
        {
            {"narration", "", "The intercom screeches to life."},
            {"speech", "Mysterious Voice", "You were expected to pass this simples test, but who are you kidding?"},
            {"speech", "", "We are the only ones watching you, and we have already made our judgment."},
            {"speech", "", "Do you think you have anything in common with us?"},
            {"speech", "", "If you did, you wouldn't be in the present situation."},
            {"narration", "", "The exit door unlocks and opens."}
        }
    };

    dialogues["PLZ2_CHOICE"] = {
        {
            {"narration", "", "The audience chuckles and cheers as you approach the next room."},
            {"speech", "Mysterious Voice", "Do you sacrifice beauty and innocence for your own gain?"}
        }
    };
    dialogues["PLZ2_CHOICE_YES"] = {
        {
            {"narrator", "", "The rose dies by your hand, you get a sick satisfaction from it."},
            {"narrator", "", "The audience begins to scream and chant. Filling the rooms with their harsh euphony."},
            {"speech", "audience", "EXPONENTIAL GROWTH! EXPONENTIAL GROWTH!"}
        }
    };
    dialogues["PLZ2_CHOICE_NO"] = {
        {
            {"narrator", "", "You keep the rose as it is."}
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

    cout << YELLOW << "\nCONTINUE: Enter" << RESET << endl;
    cin.get();
}

bool showDialogueWithChoice(string dialogueID) {
    showDialogue(dialogueID); 
    
    char choice;

    while (true) {
        cout << YELLOW << "\n[Enter Y or N]" << RESET << endl;
        cin >> choice;
        cin.ignore();

        if (choice == 'Y' || choice == 'y') {
            return true;
        } else if (choice == 'N' || choice == 'n') {
            return false;
        } else {
            cout << RED << "Invalid Input! Enter Y or N." << RESET << endl;
        }
    }
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