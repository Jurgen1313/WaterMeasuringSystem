using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;
using WatterMeasurement.Model;
using WatterMeasurement.Services.Assets;

namespace WatterMeasurement.ViewModel.Converters
{
    //Converter
    public sealed class CombineTwoValues : IMultiValueConverter
    {
        public static CombineTwoValues Combine = new CombineTwoValues();

        public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
        {
            //throw new NotImplementedException();
            CombinedTwoValues combinedTwoValues = new CombinedTwoValues();

            CounterSystem counterSystem = values[0] as CounterSystem;
            if (counterSystem != null)
                combinedTwoValues.counterSystem = counterSystem;

            SystemMeasurementsResults measurementsResults = values[1] as SystemMeasurementsResults;
            if (measurementsResults != null)
                combinedTwoValues.measurementResults = measurementsResults;

            var mainVm = (MainViewModel)values[2];
            //if (currentMeasurementNumber != null)
            //combinedTwoValues.currentMeasurementNumber = ref currentMeasurementNumber;
            combinedTwoValues.mainVm = mainVm;

            Debug.WriteLine("");
            return combinedTwoValues;
        }

        public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
