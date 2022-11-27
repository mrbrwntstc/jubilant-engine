#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// disable debug and trace logging for release builds
#if KRELEASE == 1
  #define LOG_DEBUG_ENABLED 0
  #define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level
{
  log_level_fatal = 0,
  log_level_error = 1,
  log_level_warn =  2,
  log_level_info =  3,
  log_level_debug = 4,
  log_level_trace = 5
} log_level;

b8 initialize_logging();
void shutdown_logging();

KAPI void log_output(log_level level, const char* message, ...);

// logs a log_level_fatal-level message
#define KFATAL(message, ...) log_output(log_level_fatal, message, ##__VA_ARGS__);

#ifndef KERROR
  // logs an error-level message
  #define KERROR(message, ...) log_output(log_level_error, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
  // logs a warning-level message
  #define KWARN(message, ...) log_output(log_level_warn, message, ##__VA_ARGS__);
#else
  // do nothing
  #define KWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
  // logs a info-level message
  #define KINFO(message, ...) log_output(log_level_info, message, ##__VA_ARGS__);
#else
  // do nothing
  #define KINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
  // logs a debug-level message
  #define KDEBUG(message, ...) log_output(log_level_debug, message, ##__VA_ARGS__);
#else
  // do nothing
  #define KDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
  // logs a trace-level message
  #define KTRACE(message, ...) log_output(log_level_trace, message, ##__VA_ARGS__);
#else
  // do nothing
  #define KTRACE(message, ...)
#endif
