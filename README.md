# Neural-Network-Implementation-on-FPGA
Implementing the Artificial Neural Network on Hardware platform FPGA(PYNQ Z1).

## AIM of the Project
The project involves the host PC transmitting test images to the PYNQ-Z1 board via UART. On the board, a bare-metal software application serves as the intermediary between the host PC and the hardware. This application receives the test image from the host PC and transfers it to the hardware inference module via BRAM. The inference process occurs within the hardware, and the result is then displayed using the onboard LEDs. Additionally, the inference result is sent back through the software application to the host PC, completing the feedback loop. This seamless interaction between the host PC, the PYNQ-Z1 board, and the hardware inference module facilitates efficient image processing and inference tasks.

## HLS
C++ code for creating a basic neural network Intellectual Property (IP) using high-level synthesis in Xilinx HLS.

## Python
Python scripts for training a basic neural network, extracting its weights, and interacting with the generated neural network inference hardware module.

## VHDL
VHDL code modules for managing the generated neural network inference hardware module.

## Vitis
Making C code application for facilitating communication between a host PC and the generated neural network inference hardware module.



### Prerequisites
Pynq-Z1 board, PC, USB-A to micro USB cable.






