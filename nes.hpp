#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

#define RAMSIZE 2000
#define VIDEORAMSIZE 32000

class NES
{
public:
    NES(std::string const& dumpfile); //Init the RAM and the Video RAM but doesn't start the game
    ~NES(); //Delete the RAM and the Video RAM

    void start(); //Start the game

private:
    char* m_ram;
    char* m_video_ram;
    std::string m_dump; //The way to go to the video game dump
};
