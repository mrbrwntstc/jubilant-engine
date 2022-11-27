#include "logger.h"
#include "assert.h"

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initialzie_logging()
{
  // TODO: create log file
  return TRUE;
}

void shutdown_logging()
{
  // TODO: cleanup logging/write queued entries
}

void log_output(log_level log_level, const char *message, ...)
{
  const char* level_strings[6] = { "[FATAL]:", "[ERROR]:", "[WARN]:", "[INFO]:" , "[DEBUG]:", "[TRACE]:" };
  b8 is_error = log_level < 2;

  // technically imposes a 32k character limit on a single log entry, but...
  // don't do that!
  // avoids dynamic allocation
  const int CHAR_LIMIT = 32000;
  char out_message[CHAR_LIMIT];
  memset(out_message, 0, sizeof(out_message));

  // format original message
  // NOTE: oddly enough, MS's headers override the GCC/clang va_list type with a "typedef char* va_list" in some cases
  // as a result, an error will be thrown here
  // the workaround for now is to just use __builtin_va_list, which is the type GCC/Clang's va_start expects
  __builtin_va_list arg_ptr;
  va_start(arg_ptr, message);
  vsnprintf(out_message, CHAR_LIMIT, message, arg_ptr);
  va_end(arg_ptr);

  char out_message2[CHAR_LIMIT];
  sprintf(out_message2, "%s%s\n", level_strings[log_level], out_message);

  // TODO: platform specific output
  printf("%s", out_message2);
}

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line)
{
  log_output(log_level_fatal, "Assertion failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}