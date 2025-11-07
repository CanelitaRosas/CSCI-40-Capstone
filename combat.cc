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
