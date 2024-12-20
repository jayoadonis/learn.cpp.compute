
#ifndef __LEARN$CPP$COMPUTE$SAMPLE_II$CALCULATOR_H
#define __LEARN$CPP$COMPUTE$SAMPLE_II$CALCULATOR_H

#include <string>

namespace learn::cpp::compute::sample_ii {
  class Calculator {
    public: explicit Calculator();
    public: virtual ~Calculator();
    public: virtual std::string toString() const;
  };
}

#endif