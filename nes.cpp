#include "nes.hpp"

NES::NES(std::string const& dumpfile)
{
    m_dump = dumpfile;

    m_ram = new char[RAMSIZE];
    for(int i {0};i < RAMSIZE;++i)
        m_ram[i] = 0x00;

    m_video_ram = new char[VIDEORAMSIZE];
    for(int i {0};i < VIDEORAMSIZE;++i)
        m_video_ram[i] = 0x00;
}

NES::~NES()
{
    delete[] m_ram;
    delete[] m_video_ram;
}
