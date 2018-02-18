using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Threading;
using WatterMeasurement.Model;
using WatterMeasurement.Services.Assets;
using WatterMeasurement.Services.ModBusCommand;
using WatterMeasurement.ViewModel;
using WatterMeasurement.ViewModel.Converters;

namespace WatterMeasurement.ViewModel.Commands
{
    public class StartMeasurement : BaseCOmmand
    {
        private CounterSystem systemDevice;
        private SystemMeasurementsResults measurementsResults;
        private byte currentMeasurementNumber;
        MainViewModel mainViewModel;
        private DispatcherTimer timer;

        public StartMeasurement(ViewModelCommands selectedDevice)
        {
        }
       

        public override bool CanExecute(object parameter)
        {
            mainViewModel = parameter as MainViewModel;

            if (mainViewModel != null)
            {
                this.systemDevice = mainViewModel.countersSystem;
                this.measurementsResults = mainViewModel.measurementsResults;
                this.currentMeasurementNumber = mainViewModel.CurrentMeasurementNumber;

                //Debug.WriteLine("FNC true");
                if (systemDevice != null)
                {
                    foreach (var device in systemDevice.device)
                    {
                        foreach (var counter in device.counter)
                        {
                            if (counter.Active)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        }

        public override void Execute(object parameter)
        {
            MainViewModel mainViewModel = parameter as MainViewModel;
            int[] numberOfActiveDevices;

            if (mainViewModel != null)
            {
                numberOfActiveDevices = SetValuesStartMeasurements(mainViewModel.countersSystem);

                timer = new DispatcherTimer()
                {
                    Interval = TimeSpan.FromSeconds(1),
                    IsEnabled = false,
                    Tag = numberOfActiveDevices
                };
                timer.Tick += timer_Tick;
                timer.Start();
            }
            else
            {
                MessageBox.Show("Invalid input parameter in StartMeasurement command");
            }
        }

        private int[] SetValuesStartMeasurements(CounterSystem devices)
        {
            CounterSystem countersSystem  = devices;

            int[] numberOfActiveDevices = new int[countersSystem.numberOfSlaveDevices]; 

            int index = 0;
            foreach (var device in countersSystem.device)
            {
                foreach (var counter in device.counter)
                {
                    if (counter.Active == true)
                    {
                        numberOfActiveDevices[index] = 1;
                        //++numberOfActiveCountersInDevice[index];
                        if (TransferData.IsAllSetCouterParametersOK(counter))
                        {
                            if (!TransferData.SetCounterValues(counter))
                            {
                                MessageBox.Show("Error writing data to device at address: " + device.DeviceAddress + " counter: " + counter.CounterNumber);
                            }
                        }
                        else
                        {
                            MessageBox.Show("Counter parameters are not correct: " + counter.CounterNumber);
                        }
                    }
                }
                if (numberOfActiveDevices[index] == 1)
                {
                    TransferData.DeviceMakeSendReadCommand(device, (byte)ModbusCommand.StartCounters);
                }
                ++index;
            }

            //start devicec
            //Debug.WriteLine(numberOfActiveCountersInDevice);
            return numberOfActiveDevices;
        }

        private int[] NumberOfActiveCountersInDevice(MainViewModel mainViewModel)
        {
            MainViewModel tmpMainViewModel = mainViewModel;
            int[] numberOfActiveCountersInDevice = new int[tmpMainViewModel.countersSystem.numberOfSlaveDevices];
            int index = 0;
            foreach (var device in tmpMainViewModel.countersSystem.device)
            {
                //numberOfActiveCountersInDevice[index] = TransferData.IsActiveCountersInDevice(device);
                foreach (var counter in device.counter)
                {
                    if (counter.Active == true)
                    {
                        ++numberOfActiveCountersInDevice[index];
                    }
                }
                ++index;
            }
            Debug.WriteLine(numberOfActiveCountersInDevice);
            return numberOfActiveCountersInDevice;
        }


        private void timer_Tick(object sender, EventArgs e)
        {

            DispatcherTimer tmpTimer = sender as DispatcherTimer;            

            //MessageBox.Show(DateTime.Now.ToString("HH:mm:ss"));
            //CounterSystem tmpSystemDevice = systemDevice;
            int[] numberOfActiveDevices = (int[])tmpTimer.Tag;

            Debug.WriteLine(numberOfActiveDevices);
            int index = 0;
            bool readyToReadData = true;
            foreach (var device in numberOfActiveDevices)
            {
                if (device == 1)
                {
                    if (TransferData.DeviceFinishedMeasurements(systemDevice.device[index]))
                    {
                        //numberOfActiveDevices++;
                        numberOfActiveDevices[index] = 0;
                    }
                }
                readyToReadData &= !Convert.ToBoolean(device);
                ++index;
            }

            if (readyToReadData)
            {
                timer.Stop();
                //READ DATA from slave devices
                //systemDevice.device[0].counter[0].CounterNumber
                foreach (var device in systemDevice.device)
                {
                    foreach (var counter in device.counter)
                    {
                        if (counter.Active)
                        {
                            UInt32 resultValueFromCounter;
                            double measuredCounterValue;
                            //counter.CounterNumber                            
                            //Read Counter value
                            resultValueFromCounter = TransferData.ReadCounterMeasuredValue(counter, (byte)ModbusCommand.ReadPulsesFromCounter);
                            measuredCounterValue = resultValueFromCounter * counter.CounterPulsesPerLiter;
                            measurementsResults.systemMeasurementsResults[device.DeviceNumber - 1].deviceMeasurementsResults[counter.CounterNumber - 1].counterMeasurementsResults[currentMeasurementNumber - 1].MeasuredCounterValue = measuredCounterValue;
                            //Read Examplary Counter value
                            resultValueFromCounter = TransferData.ReadCounterMeasuredValue(counter, (byte)ModbusCommand.ReadExamplaryValue);
                            measuredCounterValue = resultValueFromCounter * counter.CounterPulsesPerLiter;
                            measurementsResults.systemMeasurementsResults[device.DeviceNumber - 1].deviceMeasurementsResults[counter.CounterNumber - 1].counterMeasurementsResults[currentMeasurementNumber - 1].MeasuredExamplaryCounterValue = measuredCounterValue;
                        }
                    }
                }
                this.mainViewModel.CurrentMeasurementNumber++;
            }
        }

        //private 
        //private void StartMeasurements(CounterSystem counterSystem)
        //{
        //    CounterSystem tmpCounterSystem = counterSystem;

        //    foreach (var device in tmpCounterSystem.device)
        //    {
        //        int activeCounters = 0;
        //        int index = 0;
        //        foreach (var counter in device.counter)
        //        {
        //            if (counter.Active)
        //            {
        //                activeCounters |= 1 << index;
        //                if (TransferData.IsAllSetCouterParametersOK(counter))
        //                {
        //                    TransferData.SetCounterValues(counter);
        //                }
        //            }
        //            ++index;
        //        }
        //        if (activeCounters != 0)
        //        {
        //            TransferData.MakeSendRead(device.GetSerialPort, device.DeviceAddress, (byte)ModbusCommand.StartCounters, (byte)ModbusCommand.PackageReceivedSuccessfully);
        //        }
        //    }
        //    //Start measurement
        //}

        //private bool SetCounterValues(Counter counter)
        //{
        //    Counter activeCounter = counter;
        //    byte[] packageToSlave = new byte[20];
        //    byte[] packageFromSlave = new byte[20];
        //    bool packageSentSuccessful = false;

        //    packageSentSuccessful =TransferData.MakeSendRead(activeCounter.UsedSerialPort, activeCounter.CounterAddress, (byte)ModbusCommand.SetNumberOfPulses, 
        //                (byte)ModbusCommand.PackageReceivedSuccessfully, (byte)(activeCounter.CounterNumber - 1), activeCounter.SetCounterValue);
        //    return packageSentSuccessful;
        //}
        //private int IsActiveCountersInDevice(SlaveDevice device)
        //{
        //    SlaveDevice _device = device;
        //    int index = 0;
        //    int activeCounters = 0;

        //    foreach (var counter in _device.counter)
        //    {
        //        if (counter.Active)
        //        {
        //            activeCounters |= 1 << index;
        //        }
        //        ++index;
        //    }
        //    return activeCounters;
        //}
        //private bool IsAllSetCouterParametersOK(Counter _counter)
        //{
        //    Counter counter = _counter;            
        //    return (counter.SetCounterValue > 0 && counter.CounterPulsesPerLiter > 0);
        //}
    }

    //public class RelayCommand : ICommand
    //{
    //    private Action<object> execute;
    //    private Func<object, bool> canExecute;

    //    public event EventHandler CanExecuteChanged
    //    {
    //        add { CommandManager.RequerySuggested += value; }
    //        remove { CommandManager.RequerySuggested -= value; }
    //    }

    //    public RelayCommand(Action<object> execute, Func<object, bool> canExecute = null)
    //    {
    //        this.execute = execute;
    //        this.canExecute = canExecute;
    //    }

    //    public bool CanExecute(object parameter)
    //    {
    //        return this.canExecute == null || this.canExecute(parameter);
    //    }

    //    public void Execute(object parameter)
    //    {
    //        this.execute(parameter);
    //    }
    //}
}
