# Code for 6Sens Project : blinky application test for a customed MDBT50Q (based on nRF52840) board

## Overview
Simply Blinky example to know how to install, to configure and to use Zephyr RTOS.
The Blinky example shows how to configure GPIO pins as outputs which can also be used to drive LEDs on the hardware usually delivered as "User LEDs" on many of the supported boards in Zephyr. The Blinky sample blinks green LED (Tx LED of RFM95W transmission) and an another green LED (Rx LED of RFM95W transmission) forever using GPIO API.

This application also prints "Hello World" to the console and allows us that the device tree board file is correct (especially UART communication).
The version of Zephyr RTOS used is the version v4.0.0.

With the jlink runner, you can use either the usual console or the one developed by Segger (JLinkRTTViewer).

For Zephyr documentation, please click on this link: https://docs.zephyrproject.org/4.0.0/

## Board used
Original MDBT50Q board, powered by battery/solar panel. (see 6sens_prj repository/hardware part, for more information.)

## Building and Running
The following commands clean build folder, build and flash the sample:

**Command to use**
````
west build -t pristine

west build -p always -b mdbt50q_lora_dev applications/6sens_rtos_blinky

west flash --runner jlink