#include <vector>
#include "error.h"
#include "mapData.h"
#include <iostream>
using namespace std;

int g_currentMap;
int ch;

struct Node{
    bool locked;
    bool cleared;
};

vector<Node> nodes {
    {false, true},
    {false, false},
    {true, false},
    {true, false},
    {true, false},
    {true, false},
    {true, false},
    {true, false},
    {true, false},
    {true, false},
    {true, false},
};

void drawMap0() {
    g_currentMap = 0;
    clearscreen();
    for (size_t i = 0; i < map0.size(); i++) {
        cout << map0.at(i) << endl;
    }
}

void drawMap1() {
    g_currentMap = 1;
    clearscreen();
    for (size_t i = 0; i < map1.size(); i++) {
        cout << map1.at(i) << endl;
    }
}

void drawMap2() {
    g_currentMap = 2;
    clearscreen();
    for (size_t i = 0; i < map2.size(); i++) {
        cout << map2.at(i) << endl;
    }
}
void drawMap3() {
    g_currentMap = 3;
    clearscreen();
    for (size_t i = 0; i < map3.size(); i++) {
        cout << map3.at(i) << endl;
    }
}
void drawMap4() {
    g_currentMap = 4;
    clearscreen();
    for (size_t i = 0; i < map4.size(); i++) {
        cout << map4.at(i) << endl;
    }
}
void drawMap5() {
    g_currentMap = 5;
    clearscreen();
    for (size_t i = 0; i < map5.size(); i++) {
        cout << map5.at(i) << endl;
    }
}
void drawMap6() {
    g_currentMap = 6;
    clearscreen();
    for (size_t i = 0; i < map6.size(); i++) {
        cout << map6.at(i) << endl;
    }
}

void drawMap7() {
    g_currentMap = 7;
    clearscreen();
    for (size_t i = 0; i < map7.size(); i++) {
        cout << map7.at(i) << endl;
    }
}

void drawMap8() {
    g_currentMap = 8;
    clearscreen();
    for (size_t i = 0; i < map8.size(); i++) {
        cout << map8.at(i) << endl;
    }
}

void drawMap9() {
    g_currentMap = 9;
    clearscreen();
    for (size_t i = 0; i < map9.size(); i++) {
        cout << map9.at(i) << endl;
    }
}

void drawMap10() {
    g_currentMap = 10;
    clearscreen();
    for (size_t i = 0; i < map10.size(); i++) {
        cout << map10.at(i) << endl;
    }
}

void drawMap11() {
    g_currentMap = 11;
    clearscreen();
    for (size_t i = 0; i < map11.size(); i++) {
        cout << map11.at(i) << endl;
    }
}



void drawNotUnlocked() {
    for (size_t i = 0; i < msg_NotUnlocked.size(); i++ ) {
        clearscreen();
        cout << msg_NotUnlocked.at(i) << endl;
    }
}



void drawMap(int mapToDraw) {
    switch(mapToDraw) {
        case 0:
            //clearscreen();
            drawMap0();
            break;
        case 1:
            drawMap1();
            break;
        case 2:
            drawMap2();
            break;
        case 3:
            drawMap3();
            break;
        case 4:
            drawMap4();
            break;
        case 5:
            drawMap5();
            break;
        case 6:
            drawMap6();
            break;
        case 7:
            drawMap7();
            break;
        case 8:
            drawMap8();
            break;
        case 9:
            drawMap9();
            break;
        case 10:
            drawMap10();
            break;
        case 11:
            drawMap11();
            break;
        default:
            drawError(ERROR::MAP_ERROR);
            break;
    }
}

void updateMap() {
    while(true) {
        if (g_currentMap == 0) {
            ch = quick_read();
            if (ch == LEFT_ARROW) {
                if (nodes.at(0).locked) {
                    
                }
            }
        }
    }
}
