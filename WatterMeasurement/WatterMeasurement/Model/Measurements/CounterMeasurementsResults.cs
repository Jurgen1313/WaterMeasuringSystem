using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WatterMeasurement.Model
{
    public class CounterMeasurementsResults
    {
        public ObservableCollection<Measurement> counterMeasurementsResults { get; set; }
        private uint numberOfMeasurement;
        private uint currentNumberOfMeasurement;
        //private double[,] measurement;

        public CounterMeasurementsResults(uint numberOfMeasurement)
        {
            this.numberOfMeasurement = numberOfMeasurement;
            counterMeasurementsResults = new ObservableCollection<Measurement>();
            for (int i = 0; i < numberOfMeasurement; ++i)
            {
                counterMeasurementsResults.Add(new Measurement(i+1));
            }
            //measurement = new double[numberOfMeasurement, 4];
            this.currentNumberOfMeasurement = 0;
        }

        public double MyProperty { get; set; }
    }
}
