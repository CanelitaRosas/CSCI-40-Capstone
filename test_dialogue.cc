//TEST FILE TO SHOW DIALOGUE SYSTEM
 #include <iostream>
 #include "dialogue.h"

 using namespace std;

 int main() {
    //CALL THE DIALOGUE FUNCTION
    initializeDialogues();

    cout << "\n ===TESTING===" << endl;

    // Test location descriptions
    cout << "\n--- Testing Location Descriptions ---" << endl;
    showLocDescrip("MIDDLE_OF_FOREST");

    //Test dialogues with actions
    cout << "\n--- Testing Dialogues with Actions ---" << endl;
    showDialogue("RANDOM_BRO");

    cout << "\n=== END OF Test ===" << endl;

    return 0;
 }

 // HOW THIS SYSTEM WORKS:
 /* 1. in main.cc, call initializeDialogues() ONCE at start.
    2. include "dialogue.h
    3. Call dialogues by ID:
       showDialogue("RANDOM_BRO")
*/