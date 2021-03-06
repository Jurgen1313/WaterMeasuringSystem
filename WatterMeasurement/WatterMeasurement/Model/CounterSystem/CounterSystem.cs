﻿using System;
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
    public class CounterSystem : INotifyPropertyChanged
    {
        public ObservableCollection<SlaveDevice> device { get; set; }
        public bool foundSlaveDevice;
        public uint numberOfSlaveDevices { get; private set; }
        private UInt16 examplaryCounterPulsesPerLiter;
        public UInt16 ExamplaryCounterPulsesPerLiter
        {
            get { return examplaryCounterPulsesPerLiter; }
            set
            {
                examplaryCounterPulsesPerLiter = value;
                OnPropertyChanged("ExamplaryCounterPulsesPerLiter");
            }
        }

        public CounterSystem(SerialPort serialPort, List<FoundSlaveDevice> AllSlaveDevices)
        {
            device = new ObservableCollection<SlaveDevice>();
            numberOfSlaveDevices = 0;

            foreach (var slaveDevice in AllSlaveDevices)
            {
                device.Add(new SlaveDevice(serialPort, slaveDevice));
                //SlaveDevice newSlave = new SlaveDevice(serialPort, slaveDevice);
                //Device = newSlave;
                //AddDevice(serialPort, slaveDevice);
                numberOfSlaveDevices++;
                //OnPropertyChanged("device.Add");
            }
        }

        //public ObservableCollection<SlaveDevice> Device {
        //    get { return device; }
        //    set
        //    {
        //        device.Add(value);
        //        OnPropertyChanged("Device");
        //    }
        //}

        public void AddDevice(SerialPort serialPort, FoundSlaveDevice slaveDevice)
        {
            device.Add(new SlaveDevice(serialPort, slaveDevice));
            OnPropertyChanged(nameof(AddDevice));
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(string prop = "")
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
        }
    }
}
