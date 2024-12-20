
#include "learn/cpp/compute/util.h"

#include <string>

#ifdef __GNUG__ //REM: GCC/Clang
  #include <cxxabi.h>
  // #include <cstdlib>
  #include <memory>
#elif _MSC_VER //REM: MSVC
  #include <windows.h>
  #include <dbghelp.h> //REM: [TODO] .|. Hmmm...
  #pragma comment(lib, "dbghelp.lib") //REM: [TODO] .|. Hmmm...
#endif

namespace learn::cpp::compute {
#ifdef __GNUG__ //REM: GCC/Clang
  std::string demangle(const char* mangledName) {
    int status = 0;
    std::unique_ptr<char, decltype(&std::free)> demangledName(
      abi::__cxa_demangle(mangledName, nullptr, nullptr, &status),
      std::free
    );
    return (status == 0 && demangledName) ? demangledName.get() : mangledName;
  }
#elif _MSC_VER //REM: MSVC
  std::string demangle(const char* mangledName) {
    char demangledName[1024];
    if (
      UnDecorateSymbolName(
        mangledName, demangledName, sizeof(demangledName), UNDNAME_COMPLETE
      )
      ) {
      return demangledName;
    }
    return mangledName;
  }
#else
  std::string demangle(const char* mangledName) {
    //REM: Unsupported compiler
    return mangledName;
  }
#endif
}