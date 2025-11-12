//TEST FILE TO SHOW DIALOGUE SYSTEM
 #include <iostream>
 #include "dialogue.h"

 using namespace std;

 int main() {
    //CALL THE DIALOGUE FUNCTION
    initializeDialogues();

    cout << "\n ===TESTING===" << endl;

    // Test location descriptions
    //cout << "\n--- Testing Location Descriptions ---" << endl;
    //showLocDescrip("MIDDLE_OF_FOREST");

    //Test dialogues with actions
    //cout << "\n--- Testing Dialogues with Actions ---" << endl;
    //showDialogueWithPause("RANDOM_BRO")


         // ============ HOW MAIN SHOULD LOOK WHEN CALLING DIALOGUES =============\

// HOW THIS SYSTEM WORKS:
 /* 1. in main.cc, call initializeDialogues() ONCE at start.
    2. include "dialogue.h
    3. Call dialogues by ID:
       showDialogue("RANDOM_BRO") // IDs are found in the dialogue.cc file
*/

    showDialogueWithPause("INTRO_PT1");
    bool accepted = showDialogueWithChoice("INTRO_PT2");
      if (accepted) {
         showDialogue("INTRO_ACCEPTED"); // Show yes dialogue
      } else {
         showDialogue("INTRO_DECLINED");
      }
    
    showDialogueWithPause("UTILITY_PAUSE");
    showDialogueWithPause("PZL1_PT1");
    showDialogueWithPause("PZL1_PT1_BAD_GUY");
    showDialogueWithPause("PZL1_PT1_BAD_GUY1");
    showDialogueWithPause("PZL1_PT1_BAD_GUY2");
    showDialogueWithPause("PLZ1_PT1_BAD_GUY3");
    showDialogue("PLZ1_PT1_BAD_GUY4");

    cout << "\n=== END OF Test ===" << endl;

    return 0;
 }
 