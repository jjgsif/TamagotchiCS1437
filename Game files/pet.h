//Pet class
#include <string>
#include <map>
using namespace std;
class pet{
    public:
        pet(); //Default Constructor
        pet(string given); //Given Name
        int getHappiness(); 
        void feed(string foodType, int amount);
        void play(int type);
    private:
        string state;
        string name;
        string nature;
        int happiness;
        int hunger;
        map<string, string> foodMood = {
            {"sour", "impish"},
            {"sweet", "jolly"},
            {"salty", "sassy"},
            {"rich" , "naive"},
            {"bitter", "mean"}

        };
        
};

