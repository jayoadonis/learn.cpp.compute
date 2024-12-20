
#ifndef __LEARN$CPP$COMPUTE$SAMPLE_I$CALCULATOR_H
#define __LEARN$CPP$COMPUTE$SAMPLE_I$CALCULATOR_H

#include <stdio.h>
#include <string>

namespace learn::cpp::compute::sample_i {
  class Calculator {
    public: explicit Calculator();
    public: virtual ~Calculator();
    public: virtual std::string toString() const;
  };
}

#endif