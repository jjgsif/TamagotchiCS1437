//Pet class
#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;
class pet{
    public:
        pet(); //Default Constructor
        pet(string given); //Given Name

        void setNature(string in);
        void setHunger(int in);
        void setHappiness(int in);
        void setTired(int in);
        void setDayC(int in){
            dayCounter = in;
        }
        string retName(){
            return name;
        }
        
        string type(){
            return typeV;
        }

        int getHappiness(); 
        void feed(string foodType, int amount);
        void play();
        void increaseHunger(int change);
        void advanceDay(){
            cout << "How many days would you like to skip? " << endl;
            int dayNum;
            cin >> dayNum;
            dayCounter += dayNum;
            for (int i = 0; i < dayNum; i++){
            tiredness -= rand()%3;
            }
        }
        virtual string info();
        string retNature(){
            return nature;
        }
        virtual void takeFlight(){};
        virtual void timeToMetamorph(){};
        virtual void beginMetamorphasis(){};
        virtual void emergence(){};
        virtual void moltSkin(){};
        virtual void eyecap(){};
        virtual void setStage(int i){};
    protected:
        string name;
        string nature;
        int happiness;
        int hunger;
        int tiredness;
        int dayCounter;
        const map<string, string> foodMood = {

            {"sour", "impish"},
            {"sweet", "jolly"},
            {"salty", "sassy"},
            {"rich" , "naive"},
            {"bitter", "mean"}

        };
        const string natureArr[5] = {
            "impish" , "jolly", "sassy", "naive", "mean"
        };
        string typeV = "";
};

