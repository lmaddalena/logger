#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "logger.h"

void logger_log_info(char *msg, ...)
{
    va_list argp;

    logger_log_assert(msg != NULL);

    va_start(argp, msg);
    fprintf(stderr, "INFO: ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");
}

void logger_log_err(char *msg, ...)
{
    va_list argp;

    logger_log_assert(msg != NULL);

    va_start(argp, msg);
    fprintf(stderr, "ERR : ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");

}

void logger_log_warn(char *msg, ...)
{
    va_list argp;

    logger_log_assert(msg != NULL);

    va_start(argp, msg);
    fprintf(stderr, "WARN: ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");

}

void logger_log_abort(char *msg, ...)
{
    va_list argp;

    if(msg == NULL)
	    msg = "aborting...";

    va_start(argp, msg);
    fprintf(stderr, "ERR : ");
    vfprintf(stderr, msg, argp);
    va_end(argp);

    fprintf(stderr, "\n");
    abort();
}
