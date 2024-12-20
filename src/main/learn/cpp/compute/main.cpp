
#include "learn/cpp/compute/sample_i/Calculator.h"
#include "learn/cpp/compute/sample_ii/Calculator.h"
#include "learn/cpp/compute/Bootstrap.h"
#include "learn/cpp/compute/util.h"

#include <stdio.h>

int main(int arg_c, char ** arg_v ) {

    {
        learn::cpp::compute::Bootstrap boots;
        learn::cpp::compute::sample_i::Calculator calc;
        learn::cpp::compute::sample_ii::Calculator calc1;
    }

    std::printf("::: Hi there.\n");
    std::printf("::: Done...\n");
    
    return 0;
}