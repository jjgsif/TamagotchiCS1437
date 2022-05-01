#include "pet.h"
using namespace std;

class snake : public pet{
    public:
        snake();
        snake(string given);
        void moltSkin();
        void eyecap();
    private:
        int toMolt;
        bool eyecapStuck;
};