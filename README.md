#STM32F767-Template

Build a template for the STM32F7 microprocessor, specifically the STM32F7 Discovery and Evaluation Board. Use Makefile to create a project template for containing HAL libraries.

Tested on Ubuntu 16.04.2 LTS, both using ARM GNU Toolchain and board STM32F767IGTx.

##Prerequisites
###GNU Toolchain
[https://developer.arm.com/open-source/gnu-toolchain/gnu-rm](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm)

GNU ARM Embedded Toolchain, pre-built for ARM Cortex-M and Cortex-R processors.

###Libraries
[http://www.st.com/en/embedded-software/stm32cubef7.html](http://www.st.com/en/embedded-software/stm32cubef7.html)

Inside the downloaded zip file, you can find STM32F7Cube embedded software stack composed of:

- STM32F7xx HAL (Hardware abstraction layer) and LL (low-layer) drivers
- CMSIS (Cortex Microcontroller Software Interface Standard) drivers
- BSP (Board Support Package) - middleware components (RTOS, USB, FatFs, graphics and TCP/IP).

With this template, you can have several project directories that use a common makefile.

##Demo project usage

The demo project basically just toggles some LED's on and off.

- clone the template

- run `make (all|clean|download)` int `Create/` dir,this is create `build/` dir in same dir.

- run make in the `create/` dir.

##Programming & debugging the board
###Linux debugging

[https://github.com/texane/stlink](https://github.com/texane/stlink)

Open source version of the STMicroelectronics Stlink Tools, made for Linux (in my case built from binaries for Ubuntu):  

- Start st-flash in on windows with `st-flash write test.bin address`

###Windows flashing
[http://www.st.com/en/embedded-software/stsw-link004.html](http://www.st.com/en/embedded-software/stsw-link004.html)

- Download ST-LINK Utility and add directory with st-link_cli executable to user/system PATH variable

##Acknowledgements
###Concept
Concept adapted from [STM32-Template github project](https://github.com/geoffreymbrown/STM32-Template).
