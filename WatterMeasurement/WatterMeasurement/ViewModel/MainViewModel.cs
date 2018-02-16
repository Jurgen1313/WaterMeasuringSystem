using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO.Ports;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using WatterMeasurement.Services.COM_Port;
using WatterMeasurement.Model;
using System.Windows;
using System.Diagnostics;
using WatterMeasurement.Services.ModBusCommand;
using System.Windows.Input;
using WatterMeasurement.ViewModel.Commands;

namespace WatterMeasurement.ViewModel
{

    public class MainViewModel : INotifyPropertyChanged
    {
        private byte converterAddress { get; set; }
        private byte measurementNumber { get; set; }
        public CounterSystem countersSystem { get; set; }
        private bool foundDevice;
        public SystemMeasurementsResults measurementsResults { get; set; }

        public ICommand SomeCommand { get; }

        //public MainViewModel()
        //{
        //    SomeCommand = new RelayCommand(SomeCommand_Execute, SomeCommand_CanExecute);
        //}

        //private bool SomeCommand_CanExecute(object arg)
        //{
        //    // can execute also should work for now
        //    throw new NotImplementedException();
        //}

        //private void SomeCommand_Execute(object obj)
        //{
        //    //  do stuff. you have all access to main viewmodel
        //}

        private byte currentMeasurementNumber { get; set; }
        public byte CurrentMeasurementNumber
        {
            get { return currentMeasurementNumber; }
            set
            {
                if (currentMeasurementNumber != value)
                {
                    currentMeasurementNumber = value;
                    CurrentMeasurementResults = SelectedMeasurement.counterMeasurementsResults[currentMeasurementNumber - 1];
                    OnPropertyChanged("CurrentMeasurementNumber");
                }
            }
        }

        private Measurement currentMeasurementResults { get; set; }
        public Measurement CurrentMeasurementResults
        {
            get { return currentMeasurementResults; }
            set
            {
                if (currentMeasurementResults != value)
                {
                    currentMeasurementResults = value;
                    OnPropertyChanged("CurrentMeasurementResults");
                }
            }
        }

        private CounterMeasurementsResults selectedMeasurement;
        public CounterMeasurementsResults SelectedMeasurement
        {
            get { return selectedMeasurement; }
            set
            {
                selectedMeasurement = value;
                OnPropertyChanged("SelectedMeasurement");
            }
        }

        private SlaveDevice selectedDevice;
        public SlaveDevice SelectedDevice
        {
            get { return selectedDevice; }
            set
            {
                if (selectedDevice != value)
                {
                    selectedDevice = value;
                    SelectedCounter = selectedDevice.counter[0];
                    OnPropertyChanged("SelectedDevice");
                }
            }
        }

        private Counter selectedCounter;
        public Counter SelectedCounter
        {
            get { return selectedCounter; }
            set
            {
                if (selectedCounter != value)
                {
                    selectedCounter = value;
                    SelectedMeasurement = measurementsResults.systemMeasurementsResults[SelectedDevice.DeviceNumber - 1].deviceMeasurementsResults[SelectedCounter.CounterNumber - 1];
                    CurrentMeasurementResults = SelectedMeasurement.counterMeasurementsResults[currentMeasurementNumber - 1];
                    OnPropertyChanged("SelectedCounter");
                    OnPropertyChanged("SetValueLiters");
                }
            }
        }

        public UInt32 SetValueLiters
        {
            get { return SelectedCounter.SetCounterValue; }
            set
            {
                SelectedCounter.SetCounterValue = value;
                CurrentMeasurementResults.SetCounterValue = value;
                OnPropertyChanged("SetValueLiters");
                //OnPropertyChanged("MeasurementSetCounterValue");
            }
        }

        public MainViewModel()
        {
            // Find converter
            converterAddress = 0x02;
            measurementNumber = 3;
            currentMeasurementNumber = 1;
            FindConverterDevice converter = new FindConverterDevice(converterAddress);

            if (converter.ConverterFounded)
            {
                //Find all slave devices
                byte startAddress = 10;
                byte endAddress = 30;
                FindSlaveDevices slaveDevices = new FindSlaveDevices(converter.UsedSerialPort, startAddress, endAddress);
                bool found = slaveDevices.DevicesFound;

                //create CounterSystemModel
                if (slaveDevices.DevicesFound)
                {
                    countersSystem = new CounterSystem(converter.UsedSerialPort, slaveDevices.GetFoundDevices);
                    measurementsResults = new SystemMeasurementsResults(measurementNumber, countersSystem.numberOfSlaveDevices);
                    //measurementsResults.systemMeasurementsResults[0].
                    //OnPropertyChanged(nameof(measurementsResults));
                    SelectedDevice = countersSystem.device[0];
                    SelectedCounter = SelectedDevice.counter[0];

                    Debug.WriteLine("measurementsResults");
                }
                else
                {
                    MessageBox.Show("Can't find SLAVE DEVICES", "ERROR", MessageBoxButton.OK, MessageBoxImage.Error);
                }
                foundDevice = true;
            }
            else
            {
                MessageBox.Show("CONVERTER NOT FOUND", "ERROR", MessageBoxButton.OK, MessageBoxImage.Error);
                Debug.WriteLine(countersSystem);
                foundDevice = false;
            }
        }
        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName]string prop = "")
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
        }

        //public void FindDevicesCommand()
        //{
        //    //Find all slave devices
        //    byte startAddress = 10;
        //    byte endAddress = 30;
        //    byte converterAddress = 0x02;

        //    FindConverterDevice converter = new FindConverterDevice(converterAddress);

        //    if (converter.ConverterFounded)
        //    {
        //        FindSlaveDevices slaveDevices = new FindSlaveDevices(converter.UsedSerialPort, startAddress, endAddress);
        //        bool found = slaveDevices.DevicesFound;

        //        //create CounterSystemModel
        //        if (slaveDevices.DevicesFound)
        //        {
        //            if (countersSystem == null)
        //                countersSystem = new CounterSystem(converter.UsedSerialPort, slaveDevices.GetFoundDevices);
        //            //SelectedDevice = countersSystem.device[0];
        //            //SelectedCounter = SelectedDevice.counter[0];                     
        //        }
        //        else
        //        {
        //            MessageBox.Show("Can't find SLAVE DEVICES", "ERROR", MessageBoxButton.OK, MessageBoxImage.Error);
        //        }
        //    }
        //    ////foundDevice = true;
        //    //MainViewModel.
        //    //Debug.WriteLine("");
        //}

    }
}
