#include "bat.h"

using namespace std;

bat::bat(string inName){
            name = inName;
            maxSpan = rand()%65 + 58;
            wingspan = 58;
        }
void bat::takeFlight(){
    cout << this->name << " has taken a flight and will return soon." << endl;
    this->play();
    if((1+rand()%40) ==  1){
        cout << "Your pet's wings have grown just a bit..." << endl;
        wingspan += 1;
    }
} 