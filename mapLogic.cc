#include "/public/colors.h" // For text colors
#include "/public/read.h"   // For quick_read() and get_terminal_size()
#include "error.h"          // For error messages
#include "mapData.h"        // For map template and node art
#include <algorithm>        // For clamp
#include <iostream>
#include <string>
#include <unistd.h> // For usleep
#include <vector>

using namespace std;

int g_currentNode = 0;
int moveInput;

vector<Node> nodes{
    // Bottom Row (0-3)
    {false, true},  // Node 0 (Start)
    {false, false}, // Node 1
    {true, false},  // Node 2
    {true, false},  // Node 3
    // Middle Row (4-7)
    {true, false}, // Node 4
    {true, false}, // Node 5
    {true, false}, // Node 6
    {true, false}, // Node 7
    // Top Row (8-11)
    {true, false}, // Node 8
    {true, false}, // Node 9
    {true, false}, // Node 10
    {true, false}  // Node 11
}; // copypasted cause im not retyping that when I have alot more to type comin
// soon

void replaceNode(vector<string> &mapLines, const string &placeholder,
                 const vector<string> &nodeArt) {
  for (size_t i = 0; i < mapLines.size(); i++) {
    size_t pos = mapLines.at(i).find(placeholder);

    if (pos != string::npos) {
      for (size_t j = 0; i < nodeArt.size(); j++) {
        if (i + j < mapLines.size()) {
          mapLines[i + j].replace(pos, placeholder.length(), nodeArt.at(j));
        }
      }

      return;
    }
  }
}

void drawNotUnlocked() {
  const auto [ROWS, COLS] = get_terminal_size();
  const int msgHeight = msg_NotUnlocked.size();
  const int msgWidth = msg_NotUnlocked.at(0).length();
  const int padding = 2;
  const int totalH = msgHeight + (padding * 2);
  const int totalW = msgWidth + (padding * 2);
  int startRow = (ROWS - totalH) / 2;
  int startCol = (COLS - totalW) / 2;
  startRow = max(0, startRow);
  startCol = max(0, startCol);
  const string blankLine(totalW, ' ');
  const string sidePad(padding, ' ');

  cout << RED;

  // top padding
  for (int i = 0; i < padding; i++) {
    movecursor(startRow + i, startCol);
    cout << blankLine;
  }
  // message box
  for (int i = 0; i < msgHeight; i++) {
    movecursor(startRow + padding + i, startCol);
    cout << sidePad << msg_NotUnlocked.at(i) << sidePad;
  }

  for (int i = 0; i < padding; i++) {
    movecursor(startRow + padding + msgHeight + i, startCol);
    cout << blankLine;
  }

  cout << RESET;

  while (quick_read() != ERR) {
  	//do nothing
  }

  while (quick_read() == ERR) {
  	usleep(10000);
  }
}

void drawMap() {
  const auto [ROWS, COLS] = get_terminal_size();

  vector<string> mapToDraw = MAP_TEMPLATE;

  for (int i = 0; i < 12; i++) {
    string placeholder = "__NODE_";
    if (i < 10) {
      placeholder += "0"; // add leading 0.
    }
    placeholder += to_string(i) + "__";
    if (i == g_currentNode) {
      replaceNode(mapToDraw, placeholder, NODE_PLAYER);
    } else if (nodes.at(i).locked) {
      replaceNode(mapToDraw, placeholder, NODE_LOCKED);
    } else if (nodes.at(i).cleared) {
      replaceNode(mapToDraw, placeholder, NODE_CLEARED);
    } else {
      replaceNode(mapToDraw, placeholder, NODE_BLANK);
    }
  }

  clearscreen();
  int mapHeight = mapToDraw.size();
  int mapWidth = mapToDraw.at(0).length();

  int topPadding = (ROWS - mapHeight) / 2;
  int leftPadding = (ROWS - mapWidth) / 2;

  topPadding = max(0, topPadding);
  leftPadding = max(0, leftPadding);

  for (size_t i = 0; i < mapToDraw.size(); i++) {
    movecursor(topPadding + i, leftPadding);
    cout << mapToDraw.at(i) << endl;
  }
}

void updateMap() {
  bool keepReading = true;
  while (keepReading) {
    int oldNode = g_currentNode;

    moveInput = quick_read();

    if (moveInput == ERR) {
      usleep(50000); // 50ms pause
      continue;
    }

    switch (moveInput) {
    case UP_ARROW:
      if (g_CurrentNode == 3)
        g_currentNode = 4;
      else if (g_currentNode == 7)
        g_currentNode = 8;
      break;
    case DOWN_ARROW:
      if (g_currentNode == 4)
        g_currentNode = 3;
      else if (g_currentNode == 8)
        g_currentNode = 7;
      break;
    case RIGHT_ARROW:
      if (g_currentNode >= 0 && g_currentNode <= 2)
        g_currentNode++;
      else if (g_currentNode >= 5 && g_currentNode <= 7)
        g_currentNode--;
      else if (g_currentNode >= 8 && g_currentNode <= 10)
        g_currentNode++;
      break;

    case LEFT_ARROW:
      if (g_currentNode >= 1 && g_currentNode <= 3)
        g_currentNode--;
      else if (g_currentNode >= 4 && g_currentNode <= 6)
        g_currentNode++;
      else if (g_currentNode >= 9 && g_currentNode <= 11)
        g_currentNode--;
      break;

    case '\n':
      if (!nodes.at(g_currentNode).cleared) {
        keepReading = false;
      }
      break;
    }

    if (oldNode != g_currentNode) {
      if (nodes.at(g_CurrentNode).locked) {
        g_currentNode = oldNode;
        drawMap();
        drawNotUnlocked();
      } else {
      	drawMap();
      }
    }
  }
}
