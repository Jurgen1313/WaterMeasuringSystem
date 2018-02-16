using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WatterMeasurement.Model
{
    public class Measurement : INotifyPropertyChanged
    {
        private ObservableCollection<double> measurement { get; set; }
        private int measurementNumber;
        private double setCounterValue;
        private double measuredCounterValue;
        private double measuredExamlaryCounterValue;
        private double errorValue;

        public double SetCounterValue
        {
            get { return setCounterValue; }
            set
            {
                if (setCounterValue != value)
                    setCounterValue = value;
                OnPropertyChanged("SetCounterValue");
            }
        }
        public double MeasuredCounterValue
        {
            get { return measuredCounterValue; }
            set
            {
                if (measuredCounterValue != value)
                    measuredCounterValue = value;
                OnPropertyChanged("MeasuredCounterValue");
            }
        }
        public double MeasuredExamplaryCounterValue
        {
            get { return measuredExamlaryCounterValue; }
            set
            {
                if (measuredExamlaryCounterValue != value)
                    measuredExamlaryCounterValue = value;
                OnPropertyChanged("MeasuredExamplaryCounterValue");
            }
        }
        public double ErrorValue
        {
            get { return errorValue; }
            set
            {
                if (errorValue != value)
                    errorValue = value;
                OnPropertyChanged("ErrorValue");
            }
        }
        public int MeasurementNumber
        {
            get { return measurementNumber; }
            set
            {
                if (measurementNumber != value)
                    measurementNumber = value;
                OnPropertyChanged(nameof(MeasurementNumber));
            }
        }
        //public Measurement(double setCounterValue)
        //{
        //    measurement = new ObservableCollection<double>
        //    { setCounterValue, measuredCounterValue, measuredExamlaryCounterValue, errorValue};
        //}
        public Measurement(int currentMeasurementNumber)
        {
            measurementNumber = currentMeasurementNumber;
            measurement = new ObservableCollection<double>
            { setCounterValue, measuredCounterValue, measuredExamlaryCounterValue, errorValue};
        }
        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(string param)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(param));
        }
    }
}
