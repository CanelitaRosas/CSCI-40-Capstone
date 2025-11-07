//Rosas-Puzzles,Inv,I/o,Dialogue
//Partners:Gregory(I/o)
//Bullet Points:3 
//Extra Credit: 1,3
//URL to cover art and music: 
#include <iostream>
#include <vector>
using namespace std;
//puzzles
//Billiard ball room 
/*the correct solution to this common puzzle is to take a "less is more" appoach 
put three billaird balls on each side of the scale, if those are equal then take the three you left 
and put two on each side and leave one out. If they arent equal take the side thats tipped and 
do the same.
*/
int main(){
    cout<< "You walk into a billiard ball room this is strange!\n";
    cout << "You see two rectanglular platforms  with a large screen that sits in the middle of them\n"
    cout << "there are nine identical in appearance balls that are laid before you behind some thick glass \n";
    cout << "you walked right into my trap! BAHAHAHAHA\n";
    cout << "ahem if youre simple minded self could see even two steps ahead of yourself then youd have noticed my elementary attempt to trap you, you simpleton! bahahahah\n";
    cout<< "You'll have to use your simpleton mind to try and escape instead of just being a bonheaded brute for once, something that likely landed you here in the first place!\n";
    cout << "try and keep up! Before you there lay platforms with a screen between them and 9 identical balls as you likely have not even noticed ";
    cout << "the scale is rigged such that if youre simpleton self tried to make more than two weigh ins the room will blow up, if you try to game the system the room will blow up\n";
    cout << "there is an imposter amongst the balls much like you are amongst people you animal, it's why you're after all!\n";
    cout << "the imposter ball can only be recongnized by a scale it weighs just a miniscule amount more than the other balls which are identical in weight, it hides amongst the other balls the same way you hide among people. You see simpleton the imposter can not be spotted with the naked eye or felt out of the group with touch\n";
    cout << "the ball must be sniffed out by something made to expose it.... the scale and screen\n";
    cout << "remember simpleton... you have two weigh ins and if you try any simpleton like things that are sneaky or try a single thing out of the oridnary I will blow you up happily, naturally there are other rules of course but i'll not waste my time on such a stain of a person\n";
    cout << "what you will do is go to the screen between them and pick a number for each scale and that number will represent the amount of balls it will randomly select from, so if you choose 1 on the right scale and 1 on the left then they will be randomly selected now here's an importnat part so listen up. The screen will then flash and ask you how many balls for the second weigh in, if you try for a third time you will die here. oh and Just so luck does not play a factor in your solution the computer in the screen will then simulate your solution 100 times and if your percent accuracy of finding the imposter isnt 100 percent guess what? you die here. If I deem your solution smart enough you earn your freedom.... to the next room and test that is BAHAHAHA\n";
    cout <<"such a simpleton like you should take all the time he needs, oh yeah and if you somehow prove yourself you will earn a rose. GO!";
    boo win = false;
    int weighLeft1 = 0;
    int weighRight1 = 0;
    int weighLeft2 = 0;
    int weighRight2 = 0;
    // we assume the player walks up to the screen here
    cout << "input choice for the left side\n";
    cin>>weighLeft1;
    if(!cin){
        //death
        cout << "YOU PERSIHED, I bet you don't even hear it when it happens right?\n";
        return 0;
    }
    else {
        cout << "input choice for right side\n";
        cin >> weighRight1;
        if(!cin){
        //death
        cout << "YOU PERSIHED, I bet you don't even hear it when it happens right?\n";
        return 0;
    }
    }
    cout << "the screen flashes round 2, AGAIN\n";
     cout << "input choice for the left side\n";
    cin>>weighLeft2;
    if(!cin){
        //death
        cout << "YOU PERSIHED, I bet you don't even hear it when it happens right?\n";
        return 0;
    }
    else {
        cout << "input choice for right side\n";
        cin >> weighRight2;
        if(!cin){
        //death
        cout << "YOU PERSIHED, I bet you don't even hear it when it happens right?\n";
        return 0;
    }
    }
    if (weighLeft1 == 3 and weighRight1 == 3){
        win = true;
    }
    if (weighLeft2 != 1 and weighRight2 !=1){
        win = false;
    }
    if (win == false ){
        cout << "The lights go dark, you can't tell if your eyes are open or you're dead.... a deafening explosion rings your ears and you are obliterated\n"
        cout << "YOU PERISHED";
    }
