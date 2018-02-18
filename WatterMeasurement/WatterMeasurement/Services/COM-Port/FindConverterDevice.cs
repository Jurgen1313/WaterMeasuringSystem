using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO.Ports;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using WatterMeasurement.Services.ModBusCommand;

namespace WatterMeasurement.Services.COM_Port
{
    public class FindConverterDevice//: INotifyPropertyChanged
    {
    #region data
        private byte converterAddress;
        private SerialPort usedSerialPort = new SerialPort();
        private string[] availablePortNames;
        private bool converterFounded;
    #endregion

        public SerialPort UsedSerialPort
        {
            get
            {
                return usedSerialPort;
            }
        }
        public bool ConverterFounded
        {
            get { return converterFounded; }
        }
        public byte ConverterAddress
        { get { return converterAddress; } }

        public FindConverterDevice(byte converterAddress)
        {
            this.converterAddress = converterAddress;
            converterFounded = false;
            //usedSerialPort = new SerialPort();

            usedSerialPort.BaudRate = 115200;
            usedSerialPort.DataBits = 8;
            usedSerialPort.Parity = Parity.None;
            usedSerialPort.ReadBufferSize = 4096;
            usedSerialPort.WriteBufferSize = 20;
            usedSerialPort.ReadTimeout = 120;
            usedSerialPort.StopBits = StopBits.One;
            usedSerialPort.Handshake = Handshake.None;
            usedSerialPort.DtrEnable = true;
            availablePortNames = GetAvailablePortNames();
            FindDevice();
        }
        private string[] GetAvailablePortNames()
        {
            int num;
            string[] availablePortNames = SerialPort.GetPortNames().
                OrderBy(a => a.Length > 3 && int.TryParse(a.Substring(3), out num) ? num : 0).ToArray();
            return availablePortNames;
        }
        private void FindDevice()
        {
            const byte commandPosition = 1;
            foreach (string portName in availablePortNames)
            {
                byte[] packageToSlave = new byte[20];
                byte[] packageFromSlave = new byte[20];

                if (usedSerialPort.IsOpen)
                {
                    usedSerialPort.Close();
                }

                usedSerialPort.PortName = portName;

                if (!usedSerialPort.IsOpen)
                {
                    usedSerialPort.Open();
                    usedSerialPort.Close();
                    usedSerialPort.Open();
                }
                
                packageToSlave = TransferData.MakePackage(converterAddress, (byte)ModbusCommand.FindMaster);
                TransferData.SendPackage(usedSerialPort, packageToSlave);
                if (TransferData.ReadAnswer(usedSerialPort, packageFromSlave))
                {
                    if (packageFromSlave[commandPosition] == (byte)ModbusCommand.FindMaster)
                    {
                        converterFounded = true;
                    }
                }
                if (usedSerialPort.IsOpen)
                {
                    usedSerialPort.Close();
                }
            }
        }
    }
}
