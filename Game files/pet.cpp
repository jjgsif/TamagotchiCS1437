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
