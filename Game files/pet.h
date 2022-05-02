//Pet class
#include <string>
#include <map>
using namespace std;
class pet{
    public:
        pet(); //Default Constructor
        pet(string given); //Given Name

        void setNature(string);
        void setHunger(int);
        void setHappiness(int);
        void setTired(int);

        

        int getHappiness(); 
        void feed(string foodType, int amount);
        void play();
        void increaseHunger(int change);
    protected:
        string name;
        string nature;
        int happiness;
        int hunger;
        int tiredness;
        map<string, string> foodMood = {

            {"sour", "impish"},
            {"sweet", "jolly"},
            {"salty", "sassy"},
            {"rich" , "naive"},
            {"bitter", "mean"}

        };
        
};

