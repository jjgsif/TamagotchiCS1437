#include <fstream>
#include  "pet.cpp"
using namespace std;

class saveImport : protected pet{
    public:
    saveImport(string fileName);
    int loadPets();

    private:
    int petNum;
    string file;
};