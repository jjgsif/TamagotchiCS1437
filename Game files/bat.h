#include "pet.h"
using namespace std;

class bat : public pet{
    public:
        bat(string name){
            pet(name);
            maxSpan = rand()%65 + 58;
            wingspan = 58;
        }
        void takeFlight();
    private:
        int wingspan;
        int maxSpan;
};