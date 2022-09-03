# robotics_v1_entry

In order to execute the project copy the two .bin files containing the input and output data in the "test_input" directory. 
The CMake project will make sure those are passed to the Red Eye Remover.

In order to execute the project, enter the build directory and in the terminal run "cmake .." . Once this is finished, just run "make".
Afterwards in the /bin sub-folder there will be an executable file, which will run the project itself. All settings have been made
in advance via the CMake config.

## Notes:
- If by any chance git did not pull the build directory, you will need to create it manually, as well as the bin sub-folder inside.
- The CMake configuration file contains additional settings, which have been commented out. Those are used for running the
clang sanitizers on macOS and Ubuntu 22.4 , as well as some additional options and flags for CLion IDE.
