#include "saveImport.h"
#include <string>
using namespace std;

saveImport::saveImport(string fileName){
    ifstream saveFile(fileName);
    string file = fileName;
    if(!saveFile.good()){
        saveFile.close();
        petNum = 0;
        ofstream writeFile(fileName);
        writeFile << "Number" << endl;
        writeFile << petNum << endl;
        writeFile << endl;
        writeFile << "Pets:" << endl;
        writeFile << endl;
        writeFile.close();
    }
    
}
int saveImport::loadPets(){
    ifstream saveFile(file);
    string line;
    petNum = 0;
    for(int i = 0; getline(saveFile, line) && i < 2; i++){
        if(i == 1){
            petNum = stoi(line);
        }
    }
    saveFile.ignore();
    return petNum;
}