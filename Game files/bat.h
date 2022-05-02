#include "pet.h"
#include <iostream>
using namespace std;

class bat : public pet{
    public:
        bat(string name){
            pet(name);
            maxSpan = rand()%65 + 58;
            wingspan = 58;
        }
        void takeFlight(){
            cout << this->name << " has taken a flight and will return soon." << endl;
            this->play();
            if((1+rand()%40) ==  1){
                cout << "Your pet's wings have grown just a bit..." << endl;
                wingspan += 1;
            }
        }        
    private:
        int wingspan;
        int maxSpan;
};