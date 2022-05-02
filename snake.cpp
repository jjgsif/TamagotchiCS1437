#include "snake.h"

using namespace std;

snake::snake(string given){
        name = given;
        toMolt = 29 + rand()%3;
        typeV = "snake";
        dayCounter = 0;
        happiness = 20;
        hunger = 10;
        nature = natureArr[rand()%5];
        tiredness = 5 +rand()%3;
}
void snake::moltSkin(){
    int toMoltCur = toMolt - dayCounter;
    if(toMoltCur == 0){
        cout << this->name << " is starting to molt, its eye cap may get stuck." << endl;
        dayCounter = 0;
        toMolt = 29 + rand()%3;
    }else{
        cout << this->name << " isn't ready to molt yet, " << toMoltCur << " day(s) until it can molt." << endl;
    }
    srand(time(0));
    if((1+rand()%5) == 1){
        eyecapStuck = true;
        cout << "Eye cap is stuck! It needs help to remove the eyecap." << endl;
        }
}
void snake::eyecap(){
    if(eyecapStuck){
        cout << name << " is having trouble with their eyecap, would you like to assist? (Yes/No)" << endl;
        string answer;
        cin >> answer;
        if(answer == "yes" || answer == "Yes" || answer == "y"){
            srand(time(0));
            if(1 == rand()%4 + 1){
                cout << name << " wouldn't let you help... guess you'll have to try again later." << endl;
            } else {
                cout << "You got the eyecap off! " << name << " feels much better. " << endl;
                eyecapStuck =false;
            }
            
        }else{
            cout << name << " is still having trouble with their eyecap..." << endl;
        }
    }else {
        cout << name <<"'s eyecap isn't stuck at the moment." << endl;
    }
    cout << endl;
}