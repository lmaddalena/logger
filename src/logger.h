#pragma once

#include <errno.h>
#include <string.h>

#define STR(x)          #x
#define STRINGIFY(x)    STR(x)
#define LINESTR         STRINGIFY(__LINE__)

#define logger_log_assert(x)   if(!(x)) logger_log_abort("%s - assertion failed: '" #x "' (" __FILE__", line " LINESTR ")", __func__)

void logger_log_info(char *msg, ...);
void logger_log_err(char *msg, ...);
void logger_log_warn(char *msg, ...);
void logger_log_abort(char *msg, ...);