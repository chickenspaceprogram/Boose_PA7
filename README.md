# Poker - PA 7

To build this project, you must have CMake installed.
You can download it [here](https://cmake.org/download/), or use your preferred package manager.

### Configuring CMake

To configure the CMake project, navigate into the `build` directory using a terminal, and enter `cmake .` to configure CMake. Once you've configured CMake, you can then build the project.

### Building on *nix

To build the project on a Unix-based OS, enter `cmake --build .` when in the `build` directory, or `cmake --build build` when in the parent `Boose_PA7` directory. The executable will then compile and will be located in the `build` directory.

### Building on Windows

To build the project on Windows, you must use Microsoft Visual Studio. Open the `Boose_PA7.sln` file located in the `build` directory. Once Visual Studio has opened, right-click `Boose_PA7` in the Solution Explorer and select `Set as Startup Project`. Then, build the project.

### Running Poker

To run this project, simply run the executable generated.

On Windows, use Visual Studio to run the project.

On Unix-based systems, the executable is located in `build/Boose_PA7`.
You can then run it either by selecting it in your file manager, or by running it on the command line with `build/Boose_PA7` (if you're in the `Boose_PA7` directory) or `./Boose_PA7` (if you're in the `build` directory).

If you decide to exit this program while it is running using Ctrl+C, your terminal settings may be altered.
To fix this on Unix systems, enter the command `reset` into the terminal.
Alternately, quit and reopen your terminal emulator.

## Code explanation

There is less UI-specific code for this PA as compared to previous ones, since I wasn't going to spend the time necessary to make ASCII art for every card.

`help.h/c` contains a function generated by `cbintxt`, an application that is available [here](https://github.com/chickenspaceprogram/cbintxt) under the Mozilla Public License 2.0. `cbintxt` compiles text files into C code that can print the contents of those files. This allows text to be loaded into a program at compiletime rather than at runtime, and eliminates runtime errors resulting from files not being found or not being openable.

`src/ctty/` is my cross-platform terminal graphics library, available [here](https://github.com/chickenspaceprogram/ctty) under the Mozilla Public License 2.0. View the readme in that folder for its documentation.