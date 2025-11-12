#include "error.h"
#include "mapData.h"
#include <iostream>
#include <vector>
using namespace std;

int g_currentMap;
int moveInput;
char enter;

struct Node {
  bool locked;
  bool cleared;
};

vector<Node> nodes{
    {false, true}, {false, false}, {true, false}, {true, false},
    {true, false}, {true, false},  {true, false}, {true, false},
    {true, false}, {true, false},  {true, false},
};

void drawMap(int mapToDraw) {
  switch (mapToDraw) {
  case 0:
    g_currentMap = 0;
    clearscreen();
    for (size_t i = 0; i < map0.size(); i++) {
      cout << map0.at(i) << endl;
    }
    break;
  case 1:
    g_currentMap = 1;
    clearscreen();
    for (size_t i = 0; i < map1.size(); i++) {
      cout << map1.at(i) << endl;
    }
    break;
  case 2:
    g_currentMap = 2;
    clearscreen();
    for (size_t i = 0; i < map2.size(); i++) {
      cout << map2.at(i) << endl;
    }
    break;
  case 3:
    g_currentMap = 3;
    clearscreen();
    for (size_t i = 0; i < map3.size(); i++) {
      cout << map3.at(i) << endl;
    }
    break;
  case 4:
    g_currentMap = 4;
    clearscreen();
    for (size_t i = 0; i < map4.size(); i++) {
      cout << map4.at(i) << endl;
    }
    break;
  case 5:
    g_currentMap = 5;
    clearscreen();
    for (size_t i = 0; i < map5.size(); i++) {
      cout << map5.at(i) << endl;
    }
    break;
  case 6:
    g_currentMap = 6;
    clearscreen();
    for (size_t i = 0; i < map6.size(); i++) {
      cout << map6.at(i) << endl;
    }
    break;
  case 7:
    g_currentMap = 7;
    clearscreen();
    for (size_t i = 0; i < map7.size(); i++) {
      cout << map7.at(i) << endl;
    }
    break;
  case 8:
    g_currentMap = 8;
    clearscreen();
    for (size_t i = 0; i < map8.size(); i++) {
      cout << map8.at(i) << endl;
    }
    break;
  case 9:
    g_currentMap = 9;
    clearscreen();
    for (size_t i = 0; i < map9.size(); i++) {
      cout << map9.at(i) << endl;
    }
    break;
  case 10:
    g_currentMap = 10;
    clearscreen();
    for (size_t i = 0; i < map10.size(); i++) {
      cout << map10.at(i) << endl;
    }
    break;
  case 11:
    g_currentMap = 11;
    clearscreen();
    for (size_t i = 0; i < map11.size(); i++) {
      cout << map11.at(i) << endl;
    }
    break;
  default:
    drawError(ERROR::MAP_ERROR);
    break;
  }
}

void drawNotUnlocked() {
  for (size_t i = 0; i < msg_NotUnlocked.size(); i++) {
    cout << msg_NotUnlocked.at(i) << endl;
  }
}

void updateMap() {
  while (true) {
    if (g_currentMap == 0) {
      moveInput = quick_read();
      if (moveInput == RIGHT_ARROW) {
        drawMap(1);
      }
    }

    if (g_currentMap == 1) {
      moveInput = quick_read();
      if (moveInput == RIGHT_ARROW) {
        if (nodes.at(2).locked) {
          drawMap(1);
          drawNotUnlocked();
        } else {
          drawMap(2);
        }
      } else if (moveInput == LEFT_ARROW) {
        drawMap(0);
      } else if (moveInput == '\n') {
        if (nodes.at(1).cleared == false) {
          break;
        }
      }
    }

    if (g_currentMap == 2) {
      moveInput = quick_read();
      if (moveInput == RIGHT_ARROW) {
        if (nodes.at(3).locked) {
          drawMap(2);
          drawNotUnlocked();
        } else {
          drawMap(3);
        }
      } else if (moveInput == LEFT_ARROW) {
        drawMap(1);
      } else if (moveInput == '\n') {
        if (nodes.at(2).cleared == false) {
          break;
        }
      }
    }
  }
}
