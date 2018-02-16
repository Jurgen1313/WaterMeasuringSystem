using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Data;

namespace WatterMeasurement.ViewModel.Converters
{
    public class DeviceTypeConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value != null)
            {
                switch (value.ToString())
                {
                    case "1":
                        {
                            return "U"; // Ultrasound
                        }
                    case "2":
                        {
                            return "P"; // Pulse
                        }
                    case "3":
                        {
                            return "E_U"; // E_Ultrasound
                        }
                    case "4":
                        {
                            return "E_P"; // E_Pulse
                        }
                }
            }
            //if (value != null)
            //{
            //    switch (value)
            //    {
            //        case 1:
            //            {
            //                return "Ultrasound";
            //            }
            //        case 2:
            //            {
            //                return "Pulse";
            //            }
            //        case 3:
            //            {
            //                return "E_Ultrasound";
            //            }
            //        case 4:
            //            {
            //                return "E_Pulse";
            //            }
            //    }
            //}
            return null;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
            ////if (value != null)
            ////{
            //switch (value.ToString())
            //    {
            //        case "1":
            //            {
            //                return "Ultrasound";
            //            }
            //        case "2":
            //            {
            //                return "Pulse";
            //            }
            //        case "3":
            //            {
            //                return "E_Ultrasound";
            //            }
            //        case "4":
            //            {
            //                return "E_Pulse";
            //            }
            //    default: return string.Empty;
            //    }
            ////}
            //return null;
        }
    }
}
