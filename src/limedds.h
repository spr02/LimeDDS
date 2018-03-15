#ifndef LIMEDDS_H
#define LIMEDDS_H

#include <complex>
#include <QString>
#include <QThread>

#include "limesdrdevice.h"

class LimeDDS : public LimeSDRDevice
{
public:

    /////////////////////// FACTORY ////////////////////////
    LimeDDS();
    ~LimeDDS();

    ////////////////////// CONTROL /////////////////////////
    void setTxMux (int p_mode);
    void setRxMux (int p_mode);

    void setTaylor (int p_mode);
    void setDithering (int p_mode);

    void setSweepMode (int p_mode);
    void setSweepRate (float p_rate);

    void setFrequency (float p_freq, int p_chan);

    float getMaxFrequency (void);

    ////////////////////// HELPER //////////////////////////
    int setBit (int p_reg, int p_val, int p_bit);

    ////////////////////// OVERRIDE ////////////////////////
    void setTxSampRate(double p_rate, int p_chan = 0);

    /////////////////// DDS CONSTANTS //////////////////////

    static const int DDS_OFF = 0x00;
    static const int DDS_ON = 0x01;

    static const int SWEEP_OFF = 0x00;
    static const int SWEEP_UP = 0x01;
    static const int SWEEP_UP_DOWN = 0x03;

    static const int FREQ_BOT = 0x00;
    static const int FREQ_TOP = 0x01;

    static const int DITH_OFF = 0x00;
    static const int DITH_TRUNCATION = 0x01;
    static const int DITH_PHASE = 0x02;
    static const int DITH_BOTH = 0x03;

private:
    double m_sample_rate;

};

#endif // LIMEDDS_H
