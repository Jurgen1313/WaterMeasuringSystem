using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using WatterMeasurement.Model;
using WatterMeasurement.Services.ModBusCommand;

namespace WatterMeasurement.ViewModel.Commands
{
    public class ReadCounterMeasuredValue : ICommand
    {
        private ViewModelCommands selectedDevice;

        public ReadCounterMeasuredValue(ViewModelCommands selectedDevice)
        {
            this.selectedDevice = selectedDevice;
        }
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            //throw new NotImplementedException();
            return true;
        }

        public void Execute(object parameter)
        {
            Counter counter = parameter as Counter;
            if (counter != null)
            {
                TransferData.ReadCounterMeasuredValue(counter, (byte)ModbusCommand.ReadPulsesFromCounter);
            }
            
            //throw new NotImplementedException();
        }
    }
}
