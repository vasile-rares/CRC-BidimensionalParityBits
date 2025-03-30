# CRC & Bidimensional Parity Bits 🛡️🔒

[![Platform](https://img.shields.io/badge/Platform-Windows-brightgreen.svg)](https://www.microsoft.com/windows)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)

This project demonstrates two error detection techniques commonly used in data communication:

1. CRC (Cyclic Redundancy Check)
2. Bidimensional Parity Bits

## 🔄 CRC (Cyclic Redundancy Check)

CRC is a powerful error-detecting code widely used in digital networks and storage devices to detect accidental changes to raw data.

### How it works:

1. Takes a binary message and a polynomial generator as input
2. Appends zeros to the original message based on the polynomial's degree
3. Performs polynomial division (using XOR operations) to calculate the remainder
4. Appends the remainder to the original message to create the transmitted message
5. Receivers can verify the integrity of data by performing the same division - if the remainder is zero, the data is likely error-free

### Implementation:

-   Uses binary representation for both the message and the generator
-   Calculates CRC code through modulo-2 division
-   Outputs the original message with its appended CRC code

## 🔲 Bidimensional Parity Bits

The bidimensional parity bit method arranges data in a matrix and adds parity bits for both rows and columns, providing a way to not only detect errors but also locate where they occurred.

### How it works:

1. Takes a binary string input (multiple of 7 characters)
2. Arranges the data in a matrix with 7 bits per row
3. Calculates and adds parity bits for each row (8th column)
4. Calculates and adds parity bits for each column (last row)
5. Can detect and locate single-bit errors by identifying which row and column parity checks fail

### Implementation:

-   Organizes input into a matrix format
-   Calculates parity bits for both dimensions
-   Includes a simulation of bit corruption for demonstration
-   Detects and reports the exact location of the corrupted bit

## 💻 Usage

Both applications are console-based programs that prompt for user input:

### CRC:

-   Enter a binary string message
-   Enter a binary generator polynomial
-   The program outputs the transmitted message with the CRC code

### Bidimensional Parity Bits:

-   Enter a binary string (length must be a multiple of 7)
-   The program displays the parity matrix, corrupts a random bit, and shows how the error is detected

## 🔨 Building the Project

The project is built using Visual Studio with C++. Open the solution file and build both projects to generate the executables
