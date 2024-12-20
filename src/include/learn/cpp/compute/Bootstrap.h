
#ifndef __LEARN$CPP$COMPUTE$BOOTSTRAP_H
#define __LEARN$CPP$COMPUTE$BOOTSTRAP_H

#include "learn/cpp/compute/util.h"
#include <stdio.h>
// #include <iostream>
#include <typeinfo>
#include <string>


namespace learn::cpp::compute {
  class Bootstrap {
    public: explicit Bootstrap() {
      std::printf(
        "%s@%p\n", 
        demangle(typeid(*this).name()).c_str(), 
        (void*)this
      );
    }
    public: virtual ~Bootstrap() {
      std::printf("~%s\n", this->toString().c_str());
    }
    public: std::string toString() {
      const std::type_info& TYPE_INFO = typeid(*this);
      const std::string CLASS_CANONICAL_NAME = demangle(TYPE_INFO.name());
      
      constexpr int BUFF_LEN = 512;
      char BUFF[BUFF_LEN] = {0};

      const int DELTA_BUFF_LEN = snprintf( BUFF, BUFF_LEN, "%s@%p", CLASS_CANONICAL_NAME.c_str(), (void*)this);

      if( DELTA_BUFF_LEN > 0 && DELTA_BUFF_LEN < BUFF_LEN )
        return std::string(BUFF);

      return CLASS_CANONICAL_NAME;
    }
  };
}

#endif