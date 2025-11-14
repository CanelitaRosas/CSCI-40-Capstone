#ifndef MAPDATA_H
#define MAPDATA_H

#include <vector>
#include <string>
#include <iostream>
#include "/public/colors.h"

using namespace std;


struct Node {
    bool locked;
    bool cleared;
};

extern int g_CurrentNode;
extern vector<Node> nodes;
// Define the art for each node type, based on nodeTypes.txt
// Each node is 5 lines high.
const vector<string> NODE_BLANK = {
    "+---------+",
    "|         |",
    "|         |",
    "|         |",
    "+---------+"
};

const vector<string> NODE_PLAYER = {
    "+---------+",
    "|    * |",
    "|   /|\\   |",
    "|   / \\   |",
    "+---------+"
};

const vector<string> NODE_LOCKED = {
    "+---------+",
    "|   ( )   |",
    "|   / \\   |",
    "|   ---   |",
    "+---------+"
};

const vector<string> NODE_CLEARED = {
    "+---------+",
    "|      /  |",
    "|  \\  /   |",
    "|   \\/    |",
    "+---------+"
};


// A single map template. We will replace the _N#_ placeholders.
// The path snakes: 0-3 (bottom), 4-7 (middle), 8-11 (top)
//
//   (8) --- (9) --- (10) --- (11)
//    |
//   (7) --- (6) --- (5) --- (4)
//                            |
//   (0) --- (1) --- (2) --- (3)
//
// We add 4 spaces of padding as requested ("4 spaces before a node")
// and space them out to be equidistant.

const vector<string> MAP_TEMPLATE = {
"******************************************************************************************************",
"*                                                                                                    *",
"*    __NODE_08__                __NODE_09__                __NODE_10__                __NODE_11__    *",
"*    __NODE_08__                __NODE_09__                __NODE_10__                __NODE_11__    *",
"*    __NODE_08__    --------    __NODE_09__    --------    __NODE_10__   --------     __NODE_11__    *",
"*    __NODE_08__                __NODE_09__                __NODE_10__                __NODE_11__    *",
"*    __NODE_08__                __NODE_09__                __NODE_10__                __NODE_11__    *",
"*         |                                                                                          *",
"*         |                                                                                          *",
"*         |                                                                                          *",
"*         |                                                                                          *",
"*    __NODE_07__                __NODE_06__                __NODE_05__                __NODE_04__    *",
"*    __NODE_07__                __NODE_06__                __NODE_05__                __NODE_04__    *",
"*    __NODE_07__    --------    __NODE_06__    --------    __NODE_05__    --------    __NODE_04__    *",
"*    __NODE_07__                __NODE_06__                __NODE_05__                __NODE_04__    *",
"*    __NODE_07__                __NODE_06__                __NODE_05__                __NODE_04__    *",
"*         |                                                                                          *",
"*         |                                                                                          *",
"*         |                                                                                          *",
"*         |                                                                                          *",
"*    __NODE_00__                __NODE_01__                __NODE_02__                __NODE_03__    *",
"*    __NODE_00__                __NODE_01__                __NODE_02__                __NODE_03__    *",
"*    __NODE_00__    --------    __NODE_01__    --------    __NODE_02__    --------    __NODE_03__    *",
"*    __NODE_00__                __NODE_01__                __NODE_02__                __NODE_03__    *",
"*    __NODE_00__                __NODE_01__                __NODE_02__                __NODE_03__    *",
"*                                                                                                    *",
"******************************************************************************************************",
};

// Message for a locked node
const vector<string> msg_NotUnlocked {
    "*********************************************",
    "*                                           *",
    "*    This node has not yet been unlocked    *",
    "*                                           *",
    "*********************************************",
};


#endif // MAPDATA_H