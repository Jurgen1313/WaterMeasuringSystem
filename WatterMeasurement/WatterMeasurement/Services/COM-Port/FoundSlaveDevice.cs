using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace WatterMeasurement.Services.COM_Port
{
    public class FoundSlaveDevice : INotifyPropertyChanged
    {
        private byte slaveDeviceAddress;
        private byte slaveDeviceType;
        private byte slaveDeviceNumber;

        public FoundSlaveDevice(byte slaveDeviceAddress, byte slaveDeviceType, byte slaveDeviceNumber)
        {
            SlaveDeviceAddress = slaveDeviceAddress;
            SlaveDeviceType = slaveDeviceType;
            SlaveDeviceNumber = slaveDeviceNumber;
        }

        public byte SlaveDeviceAddress
        {
            get
            {
                return slaveDeviceAddress;
            }
            private set
            {
                slaveDeviceAddress = value;
                OnPropertyChanged("SlaveAddress");
            }
        }
        public byte SlaveDeviceType
        {
            get { return slaveDeviceType; }
            private set
            {
                slaveDeviceType = value;
                OnPropertyChanged("SlaveDeviceType");
            }
        }
        public byte SlaveDeviceNumber
        {
            get { return slaveDeviceNumber; }
            private set
            {
                slaveDeviceNumber = value;
                OnPropertyChanged("SlaveDeviceNumber");
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName]string prop = "")
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
        }
    }
}
