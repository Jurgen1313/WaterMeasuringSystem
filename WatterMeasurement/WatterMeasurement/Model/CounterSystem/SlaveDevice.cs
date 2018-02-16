using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO.Ports;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using WatterMeasurement.Services.COM_Port;

namespace WatterMeasurement.Model
{
    public sealed class SlaveDevice : INotifyPropertyChanged
    {
        public ObservableCollection<Counter> counter { get; set; }
        private byte deviceType;
        private byte deviceAddress;
        private byte deviceNumber;
        private SerialPort serialPort;

        public SlaveDevice(SerialPort serialPort, FoundSlaveDevice slaveDevices)
        {
            deviceAddress = slaveDevices.SlaveDeviceAddress;
            deviceType = slaveDevices.SlaveDeviceType;
            deviceNumber = slaveDevices.SlaveDeviceNumber;
            this.serialPort = serialPort;
            counter = new ObservableCollection<Counter>();
            for (int i = 0; i < 7; ++i)
            {
                counter.Add(new Counter(slaveDevices.SlaveDeviceType, slaveDevices.SlaveDeviceAddress, serialPort, (byte)(i + 1)));
            }
        }
        public byte DeviceAddress
        {
            get
            {
                return deviceAddress;
            }
        }
        public byte DeviceType
        {
            get
            {
                return deviceType;
            }
        }
        public byte DeviceNumber
        {
            get { return deviceNumber; }
        }
        public SerialPort GetSerialPort
        {
            get
            {
                return serialPort;
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(string prop = "")
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
        }
    }
}
