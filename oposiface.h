#ifndef OPOSIFACE_H
#define OPOSIFACE_H

#include <QObject>

class OposIface : public QObject
{
    Q_OBJECT
public slots:
    // Methods
    virtual int  AdjustCashCounts(QString cashCounts) = 0;
    virtual int  BeginDeposit() = 0;
    virtual int  CheckHealth(int level) = 0;
    virtual int  ClaimDevice(int timeout) = 0;
    virtual int  ClearInput() = 0;
    virtual int  Close() = 0;
    virtual int  CompareFirmwareVersion(QString firmwareFileName, int& pResult) = 0;
    virtual int  DirectIO(int command, int& pData, QString& pString) = 0;
    virtual int  DispenseCash(QString cashCounts) = 0;
    virtual int  DispenseChange(int amount) = 0;
    virtual int  EndDeposit(int success) = 0;
    virtual int  FixDeposit() = 0;
    virtual int  Open(QString deviceName) = 0;
    virtual int  PauseDeposit(int control) = 0;
    virtual int  ReadCashCounts(QString& pCashCounts, bool& pDiscrepancy) = 0;
    virtual int  ReleaseDevice() = 0;
    virtual int  ResetStatistics(QString statisticsBuffer) = 0;
    virtual int  RetrieveStatistics(QString& pStatisticsBuffer) = 0;
    virtual void SOData(int status) = 0;
    virtual void SODirectIO(int eventNumber, int& pData, QString& pString) = 0;
    virtual void SOErrorDummy(int resultCode, int resultCodeExtended, int errorLocus, int& pErrorResponse) = 0;
    virtual void SOOutputCompleteDummy(int outputID) = 0;
    virtual int  SOProcessID() = 0;
    virtual void SOStatusUpdate(int data) = 0;
    virtual int  UpdateFirmware(QString firmwareFileName) = 0;
    virtual int  UpdateStatistics(QString statisticsBuffer) = 0;
signals:
    void DataEvent(int status);
    void DirectIOEvent(int eventNumber, int& pData, QString& pString);
    void StatusUpdateEvent(int data);
    void exception(int code, QString source, QString disc, QString help);
    void propertyChanged(QString name);
    void signal(QString name, int argc, void* argv);
public:
    // Properties
    virtual bool    AsyncMode() = 0;
    virtual int     AsyncResultCode() = 0;
    virtual int     AsyncResultCodeExtended() = 0;
    virtual int     BinaryConversion() = 0;
    virtual bool    CapCompareFirmwareVersion() = 0;
    virtual bool    CapDeposit() = 0;
    virtual bool    CapDepositDataEvent() = 0;
    virtual bool    CapDiscrepancy() = 0;
    virtual bool    CapEmptySensor() = 0;
    virtual bool    CapFullSensor() = 0;
    virtual bool    CapJamSensor() = 0;
    virtual bool    CapNearEmptySensor() = 0;
    virtual bool    CapNearFullSensor() = 0;
    virtual bool    CapPauseDeposit() = 0;
    virtual int     CapPowerReporting() = 0;
    virtual bool    CapRealTimeData() = 0;
    virtual bool    CapRepayDeposit() = 0;
    virtual bool    CapStatisticsReporting() = 0;
    virtual bool    CapUpdateFirmware() = 0;
    virtual bool    CapUpdateStatistics() = 0;
    virtual QString CheckHealthText() = 0;
    virtual bool    Claimed() = 0;
    virtual QString ControlObjectDescription() = 0;
    virtual int     ControlObjectVersion() = 0;
    virtual QString CurrencyCashList() = 0;
    virtual QString CurrencyCode() = 0;
    virtual QString CurrencyCodeList() = 0;
    virtual int     CurrentExit() = 0;
    virtual int     CurrentService() = 0;
    virtual int     DataCount() = 0;
    virtual bool    DataEventEnabled() = 0;
    virtual int     DepositAmount() = 0;
    virtual QString DepositCashList() = 0;
    virtual QString DepositCodeList() = 0;
    virtual QString DepositCounts() = 0;
    virtual int     DepositStatus() = 0;
    virtual QString DeviceDescription() = 0;
    virtual bool    DeviceEnabled() = 0;
    virtual int     DeviceExits() = 0;
    virtual QString DeviceName() = 0;
    virtual int     DeviceStatus() = 0;
    virtual QString ExitCashList() = 0;
    virtual bool    FreezeEvents() = 0;
    virtual int     FullStatus() = 0;
    virtual int     OpenResult() = 0;
    virtual int     PowerNotify() = 0;
    virtual int     PowerState() = 0;
    virtual bool    RealTimeDataEnabled() = 0;
    virtual int     ResultCode() = 0;
    virtual int     ResultCodeExtended() = 0;
    virtual int     ServiceCount() = 0;
    virtual int     ServiceIndex() = 0;
    virtual QString ServiceObjectDescription() = 0;
    virtual int     ServiceObjectVersion() = 0;
    virtual int     State() = 0;

    // Properties Setters
    virtual bool    SetAsyncMode(bool AsyncMode) = 0;
    virtual int     SetBinaryConversion(int BinaryConversion) = 0;
    virtual QString SetCurrencyCode(QString CurrencyCode) = 0;
    virtual int     SetCurrentExit(int CurrentExit) = 0;
    virtual int     SetCurrentService(int CurrentService) = 0;
    virtual bool    SetDataEventEnabled(bool DataEventEnabled) = 0;
    virtual bool    SetDeviceEnabled(bool DeviceEnabled) = 0;
    virtual bool    SetFreezeEvents(bool FreezeEvents) = 0;
    virtual int     SetPowerNotify(int PowerNotify) = 0;
    virtual bool    SetRealTimeDataEnabled(bool RealTimeDataEnabled) = 0;
};

#endif // OPOSIFACE_H
