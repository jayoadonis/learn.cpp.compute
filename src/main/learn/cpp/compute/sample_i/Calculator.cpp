
#include "learn/cpp/compute/sample_i/Calculator.h"
#include "learn/cpp/compute/util.h"

#include <typeinfo>

namespace learn::cpp::compute::sample_i {
  Calculator::Calculator() {
    std::printf("%s\n", this->toString().c_str());
  }
  Calculator::~Calculator() {
    std::printf("~%s\n", this->toString().c_str());
  }

  std::string Calculator::toString() const {
    const std::type_info& TYPE_INFO = typeid(*this);
    const std::string CLASS_CANONICAL_NAME 
      = compute::demangle( TYPE_INFO.name() );
    constexpr std::size_t BUFF_LEN = 512;
    char BUFF[BUFF_LEN] = {0};

    const int32_t DELTA_BUFF_LEN = snprintf(
      BUFF, BUFF_LEN,
      "%s@%p", CLASS_CANONICAL_NAME.c_str(), this
    );

    if( DELTA_BUFF_LEN > 0 && DELTA_BUFF_LEN < BUFF_LEN )
      return BUFF;
    
    return CLASS_CANONICAL_NAME;
  }
}