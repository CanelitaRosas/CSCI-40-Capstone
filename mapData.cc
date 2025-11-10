#include <vector>
#include <string>
#include <iostream> //remove when done testing
using namespace std;

struct Node {
    bool locked;
    bool player;
    int position;
    bool connectedHorizontal;
    bool isEnd;
    
};

const vector<string> nodeLocked {
    "+---------+",
    "|   ( )   |",
    "|   / \\   |",
    "|   ---   |",
    "+---------+",

};

const vector<string> nodePlayer {
    "+---------+",
    "|    *    |",
    "|   /|\\   |",
    "|   / \\   |",
    "+---------+",
};


const vector<string> nodeEmpty {
    "+---------+",
    "|         |",
    "|         |",
    "|         |",
    "+---------+",
};

const vector<string> baseMap { //maybe will become unused? Idk, i might just
    "*********************************************************************************************************",
    "*     +---------+                +---------+                +---------+                +----------+     *",
	"*     |         |                |         |                |         |                |          |     *",
	"*     |         |    --------    |         |    --------    |         |    --------    |          |     *",
	"*     |         |                |         |                |         |                |          |     *",
	"*     +---------+                +---------+                +---------+                +----------+     *",
    "*          |                                                                                            *",
    "*          |                                                                                            *",
    "*          |                                                                                            *",
    "*          |                                                                                            *",
    "*     +---------+                +---------+                +---------+                 +---------+     *",
    "*     |         |                |         |                |         |                 |         |     *",
    "*     |         |    --------    |         |    --------    |         |    ---------    |         |     *",
    "*     |         |                |         |                |         |                 |         |     *",
    "*     +---------+                +---------+                +---------+                 +---------+     *",
    "*                                                                                            |          *",
    "*                                                                                            |          *",
    "*                                                                                            |          *",
    "*                                                                                            |          *",
    "*     +---------+                +---------+                +---------+                 +---------+     *",
    "*     |         |                |         |                |         |                 |         |     *",
    "*     |         |    --------    |         |    --------    |         |    ----------   |         |     *",
    "*     |         |                |         |                |         |                 |         |     *",
    "*     +---------+                +---------+                +---------+                 +---------+     *",
    "*********************************************************************************************************",
};

vector<Node> map {
    {false, true, 0, true, false},
    {false, false, 1, true, false},
    {true, false, 2, true, false},
    {true, false, 3, false, false},
    {true, false, 4, true, false},
    {true, false, 5, true, false},
    {true, false, 6, true, false},
    {true, false, 7, false, false},
    {true, false, 8, true, false},
    {true, false, 9, true, false},
    {true, false, 10, true, false},
    {true, false, 11, true, true}
};

int main() {
    for (int i = 0; i < baseMap.size(); i++) {
        cout << baseMap.at(i) << endl;
    }

    for (int i = 0; i < nodePlayer.size(); i++) {
        cout << nodePlayer.at(i) << endl;
    }

    for (int i = 0; i < nodeLocked.size(); i++) {
        cout << nodeLocked.at(i) << endl;
    }

    for (int i = 0; i < nodeEmpty.size(); i++) {
        cout << nodeEmpty.at(i) << endl;
    }

    for (int i = 0; i < map.size(); i++) {
        cout << "Item " << i << endl;
        cout << "isLocked: " << map.at(i).locked << endl;
        cout << "isPlayer: " << map.at(i).player << endl;
        cout << "Position: " << map.at(i).position << endl;
        cout << "isNextNodeConnectedHorizontally: " << map.at(i).connectedHorizontal << endl;
    }
}
