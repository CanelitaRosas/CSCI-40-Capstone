#include <vector>
#include <string>
#include "/public/colors.h"
#include <iostream>

using namespace std;

enum ERROR {
    MAP_ERROR
};
const vector<string> ERROR_InvalidMap {
    "************************************",
    "*            --- OOPS ---          *",
    "*     You're seeing this message   *",
    "*        because of an error       *",
    "*     in the draw code. Sorry :(   *",
    "*                                  *",
    "*     Error: Invalid map called    *",
    "************************************",
};

const vector<string> ERROR_A {
    "Fill this out when needed",
};

void drawError(ERROR error) {
    switch (error){
        case ERROR::MAP_ERROR:
            cout << RED << endl;
            for (size_t i = 0; i < ERROR_InvalidMap.size(); i++) {
                cout << ERROR_InvalidMap.at(i) << endl;
            }
    }
}
