
#include "learn/cpp/compute/sample_i/Calculator.h"
#include "learn/cpp/compute/sample_ii/Calculator.h"
#include "learn/cpp/compute/Bootstrap.h"
#include "learn/cpp/compute/util.h"

#include <stdio.h>
#include <fstream>
#include <filesystem>
#include <iostream>

int main(int arg_c, char ** arg_v ) {
    
    std::printf("=== BEGIN: 1st\n");

    {
        learn::cpp::compute::Bootstrap boots;
        learn::cpp::compute::sample_i::Calculator calc;
        learn::cpp::compute::sample_ii::Calculator calc1;
    }

    std::printf("=== END: 1st\n");
    std::printf("=== BEGIN: 2nd\n");
    {
        const char* rezFile = "learn/cpp/compute/rez/.keep";
        std::ifstream file(rezFile);

        if( !file.is_open() ) {
            std::fprintf( 
                stderr, 
                "Error: Could not open the file: '%s'\n", 
                rezFile 
            );
        }
        else {
            std::string line;
            while( std::getline( file, line ) )
                std::printf("%s\n", line.c_str());
        }

        std::printf("===\n");

        //REM: [C++17] .|. 
        std::filesystem::path execPath 
            = std::filesystem::canonical("/proc/self/exe");
        std::filesystem::path execDir = execPath.parent_path();

        try {
            const std::string rezPath = (execDir / rezFile).string();
            std::ifstream fileII( rezPath );
            if( !fileII )
                throw std::runtime_error("Failed to open file: " + (rezPath) );
            
            std::string line;
            while( std::getline(fileII, line) )
                std::printf("%s\n", line.c_str() );

        }
        catch( const std::runtime_error& rErr ) {
            std::cerr << rErr.what() << std::endl;
        }
        catch( const std::exception& e ) {
            std::cerr << e.what() << std::endl;
        }


    }
    
    std::printf("=== END: 2nd\n");

    std::printf("::: Hi there.\n");
    std::printf("::: Done...\n");
    
    return 0;
}