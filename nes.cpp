#include "nes.hpp"

NES::NES(std::string const& romfile)
{
    //We get the path of the game
    m_rom = romfile;

    //We do an dynamic allocation of the RAM
    m_ram = new char[RAMSIZE];
    for(int i {0};i < RAMSIZE;++i)
        m_ram[i] = 0x00;

    //Same thing for the Video RAM
    m_video_ram = new char[VIDEORAMSIZE];
    for(int i {0};i < VIDEORAMSIZE;++i)
        m_video_ram[i] = 0x00;

    for(int i {0};i < 3;++i)
        m_registers[i] = 0x00;

    m_status_flags = 00000000;
}

NES::~NES()
{
    delete[] m_ram;
    delete[] m_video_ram;
}

void NES::start()
{
    std::ifstream file(m_rom, std::ifstream::binary);
    if(!file)
        std::cerr << "Dump cannot be opened...\n";

    //We look for the size of the file
    file.seekg(0, file.end); //We set the cursor on the end of the file
    int lenght = file.tellg();
    if(lenght == 1) //If the file is just 1 byte, this can't be a game
    {
        std::cerr << "One byte is too few, please give a bigger file (a real file?)..." << std::endl;
        std::cerr << "Turning off the program..." << std::endl;
        exit(1);
    }

    char* buffer = new char[lenght];
    file.seekg(0, file.beg); //The cursor goes to the beginning of the file

    //We put each byte in the buffer
    file.read(buffer, lenght);

    //Now comes the time of interpretation

    delete[] buffer;
    file.close();
}
