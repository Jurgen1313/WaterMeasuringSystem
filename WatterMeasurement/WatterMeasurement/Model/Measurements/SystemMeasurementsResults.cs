using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WatterMeasurement.Model
{
    public class SystemMeasurementsResults
    {
        public ObservableCollection<DeviceMeasurementsResults> systemMeasurementsResults;
        private uint numberOfMeasurements;

        public SystemMeasurementsResults(uint numberOfMeasurements, uint numberOfDevices)
        {
            this.numberOfMeasurements = numberOfMeasurements;
            systemMeasurementsResults = new ObservableCollection<DeviceMeasurementsResults>();
            for (int i = 0; i < numberOfDevices; ++i)
            {
                systemMeasurementsResults.Add(new DeviceMeasurementsResults(this.numberOfMeasurements));
            }
        }
    }
}
