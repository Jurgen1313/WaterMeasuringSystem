using System;
using System.IO.Ports;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using WatterMeasurement.Model;

namespace WatterMeasurement.Services.ModBusCommand
{
    public static class TransferData
    {
        public static byte[] MakePackage(byte deviceAddress, byte modbusCommand)
        {
            const byte numberOfBytes = 2;
            const byte packageLenght = 5;
            byte[] tmpPackage = new byte[numberOfBytes];
            byte[] tmpSendPackage = new byte[packageLenght];

            tmpPackage[0] = modbusCommand;
            tmpPackage[1] = numberOfBytes;

            ushort crc16Value = CRC16Calculation.ComputeCrc(tmpPackage);

            tmpSendPackage[0] = deviceAddress;
            tmpSendPackage[1] = modbusCommand;
            tmpSendPackage[2] = numberOfBytes;
            tmpSendPackage[3] = Convert.ToByte(crc16Value >> 8);
            tmpSendPackage[4] = Convert.ToByte(crc16Value & 0xFF);

            return tmpSendPackage;//
        }
        public static byte[] MakePackage(byte deviceAddress, byte modbusCommand, byte data)
        {
            const byte numberOfBytes = 3;
            const byte packageLenght = 6;
            byte[] tmpPackage = new byte[numberOfBytes];
            byte[] tmpSendPackage = new byte[packageLenght];

            tmpPackage[0] = modbusCommand;
            tmpPackage[1] = numberOfBytes;
            tmpPackage[2] = data;

            ushort crc16Value = CRC16Calculation.ComputeCrc(tmpPackage);

            tmpSendPackage[0] = deviceAddress;
            tmpSendPackage[1] = modbusCommand;
            tmpSendPackage[2] = numberOfBytes;
            tmpSendPackage[3] = data;
            tmpSendPackage[4] = Convert.ToByte(crc16Value >> 8);
            tmpSendPackage[5] = Convert.ToByte(crc16Value & 0xFF);

            return tmpSendPackage;//
        }
        public static byte[] MakePackage(byte deviceAddress, byte modbusCommand, byte channel, UInt32 data)
        {
            const byte numberOfBytes = 8;
            const byte packageLenght = 11;
            const byte crcLenght = 2;
            const UInt32 maxPeriod = 255;
            UInt32 overflow;

            overflow = data / maxPeriod;

            byte[] tmpPackage = new byte[numberOfBytes];
            byte[] tmpSendPackage = new byte[packageLenght];

            tmpPackage[0] = modbusCommand;
            tmpPackage[1] = numberOfBytes;
            tmpPackage[2] = channel;
            tmpPackage[3] = Convert.ToByte(overflow >> 24);
            tmpPackage[4] = Convert.ToByte((overflow >> 16) & 0xFF);
            tmpPackage[5] = Convert.ToByte((overflow >> 8) & 0xFF);
            tmpPackage[6] = Convert.ToByte(overflow & 0xFF);
            tmpPackage[7] = Convert.ToByte(data - overflow * maxPeriod);

            ushort crc16Value = CRC16Calculation.ComputeCrc(tmpPackage);

            tmpSendPackage[0] = deviceAddress;

            for (int i = 1; i < (packageLenght - crcLenght); ++i)
            {
                tmpSendPackage[i] = tmpPackage[i - 1];
            }

            tmpSendPackage[9] = Convert.ToByte(crc16Value >> 8);
            tmpSendPackage[10] = Convert.ToByte(crc16Value & 0xFF);

            return tmpSendPackage;//
        }
        public static bool SendPackage(SerialPort serialPort, byte[] package)
        {
            int numberBytesPosition = 2;
            byte preambula = 3;
            byte packageLenght = (byte)(package[numberBytesPosition] + preambula);
            if (!serialPort.IsOpen)
            {
                serialPort.Open();
                serialPort.Close();
                serialPort.Open();
            }
            else
            {
                serialPort.Close();
                serialPort.Open();
            }
            try
            {
                serialPort.Write(package, 0, packageLenght);
            }
            catch
            {
                if (serialPort.IsOpen)
                    serialPort.Close();
                return false;
            }
            return true;
        }
        public static bool ReadAnswer(SerialPort serialPort, byte[] package)
        {
            const int numberBytesPosition = 2;
            bool packageReceived = true;
            //-ADDR-Com--NumberBytes
            //---0---1---2
            for (int i = 0; i <= numberBytesPosition; ++i)
            {
                if (!serialPort.IsOpen)
                {
                    Debug.Write("");
                    serialPort.Open();
                    serialPort.Close();
                    serialPort.Open();
                }
                try
                {
                    package[i] = (byte)serialPort.ReadByte();
                }
                catch (TimeoutException)
                {
                    serialPort.DiscardInBuffer();
                    packageReceived = false;
                    serialPort.Close();
                    return packageReceived;////
                }                
            }
            for (int i = (numberBytesPosition + 1); i <= (package[numberBytesPosition] + numberBytesPosition); ++i)
            {
                if (!serialPort.IsOpen)
                {
                    serialPort.Open();
                    serialPort.Close();
                    serialPort.Open();
                }
                try
                {
                    package[i] = (byte)serialPort.ReadByte();
                }
                catch (TimeoutException)
                {
                    serialPort.DiscardInBuffer();
                    packageReceived = false;
                    serialPort.Close();
                    return packageReceived;
                }
            }
            packageReceived = IsPackageCorrect(package);
            return packageReceived;
        }
        public static bool IsPackageCorrect(byte[] package)
        {
            const int numberBytePosition = 2;
            if (package[numberBytePosition] < 20)
            {
                //ushort calculatedCrc16Value;
                //ushort receivedCrc16Value;
                byte[] tmpPackage = new byte[package[numberBytePosition]];
                for (byte i = 0; i < package[numberBytePosition]; ++i)
                {
                    tmpPackage[i] = package[i + 1];
                }

                if (CRC16Calculation.ComputeCrc(tmpPackage) == 
                    GetCRC16FromPackage(package))
                {
                    return true;
                }
                //else
                //    return false;
            }
            //else
            //{
                return false;
            //}
        }
        public static UInt16 GetCRC16FromPackage(byte[] package)
        {
            const int numberBytesPosition = 2;
            int crc16HiByte = package[numberBytesPosition] + 1;
            int crc16LoByte = package[numberBytesPosition] + 2;
            //UInt16 receivedCRC16Value;
            //receivedCRC16Value = Convert.ToUInt16(package[package[2] + 1]);
            //receivedCRC16Value = receivedCRC16Value << 8;
            ////) | (ushort)package[package[2] + 2]);
            //receivedCRC16Value = (package[package[2] + 1]) << 8;//) | (ushort)package[package[2] + 2]);
            return (UInt16)(((UInt16)package[crc16HiByte] << 8) | package[crc16LoByte]);
        }

        private static string[] GetAvailablePortNames()
        {
            int num;
            string[] availablePortNames = SerialPort.GetPortNames().
                OrderBy(a => a.Length > 3 && int.TryParse(a.Substring(3), out num) ? num : 0).ToArray();
            return availablePortNames;
        }
        //public static SerialPort FindConverterDevice(byte _converterAddress)
        //{
        //    byte converterAddress = _converterAddress;
        //    bool converterFounded = false;
        //    const byte commandPosition = 1;
        //    SerialPort serialPort = new SerialPort();

        //    serialPort.BaudRate = 115200;
        //    serialPort.DataBits = 8;
        //    serialPort.Parity = Parity.None;
        //    serialPort.ReadBufferSize = 4096;
        //    serialPort.WriteBufferSize = 20;
        //    serialPort.ReadTimeout = 120;
        //    serialPort.StopBits = StopBits.One;
        //    serialPort.Handshake = Handshake.None;
        //    serialPort.DtrEnable = true;
        //    //availablePortNames = GetAvailablePortNames();

        //    foreach (string portName in GetAvailablePortNames())
        //    {
        //        byte[] packageToSlave = new byte[20];
        //        byte[] packageFromSlave = new byte[20];

        //        if (serialPort.IsOpen)
        //        {
        //            serialPort.Close();
        //        }

        //        serialPort.PortName = portName;

        //        if (!serialPort.IsOpen)
        //        {
        //            serialPort.Open();
        //            serialPort.Close();
        //            serialPort.Open();
        //        }

        //        packageToSlave = TransferData.MakePackage(converterAddress, (byte)ModbusCommand.FindMaster);
        //        TransferData.SendPackage(serialPort, packageToSlave);
        //        if (TransferData.ReadAnswer(serialPort, packageFromSlave))
        //        {
        //            if (packageFromSlave[commandPosition] == (byte)ModbusCommand.FindMaster)
        //            {
        //                converterFounded = true;
        //            }
        //        }
        //        if (serialPort.IsOpen)
        //        {
        //            serialPort.Close();
        //        }
        //    }
        //    return serialPort;
        //}
        ////public static 
        public static bool MakeSendRead(SerialPort serialPort, byte deviceAddress, byte modbusCommand, byte answerCommandFromSlave, byte channel, UInt32 data)
        {
            byte[] packageToSlave = new byte[20];
            byte[] packageFromSlave = new byte[20];
            bool packageSentSuccessful = false;
            byte currentAttempt = 0;
            const byte numberOfAttempts = 5;
            const byte commandPosition = 1;

            packageToSlave = MakePackage(deviceAddress, modbusCommand, channel, data);
            do
            {                
                bool packageSent = SendPackage(serialPort, packageToSlave);
                if (packageSent)
                {
                    if (ReadAnswer(serialPort, packageFromSlave))
                    {
                        if (packageFromSlave[commandPosition] == answerCommandFromSlave)
                        {
                            packageSentSuccessful = true;
                        }
                    }
                    else
                    {
                        currentAttempt++;
                        packageSentSuccessful = false;
                    }
                }
                else
                {
                    currentAttempt++;
                    packageSentSuccessful = false;
                }

                if (serialPort.IsOpen)
                {
                    serialPort.Close();
                }
            }
            while ((Enum.IsDefined(typeof(ModBusErrors), (byte)packageFromSlave[commandPosition])) && (currentAttempt < numberOfAttempts));
            //while ((!packageSentSuccessful) && (currentAttempt < numberOfAttempts));
            //Enum.IsDefined(typeof(ModBusErrors), packageFromSlave[commandPosition]);
            if (packageSentSuccessful && (currentAttempt < numberOfAttempts))
                return true;
            else
                return false;
        }
        public static byte[] MakeSendRead(SerialPort serialPort, byte deviceAddress, byte modbusCommand, byte channel)
        {
            byte[] packageToSlave = new byte[20];
            byte[] packageFromSlave = new byte[20];
            bool packageSentSuccessful = false;
            byte currentAttempt = 0;
            const byte numberOfAttempts = 5;

            packageToSlave = MakePackage(deviceAddress, modbusCommand, channel);
            do
            {
                bool packageSent = SendPackage(serialPort, packageToSlave);
                if (packageSent)
                {
                    if (ReadAnswer(serialPort, packageFromSlave))
                    {
                        const byte commandPosition = 1;
                        if (packageFromSlave[commandPosition] == modbusCommand)
                        {
                            packageSentSuccessful = true;
                        }
                    }
                    else
                    {
                        currentAttempt++;
                        packageSentSuccessful = false;
                    }
                }
                else
                {
                    currentAttempt++;
                    packageSentSuccessful = false;
                }

                if (serialPort.IsOpen)
                {
                    serialPort.Close();
                }
            }
            while ((!packageSentSuccessful) && (currentAttempt < numberOfAttempts));

            //return packageFromSlave;
            if (packageSentSuccessful && (currentAttempt < numberOfAttempts))
                return packageFromSlave;
            else
                return null;
        }
        public static byte[] DeviceMakeSendReadCommand(SlaveDevice _device, byte modbusCommand)
        {
            SlaveDevice device = _device;
            byte[] packageToSlave = new byte[20];
            byte[] packageFromSlave = new byte[20];
            bool packageSentSuccessful = false;
            byte currentAttempt = 0;
            const byte numberOfAttempts = 5;
            byte packageReceivedSuccessfully = (byte)ModbusCommand.PackageReceivedSuccessfully;

            packageToSlave = MakePackage(device.DeviceAddress, modbusCommand);
            do
            {
                bool packageSent = SendPackage(device.GetSerialPort, packageToSlave);
                if (packageSent)
                {
                    if (ReadAnswer(device.GetSerialPort, packageFromSlave))
                    {
                        const byte commandPosition = 1;
                        if (packageFromSlave[commandPosition] == packageReceivedSuccessfully)
                        {
                            packageSentSuccessful = true;
                        }
                    }
                    else
                    {
                        currentAttempt++;
                        packageSentSuccessful = false;
                    }
                }
                else
                {
                    currentAttempt++;
                    packageSentSuccessful = false;
                }

                if (device.GetSerialPort.IsOpen)
                {
                    device.GetSerialPort.Close();
                }
            }
            while ((!packageSentSuccessful) && (currentAttempt < numberOfAttempts));

            //return packageFromSlave;
            if (packageSentSuccessful && (currentAttempt < numberOfAttempts))
                return packageFromSlave;
            else
                return null;
        }
        //public static byte[] DeviceMakeSendReadCommand(SlaveDevice _device, byte modbusCommand)
        //{
        //    SlaveDevice device = _device;
        //    byte[] packageToSlave = new byte[20];
        //    byte[] packageFromSlave = new byte[20];
        //    bool packageSentSuccessful = false;
        //    byte currentAttempt = 0;
        //    const byte numberOfAttempts = 5;
        //    byte packageReceivedSuccessfully = (byte)ModbusCommand.PackageReceivedSuccessfully;

        //    packageToSlave = MakePackage(device.DeviceAddress, modbusCommand);
        //    do
        //    {
        //        bool packageSent = SendPackage(device.GetSerialPort, packageToSlave);
        //        if (packageSent)
        //        {
        //            if (ReadAnswer(device.GetSerialPort, packageFromSlave))
        //            {
        //                const byte commandPosition = 1;
        //                if (packageFromSlave[commandPosition] == packageReceivedSuccessfully)
        //                {
        //                    packageSentSuccessful = true;
        //                }
        //            }
        //            else
        //            {
        //                currentAttempt++;
        //                packageSentSuccessful = false;
        //            }
        //        }
        //        else
        //        {
        //            currentAttempt++;
        //            packageSentSuccessful = false;
        //        }

        //        if (device.GetSerialPort.IsOpen)
        //        {
        //            device.GetSerialPort.Close();
        //        }
        //    }
        //    while ((!packageSentSuccessful) && (currentAttempt < numberOfAttempts));

        //    //return packageFromSlave;
        //    if (packageSentSuccessful && (currentAttempt < numberOfAttempts))
        //        return packageFromSlave;
        //    else
        //        return null;
        //}
        public static void ActivateDeactivateCountersInDevice(SlaveDevice device)
        {
            SlaveDevice _device = device;
            int index = 0;
            int activeCounters = 0;

            foreach (var counter in _device.counter)
            {
                if (counter.Active)
                {
                    activeCounters |= 1 << index;
                }
                ++index;
            }

            byte[] packageToSlave = new byte[20];
            byte[] packageFromSlave = new byte[20];
            packageToSlave = MakePackage(_device.DeviceAddress, (byte)ModbusCommand.EnableCounters, (byte)activeCounters);
            SendPackage(_device.GetSerialPort, packageToSlave);
        }
        public static bool SetCounterValues(Counter counter)
        {
            Counter activeCounter = counter;
            byte[] packageToSlave = new byte[20];
            byte[] packageFromSlave = new byte[20];
            bool packageSentSuccessful = false;

            packageSentSuccessful = MakeSendRead(activeCounter.UsedSerialPort, activeCounter.CounterAddress, (byte)ModbusCommand.SetNumberOfPulses,
                        (byte)ModbusCommand.PackageReceivedSuccessfully, (byte)(activeCounter.CounterNumber - 1), activeCounter.SetCounterValue);
            return packageSentSuccessful;
        }
        public static int IsActiveCountersInDevice(SlaveDevice device)
        {
            SlaveDevice _device = device;
            int index = 0;
            int activeCounters = 0;

            foreach (var counter in _device.counter)
            {
                if (counter.Active)
                {
                    activeCounters |= 1 << index;
                }
                ++index;
            }
            return activeCounters;
        }
        public static bool IsAllSetCouterParametersOK(Counter _counter)
        {
            Counter counter = _counter;
            return (counter.SetCounterValue > 0 && counter.CounterPulsesPerLiter > 0);
        }
        public static bool StartMeasurements(CounterSystem counterSystem)
        {
            CounterSystem tmpCounterSystem = counterSystem;
            bool isOK = true;
            foreach (var device in tmpCounterSystem.device)
            {
                int activeCounters = 0;
                int index = 0;
                foreach (var counter in device.counter)
                {
                    if (counter.Active)
                    {
                        activeCounters |= 1 << index;
                        if (IsAllSetCouterParametersOK(counter))
                        {
                            isOK &= SetCounterValues(counter);
                        }
                    }
                    ++index;
                }
                if (activeCounters != 0)
                {
                    DeviceMakeSendReadCommand(device, (byte)ModbusCommand.StartCounters);                    
                }
            }
            return isOK;
            //Start measurement
        }
        public static bool DeviceFinishedMeasurements(SlaveDevice _device)
        {
            SlaveDevice device = _device;
            byte[] packageToSlave = new byte[20];
            byte[] packageFromSlave = new byte[20];
            //bool packageSentSuccessful = false;
            byte currentAttempt = 0;
            const byte numberOfAttempts = 5;
            const byte commandPosition = 1;
            const byte answerCodePosition = 3;
            //byte packageReceivedSuccessfully = (byte)ModbusCommand.PackageReceivedSuccessfully;

            packageToSlave = MakePackage(device.DeviceAddress, (byte)ModbusCommand.ReadyToSendData);
            do
            {
                //bool packageSent = SendPackage(device.GetSerialPort, packageToSlave);
                if (SendPackage(device.GetSerialPort, packageToSlave))
                {
                    if (!ReadAnswer(device.GetSerialPort, packageFromSlave))
                        currentAttempt++;

                }
                else
                {
                    currentAttempt++;
                    //packageSentSuccessful = false;
                }

                if (device.GetSerialPort.IsOpen)
                {
                    device.GetSerialPort.Close();
                }
            }
            while ((Enum.IsDefined(typeof(ModBusErrors), packageFromSlave[commandPosition])) && (currentAttempt < numberOfAttempts));
            //while ((!packageSentSuccessful) && (currentAttempt < numberOfAttempts));

            //return packageFromSlave;
            if (packageFromSlave[answerCodePosition] == 1)
                return true;
            else
                return false;
        }
        public static UInt32 ReadCounterMeasuredValue(Counter counter, byte modbusCommand)
        {
            Counter tmpCounter = counter;
            UInt32 counterMeasuredValue = 0;
            byte[] packageFromSlave;
            
            packageFromSlave = MakeSendRead(tmpCounter.UsedSerialPort, tmpCounter.CounterAddress, modbusCommand, (byte)(tmpCounter.CounterNumber - 1));
            if (packageFromSlave != null)
            {
                UInt32 dataOV = 0;
                UInt32 data = 0;
                UInt32 value = 0;
                dataOV |= ((UInt32)packageFromSlave[4] << 24);
                dataOV |= ((UInt32)packageFromSlave[5] << 16);
                dataOV |= ((UInt32)packageFromSlave[6] << 8);
                dataOV |= ((UInt32)packageFromSlave[7] & 0xFF);
                data |= (UInt32)packageFromSlave[8] << 8;
                data |= (UInt32)packageFromSlave[9] & 0xFF;
                value = dataOV * 65535 + data;
                return value;
            }
            else
                return 0;
            //return counterMeasuredValue;
        }
    }
}
