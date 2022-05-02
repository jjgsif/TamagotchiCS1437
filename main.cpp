//Loader Class - Loads Assets and files

#include <fstream>
#include <string>
#include <iostream>
#include "pet.cpp"
#include "bat.cpp"
#include "snake.cpp"
#include "butterfly.cpp"


using namespace std;




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
        pet** petArr =  new pet*[petNum];     
        string line;
        string name;
        int placeholder;
        for(int i = 0; i<petNum; i++){
            getline(file,name,'|');
            for(int j = 0; j < 5; j++){
                getline(file,line,'|');
                switch(j){
                    case 0: if(line == "butterfly"){petArr[i] = new butterfly(name);} else if(line == "bat"){petArr[i] = new bat(name);}else if(line == "snake"){petArr[i] = new snake(name);}break;
                    case 1: petArr[i]->setNature(line); break;
                    case 2: placeholder= stoi(line); petArr[i]->setHunger(placeholder); break;
                    case 3: placeholder= stoi(line); petArr[i]->setHappiness(placeholder); break;
                    case 4: placeholder= stoi(line); petArr[i]->setTired(placeholder); break;
                }
            }
        }
        cout << "Pets loaded" << endl;
        exit(1);
    }else if (answer == 2){
        string fileName;
        cout<<"Enter new save name:" << endl;
        cin >> fileName;
        ofstream newFile(fileName);
        cout << fileName << " created." << endl;
        exit(1);
    }else if (answer != 1 || answer != 2){
        cout << endl;
        cout << "Not a menu option. Exiting Game";
        exit(-1);
    }

   
}





