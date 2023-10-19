#ifndef OPOSCONTROLLER_H
#define OPOSCONTROLLER_H

#include "oposiface.h"

#include <QAxObject>

class OposController : public OposIface
{
    Q_OBJECT
public:
    OposController();
    ~OposController();
public slots:
    int  AdjustCashCounts(QString cashCounts) override;
    int  BeginDeposit() override;
    int  CheckHealth(int level) override;
    int  ClaimDevice(int timeout) override;
    int  ClearInput() override;
    int  Close() override;
    int  CompareFirmwareVersion(QString firmwareFileName, int& pResult) override;
    int  DirectIO(int command, int& pData, QString& pString) override;
    int  DispenseCash(QString cashCounts) override;
    int  DispenseChange(int amount) override;
    int  EndDeposit(int success) override;
    int  FixDeposit() override;
    int  Open(QString deviceName) override;
    int  PauseDeposit(int control) override;
    int  ReadCashCounts(QString& pCashCounts, bool& pDiscrepancy) override;
    int  ReleaseDevice() override;
    int  ResetStatistics(QString statisticsBuffer) override;
    int  RetrieveStatistics(QString& pStatisticsBuffer) override;
    void SOData(int status) override;
    void SODirectIO(int eventNumber, int& pData, QString& pString) override;
    void SOErrorDummy(int resultCode, int resultCodeExtended, int errorLocus, int& pErrorResponse) override;
    void SOOutputCompleteDummy(int outputID) override;
    int  SOProcessID() override;
    void SOStatusUpdate(int data) override;
    int  UpdateFirmware(QString firmwareFileName) override;
    int  UpdateStatistics(QString statisticsBuffer) override;
public:
    bool    AsyncMode() override;
    int     AsyncResultCode() override;
    int     AsyncResultCodeExtended() override;
    int     BinaryConversion() override;
    bool    CapCompareFirmwareVersion() override;
    bool    CapDeposit() override;
    bool    CapDepositDataEvent() override;
    bool    CapDiscrepancy() override;
    bool    CapEmptySensor() override;
    bool    CapFullSensor() override;
    bool    CapJamSensor() override;
    bool    CapNearEmptySensor() override;
    bool    CapNearFullSensor() override;
    bool    CapPauseDeposit() override;
    int     CapPowerReporting() override;
    bool    CapRealTimeData() override;
    bool    CapRepayDeposit() override;
    bool    CapStatisticsReporting() override;
    bool    CapUpdateFirmware() override;
    bool    CapUpdateStatistics() override;
    QString CheckHealthText() override;
    bool    Claimed() override;
    QString ControlObjectDescription() override;
    int     ControlObjectVersion() override;
    QString CurrencyCashList() override;
    QString CurrencyCode() override;
    QString CurrencyCodeList() override;
    int     CurrentExit() override;
    int     CurrentService() override;
    int     DataCount() override;
    bool    DataEventEnabled() override;
    int     DepositAmount() override;
    QString DepositCashList() override;
    QString DepositCodeList() override;
    QString DepositCounts() override;
    int     DepositStatus() override;
    QString DeviceDescription() override;
    bool    DeviceEnabled() override;
    int     DeviceExits() override;
    QString DeviceName() override;
    int     DeviceStatus() override;
    QString ExitCashList() override;
    bool    FreezeEvents() override;
    int     FullStatus() override;
    int     OpenResult() override;
    int     PowerNotify() override;
    int     PowerState() override;
    bool    RealTimeDataEnabled() override;
    int     ResultCode() override;
    int     ResultCodeExtended() override;
    int     ServiceCount() override;
    int     ServiceIndex() override;
    QString ServiceObjectDescription() override;
    int     ServiceObjectVersion() override;
    int     State() override;

    bool    SetAsyncMode(bool AsyncMode) override;
    int     SetBinaryConversion(int BinaryConversion) override;
    QString SetCurrencyCode(QString CurrencyCode) override;
    int     SetCurrentExit(int CurrentExit) override;
    int     SetCurrentService(int CurrentService) override;
    bool    SetDataEventEnabled(bool DataEventEnabled) override;
    bool    SetDeviceEnabled(bool DeviceEnabled) override;
    bool    SetFreezeEvents(bool FreezeEvents) override;
    int     SetPowerNotify(int PowerNotify) override;
    bool    SetRealTimeDataEnabled(bool RealTimeDataEnabled) override;
private:
    const QString CLSID = "{CCB90032-B81E-11D2-AB74-0040054C3719}";
private:
    QAxObject *cashChanger;
};

#endif // OPOSCONTROLLER_H
