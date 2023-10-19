#include "oposcontroller.h"

#include <QDebug>

OposController::OposController()
{
    cashChanger = new QAxObject();
    if(!cashChanger->setControl(CLSID)){
        qDebug() << tr(">> Error: Not possible to charge control ActiveX %1").arg(cashChanger->control());
        delete cashChanger;
    }
    else qDebug() << tr(">> Control ActiveX %1 charged").arg(cashChanger->control());
}

OposController::~OposController()
{
    delete cashChanger;
}

// Methods
int OposController::AdjustCashCounts(QString cashCounts)
{
    return cashChanger->dynamicCall("AdjustCashCounts(QString)", cashCounts).toInt();
}

int OposController::BeginDeposit()
{
    return cashChanger->dynamicCall("BeginDeposit()").toInt();
}

int OposController::CheckHealth(int level)
{
    return cashChanger->dynamicCall("CheckHealth(int)", level).toInt();
}

int OposController::ClaimDevice(int timeout)
{
    return cashChanger->dynamicCall("ClaimDevice(int)", timeout).toInt();
}

int OposController::ClearInput()
{
    return cashChanger->dynamicCall("ClearInput()").toInt();
}

int OposController::Close()
{
    return cashChanger->dynamicCall("Close()").toInt();
}

int OposController::CompareFirmwareVersion(QString firmwareFileName, int &pResult)
{
    QVariantList params;
    params.append(firmwareFileName);
    params.append(pResult);
    int r = cashChanger->dynamicCall("CompareFirmwareVersion(QString,int&)", params).toInt();
    pResult = params.at(1).toInt();
    return r;
}

int OposController::DirectIO(int command, int &pData, QString &pString)
{
    QVariantList params;
    params.append(command);
    params.append(pData);
    params.append(pString);
    int r = cashChanger->dynamicCall("DirectIO(int,int&,QString&)", params).toInt();
    pData = params.at(1).toInt();
    pString = params.at(2).toString();
    return r;
}

int OposController::DispenseCash(QString cashCounts)
{
    return cashChanger->dynamicCall("DispenseCash(QString)", cashCounts).toInt();
}

int OposController::DispenseChange(int amount)
{
    return cashChanger->dynamicCall("DispenseChange(int)", amount).toInt();
}

int OposController::EndDeposit(int success)
{
    return cashChanger->dynamicCall("EndDeposit(int)", success).toInt();
}

int OposController::FixDeposit()
{
    return cashChanger->dynamicCall("FixDeposit()").toInt();
}

int OposController::Open(QString deviceName)
{
    return cashChanger->dynamicCall("Open(QString)", deviceName).toInt();
}

int OposController::PauseDeposit(int control)
{
    return cashChanger->dynamicCall("PauseDeposit(int)", control).toInt();
}

int OposController::ReadCashCounts(QString &pCashCounts, bool &pDiscrepancy)
{
    QVariantList params;
    params.append(pCashCounts);
    params.append(pDiscrepancy);
    int r = cashChanger->dynamicCall("ReadCashCounts(QString&,bool&)", params).toInt();
    pCashCounts = params.at(0).toString();
    pDiscrepancy = params.at(1).toBool();
    return r;
}

int OposController::ReleaseDevice()
{
    return cashChanger->dynamicCall("ReleaseDevice()").toInt();
}

int OposController::ResetStatistics(QString statisticsBuffer)
{
    return cashChanger->dynamicCall("ResetStatistics(QString)", statisticsBuffer).toInt();
}

int OposController::RetrieveStatistics(QString &pStatisticsBuffer)
{
    // ToDo: Review
    QVariant param = pStatisticsBuffer;
    int r = cashChanger->dynamicCall("ResetStatistics(QString&)", param).toInt();
    pStatisticsBuffer = param.toString();
    return r;
}

void OposController::SOData(int status)
{
    cashChanger->dynamicCall("SOData(int)", status).toInt();
}

void OposController::SODirectIO(int eventNumber, int &pData, QString &pString)
{
    QVariantList params;
    params.append(eventNumber);
    params.append(pData);
    params.append(pString);
    cashChanger->dynamicCall("SODirectIO(int,int&,QString&)", params);
    pData = params.at(1).toInt();
    pString = params.at(2).toString();
}

void OposController::SOErrorDummy(int resultCode, int resultCodeExtended, int errorLocus, int &pErrorResponse)
{
    QVariantList params;
    params.append(resultCode);
    params.append(resultCodeExtended);
    params.append(errorLocus);
    params.append(pErrorResponse);
    cashChanger->dynamicCall("SOErrorDummy(int,int,int,int&)", params);
    pErrorResponse = params.at(3).toInt();
}

void OposController::SOOutputCompleteDummy(int outputID)
{
    cashChanger->dynamicCall("SOOutputCompleteDummy(int)", outputID);
}

int OposController::SOProcessID()
{
    return cashChanger->dynamicCall("SOProcessID()").toInt();
}

void OposController::SOStatusUpdate(int data)
{
    cashChanger->dynamicCall("SOStatusUpdate(int)", data);
}

int OposController::UpdateFirmware(QString firmwareFileName)
{
    return cashChanger->dynamicCall("UpdateFirmware(QString)", firmwareFileName).toInt();
}

int OposController::UpdateStatistics(QString statisticsBuffer)
{
    return cashChanger->dynamicCall("UpdateStatistics(QString)", statisticsBuffer).toInt();
}

// Properties
bool OposController::AsyncMode()
{
    return cashChanger->property("AsyncMode").toBool();
}

int OposController::AsyncResultCode()
{
    return cashChanger->property("AsyncResultCode").toInt();
}

int OposController::AsyncResultCodeExtended()
{
    return cashChanger->property("AsyncResultCodeExtended").toInt();
}

int OposController::BinaryConversion()
{
    return cashChanger->property("BinaryConversion").toInt();
}

bool OposController::CapCompareFirmwareVersion()
{
    return cashChanger->property("CapCompareFirmwareVersion").toBool();
}

bool OposController::CapDeposit()
{
    return cashChanger->property("CapDeposit").toBool();
}

bool OposController::CapDepositDataEvent()
{
    return cashChanger->property("CapDepositDataEvent").toBool();
}

bool OposController::CapDiscrepancy()
{
    return cashChanger->property("CapDiscrepancy").toBool();
}

bool OposController::CapEmptySensor()
{
    return cashChanger->property("CapEmptySensor").toBool();
}

bool OposController::CapFullSensor()
{
    return cashChanger->property("CapFullSensor").toBool();
}

bool OposController::CapJamSensor()
{
    return cashChanger->property("CapJamSensor").toBool();
}

bool OposController::CapNearEmptySensor()
{
    return cashChanger->property("CapNearEmptySensor").toBool();
}

bool OposController::CapNearFullSensor()
{
    return cashChanger->property("CapNearFullSensor").toBool();
}

bool OposController::CapPauseDeposit()
{
    return cashChanger->property("CapPauseDeposit").toBool();
}

int OposController::CapPowerReporting()
{
    return cashChanger->property("CapPowerReporting").toInt();
}

bool OposController::CapRealTimeData()
{
    return cashChanger->property("CapRealTimeData").toBool();
}

bool OposController::CapRepayDeposit()
{
    return cashChanger->property("CapRepayDeposit").toBool();
}

bool OposController::CapStatisticsReporting()
{
    return cashChanger->property("CapStatisticsReporting").toBool();
}

bool OposController::CapUpdateFirmware()
{
    return cashChanger->property("CapUpdateFirmware").toBool();
}

bool OposController::CapUpdateStatistics()
{
    return cashChanger->property("CapUpdateStatistics").toBool();
}

QString OposController::CheckHealthText()
{
    return cashChanger->property("CheckHealthText").toString();
}

bool OposController::Claimed()
{
    return cashChanger->property("Claimed").toBool();
}

QString OposController::ControlObjectDescription()
{
    return cashChanger->property("ControlObjectDescription").toString();
}

int OposController::ControlObjectVersion()
{
    return cashChanger->property("ControlObjectVersion").toInt();
}

QString OposController::CurrencyCashList()
{
    return cashChanger->property("CurrencyCashList").toString();
}

QString OposController::CurrencyCode()
{
    return cashChanger->property("CurrencyCode").toString();
}

QString OposController::CurrencyCodeList()
{
    return cashChanger->property("CurrencyCodeList").toString();
}

int OposController::CurrentExit()
{
    return cashChanger->property("CurrentExit").toInt();
}

int OposController::CurrentService()
{
    return cashChanger->property("CurrentService").toInt();
}

int OposController::DataCount()
{
    return cashChanger->property("DataCount").toInt();
}

bool OposController::DataEventEnabled()
{
    return cashChanger->property("DataEventEnabled").toBool();
}

int OposController::DepositAmount()
{
    return cashChanger->property("DepositAmount").toInt();
}

QString OposController::DepositCashList()
{
    return cashChanger->property("DepositCashList").toString();
}

QString OposController::DepositCodeList()
{
     return cashChanger->property("DepositCodeList").toString();
}

QString OposController::DepositCounts()
{
    return cashChanger->property("DepositCounts").toString();
}

int OposController::DepositStatus()
{
    return cashChanger->property("DepositStatus").toInt();
}

QString OposController::DeviceDescription()
{
    return cashChanger->property("DeviceDescription").toString();
}

bool OposController::DeviceEnabled()
{
    return cashChanger->property("DeviceEnabled").toBool();
}

int OposController::DeviceExits()
{
    return cashChanger->property("DeviceExits").toInt();
}

QString OposController::DeviceName()
{
    return cashChanger->property("DeviceName").toString();
}

int OposController::DeviceStatus()
{
    return cashChanger->property("DeviceStatus").toInt();
}

QString OposController::ExitCashList()
{
    return cashChanger->property("ExitCashList").toString();
}

bool OposController::FreezeEvents()
{
    return cashChanger->property("FreezeEvents").toBool();
}

int OposController::FullStatus()
{
    return cashChanger->property("FullStatus").toInt();
}

int OposController::OpenResult()
{
    return cashChanger->property("OpenResult").toInt();
}

int OposController::PowerNotify()
{
    return cashChanger->property("PowerNotify").toInt();
}

int OposController::PowerState()
{
    return cashChanger->property("PowerState").toInt();
}

bool OposController::RealTimeDataEnabled()
{
    return cashChanger->property("RealTimeDataEnabled").toBool();
}

int OposController::ResultCode()
{
    return cashChanger->property("ResultCode").toInt();
}

int OposController::ResultCodeExtended()
{
    return cashChanger->property("ResultCodeExtended").toInt();
}

int OposController::ServiceCount()
{
    return cashChanger->property("ServiceCount").toInt();
}

int OposController::ServiceIndex()
{
     return cashChanger->property("ServiceIndex").toInt();
}

QString OposController::ServiceObjectDescription()
{
     return cashChanger->property("ServiceObjectDescription").toString();
}

int OposController::ServiceObjectVersion()
{
    return cashChanger->property("ServiceObjectVersion").toInt();
}

int OposController::State()
{
    return cashChanger->property("State").toInt();
}

// Properties Setters
bool OposController::SetAsyncMode(bool AsyncMode)
{
    cashChanger->setProperty("AsyncMode", AsyncMode);
    return this->AsyncMode();
}

int OposController::SetBinaryConversion(int BinaryConversion)
{
    cashChanger->setProperty("BinaryConversion", BinaryConversion);
    return this->BinaryConversion();
}

QString OposController::SetCurrencyCode(QString CurrencyCode)
{
    cashChanger->setProperty("CurrencyCode", CurrencyCode);
    return this->CurrencyCode();
}

int OposController::SetCurrentExit(int CurrentExit)
{
    cashChanger->setProperty("CurrentExit", CurrentExit);
    return this->CurrentExit();
}

int OposController::SetCurrentService(int CurrentService)
{
    cashChanger->setProperty("CurrentService", CurrentService);
    return this->CurrentService();
}

bool OposController::SetDataEventEnabled(bool DataEventEnabled)
{
    cashChanger->setProperty("DataEventEnabled", DataEventEnabled);
    return this->DataEventEnabled();
}

bool OposController::SetDeviceEnabled(bool DeviceEnabled)
{
    cashChanger->setProperty("DeviceEnabled", DeviceEnabled);
    return this->DeviceEnabled();
}

bool OposController::SetFreezeEvents(bool FreezeEvents)
{
    cashChanger->setProperty("FreezeEvents", FreezeEvents);
    return this->FreezeEvents();
}

int OposController::SetPowerNotify(int PowerNotify)
{
    cashChanger->setProperty("PowerNotify", PowerNotify);
    return this->PowerNotify();
}

bool OposController::SetRealTimeDataEnabled(bool RealTimeDataEnabled)
{
    cashChanger->setProperty("RealTimeDataEnabled", RealTimeDataEnabled);
    return this->RealTimeDataEnabled();
}
