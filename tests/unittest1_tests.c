#include "test.h"

DEFINE_TEST(test_operation1)
{

    test_assert(2 == 2, "demo assertion");
    return NULL;
}


DEFINE_TEST(all_tests)
{
    test_run(test_operation1);

    return NULL;
}

TEST_SUITE(all_tests);
