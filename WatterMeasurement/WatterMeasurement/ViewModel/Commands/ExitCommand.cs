using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;
using WatterMeasurement.Model;

namespace WatterMeasurement.ViewModel.Commands
{
    public class ExitCommand : ICommand
    {
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            //throw new NotImplementedException();
            return true;
        }

        public void Execute(object parameter)
        {
            if (parameter is SlaveDevice device)
            {
                if (device.GetSerialPort.IsOpen)
                {
                    device.GetSerialPort.Close();
                }
            }

            //throw new NotImplementedException();
            Exit();

        }

        public void Exit()
        {
            Application.Current.Shutdown();
        }
    }
}
