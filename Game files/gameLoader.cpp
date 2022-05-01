//Loader Class - Loads Assets and files

#include <fstream>
#include <string>
#include <iostream>
#include "bat.h"
#include "snake.h"
#include "butterfly.h"
#include <vector>
#include <variant>

using namespace std;

pet *petArr;


int main(){
    cout << "--------Farm House--------" << endl;
    cout<< endl << endl;
    cout << "Menu Choices: " << endl;
    cout << "==========================" << endl;
    cout << "1. Open Save File" << endl;
    cout << "2. New Save File" << endl;
    int answer;
    cin >> answer;
    if(answer == 1){
        cout << "Enter local save file name: "<< endl;
        string fileName;
        cin >> fileName;
        ifstream file(fileName);
        int petNum;
        file >> petNum; 
        pet* petArr = new pet[petNum];
        string traits[5];
        string line;
        string name;
        int placeholder;
        for(int i = 0; i<petNum; i++){
            getline(file,name,'|');
            for(int j = 0; j < 5; j++){
                switch(j){
                    case 0: getline(file, line,'|'); if(line == "butterfly"){petArr[i] = butterfly(name);} else if(line == "bat"){petArr[i] = bat(name);}else if(line == "snake"){petArr[i] = snake(name);}break;
                    case 1: getline(file,line,'|'); petArr[i].setNature(line);
                    case 2: getline(file,line,'|'); placeholder= stoi(line); petArr[i].setHunger(placeholder); break;
                    case 3: getline(file,line,'|'); placeholder= stoi(line); petArr[i].setHappiness(placeholder); break;
                    case 4: getline(file,line,'|'); placeholder= stoi(line); petArr[i].setTired(placeholder); break;
                }
            }
        }
    }else if (answer == 2){
        string fileName;
        cout<<"Enter new save name:" << endl;
        cin >> fileName;
        ofstream newFile(fileName);
        cout << fileName << " created." << endl;
        exit(1);
    }else{
        cout << endl;
        cout << "Not a menu option. Exiting Game";
        exit(-1);
    }

   
}





