#include "pet.h"
#include <iostream>
using namespace std;

class snake : public pet{
    public:
        snake(string given);
        void moltSkin();
        void eyecap();
    private:
        int toMolt;
        bool eyecapStuck;
};