using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using WatterMeasurement.ViewModel;
using WatterMeasurement.View;
using WatterMeasurement.Model;

namespace WatterMeasurement
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        public App()
        {
            var mainWindow = new MainWindow()
            {
                DataContext = new MainViewModel()   
            };
            mainWindow.Show();
        }
    }
}
