#include "limedds.h"
#include "dds_regs.h"

LimeDDS::LimeDDS() :
    LimeSDRDevice(), m_sample_rate(5.0e6)
{
		
}

LimeDDS::~LimeDDS()
{
	
}

int LimeDDS::setBit(int p_reg, int p_val, int p_bit)
{
    if(p_val)
    {
        p_reg |= (1 << p_bit);
    }
    else
    {
        p_reg &=~ (1 << p_bit);
    }
    return p_reg;
}

void LimeDDS::setTxMux (int p_mode)
{
    int reg = LimeSDRDevice::readReg("BBIC", DDS_MUX);
    LimeSDRDevice::writeReg("BBIC", DDS_MUX, setBit(reg, p_mode, DDS_TX_SEL));
}

void LimeDDS::setRxMux (int p_mode)
{
    int reg = LimeSDRDevice::readReg("BBIC", DDS_MUX);
    LimeSDRDevice::writeReg("BBIC", DDS_MUX, setBit(reg, p_mode, DDS_RX_SEL));
}

void LimeDDS::setTaylor (int p_mode)
{
    int reg = LimeSDRDevice::readReg("BBIC", DDS_CONTROL);
    LimeSDRDevice::writeReg("BBIC", DDS_CONTROL, setBit(reg, p_mode, DDS_TAYLOR_EN));
}

void LimeDDS::setDithering (int p_mode)
{
    int reg = LimeSDRDevice::readReg("BBIC", DDS_CONTROL);
    if(p_mode == LimeDDS::DITH_OFF)
    {
        reg = setBit(reg, 0, DDS_PH_DITH_EN);
        reg = setBit(reg, 0, DDS_TR_DITH_EN);
    }
    else if(p_mode == LimeDDS::DITH_PHASE)
    {
        reg = setBit(reg, 1, DDS_PH_DITH_EN);
    }
    else if(p_mode == LimeDDS::DITH_TRUNCATION)
    {
        reg = setBit(reg, 1, DDS_TR_DITH_EN);
    }
    else
    {
        reg = setBit(reg, 0, DDS_PH_DITH_EN);
        reg = setBit(reg, 0, DDS_TR_DITH_EN);
    }
    LimeSDRDevice::writeReg("BBIC", DDS_CONTROL, reg);
}

void LimeDDS::setSweepMode (int p_mode)
{
    int reg = LimeSDRDevice::readReg("BBIC", DDS_CONTROL);
    if(p_mode == LimeDDS::SWEEP_OFF)
    {
        reg = setBit(reg, 0, DDS_SWEEP_EN);
        reg = setBit(reg, 0, DDS_SWEEP_UP_DOWN);
    }
    else if(p_mode == LimeDDS::SWEEP_UP)
    {
        reg = setBit(reg, 1, DDS_SWEEP_EN);
        reg = setBit(reg, 0, DDS_SWEEP_UP_DOWN);
    }
    else
    {
        reg = setBit(reg, 1, DDS_SWEEP_EN);
        reg = setBit(reg, 1, DDS_SWEEP_UP_DOWN);
    }
    LimeSDRDevice::writeReg("BBIC", DDS_CONTROL, reg);
}

void LimeDDS::setSweepRate (float p_rate)
{
    double factor = m_sample_rate * m_sample_rate / std::pow(2, 31); //frequency resolution (32-Bit phase accu)
    double rate_d = p_rate / factor;
    unsigned int rate = (unsigned int) rate_d;
    unsigned int rate_h = (0xFFFF0000 & rate) >> 16;
    unsigned int rate_l = (0x0000FFFF & rate) >> 0;
    LimeSDRDevice::writeReg("BBIC", DDS_SWEEP_RATE_H, rate_h);
    LimeSDRDevice::writeReg("BBIC", DDS_SWEEP_RATE_L, rate_l);
}

void LimeDDS::setTxSampRate(double p_rate, int p_chan)
{
    std::cout << "LimeDDS setTxSampRate" << std::endl;
    m_sample_rate = p_rate;
    LimeSDRDevice::setTxSampRate(p_rate, p_chan);
}

void LimeDDS::setFrequency (float p_freq, int p_chan)
{
    double freq_res = m_sample_rate / std::pow(2, 32); //frequency resolution (32-Bit phase accu)
    std::cout << "Sample Rate: " << m_sample_rate << " Frequency: " << p_freq << std::endl;
    int freq = (int) p_freq / freq_res;
    int freq_h = (0xFFFF0000 & freq) >> 16;
    int freq_l = (0x0000FFFF & freq) >> 0;

    if(p_chan == FREQ_BOT)
    {
        LimeSDRDevice::writeReg("BBIC", DDS_BOT_FTW_H, freq_h);
        LimeSDRDevice::writeReg("BBIC", DDS_BOT_FTW_L, freq_l);
    }
    else if (p_chan == FREQ_TOP)
    {
        LimeSDRDevice::writeReg("BBIC", DDS_TOP_FTW_H, freq_h);
        LimeSDRDevice::writeReg("BBIC", DDS_TOP_FTW_L, freq_l);
    }
}

float LimeDDS::getMaxFrequency (void)
{
    return m_sample_rate;
}
