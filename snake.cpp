#include "snake.h"

using namespace std;

snake::snake(string given){
        name = given;
          toMolt = 29 + rand()%3;
}
void snake::moltSkin(){
    if(toMolt == 0){
        cout << this->name << " is starting to molt, its eye cap may get stuck." << endl;
    }else{
        cout << this->name << " isn't ready to molt yet, " << toMolt << " day until it can molt." << endl;
    }
    srand(time(0));
    if((1+rand()%5) == 1){
        eyecapStuck = true;
        cout << "Eye cap is stuck! It needs help to remove the eyecap." << endl;
        }
}
        void eyecap();