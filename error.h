#ifndef ERROR_H
#define ERROR_H

#include <vector>
#include <string>
#include <iostream>
#include "/public/colors.h"
using namespace std;

enum ERROR {
    MAP_ERROR,
    NOT_DONE_YET
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

const vector<string> ERROR_NotDoneYet {
    "*********************************************",
    "* --- I didnt know I was playing a demo --- *",
    "*         You're seeing this message        *",
    "*            because we arent done          *",
    "*           with everything yet  :(         *",
    "*                                           *",
    "*               Check back soon!            *",
    "*********************************************",
};

void drawError(ERROR error) {
    switch (error){
        case ERROR::MAP_ERROR:
            cout << RED << endl;
            clearscreen();
            for (size_t i = 0; i < ERROR_InvalidMap.size(); i++) {
                cout << ERROR_InvalidMap.at(i) << endl;
            }
            cout << RESET << endl;
            break;

        case ERROR::NOT_DONE_YET:
            cout << GREEN << endl;
            clearscreen();
            for (size_t i = 0; i < ERROR_NotDoneYet.size(); i++) {
                cout << ERROR_NotDoneYet.at(i) << endl;
            }
            cout << RESET << endl;
    }
}

#endif
