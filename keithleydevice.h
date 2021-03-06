#ifndef KEITHLEYDEVICE_H
#define KEITHLEYDEVICE_H

#include <string>

#define EARM  22  // The ibnotify Callback failed to rearm
#define EHDL  23  // The input handle is invalid
#define EWIP  26  // Wait already in progress on input ud
#define ERST  27  // The event notification was cancelled due to a reset of the interface
#define EPWR  28  // The system or board has lost power or gone to standby


class KeithleyDevice {
public:
    void pulsesweepvoltage(double,double,int);
    void current_pulse_sweep(double,double,int,char *);
    void rampvoltagedown(int,int);
    void rampvoltageup(int,int);
    std::string forward_voltage_measurement(double);
    int write(const char *);
    int read(void *,int) const;
    int close_connection() const;
    int clear() const;
    void cls() const;
    void rst() const;
    KeithleyDevice();
private:

    int Device;                   /* Device unit descriptor                  */
    int BoardIndex;               /* Interface Index (GPIB0=0,GPIB1=1,etc.)  */
    char stringinput[512];
};

#endif // KEITHLEYDEVICE_H
