#include "pet.h"
#include <iostream>
using namespace std;

class snake : public pet{
    public:
        snake(string given){
            pet(given);
            toMolt = 29 + rand()%3;
        }
        void moltSkin(){
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
    private:
        int toMolt;
        bool eyecapStuck;
};