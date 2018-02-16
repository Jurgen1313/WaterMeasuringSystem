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
    public class SetValueToCounter : ICommand
    {
        private ViewModelCommands selectedDevice;

        public SetValueToCounter(ViewModelCommands selectedDevice)
        {
            this.selectedDevice = selectedDevice;
        }

        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            object tmpObj = parameter;
            if (tmpObj != null)
            {
                var receivedCounter = tmpObj as Counter;
                if (receivedCounter != null)
                {
                    if (receivedCounter.SetCounterValue != 0)
                        return true;
                }
                return false;
            }
            return false;
        }

        public void Execute(object parameter)
        {
            SetAllValuesToCounter(parameter as Counter);
        }
        private void SetAllValuesToCounter(Counter selectedCounter)
        {
            const int maxPackageLenght = 20;
            bool sentSuccessful;
            byte[] packageToSlave = new byte[maxPackageLenght];
            byte[] packageFromSlave = new byte[maxPackageLenght];

            packageToSlave = TransferData.MakePackage(selectedCounter.CounterAddress, (byte)ModbusCommand.SetNumberOfPulses,
                (byte)(selectedCounter.CounterNumber - 1), selectedCounter.SetCounterValue);
            //packageToSlave = TransferData.MakePackage(slaveAddress, (byte)ModbusCommand.FindDevices);
            sentSuccessful = TransferData.SendPackage(selectedCounter.UsedSerialPort, packageToSlave);
        }

    }
}
