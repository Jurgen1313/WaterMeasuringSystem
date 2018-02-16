using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using WatterMeasurement.Model;
using System.Diagnostics;

namespace WatterMeasurement.ViewModel.Commands
{
    public class FindAllDevices : ICommand
    {
        private MainViewModel viewModelCommand;
        public CounterSystem counterSystem;
        public FindAllDevices(MainViewModel viewModelCommand)
        {
            this.viewModelCommand = viewModelCommand;
        }
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            CounterSystem systemFound = parameter as CounterSystem;
            if (systemFound == null)
                return true;
            return false;
        }

        public void Execute(object parameter)
        {
            //throw new NotImplementedException();
            //FindDevicesCommand();
        }

        //private void FindDevicesCommand()
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
        //            if (counterSystem == null)
        //                counterSystem = new CounterSystem(converter.UsedSerialPort, slaveDevices.GetFoundDevices);
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
        //    Debug.WriteLine("");
        //}

    }
}
