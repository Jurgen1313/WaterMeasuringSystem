# THIS FILE IS AUTOMATICALLY GENERATED
# Project: F:\Google\Cypress\WaterMeasurement\EmulRelay\psoc\PSoC_4200M_Watter_measurement_relay.cydsn\PSoC_4200M_Watter_measurement_relay.cyprj
# Date: Sat, 16 Dec 2017 10:14:39 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/ff_div_11}] [get_pins {ClockBlock/ff_div_12}] [get_pins {ClockBlock/ff_div_13}] [get_pins {ClockBlock/ff_div_14}] [get_pins {ClockBlock/ff_div_15}] [get_pins {ClockBlock/ff_div_16}] [get_pins {ClockBlock/ff_div_17}] [get_pins {ClockBlock/ff_div_18}]]
create_clock -name {UART_RS_485_SCBCLK(FFB)} -period 1437.5 -waveform {0 718.75} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 5} [list]
create_generated_clock -name {UART_RS_485_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 69 139} [list]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 16001 32001} -nominal_period 333333.33333333331 [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for F:\Google\Cypress\WaterMeasurement\EmulRelay\psoc\PSoC_4200M_Watter_measurement_relay.cydsn\TopDesign\TopDesign.cysch
# Project: F:\Google\Cypress\WaterMeasurement\EmulRelay\psoc\PSoC_4200M_Watter_measurement_relay.cydsn\PSoC_4200M_Watter_measurement_relay.cyprj
# Date: Sat, 16 Dec 2017 10:14:34 GMT