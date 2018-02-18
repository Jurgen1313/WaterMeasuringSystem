using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;


namespace WatterMeasurement.ViewModel.Commands
{
    public class FindDevices : ICommand
    {
        private ViewModelCommands selectedDevice;
        private byte converterAddress = 0x02;

        public FindDevices(ViewModelCommands selectedDevice)
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
            MainViewModel tmpMainViewModel = parameter as MainViewModel;
            if (tmpMainViewModel != null)
            {
                tmpMainViewModel.FindSystem(converterAddress);
            }
            Debug.WriteLine("");
            //FindSystem();
            //throw new NotImplementedException();
        }
    }
}
