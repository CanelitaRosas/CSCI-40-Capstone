Running EZPC pre-check on main.cc...
Warning on line: 63, character: 19
if( x == ItemX && y = ItemY){
               ~~~ ^ ~~~
Warning: You have a single equals sign inside an if statement.
This is sometimes okay, but usually you meant to write a double equals sign instead.
Remember, one equal sign is assignment, two equal signs means comparison.

GOOD: if (x == 3) {
BAD : if (x =  3) {
If your code is okay, type 'override' now, otherwise 'q' to quit: override
Overridden. You will not see this warning again for this file.
Error on line: 44, character: 18
usleep(100'000);
              ~~~ ^ ~~~
Making sure you have the appropiate amount of parentheses is crucial
to make sure that your code runs properly. You should count them again
on line 44 to make sure that they match exactly as you want
If your code is okay, type 'override' now, otherwise 'q' to quit: q
Quitting...
EZPC pre-check failed, quitting now.
No program was compiled.
mohammed_1057713 [~/CSCI-40-Capstone]% git look
git: 'look' is not a git command. See 'git --help'.

The most similar command is
        hook
mohammed_1057713 [~/CSCI-40-Capstone]% git checkout
M       README
M       bunny_demo.cc
M       main.cc
Your branch is up to date with 'origin/mohammed'.
mohammed_1057713 [~/CSCI-40-Capstone]% git checkout mohammed
M       README
M       bunny_demo.cc
M       main.cc
Already on 'mohammed'
Your branch is up to date with 'origin/mohammed'.
mohammed_1057713 [~/CSCI-40-Capstone]% ls
bunny_demo.cc  LICENSE  main.cc  README  sample_nonblocking_io.cc
mohammed_1057713 [~/CSCI-40-Capstone]% vim Combat.cc
mohammed_1057713 [~/CSCI-40-Capstone]% ls
bunny_demo.cc  LICENSE  main.cc  README  sample_nonblocking_io.cc
mohammed_1057713 [~/CSCI-40-Capstone]% vim main.cc
mohammed_1057713 [~/CSCI-40-Capstone]% vim combat.cc
mohammed_1057713 [~/CSCI-40-Capstone]% vim main.cc
mohammed_1057713 [~/CSCI-40-Capstone]% vim combat.cc
mohammed_1057713 [~/CSCI-40-Capstone]% vim main.cc
//Fill out this comment with your names and which bullet points you did
//Partners:
//Bullet Points:
//Extra Credit:
//URL to cover art and music:

/* Combat Code
* Player code from main
* Simple movement
* When item picke dup, move it off an ofset of one tile according to the player
* When item is on the same tile as enemey, add 1 to hit counter
*/

// Establishing characters

const auto [rows, cols] = get_terminal_size();
cout << rows << " " << cols << endl;


// spawns player @ coords
int x  = cols / 2;
int y = rows / 2;


// spawns enemt at 1/4, 2/4, 3/4, or 4/4 of the screen
int EnemyX = (cols * (rand() % 4)) / 4;
int EnemyY = rows / 2;

// spawns item here, just a test to see if overlap
int ItemX = cols / 3;
int ItemY = rows / 2;

// player doesnt have item by default, no hits on target
bool hasItem = false;
int hits = 0;

// Making logic

set_raw_mode(true);

int ch = quick_read();

if (ch == ERR) {
    usleep(100'000);
}

// Quits on q or Q
if (ch == 'Q' or ch == 'q') {
    break;
}

if (ch == UP_ARROW) y--;
if (ch == DOWN_ARROW) y++;
if (ch == LEFT_ARROW) x--;
if (ch == RIGHT_ARROW) x++;


y = clamp(y, 0, ROWS - 2);
x = clamp(x, 0, COLS - 2);

// If player is standing over item, hasItem = true
if (!hasItem) {
if (x == ItemX && y = ItemY) {
        hasItem = true;
    }

}

// If item touches enemy, hits++;
if (hasItem) {
    if (x == EnemyX && y == EnemyY) {
        hits++;

        // Knocks enemy back to reduce loop

        EnemyX--;
    }
}
clearscreen();

// Make Screen (WIP)
movecursor(y, x);
cout << "🐰" << endl;
}
