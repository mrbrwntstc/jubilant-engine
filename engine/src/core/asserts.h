#pragma once

#include "defines.h"

// disable assertions by commenting out the below line
#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED
  #if _MSC_VER
    #include <intrin.h>
    #define debugBreak() __debugbreak()
  #else
    #define debugBreak() __builtin_trap()
  #endif

  KAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

  #define KASSERT(expr)                                        \
  {                                                            \
    if(expr)                                                   \
    {                                                          \
    }                                                          \
    else                                                       \
    {                                                          \
      report_assertion_failure(#expr, "", __FILE__, __LINE__); \
    }                                                          \
  }

  #define KASSERT_MSG(expr, message)                                \
  {                                                                 \
    if(expr)                                                        \
    {                                                               \
    }                                                               \
    else                                                            \
    {                                                               \
      report_assertion_failure(#expr, message, __FILE__, __LINE__); \
      debugBreak();                                                 \
    }                                                               \
  }

  #ifdef _DEBUG
    #define KASSERT_DEBUG(expr)                                  \
    {                                                            \
      if(expr)                                                   \
      {                                                          \
      }                                                          \
      else                                                       \
      {                                                          \
        report_assertion_failure(#expr, "", __FILE__, __LINE__); \
      }                                                          \
    }
  #else
    #define KASSERT_DEBUG(expr) // do nothing
  #endif

#else
  // do nothing
  #define KASSERT(expr)
  #define KASSERT_MSG(expr, message)
  #define KASSERT_DEBUG(expr)

#endif