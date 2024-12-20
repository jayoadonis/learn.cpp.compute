

#include "learn/cpp/compute/sample_ii/Calculator.h"
#include "learn/cpp/compute/sample_i/Calculator.h"
#include "learn/cpp/compute/util.h"

#include <string>
#include <typeinfo>

namespace learn::cpp::compute::sample_ii {

  Calculator::Calculator() {
    std::printf("%s\n", this->toString().c_str());
  }

  Calculator::~Calculator() {
    std::printf("~%s\n", this->toString().c_str());
  }

  std::string Calculator::toString() const {
    const std::type_info& TYPE_INFO = typeid(*this);
    const std::string CLASS_CANNONICAL_NAME 
      = compute::demangle( TYPE_INFO.name() );
    
    constexpr std::size_t BUFF_LEN = 512;
    char BUFF[BUFF_LEN] = {0};

    const int32_t DELTA_BUFF_LEN = snprintf(
      BUFF, BUFF_LEN,
      "%s@%p", CLASS_CANNONICAL_NAME.c_str(), this
    );

    if( DELTA_BUFF_LEN > 0 && DELTA_BUFF_LEN < BUFF_LEN )
      return std::string(BUFF);

    return CLASS_CANNONICAL_NAME;
  }
}