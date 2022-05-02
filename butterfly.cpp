#include "butterfly.h"

butterfly::butterfly(string given){
    pet(given);
    caterpillar = true;
    srand(time(0));
}
void butterfly::timeToMetamorph(){
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
void butterfly::beginMetamorphasis(){
    chrysalis = true;
    caterpillar = false;
    chrysalisSet = 3 + rand()%3;
    cout << this->name << " will be in a chrysalis for " << chrysalisSet << " days." << endl;
}
void butterfly::emergence(){
    butterflyStage = true;
    chrysalis = false;
    cout << "Congratulations! " << this->name << " has become a butterfly." << endl;
}