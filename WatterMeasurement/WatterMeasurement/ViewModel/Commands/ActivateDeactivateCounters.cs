using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using WatterMeasurement.Model;
using WatterMeasurement.Services.ModBusCommand;

namespace WatterMeasurement.ViewModel.Commands
{
    //public DelegateCommand sdfsdfsdf();
    public class ActivateDeactivateCounters : ICommand
    {
        public ActivateDeactivateCounters()
        {
        }

        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            //object tmpObj = parameter;
            //if (tmpObj != null)
            //{
            //    var receivedSlaveDevice = tmpObj as SlaveDevice;
            //    if (receivedSlaveDevice != null)
            //    {
            //        return true;
            //    }
            //    return false;
            //}
            //return false;
            return true;
        }

        public void Execute(object parameter)
        {
            //Debug.WriteLine("You made it!!!!");
            var slaveDevice = parameter as SlaveDevice;
            if (slaveDevice != null)
                TransferData.ActivateDeactivateCountersInDevice(parameter as SlaveDevice);
            else
                MessageBox.Show("Invalid parameter in ActivateDeactivateCounters command");
        }
    }
}
