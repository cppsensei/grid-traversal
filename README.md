# Project Name

This project finds the longest possible path in a 2D grid with blocked cells, visiting as many unique (non-repeated) positions as possible within a fixed number of moves. Movement is allowed only up, down, left, or right, and revisiting cells is allowed but does not count as unique.

# Build Instructions

To build the project, follow these steps:

   ```bash
   git clone <repository-address>
   cd grid-traversal
   chmod +x build.sh
   ./build.sh
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
   chmod +x GridMain
   ./GridMain
   ```

# Limitation

The project has currently been tested only on x86_64 Linux systems.
Compatibility with other architectures or operating systems has not yet been verified.
