using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using WatterMeasurement.Model;

namespace WatterMeasurement.ViewModel.Commands
{
    public class ResetMeasurements : ICommand
    {
        private SystemMeasurementsResults measurementResults;
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            measurementResults = parameter as SystemMeasurementsResults;
            if (measurementResults != null)
                return true;
            return false;
        }

        public void Execute(object parameter)
        {
            ResetMeasurementsResult(parameter as SystemMeasurementsResults);
        }

        private void ResetMeasurementsResult(SystemMeasurementsResults _measurementResults)
        {
            SystemMeasurementsResults measurementResults = _measurementResults;
            for (int i = 0; i < measurementResults.systemMeasurementsResults.Count; ++i)
            {
                for (int j = 0;
                    j < measurementResults.systemMeasurementsResults[i].deviceMeasurementsResults.Count;
                    ++j)
                {
                    for (int k = 0; k < measurementResults.systemMeasurementsResults[i].deviceMeasurementsResults[j].counterMeasurementsResults.Count; k++)
                    {
                        measurementResults.systemMeasurementsResults[i].deviceMeasurementsResults[j]
                            .counterMeasurementsResults[k].ErrorValue = 0;
                        measurementResults.systemMeasurementsResults[i].deviceMeasurementsResults[j]
                            .counterMeasurementsResults[k].MeasuredCounterValue = 0;
                        measurementResults.systemMeasurementsResults[i].deviceMeasurementsResults[j]
                            .counterMeasurementsResults[k].MeasuredExamplaryCounterValue = 0;
                        measurementResults.systemMeasurementsResults[i].deviceMeasurementsResults[j]
                            .counterMeasurementsResults[k].SetCounterValue = 0;
                    }
                }
            }
        }
    }
}
