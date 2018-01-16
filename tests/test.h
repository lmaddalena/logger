#pragma once

#include <stdio.h>
#include <stdlib.h>

#define log_err(message) printf("\tError: %s\n", message)

#define test_assert(test, message)  \
    do {                            \
        if (!(test)) {              \
            log_err(message);       \
            return message;         \
        }                           \
    } while(0)

#define test_run(test)                           \
    do {                                         \
        printf("\n-----%s", " " #test);          \
        char *message = test();                  \
        tests_run++;                             \
        if (message != NULL) { return message; } \
    } while(0)

#define DEFINE_TEST(name) char *name()

#define TEST_SUITE(name)                                   \
    int main(int argc, char *argv[]) {                     \
        char *program = argc ? argv[0] : "";               \
        tests_run = 0;                                     \
        printf("----\nRUNNING: %s\n", program);            \
        char *result = name();                             \
        if (result != NULL) {                              \
            printf(" FAILED: %s\n", result);               \
        }                                                  \
        else {                                             \
            printf("\nALL TESTS PASSED\n");                \
        }                                                  \
        printf("\nTests run: %d\n", tests_run);            \
        exit(result == NULL ? EXIT_SUCCESS : EXIT_FAILURE);\
    }

int tests_run;
