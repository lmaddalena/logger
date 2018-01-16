#include "stda.h"
#include "log.h"

int main(int argc, char *argv[])
{    
	printf("Hello World!!\n");

    log_info("this is an information");

    printf("Press [ENTER] to quit!\n");
    getchar();

    return 0;
}