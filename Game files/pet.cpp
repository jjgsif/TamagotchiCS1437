#include "pet.h"
using namespace std;
#include <iostream>;
class pet{
    pet(){
        cout << "Please enter name: ";
        cin >> name;
    }
    pet(string given){
        name = given;
    }
}