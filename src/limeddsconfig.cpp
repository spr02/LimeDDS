#include "limeddsconfig.h"
#include "ui_limeddsconfig.h"

limeddsconfig::limeddsconfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::limeddsconfig)

{
    ui->setupUi(this);
}

limeddsconfig::~limeddsconfig()
{
    delete ui;
}


//////////////////// setter and getter for device pointer ////////////////////
LimeDDS* limeddsconfig::getDevPtr (void)
{
    return m_sdr_dev;
}

void limeddsconfig::setDevPtr(LimeDDS* p_dev)
{
    m_sdr_dev = p_dev;
}


///////////////////////////////// ENABLE MUX /////////////////////////////////
void limeddsconfig::on_tx_mux_en_chkbx_clicked()
{
    if(ui->tx_mux_en_chkbx->isChecked())
    {
        m_sdr_dev->setTxMux(LimeDDS::DDS_ON);
    }
    else
    {
        m_sdr_dev->setTxMux(LimeDDS::DDS_OFF);
    }
}

void limeddsconfig::on_rx_mux_en_chkbx_clicked()
{
    if(ui->rx_mux_en_chkbx->isChecked())
    {
        m_sdr_dev->setRxMux(LimeDDS::DDS_ON);
    }
    else
    {
        m_sdr_dev->setRxMux(LimeDDS::DDS_OFF);
    }
}


////////////////////////////// NOISE SHAPING /////////////////////////////////
void limeddsconfig::on_taylor_en_chkbx_clicked()
{
    if(ui->taylor_en_chkbx->isChecked())
    {
        m_sdr_dev->setTaylor(LimeDDS::DDS_ON);
    }
    else
    {
        m_sdr_dev->setTaylor(LimeDDS::DDS_OFF);
    }
}

void limeddsconfig::on_phase_dith_chkbx_clicked()
{
    if(ui->phase_dith_chkbx->isChecked() && ui->trunc_dith_chkbx->isChecked())
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_BOTH);
    }
    else if(ui->phase_dith_chkbx->isChecked())
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_PHASE);
    }
    else if(ui->trunc_dith_chkbx->isChecked())
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_TRUNCATION);
    }
    else
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_OFF);
    }
}

void limeddsconfig::on_trunc_dith_chkbx_clicked()
{
    if(ui->phase_dith_chkbx->isChecked() && ui->trunc_dith_chkbx->isChecked())
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_BOTH);
    }
    else if(ui->phase_dith_chkbx->isChecked())
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_PHASE);
    }
    else if(ui->trunc_dith_chkbx->isChecked())
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_TRUNCATION);
    }
    else
    {
        m_sdr_dev->setDithering(LimeDDS::DITH_OFF);
    }
}


///////////////////////////////// SWEEP //////////////////////////////////////
void limeddsconfig::on_sweep_off_radio_clicked()
{
    m_sdr_dev->setSweepMode(LimeDDS::SWEEP_OFF);
}

void limeddsconfig::on_sweep_up_radio_clicked()
{
    m_sdr_dev->setSweepMode(LimeDDS::SWEEP_UP);
}

void limeddsconfig::on_sweep_updown_radio_clicked()
{
    m_sdr_dev->setSweepMode(LimeDDS::SWEEP_UP_DOWN);
}

void limeddsconfig::on_set_rate_but_clicked()
{
    m_sdr_dev->setSweepRate(ui->sweep_rate_spin->value()*1e9);
}


///////////////////////////////// FREQUENCY //////////////////////////////////
void limeddsconfig::on_set_freq_bot_but_clicked()
{
    m_sdr_dev->setFrequency(ui->freq_bot_spin->value()*1e6, LimeDDS::FREQ_BOT);
}

void limeddsconfig::on_set_freq_top_but_clicked()
{
     m_sdr_dev->setFrequency(ui->freq_top_spin->value()*1e6, LimeDDS::FREQ_TOP);
}

