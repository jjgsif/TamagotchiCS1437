#include "butterfly.h"

butterfly::butterfly(string given){
    name = given;
    caterpillar = true;
    srand(time(0));
    typeV = "butterfly";
    cacoonSet =  10 + rand()%(5);
    chrysalisSet = 3 + rand()%3;
    dayCounter = 0;
    happiness = 20;
    hunger = 10;
    nature = natureArr[rand()%5];
    tiredness = 5 +rand()%3;
    
}
void butterfly::timeToMetamorph(){
    
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
    if(cacoonSet-dayCounter==0){
    chrysalis = true;
    caterpillar = false;
    
    cout << this->name << " will be in a chrysalis for " << chrysalisSet << " days." << endl;
    dayCounter = 0;
    }else{
        cout << name << " is not ready to go into the cacoon yet." << endl;
    }
}
void butterfly::emergence(){
    if(chrysalisSet - dayCounter == 0){
        butterflyStage = true;
        chrysalis = false;
        cout << "Congratulations! " << this->name << " has become a butterfly." << endl;
    } else {
        cout << name << "is still in their chrysalis for another " << chrysalisSet-dayCounter << " days." << endl;
    }
    
}