//Loader Class - Loads Assets and files

#include <fstream>
#include <string>
#include <iostream>
#include "saveImport.h"

using namespace std;
saveImport saveFile();


int main(){
    cout << "--------Farm House--------" << endl;
    cout<< endl << endl;
    cout << "Menu Choices: " << endl;
    cout << "==========================" << endl;
    cout << "1. Open/New Save File" << endl;
    int answer;
    cin >> answer;
    if(answer == 1){
        saveImport file = saveFile();
    }else{
        cout << endl;
        cout << "Not a menu option. Exiting Game";
        exit(-1);
    }

   
}

saveImport saveFile(){
    string answer;
    string fileName;
    cout << "Would you like to open a save file? (Y/N)" << endl;
    cin >> answer;
    cout << endl;
    if (answer == "Y" || answer == "y"){
        cout << "What is the file name?" << endl;
        cin >> fileName;
        saveImport loadFile(fileName);
        return loadFile;
    }else if(answer == "n" || answer == "N"){
        cout << "What would you like the file name to be?" << endl;
        cin >> fileName;
        saveImport newFile(fileName);
        return newFile;
    }

}
