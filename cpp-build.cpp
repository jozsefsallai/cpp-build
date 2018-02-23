/*********************************************************************
 * 
 * C++ Build and Run
 * Quickly build and execute your C++ programs in the Windows Command
 * Line or Bash. 
 * 
 * Copyright (c) Jozsef Sallai (jozsef@sallai.me)
 * 
 * This piece of code is licensed under the GNU General Public License
 * as published by the Free Software Foundation. Please check the
 * LICENSE file included in this repository for more details.
 * 
 * The author of this code does NOT guarantee its flawless operation.
 * Community contributions are more than welcome.
 * 
 *********************************************************************/

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cstring>

bool fileCheck(const std::string filename) {
    // Check if executable file exists
    std::ifstream f(filename.c_str());
    return f.good();
}

int main (int argsNum, char* Args[]) {
    if (argsNum != 2) {
        // Check if CPP file was provided as argument
        std::cout << "Please specify the C++ file you'd like to build and run.";
        return -1;
    }

    // Get CPP file name from argument list
    std::string filename(Args[1]);
    std::string execname;

    #ifdef _WIN32
    execname = filename + ".exe";
    #else
    execname = filename;
    #endif

    if (fileCheck(execname)) {
        // Necessary step, especially for failed builds
        if (remove((execname).c_str()) != 0) {
            std::cout << "Error deleting file.";
            return -1;
        }
    }

    // Build the thing!
    std::string build = "g++ " + filename + ".cpp -o" + execname;
    system(build.c_str());

    std::cout << "Build job ended. Attempting to run executable...\n";

    if (fileCheck(execname)) {
        // Run the thing!
        std::string run;

        #ifdef _WIN32
        run = execname;
        #else
        run = "./" + execname;
        #endif
        
        std::cout << "Running...\n\n";
        system(run.c_str());
    } else {
        std::cout << "Couldn't run executable. The build has probably failed. Fix the errors described above, and try again.\n";
        return -1;
    }

    // Extra newline for *nix
    std::cout << std::endl;

    return false;
}
