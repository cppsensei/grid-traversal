# Project Name

This project finds the longest possible path in a 2D grid with blocked cells, visiting as many unique (non-repeated) positions as possible within a fixed number of moves. Movement is allowed only up, down, left, or right, and revisiting cells is allowed but does not count as unique.

# Dependencies

For Linux (x86_64)
   ```bash
   sudo apt update
   sudo apt install build-essential cmake ninja-build git
   ```

For Windows (Win64) run in PowerShell
   ```bash
   winget install cmake
   winget install ninja
   winget install git
   winget install BrechtSanders.WinLibs.POSIX.UCRT
   ```

# Build Instructions

To build the project, follow these steps:

   ```bash
   git clone https://github.com/cppsensei/grid-traversal.git
   cd grid-traversal
   ./build.sh or .\build.ps1 (in PowerShell for Win64)
   ```

After building the project, the following directories will be created:

install/
install/bin/ – the compiled executable
install/include/ – the public API headers
install/lib/ – the compiled shared library (.so / .dll / .dylib depending on platform)

# Running Instructions

After perform 'Build Instruction' section you can run the compiled app.

   ```bash
   cd install/bin
   ./GridMain or .\GridMain.exe (for Win64)
   ```

# Limitation

The project has currently been tested on x86_64 Linux and Windows (Win64) architectures.
Compatibility with other architectures or operating systems has not yet been verified.
