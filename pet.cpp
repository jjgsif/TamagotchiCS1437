
#include <string>
#include <map>
#include "pet.h"
#include <iostream>

using namespace std;


pet::pet(){
}
pet::pet(string given){
    name = given;
}
int pet::getHappiness(){
    return happiness;
}
void pet::increaseHunger(int change){
    hunger += change;
}
void pet::feed(string foodType, int amount){
    if(nature == foodMood.at(foodType)){
        hunger -= amount * 1.5;
        if(hunger < 0){
            hunger = 0;
        }
    }
    if(nature != foodMood.at(foodType)){
        hunger -= amount * 2/3;
        if(hunger < 0){
            hunger = 0;
        }
    }
    
}
void pet::setNature(string in){
    this->nature = in;
}

void pet::setHunger(int in){
    this->hunger = in;
}

void pet::setHappiness(int in){
    this->happiness = in;
}
void pet::setTired(int in){
    this->tiredness = in;
}
void pet::play(){
    srand(time(0));
    hunger += (1 + rand()%5);
    if(hunger > 50){
        hunger = 50;
    }
    if(hunger == 50){
        cout << "Your pet had fun but is extremely hungry. (Hunger: 50)" << endl;
    } else if(hunger < 50 && hunger >= 35){
        cout << "Your pet had a good time and has developed and an appetite. (Hunger: " << hunger <<")" << endl;
    } else if(hunger < 35){
        cout << "Your pet might have overworked themselves a bit and needs a snack. (Hunger: " << hunger <<")" << endl;
    }
}
