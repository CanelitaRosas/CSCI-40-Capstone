#include "/public/colors.h"
#include "/public/read.h"
#include <iostream>
#include <vector>

using namespace std;
bool roseN(const vector<bool> &r) {
  for (int i = 0; i < r.size(); i++) {
    if (r.at(i) == true) {
      return true;
    } else
      return false;
  }
}
// whe you get where you want to go how can you explain what youve done, virtue
// wasnt conv at the time puzzles Billiard ball room
/*the correct solution to this common puzzle is to take a "less is more" appoach
put three billaird balls on each side of the scale, if those are equal then take
the three you left and put two on each side and leave one out. If they arent
equal take the side thats tipped and do the same.
*/
// montey hall puzzle three tbalets with three choices on each +-= signiying
// their relationships
// code the start
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
  cout << "The rose won't survive in this place.... take the rose y/n";
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
    cout << "Press any key to continue";
    cin.get();
    rose.at(0) = true;
  } else {
    cout << "You never were one to commit selfless acts... maybe that's what "
            "brought you here to begin with???\n";
    cout << "Press any key to continue";
    cin.get();
    crushed = true;
  }
  // when the character walks forward into the door
}
// puzzle 1
int puzzle1() {
  clearscreen();
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
  bool win1 = false;
  int weighLeft1 = 0;
  int weighRight1 = 0;
  int weighLeft2 = 0;
  int weighRight2 = 0;
  char p1ch;
  if (roseN(rose)) {
    cout << "You hear a crowd of laughter roar behind you from the top of the "
            "pit,This your chance.... \n";
    cout << "You feel you could snuff the rose to your gain, will you?? y/n";
    cout << endl;
    while (true) {
      p1ch = quick_read();
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
  set_raw_mode(false);
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
      win1 = true;
    }
  }

  if (win1 == false) {
    cout << "The lights go dark, you can't tell if your eyes are open or "
            "you're dead.... a deafening explosion rings your ears and you are "
            "obliterated\n";
    cout << "YOU PERISHED\n";
    return 0;
  }
  if (roseN(rose)) {
    // they say actions show who a person really is, i think youve shown us all
    // who you really and maybe more importanly why you arew here...
    cout << "A voice screeches onto the intercom" << endl;
    cout << "you're not a very good person are you???\n";
    cout
        << "what use is life without love, and of what use is it to be warrior "
           "in a garden without knowing what it is to be a gardener???\n";
    cout << "answer me this is it better to perish here a gardener or exit "
            "this place a warrior?\n";
    cout << "Don't answer that... They say when people show you who they "
            "really are to believe them and I think you've show us all just "
            "who you really are"
         << endl;
    cout << "Laughter erupts behind you as you hear the door in front of you "
            "unlock"
         << endl;
         set_raw_mode(true);
         return 1;
  } else if (roseN(rose) == false) {
    cout << "A voice screeches onto the intercom" << endl;
    cout << "A simple test you were expected to pass it but why are you "
            "kidding yourself?"
         << endl;
    cout << "We are the only ones wathcing you and we have already judged you, "
            "do you think you have anything in common with us?"
         << endl;
    cout << "You wouldn't be in your predictament if you did... You'd be where "
            "I stand not the other way around"
         << endl;
    cout << "You hear a door unlock in front of you\n";
    set_raw_mode(true);
    return 1;

  }
}

// puzzle two starts just after a combat node and a rose is given

int puzzle2() {
  bool win2;
  char p2ch;
  if (roseN(rose)) {
    cout << "Laughter erputps behind you along with screaming and yelling, "
            "this is your chance make a rose perish by your hand???\n";
    while (true) {
      cin >> p2ch;
      if (p2ch == 'y' or p2ch == 'Y' or p2ch == 'n' or p2ch == 'N') {
        break;
      }
    }
    if (p2ch == 'y' or p2ch == 'Y') {
      cout
          << "The rose perishes by your hand, you always did enjoy innocence "
             "lost. You hear screaming behind you from the top of the pit...\n";
      cout << "Yelling and choas can be heard from the hole where you were "
              "thrown from it fills the room with noise the start yelling "
              "uniformly\n";
      cout << "EPONENTIAL GROWTH!!!!! \n";
      if (crushed == false) {
        crushed = true;
      }
      rose.at(1) = false;
    } else if (p2ch == 'N' or p2ch == 'n') {
      cout << "\n";
    }
  }
  cout << "You step into a room with thick glass on all sides, the floor is "
          "glass as are the walls and ceiling, behind the glass is rapid "
          "water\n";
  cout << "there is only a tablet in the middle of the room, and a voice "
          "crackles onto the intercom\n";
  if (crushed == true) {
    cout << "I can give you a hint about this place... about yourself even\n";
    cout << "Nothing you do from here on matters... you have made your choice "
            "that to reiterate is why you are likely here to begin with\n";
    cout << "I have a question for you to ponder about yourself... free will "
            "is what brought you here so my question to you is can you blame "
            "your enviroment for the way you are or for the things you have "
            "done and all the while you tell yourself they had to be done "
            "because virtue wasn't conveneint at the time?\n";
    cout << "Let's presume for a second you were born here into this pit... do "
            "you blame the pit for the choices you have made...? do you blame "
            "me?, do you blame yourself...? or is there something else?\n";
  } else if (crushed == false) {
    cout << "No matter how cruel this pit is to you, you keep trying don't "
            "you? It's admirable... Let me ask you a question to ponder to "
            "yourself while you are here\n";
    cout << "If you chose to go the other route who really is to blame? We all "
            "have free will do we not?\n";
    cout << "The pit has been cruel to you do you blame it? Do you think you "
            "were always bound to make a virtuos decision because you have a "
            "true nature? Do you think evil is made or born? Both?\n";
    cout << "Ponder to yourself who really would be to blame for you becoming "
            "a bad person, you? The pit? Whatever threw you in here? Me? or is "
            "there something else?\n";
    cout << "You try and kid yourself like you are noble or good even but "
            "again then why are you here to begin with..."
         << endl;
  }
  cout << "A staduim is being filled with drops of water, the amount of water "
          "in the stadium doubles each second. The stadium is full of water at "
          "thirty seconds. So...\n";
  cout << "The question to ask yourself is when is the stadium half full?\n";
  if (crushed == true) {
    cout << "if you are wrong you die here and you've already received all the "
            "help you can get haven't you? You didn't care what that cost you "
            "and even if you do somehow escape this place it won't matter. "
            "You'll see...\n";
  } else if (crushed == false) {
    cout << "Time is your friend now, that's all you have to help you now so "
            "take all the time you need...\n";
  }
  win2 = false;
  int t = 0;
  cout << "The tablet displays on its screen: delta t =?";
  cout << "Enter delta t\n";
  while (true) {
    cin >> t;
    if (!cin) {
      continue;
    } else {
      break;
    }
  }
  if (t == 29) {
    win2 = true;
  } else {
    win2 = false;
  }
  if (win2 == false) {
    cout << "The glass covering the ceiling opens revealing a net, water "
            "floods the entire room and you drown to death\n";
    cout << "YOU PERISHED\n";
    return 0;
  } else {
    cout << "You hear the door in front of you unlock, and prepare yourself "
            "for what is to come\n";
  }
}
// player moves to the next room gets a rose after completing another combat

int puzzle3() {
  rose.at(2) = true;
  bool win3 = false;
  char p3ch;
  cout << "You walk into a room this time there is money signs and huge yellow "
          "game show lights all over the walls\n";
  if (roseN(rose) == true) {
    cout << "Sounds of snoring and coughing echo through the empty rooms "
            "behind you, they are coming from the pit...\n";
    cout << "Now is your chance to strike, kill a rose?\n";
    while (true) {
      cin >> p3ch;
      if (p3ch == 'y' or p3ch == 'Y' or p3ch == 'n' or p3ch == 'N') {
        break;
      }
    }
    if (p3ch == 'y' or p3ch == 'Y') {
      cout << "You crush the rose and it's petals and leave it's remains on "
              "the ground, you aren't trying to even pretend to be a good "
              "person you have embraced who you really are\n";
      cout << "A zombie like horde snarls in unison\n";
      cout << "THE BIG PICTURE\n";
      if (crushed == false) {
        crushed = true;
      }
      rose.at(2) = false;
    } else if (p3ch == 'N' or p3ch == 'n') {
      cout << "You saved another rose you won't let them die here\n";
    }
  }
  cout << "Faint static turns into large popping sounds from the intercom\n";
  if (crushed == true) {
    cout << "You shouldn't try and hide who you really are, wear it like armor "
            "and it can never be never be used to hurt you\n";
    cout << "When the scorpion stung the frog, the frog couldn't help it. It's "
            "in the frogs nature to help and it's in your nature to sting...\n";
    cout << "You cannot pretend to be somebody else, be yourself because "
            "everybody else is taken, it seems you have embraced that\n";
  } else if (crushed = false) {
    cout << "What do you think you are doing? Do you really think you can "
            "escape this place?\n";
    cout << "Do you really think you can help the innocence you have found "
            "here? Even if you do won't it just die from something else out "
            "there? Tell me isn't it better they die now in this place than "
            "out there?\n";
    cout << "You are in here for a reason, don't try and kid yourself...\n";
  }
  cout << "You are on a game show, there are three doors. Two have a goat and "
          "one have a car\n";
  cout << "The game show host knows which doors hide which objects, he tells "
          "you to pick a door. You pick one and then he goes and opens another "
          "door. A goat!\n";
  cout << "He asks you, would you like to switch your door?\n";
  cout << "there's one tablet in the center of the room\n";
  char montHall;
  win3 = false;
  while (true) {
    cin >> montHall;
    if (montHall == 'y' or montHall == 'Y' or montHall == 'n' or
        montHall == 'N') {
      break;
    }
  }
  if (montHall == 'y' or montHall == 'Y') {
    win3 = true;
  } else if (p3ch == 'N' or p3ch == 'n') {
    win3 = false;
  }
  int mHOGN = 0;
  int mHOGD = 0;
  cout << "The screen Flashes\n";
  cout << "Enter top number and bottom number of a fraction, for the "
          "proabability there is a car behind the door you chose to begin "
          "with\n";
  cout << "Enter numerator: \n";
  while (true) {
    cin >> mHOGN;
    if (!cin) {
      continue;
    } else {
      break;
    }
  }
  cout << "Enter denominator: \n";
  while (true) {
    cin >> mHOGD;
    if (!cin) {
      continue;
    } else {
      break;
    }
  }
  if (mHOGN == 1 and mHOGD == 3) {
    win3 = true;
  } else {
    win3 = false;
  }
  cout << "Enter top number and bottom number of a fraction, for the "
          "proabability there is a car behind the door you can switch to\n";
  int mHswtitchN = 0;
  int mHswitchD = 0;
  cout << "Enter the numerator: \n";
  while (true) {
    cin >> mHswtitchN;
    if (!cin) {
      continue;
    } else {
      break;
    }
  }
  cout << "Enter the denominator: \n";
  while (true) {
    cin >> mHswitchD;
    if (!cin) {
      continue;
    } else {
      break;
    }
  }
  if (mHswtitchN == 2 and mHswitchD == 3) {
    win3 = true;
  } else {
    win3 = false;
  }
  if (win3 == false) {
    cout << "Molten liquid gold sprinkles from holes on all sides of the room, "
            "it sinks you to the ground when enough is piled onto you as you "
            "burn and suffocate to death\n";
  }
}
