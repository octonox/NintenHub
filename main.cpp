#include "nes.hpp"

int main(int argc, char* argv[])
{
    argc = argc; //This is just to don't have a "Unused parameter argc" warning
    argv[0] = argv[0]; //Same thing

    NES nes("essai.txt");
    nes.start();
    return 0;
}
