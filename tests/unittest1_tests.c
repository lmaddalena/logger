#include "test.h"
#include "logger.h"

DEFINE_TEST(test1)
{

    logger_log_info("this is an information: %d, %d, %d...", 1, 2, 3);
    logger_log_warn("this is a warning");
    logger_log_err("this is an error");    
    //logger_log_assert(1 > 2);

    //test_assert(2 == 2, "demo assertion");
    return NULL;
}


DEFINE_TEST(all_tests)
{
    test_run(test1);

    return NULL;
}

TEST_SUITE(all_tests);
