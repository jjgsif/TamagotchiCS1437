#include <string>
#include <map>
#include "pet.h"

using namespace std;
#include <iostream>;

pet::pet(){
    cout << "Please enter name: ";
    cin >> name;
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
    if(nature == foodMood.at(foodType)){
        hunger -= amount * 2/3;
        if(hunger < 0){
            hunger = 0;
        }
    }
    
}
void pet::setNature(string in){
    nature = in;
}

void pet::setHunger(int in){
    hunger = in;
}

void pet::setHappiness(int in){
    happiness = in;
}
void pet::setTired(int in){
    tiredness = in;
}
