// Rosas-Puzzles,Inv,I/o,Dialogue
// Partners:Gregory(I/o)
// Bullet Points:3
// Extra Credit: 1,3
// URL to cover art and music:
#include "combat.cc"
#include "dialogue.cc"
#include "mapLogic.cc"
#include "puzzle.cc"
#include <cstdlib>
#include <vector>

using namespace std;


void startTrial() {
    if (g_currentMap == 1) {
      if (puzzle1()) {
        nodes.at(1).cleared = true;
        nodes.at(2).locked = false;
      } else {
        exit(EXIT_SUCCESS);
      }
    } else if (g_currentMap == 2) {
      if(combatMain()) {
      nodes.at(2).cleared = true;
      nodes.at(3).locked = false;
      } else {
          exit(EXIT_SUCCESS);
      }
    }
}
int main() {
  set_raw_mode(true);
  start();
  clearscreen();
  drawMap(0);
  while(true) {
      updateMap();
      startTrial();
      drawMap(g_currentMap);
  }
}
