REM x86 compile
gcc -m32 main.c ./helper/cpuinfo.c ./helper/logger.c ./helper/colors.c ./helper/cpu_data.c -o cpu_x86.exe
REM x64 compile
gcc -m64 main.c ./helper/cpuinfo.c ./helper/logger.c ./helper/colors.c ./helper/cpu_data.c -o cpu_x64.exe