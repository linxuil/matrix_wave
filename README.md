# MatrixWave

   MatrixWave is a solution for performing matrix multiplication and transmitting
   the results over SPI (Serial Peripheral Interface).

## 1. Project Description

   The aim of this project is:
   - Develop a user-space application `mt_mult_app` that performs
     matrix multiplication
   - And a driver `mt_spisend_driver` that transmits the matrix over SPI.

## 2. Project Structure

   The project includes:

   - An application for matrix multiplication (`mt_mult_app`)
   - A driver that can transmit matrices over SPI (`mt_spisend_driver`)
   - A simple serialization/deserialization functionality for transmitting matrix
     over SPI (`matrix_serialization.c`)

   The repository is structured as follows:

   - **mt_spisend_driver**: This directory contains the driver for transmitting
     matrix results over SPI.
     - `Makefile`: The makefile for building the driver.
     - `Make.defs`: The compiler definitions for building the driver.
     - `Kconfig`: The configuration file for the driver.
     - `matrix_serialization.c`: Source file implementing matrix serialization.
     - `...`: Other source files necessary for the driver.

   - **mt_mult_app**: This directory contains the application for matrix
     multiplication.
     - `Makefile`: The makefile for building the application.
     - `Make.defs`: The compiler definitions for building the application.
     - `Kconfig`: The configuration file for the application.
     - `...`: Other source files necessary for the application.

   - **tests**: This directory contains the unit tests for both the driver and
     the application. This includes:
     - `test_mt_mult_app.c`
     - `test_matrix_serialization.c`
     - `test_mt_spisend_driver.c`

## 3. How to Install

   The project is designed to work with the NuttX Real-Time Operating System.
   To install:
   - Clone this repository
   - Copy the directories (`mt_spisend_driver` and `mt_mult_app`) into
     the `apps` directory of your NuttX installation.
   - Then, you can include the driver and application in your 
     build configuration
     ```
     $ make menuconfig
     ```
   - And compile NuttX as usual.
     ```
     $ make -j
     ```

## 4. How to Use
   ...
