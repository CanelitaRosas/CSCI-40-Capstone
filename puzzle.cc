#include <iostream>
#include <vector>
#include "/public/read.h"
#include "/public/colors.h"
using namespace std;

// whe you get where you want to go how can you explain what youve done, virtue
// wasnt conv at the time puzzles Billiard ball room
/*the correct solution to this common puzzle is to take a "less is more" appoach
put three billaird balls on each side of the scale, if those are equal then take
the three you left and put two on each side and leave one out. If they arent
equal take the side thats tipped and do the same.
*/
// montey hall puzzle three tbalets with three choices on each +-= signiying
// their relationships
vector<bool> rose(6);
bool crushed = false;
char ch;
string throwaway;

void start() {
  cout << "you wake up in a pit with rays of sunshine beaming down on you\n";
  cout << "you don't know who you are, you stand up to get your bearings "
          "correct\n";
  cout << "You look up at the pit and light and hear a crowd of laughs rain "
          "down from the small light all the way to the bottom of the pit "
          "where you reside\n";
  cout << "You look around and see a door and a rose, how did such beauty and "
          "innocence find it's way here???\n";
  cout << "The rose is growing out of a crack in the wall where small drops of "
          "water brush against it's petals about every 60 seconds\n";
  cout << "The rose won't survive in this place.... take the rose y/n: ";
  cout << endl;
  while (true) {
    ch = quick_read();
    if (ch == 'y' or ch == 'Y' or ch == 'n' or ch == 'N') {
      break;
    }
  }
  if (ch == 'y' or ch == 'Y') {
    cout << "you gently pluck the rose from it's resting place, and hold it in "
            "your hand such innocence should be protected\n";
    cout << "Press any key to continue.\n";
    cin.get();
    rose.at(0) = true;
    clearscreen();
  } else {
    cout << "You never were one to commit selfless acts... maybe that's what "
            "brought you here to begin with???\n";
    crushed = true;
    cout << "Press any key to continue.\n";
    cin.get();
    clearscreen();
  }
}
// when the character walks forward into the door

int puzzle1() {
  cout << "You walk into a billiard ball room with sigls of playing cards and "
          "checkered patterns lining the walls this is strange!\n";
  cout << "You see two rectanglular platforms  with a large screen that sits "
          "in the middle of them\n";
  cout << "there are nine identical in appearance balls that are laid before "
          "you behind some thick glass \n";
  cout << "you walked right into my trap! BAHAHAHAHA\n";
  cout << "ahem if youre simple minded self could see even two steps ahead of "
          "yourself then youd have noticed my elementary attempt to trap you, "
          "you simpleton! bahahahah\n";
  cout << "You'll have to use your simpleton mind to try and escape instead of "
          "just being a bonheaded brute for once, something that likely landed "
          "you here in the first place!\n";
  cout << "try and keep up! Before you there lay platforms with a screen "
          "between them and 9 identical balls as you likely have not even "
          "noticed ";
  cout << "the scale is rigged such that if youre simpleton self tried to make "
          "more than two weigh ins the room will blow up, if you try to game "
          "the system the room will blow up\n";
  cout << "there is an imposter amongst the balls much like you are amongst "
          "people you animal, it's why you're after all!\n";
  cout << "the imposter ball can only be recongnized by a scale it weighs just "
          "a miniscule amount more than the other balls which are identical in "
          "weight, it hides amongst the other balls the same way you hide "
          "among people. You see simpleton the imposter can not be spotted "
          "with the naked eye or felt out of the group with touch\n";
  cout << "the ball must be sniffed out by something made to expose it.... the "
          "scale and screen\n";
  cout << "remember simpleton... you have two weigh ins and if you try any "
          "simpleton like things that are sneaky or try a single thing out of "
          "the oridnary I will blow you up happily, naturally there are other "
          "rules of course but i'll not waste my time on such a stain of a "
          "person\n";
  cout << "what you will do is go to the screen between them and pick a number "
          "for each scale and that number will represent the amount of balls "
          "it will randomly select from, so if you choose 1 on the right scale "
          "and 1 on the left then they will be randomly selected now here's an "
          "importnat part so listen up. The screen will then flash and ask you "
          "how many balls for the second weigh in, if you try for a third time "
          "you will die here. oh and Just so luck does not play a factor in "
          "your solution the computer in the screen will then simulate your "
          "solution 100 times and if your percent accuracy of finding the "
          "imposter isnt 100 percent guess what? you die here. If I deem your "
          "solution smart enough you earn your freedom.... to the next room "
          "and test that is BAHAHAHA\n";
  cout << "such a simpleton like you should take all the time he needs, oh "
          "yeah and if you somehow prove yourself you will earn a rose. GO!";
  bool win = false;
  int weighLeft1 = 0;
  int weighRight1 = 0;
  int weighLeft2 = 0;
  int weighRight2 = 0;
  char p1ch;
  if (rose.at(0) == true) {
    cout << "This your chance.... \n";
    cout << "You feel you could snuff the rose to your gain, will you?? y/n";
    while (true) {
      cin >> p1ch;
      if (p1ch == 'y' or p1ch == 'Y' or p1ch == 'n' or p1ch == 'N') {
        break;
      }
    }
    if (p1ch == 'y' or p1ch == 'Y') {
      cout << "You snuff the rose, it doesn't take much for you to cause pain "
              "does it???\n";
      cout << "Laughter erupts from the door behind you, it's deafeaning. You "
              "hear glasses clink together as they chant in unison\n";
      cout << "LESS IS MORE!!! HAHAHAHA LESS IS MORE!!!\n";
      crushed = true;
      rose.at(0) = false;
    } else if (p1ch == 'N' or p1ch == 'n') {
      cout << "you opt to protect the rose even though it cuts your hands with "
              "it's thorns that it developed because of the very world you "
              "wish to protect it from\n";
    }
  }
  // we assume the player walks up to the screen here
  cout << "input choice for the left side\n";
  cin >> weighLeft1;
  if (!cin) {
    // death
    cout << "YOU PERSIHED, I bet you don't even hear it when it happens "
            "right?\n";
    return 0;
  } else {
    cout << "input choice for right side\n";
    cin >> weighRight1;
    if (!cin) {
      // death
      cout << "YOU PERSIHED, I bet you don't even hear it when it happens "
              "right?\n";
      return 0;
    }
  }
  cout << "the screen flashes round 2, AGAIN\n";
  cout << "input choice for the left side\n";
  cin >> weighLeft2;
  if (!cin) {
    // death
    cout << "YOU PERSIHED, I bet you don't even hear it when it happens "
            "right?\n";
    return 0;
  } else {
    cout << "input choice for right side\n";
    cin >> weighRight2;
    if (!cin) {
      // death
      cout << "YOU PERSIHED, I bet you don't even hear it when it happens "
              "right?\n";
      return 0;
    }
  }
  if (weighLeft1 == 3 and weighRight1 == 3) {
    if (weighLeft2 == 1 and weighRight2 == 1) {
      win = true;
    }
  }

  if (win == false) {
    cout << "The lights go dark, you can't tell if your eyes are open or "
            "you're dead.... a deafening explosion rings your ears and you are "
            "obliterated\n";
    cout << "YOU PERISHED\n";
    return 0;
  }
  if (rose.at(0) == false) {
    // they say actions show who a person really is, i think youve shown us all
    // who you really and maybe more importanly why you arew here...
    cout << "A voice screeches onto the intercom, you're not a very good "
            "person are you???\n";
    cout
        << "what use is life without love, and of what use is it to be warrior "
           "in a garden without knowing what it is to be a gardener???\n";
    cout << "answer me this is it better to perish here a gardener or exit "
            "this place a warrior?\n";
  }
}; // To puzzle guy, ADD RETURNS (FALSE being death, true being cleared, this
   // will help for map unlocks)
