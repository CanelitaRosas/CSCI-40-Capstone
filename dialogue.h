#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
#include <vector>
#include <map>
using namespace std;

// Struct for a single line (speech or action)
struct Line {
    string type;
    string speaker;
    string text;
};

// A dialogue is a sequence of lines
struct Dialogue {
    vector<Line> lines;
};

// Main functions
void initializeDialogues(); //Load all dialogues into memory
void showDialogue(string dialogueID);
void showDialogueWithPause(string dialogueID);
bool showDialogueWithChoice(string dialogueID);
void showLocDescrip(string location);

// Helper function for wrapping
void printWrapped(string text, int maxWidth, string indent = "");

#endif