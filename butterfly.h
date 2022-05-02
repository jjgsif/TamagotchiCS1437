#include "pet.h"
#include <iostream>
using namespace std;
class butterfly : public pet{
    public:
        butterfly(string given);
        void timeToMetamorph();
        void beginMetamorphasis();
        void emergence();
        void setStage(int i){
            switch (i){
                case 0: caterpillar = true; chrysalis = false; butterflyStage =false; break;
                case 1: chrysalis = true; caterpillar =false; butterflyStage =false; break;
                case 2: butterflyStage = true; caterpillar = false; chrysalis = false; break;
            }
        }
string info(){
    stringstream ss;
        if(caterpillar){
            ss <<  name << " | " << typeV << " | " + nature  << " | " << happiness << " | " << hunger << " | " << tiredness << " | " << dayCounter << " | " << 0;
        } else if (chrysalis){
            ss <<  name << " | " << typeV << " | " + nature  << " | " << happiness << " | " << hunger << " | " << tiredness << " | " << dayCounter << " | " << 1;
        }else if (butterflyStage){
            ss <<  name << " | " << typeV << " | " + nature  << " | " << happiness << " | " << hunger << " | " << tiredness << " | " << dayCounter << " | " << 2;
        }
        return ss.str();
}
    private:
        bool caterpillar;
        bool chrysalis; 
        bool butterflyStage;
        int cacoonSet;
        int chrysalisSet;
};