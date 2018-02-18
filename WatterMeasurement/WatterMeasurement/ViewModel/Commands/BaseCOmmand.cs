using System;
using System.Windows.Input;

namespace WatterMeasurement.ViewModel.Commands
{
    public abstract class BaseCOmmand : ICommand
    {
        public virtual bool CanExecute(object parameter) => true;

        public abstract void Execute(object parameter);

        public event EventHandler CanExecuteChanged
        {
            add => CommandManager.RequerySuggested += value;
            remove => CommandManager.RequerySuggested -= value;
        }
    }
}