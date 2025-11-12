//Rosas-Puzzles,Inv,I/o,Dialogue
//Partners:Gregory(I/o)
//Bullet Points:3
//Extra Credit: 1,3
//URL to cover art and music:

#include <iostream>
#include <vector>
#include "error.h"
#include "/public/colors.h"
#include "puzzle.cc"
#include "combat.cc"
#include "dialogue.cc"
#include "mapLogic.cc"

using namespace std;

int main(){
    set_raw_mode(true);
    clearscreen();
    start();



    drawMap(0);
}
