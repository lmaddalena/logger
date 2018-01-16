#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "log.h"

void log_info(char *msg, ...)
{
    va_list argp;

    log_assert(msg != NULL);

    va_start(argp, msg);
    fprintf(stderr, "INFO: ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");
}

void log_err(char *msg, ...)
{
    va_list argp;

    log_assert(msg != NULL);

    va_start(argp, msg);
    fprintf(stderr, "ERR : ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");

}

void log_warn(char *msg, ...)
{
    va_list argp;

    log_assert(msg != NULL);

    va_start(argp, msg);
    fprintf(stderr, "WARN: ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");

}

void log_abort(char *msg, ...)
{
    va_list argp;

    log_assert(msg != NULL);

    va_start(argp, msg);
    fprintf(stderr, "ERR : ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");
    abort();
}