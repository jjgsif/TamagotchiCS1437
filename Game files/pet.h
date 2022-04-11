//Pet class
#include <string>
using namespace std;
class pet{
    public:
        pet(); //Default Constructor
        pet(string given); //Given Name
        int getHappiness(); 
        void feed(int foodType, int amount);
        void play(int type);
    private:
        string state;
        string name;
        int happiness;
        int hunger;
};