using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WatterMeasurement.Model
{
    public class DeviceMeasurementsResults
    {
        public ObservableCollection<CounterMeasurementsResults> deviceMeasurementsResults;
        private uint numberOfMeasurements;

        public DeviceMeasurementsResults(uint numberOfMeasurements)
        {
            const int numberOfCounters = 7;
            this.numberOfMeasurements = numberOfMeasurements;
            deviceMeasurementsResults = new ObservableCollection<CounterMeasurementsResults>();
            for (int i = 0; i < numberOfCounters; ++i)
            {
                deviceMeasurementsResults.Add(new CounterMeasurementsResults(this.numberOfMeasurements));
            }
        }
    }
}
