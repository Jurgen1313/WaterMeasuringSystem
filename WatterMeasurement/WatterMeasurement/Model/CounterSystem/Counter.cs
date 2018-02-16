using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO.Ports;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace WatterMeasurement.Model
{
    public class Counter : INotifyPropertyChanged
    {
        #region data        
        private byte counterNumber;
        private bool active;
        private UInt32 setCounterValue;
        private UInt32 measuredCounterValue;
        private UInt32 measuredExamplaryCounterValue;
        private string owner;
        private string counterModel;
        private double counterPulsesPerLiter;
        private string counterSerialNumber;
        private UInt32 liters;
        //private double measuredNumberOfLitersWithCounter;
        //private double measuredNumberOfLitersWithExamplaryCounter;
        private byte counterType;
        private byte counterAddress;
        private SerialPort serialPort;
        #endregion
        
        public byte CounterNumber
        {
            get
            {
                return counterNumber;
            }
        }
        public byte CounterAddress
        {
            get { return counterAddress; }
        }
        public byte CounterType
        {
            get { return counterType; }
        }
        public Counter(byte counterType, byte counterAddress, SerialPort serialPort, byte counterNumber)
        {
            this.counterNumber = counterNumber;
            this.counterType = counterType;
            this.counterAddress = counterAddress;
            this.serialPort = serialPort;
        }        
        public SerialPort UsedSerialPort
        {
            get { return serialPort; }
        }
        public bool Active
        {
            get
            {
                return active;
            }
            set
            {
                if (active != value)
                    active = value;
                OnPropertyChanged("Active");
            }
        }
        public UInt32 SetCounterValue
        {
            get
            {
                return setCounterValue;
            }
            set
            {
                if (setCounterValue != value)
                    setCounterValue = value;
                OnPropertyChanged("SetCounterValue");
            }
        }
        public UInt32 CurrentCounterValue
        {
            get
            {
                return measuredCounterValue;
            }
            set
            {
                if (measuredCounterValue != value)
                    measuredCounterValue = value;
                OnPropertyChanged("setCurrentCounterValue");
            }
        }
        public UInt32 CurrentExamplaryCounterValue
        {
            get
            {
                return measuredExamplaryCounterValue;
            }
            set
            {
                if (measuredExamplaryCounterValue != value)
                    measuredExamplaryCounterValue = value;
                OnPropertyChanged("setCurrentExamplaryCounterValue");
            }
        }
        public string Owner
        {
            get
            {
                if (owner != null)
                    return owner;
                else
                    return "set owner name";
            }
            set
            {
                if (owner != value)
                    owner = value;
                OnPropertyChanged("Owner");
            }
        }
        public string CounterModel
        {
            get
            {
                return counterModel;
            }
            set
            {
                if (counterModel != value)
                    counterModel  = value;
                OnPropertyChanged("CounterModel");
            }
        }
        public string CounterSerialNumber
        {
            get
            {
                return counterSerialNumber;
            }
            set
            {
                if (counterSerialNumber!= value)
                    counterSerialNumber = value;
                OnPropertyChanged("CounterSerialNumber");
            }
        }
        public double CounterPulsesPerLiter
        {
            get
            {
                return counterPulsesPerLiter;
            }
            set
            {
                if (counterPulsesPerLiter != value)
                {
                    counterPulsesPerLiter = value;
                    //setCounterValue = (UInt32)(Liters / counterPulsesPerLiter);
                }
                OnPropertyChanged("CounterPulsesPerLiter");
            }
        }
        public UInt32 Liters
        {
            get { return liters; }
            set
            {
                if (liters != value)
                {
                    liters = value;
                    //setCounterValue = (UInt32)(liters / counterPulsesPerLiter);
                }
                OnPropertyChanged("Liters");
            }
        }

        //public double MeasuredNumberOfLitersWithCounter
        //{
        //    get
        //    {
        //        return measuredCounterValue * counterPulsesPerLiter;
        //    }
        //}
        
        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(string prop = "")
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
        }
    }
}
