#include "pet.h"
#include <iostream>
using namespace std;
class butterfly : public pet{
    public:
        butterfly(string given);
        void timeToMetamorph();
        void beginMetamorphasis();
        void emergence();
    private:
        bool caterpillar;
        bool chrysalis; 
        bool butterflyStage;
        int dayCounter;
        int cacoonSet;
        int chrysalisSet;
};