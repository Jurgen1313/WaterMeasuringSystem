using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WatterMeasurement.Model;
using WatterMeasurement.ViewModel;

namespace WatterMeasurement.Services.Assets
{
    public sealed class CombinedTwoValues
    {
        public CounterSystem counterSystem;
        public SystemMeasurementsResults measurementResults;
        public MainViewModel mainVm;
    }
}
