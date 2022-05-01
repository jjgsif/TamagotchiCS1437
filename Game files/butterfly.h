#include "pet.h"
#include <iostream>
using namespace std;
class butterfly : public pet{
    public:
        butterfly(string given){
            pet(given);
            caterpillar = true;
            srand(time(0));
        }
        void timeToMetamorph(){
            cacoonSet =  10 + rand()%(5);
            cout << cacoonSet - dayCounter << " days until " << this->name <<" can go into its chrysalis. " << endl;
            if((cacoonSet-dayCounter) == 0){
                cout << "Would you like to allow your caterpillar to begin its metamorphasis? (Yes/No) ";
                string answer;
                cin >> answer;
                if(answer == "yes" || answer == "Yes"){
                    this->beginMetamorphasis();
                }
            }
        }
        void beginMetamorphasis(){
            chrysalis = true;
            caterpillar = false;
            chrysalisSet = 3 + rand()%3;
            cout << this->name << " will be in a chrysalis for " << chrysalisSet << " days." << endl;
        }
        void emergence(){
            butterflyStage = true;
            chrysalis = false;
            cout << "Congratulations! " << this->name << " has become a butterfly." << endl;
        }
    private:
        bool caterpillar;
        bool chrysalis; 
        bool butterflyStage;
        int dayCounter;
        int cacoonSet;
        int chrysalisSet;
};