#include "./helper/logger.h"
#include "./helper/cpuinfo.h"

int main(void){
    info("start program");
    warning("test warning");
    error("test error");

    message("test message", NONE);

    return 0;
}