/*File who define the NES class (NES emulator) and informations about features of NES*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <bitset>

#define RAMSIZE 2000
#define VIDEORAMSIZE 32000

//We don't use the sack pointer and the status register is a bitset
enum class registers
{
    A,
    X,
    Y
};

class NES
{
public:
    NES(std::string const& romfile); //Init the RAM and the Video RAM but doesn't start the game
    ~NES(); //Delete the RAM and the Video RAM

    void start(); //Start the game

private:
    char* m_ram;
    char* m_video_ram;
    std::string m_rom; //The way to go to the ROM
    char m_registers[3];
    std::bitset<8> m_status_flags;
};
