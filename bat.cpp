#include "bat.h"

using namespace std;

bat::bat(string inName){
        name = inName;
        maxSpan = rand()%8 + 58;
        wingspan = 58;
        typeV = "bat";
        dayCounter = 0;
        happiness = 20;
        hunger = 10;
        nature = natureArr[rand()%5];
        tiredness = 5 +rand()%3;
}
void bat::takeFlight(){
    cout << this->name << " has taken a flight and will return soon." << endl;
    this->play();
    if((1+rand()%40) ==  1){
        cout << "Your pet's wings have grown just a bit..." << endl;
        wingspan += 1;
    }
} 