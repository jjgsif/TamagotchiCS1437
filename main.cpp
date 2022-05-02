

#include <fstream>
#include <string>
#include <iostream>
#include "pet.cpp"
#include "bat.cpp"
#include "snake.cpp"
#include "butterfly.cpp"
#include <vector>

using namespace std;


void options(pet*);
void createPet(vector<pet*>& vect);
void whichPet(vector<pet*>& vect,string fileName);
void saveFile(string filename, vector<pet*>& vect);
void startFeed(pet* givenPet);

int main(){
    cout << "--------Farm House--------" << endl;
    cout<< endl << endl;
    cout << "       Menu Choices: " << endl;
    cout << "==========================" << endl;
    cout << "1. Open Save File" << endl;
    cout << "2. New Save File" << endl;
    vector<pet*> petVect;
    pet* petN;
    int answer;
    cin >> answer;
    if(answer == 1){
        cout << "Enter local save file name: "<< endl;
        string fileName;
        cin >> fileName;
        fstream file(fileName);
        int petNum;
        file >> petNum;   
        string line;
        string name;
        int placeholder;
        try{
        for(int i = 0; i<petNum; i++){
            file >> name;
            for(int j = 0; j < 7; j++){
                
                switch(j){
                    case 0: file >> line;while(line == "|"){file >> line;}if(line == "butterfly"){petN = new butterfly(name);petVect.push_back(petN);} else if(line == "bat"){petN = new bat(name);petVect.push_back(petN);}else if(line == "snake"){petN = new snake(name); petVect.push_back(petN);}break;
                    case 1: file >> line;while(line == "|"){file >> line;}petVect.at(i)->setNature(line); break;
                    case 2: file >> line;while(line == "|"){file >> line;}placeholder= stoi(line); petVect.at(i)->setHunger(placeholder); break;
                    case 3: file >> line;while(line == "|"){file >> line;}placeholder= stoi(line); petVect.at(i)->setHappiness(placeholder); break;
                    case 4: file >> line;while(line == "|"){file >> line;}placeholder= stoi(line); petVect.at(i)->setTired(placeholder); break;
                    case 5: file >> line;while(line == "|"){file >> line;}placeholder= stoi(line); petVect.at(i)->setDayC(placeholder);break;
                    case 6: if(petVect.at(i)->type() =="butterfly"){file >> line;while(line == "|"){file >> line;} placeholder = stoi(line); petVect.at(i)->setStage(placeholder);}break;
                }
            }
        }
        }catch(exception e){
            cout<< "something wrong";
            exit(-1);
        }
        whichPet(petVect,fileName);
        exit(1);
    }else if (answer == 2){
        string fileName;
        cout<<"Enter new save name:" << endl;
        cin >> fileName;
        fstream newFile(fileName);
        cout << fileName << " created." << endl;
        createPet(petVect);
        whichPet(petVect, fileName);

    }else if (answer != 1 || answer != 2){
        cout << endl;
        cout << "Not a menu option. Exiting Game"<< endl;
        exit(-1);
    }

   
}

void whichPet(vector<pet*> &petVect,string fileName){
        int petNum;
        bool interact = true;
        int answer;
        while(interact){
            petNum = petVect.size();
            cout << "Choose which pet you want to interact with or to save all pets: (Enter a number out of range to exit)" << endl;
            for(int i = 0; i < petNum; i++){
                cout << i+1 << ". " << petVect.at(i)-> retName() << " - " << petVect.at(i)->type() << endl;
            }
            cout << petVect.size()+1 << ". Save all pets" << endl;
            cout << petVect.size()+2 << ". Create new pet" << endl;
            cin >> answer;
            if(answer-1 > petNum+1){
                interact = false;
            }
            if ((answer-1) < petNum){
                options(petVect.at(answer -1));
            }
            if(answer-1 == petNum){
                saveFile(fileName, petVect);
            }
            if((answer-1) == petNum+1){
                createPet(petVect);
            }
        }
}

void options(pet* givenPet){ //Feed,Play,Advance, and special interactions
    bool stay = true;
    int answer;
    if(givenPet->type() == "snake"){
        while(stay){
        cout << "Snake name: " << givenPet->retName() << endl;
        cout << "Available activities and interactions: " << endl;
        cout << "1. Feed " << endl;
        cout << "2. Play " << endl;
        cout << "3. Assist with shedding skin" << endl;
        cout << "4. Assist with Eye cap removal" << endl;
        cout << "5. Advance day" << endl;
        cout << "6. Return to last menu" << endl;
        cin >> answer;
        switch(answer){
            case 1: startFeed(givenPet); break;
            case 2: givenPet->play(); break;
            case 3: givenPet->moltSkin();break;
            case 4: givenPet->eyecap(); break;
            case 5: givenPet->advanceDay(); break;
            case 6:stay = false; break;
        }
        }
    }
    if(givenPet->type() == "butterfly"){
        while(stay){
        cout << "Butterfly name: " << givenPet->retName() << endl;
        cout << "Available activities and interactions: " << endl;
        cout << "1. Feed " << endl;
        cout << "2. Play " << endl;
        cout << "3. Check time to metamorphasis" << endl;
        cout << "4. Begin Metamorphasis" << endl;
        cout << "5. Assist with emergence" << endl;
        cout << "6. Advance day" << endl;
        cout << "7. Return to last menu" << endl;
        cin >> answer;
        switch(answer){
            case 1: startFeed(givenPet); break;
            case 2: givenPet->play(); break;
            case 3: givenPet->timeToMetamorph(); break;
            case 4: givenPet->beginMetamorphasis();break;
            case 5: givenPet->emergence(); break;
            case 6: givenPet-> advanceDay(); break;
            case 7:stay = false; break;
        }
        }
    }
    if(givenPet->type() == "bat"){
        while(stay){
        cout << "Bat name: " << givenPet->retName() << endl;
        cout << "=======================================" << endl;
        cout << "Available activities and interactions: " << endl;
        cout << "1. Feed " << endl;
        cout << "2. Play " << endl;
        cout << "3. Advance day " << endl;
        cout << "4. Return to last menu" << endl;
        cin >> answer;
        switch(answer){
            case 1: startFeed(givenPet); break;
            case 2: givenPet->takeFlight(); break;
            case 3: givenPet-> advanceDay(); break;
            default: stay = false;  break;
        }
    }
    }
}

void createPet(vector<pet*> &vect){
    cout << endl;
    cout << "Welcome to the pet creator! What species of pet would you like?" << endl;
    cout << "You can choose between a snake, butterfly, and bat. \n(Type anything other than a species to esacpe)" << endl;
    string answer;
    cin >> answer;
    if(answer == "snake"){
        cout << "What would you like your snake's name to be?" << endl;
        cin >> answer;
        vect.push_back(new snake(answer));
    } else if(answer == "butterfly"){
        cout << "What would you like your butterfly's name to be?" << endl;
        cin >> answer;
        vect.push_back(new butterfly(answer));
    } else if(answer == "bat"){
        cout << "What would you like your bat's name to be?" << endl;
        cin >> answer;
        vect.push_back(new bat(answer));
    }
    cout << "Pet created! You may now interact with your new pet." << endl;
}

void saveFile(string fileName, vector<pet*>& vect){
    int n = fileName.length();
    char* filename = new char[n+1];
    strcpy(filename, fileName.c_str());
    remove(filename);
    fstream writeF(fileName);
    writeF << vect.size() << endl;
    for(int i = 0; i < vect.size(); i++){
        writeF << vect.at(i)->info() << endl;
    }
    cout << "Pets are saved!" << endl;

}

void startFeed(pet* givenPet){
    cout << "Explanation: if your pet's nature and the food's flavor match, \nhunger will be lower dramatically." << endl;
    cout << endl;
    cout << givenPet->retName() << " nature: " << givenPet->retNature() << endl;
    cout << "Options:" << endl;
    cout << "=====================" << endl;
    cout << "1. Meat pie (rich)" << endl;
    cout << "2. Orange slices (sour)" << endl;
    cout << "3. Grapefruit (bitter)" << endl;
    cout << "4. French fries (salty)" << endl;
    cout << "5. Apple (sweet)" << endl;
    int answer;
    cin >> answer;
    int amount = 1+rand()%15;
    switch(answer){
        case 1: givenPet->feed("rich", amount); break;
        case 2: givenPet->feed("sour", amount); break;
        case 3: givenPet->feed("bitter", amount);break;
        case 4: givenPet->feed("salty",amount); break;
        case 5: givenPet->feed("sweet", amount); break;
    }
}

