using System.IO.Ports;
using WatterMeasurement.Model;
using WatterMeasurement.Services.ModBusCommand;
using WatterMeasurement.Services.COM_Port;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace WatterMeasurement.Services.COM_Port
{
    public class FindSlaveDevices
    {
        private SerialPort serialPort;
        private List<FoundSlaveDevice> AllSlaveDevices;
        private byte startAddress { get; }
        private byte endAddress { get; }
        private bool devicesFound;

        public bool DevicesFound
        {
            get { return devicesFound; }
        }

        public List<FoundSlaveDevice> GetFoundDevices
        {
            get
            {
                return AllSlaveDevices;
            }
        }

        public FindSlaveDevices(SerialPort serialPort, byte startAddress, byte endAddress)
        {
            this.startAddress = startAddress;
            this.endAddress = endAddress;
            this.serialPort = serialPort;
            FindDevice();
            //AllSlaveDevices = new FoundSlaveDevice();
        }
        private void FindDevice()
        {
            const byte commandPosition = 1;
            const int maxPackageLenght = 20;
            const int deviceTypePosition = 3;
            byte deviceNumber = 1;

            bool sentSuccessful;
            if (!serialPort.IsOpen)
            {
                serialPort.Open();
            }
            for (byte slaveAddress = startAddress; slaveAddress < endAddress; ++slaveAddress)
            {
                byte[] packageToSlave = new byte[maxPackageLenght];
                byte[] packageFromSlave = new byte[maxPackageLenght];
                packageToSlave = TransferData.MakePackage(slaveAddress, (byte)ModbusCommand.FindDevices);
                sentSuccessful = TransferData.SendPackage(serialPort, packageToSlave);

                if (TransferData.ReadAnswer(serialPort, packageFromSlave))
                {
                    if (packageFromSlave[commandPosition] == (byte)ModbusCommand.FindDevices)
                    {
                        if (AllSlaveDevices != null)
                            AllSlaveDevices.Add(new FoundSlaveDevice(slaveAddress, packageFromSlave[deviceTypePosition], deviceNumber));
                        else
                        {
                            AllSlaveDevices = new List<FoundSlaveDevice>
                            {
                                new FoundSlaveDevice(slaveAddress, packageFromSlave[deviceTypePosition], deviceNumber)
                            };
                        }
                        deviceNumber++;
                    }
                    devicesFound = true;
                }
            }
            serialPort.Close();
        }
    }
}