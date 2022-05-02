#include "pet.h"
#include <iostream>
using namespace std;

class snake : public pet{
    public:
        snake(string given);
        void moltSkin();
        void eyecap();
        void setStage(int i){
            if (i == 1){
                eyecapStuck = true;
            }
        }
        
    private:
        int toMolt;
        bool eyecapStuck;
};