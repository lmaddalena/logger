#include "stda.h"
#include "log.h"

int main(int argc, char *argv[])
{    
	printf("Hello World!!\n");

    log_info("this is an information");
    log_warn("this is a warning");
    log_err("this is an error");
    
    log_assert(1 > 2);

    printf("Press [ENTER] to quit!\n");
    getchar();

    return 0;
}