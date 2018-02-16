enum ModbusCommand : byte
{
    StartCounters                   = 0xA1, //0xA1  --  Start all active PWMs 
    StopCounters                    = 0xA2, //0xB2  --  Stop all PWMs 
    ReadyToSendData                 = 0xA3,
    FindDevices                     = 0xA6,
    FindMaster                      = 0xA7,

    EnableCounters                  = 0xB1,
    EnableEmulatorCounters          = 0xB2,

    SetCounterPeriod                = 0xC1,
    SetCounterCompare               = 0xC2,
    SetNumberOfPulses               = 0xC3, //0xC2  --  Set channels with pulses
    ReadPulsesFromCounter           = 0xC4,
    SetCounter                      = 0xC5,
    ReadExamplaryStartValue         = 0xC6,
    ReadExamplaryEndValue           = 0xC7,
    //ReadCounterValue                = 0xC8,
    ReadExamplaryValue              = 0xC8,    

    PackageSentSuccessfully         = 0xD1, //0xD1  --  Package was successfully sent 
    PackageReceivedSuccessfully     = 0xD2, //0xD2  --  Package received successfully 
}

enum ModBusErrors : byte
{
    ErrorDamadgedPackageFromPc      = 0xE0, //0xE0  --  package from PC is damaged
    ErrorCommunicationWithPc        = 0xE1, //0xE1  -- communiation error with PC
    ErrorDamagedPackageFromSlave    = 0xE2,
    ErrorCommunicationWithSlave     = 0xE3, //0xE3
    ErrorMasterDamagedPackage       = 0XE4,
    ErrorMasterCommunication        = 0xE5,
    ErrorUnknownCommand             = 0xE9
}
