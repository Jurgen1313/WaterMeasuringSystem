using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WatterMeasurement.ViewModel.Commands;

namespace WatterMeasurement.ViewModel
{
    public class ViewModelCommands
    {
        //public ActivateCounter activateCounters { get; set; }
        public ActivateDeactivateCounters ActivateDeactivateCountersInDevice { get; set; }
        public SetValueToCounter SetValuesToCounter { get; set; }
        public StartMeasurement StartMeasurements { get; set; }
        public ReadCounterMeasuredValue ReadCounterMeasuredValues { get; set; }
        public ExitCommand ProgramExit { get; set; }
        public ResetMeasurements ResetMeasuremet { get; set; }
        //public FindAllDevices FindDevices { get; set; }

        public ViewModelCommands()
        {
            //this.activateCounters = new ActivateCounter();
            this.ActivateDeactivateCountersInDevice = new ActivateDeactivateCounters(this);
            this.SetValuesToCounter = new SetValueToCounter(this);
            this.StartMeasurements = new StartMeasurement(this);
            this.ReadCounterMeasuredValues = new ReadCounterMeasuredValue(this);
            this.ProgramExit = new ExitCommand();
            this.ResetMeasuremet = new ResetMeasurements();
            //this.FindDevices = new FindAllDevices(this);
        }
    }
}
