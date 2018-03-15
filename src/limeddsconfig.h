#ifndef LIMEDDSCONFIG_H
#define LIMEDDSCONFIG_H

#include <QWidget>
#include "limedds.h"

namespace Ui {
class limeddsconfig;
}

class limeddsconfig : public QWidget
{
    Q_OBJECT

public:
    explicit limeddsconfig(QWidget *parent = 0);
    ~limeddsconfig();

    //setter method for the device pointer
    void setDevPtr(LimeDDS* p_dev);
    LimeDDS* getDevPtr (void);

private slots:


    void on_tx_mux_en_chkbx_clicked();

    void on_rx_mux_en_chkbx_clicked();

    void on_taylor_en_chkbx_clicked();

    void on_phase_dith_chkbx_clicked();

    void on_trunc_dith_chkbx_clicked();

    void on_sweep_off_radio_clicked();

    void on_sweep_up_radio_clicked();

    void on_sweep_updown_radio_clicked();

    void on_set_rate_but_clicked();

    void on_set_freq_bot_but_clicked();

    void on_set_freq_top_but_clicked();



private:
    Ui::limeddsconfig *ui;

    LimeDDS* m_sdr_dev;
};

#endif // LIMEDDSCONFIG_H
