#include "pet.h"
#include <iostream>
using namespace std;

class bat : public pet{
    public:
        bat(string name);
        void takeFlight();       
    private:
        int wingspan;
        int maxSpan;
};