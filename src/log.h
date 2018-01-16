#pragma once

#include <errno.h>
#include <string.h>

#define STR(x)          #x
#define STRINGIFY(x)    STR(x)
#define LINESTR         STRINGIFY(__LINE__)

#define log_assert(x)   if(!(x)) log_abort("%s - assertion failed: '" #x "' (" __FILE__", line " LINESTR ")", __func__)

void log_info(char *msg, ...);
void log_err(char *msg, ...);
void log_warn(char *msg, ...);
void log_abort(char *msg, ...);