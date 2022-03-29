#include "logger.h"

const char* curr_date_time(){
    long int tm = time(NULL);
    return (const char*) ctime(&tm);
}

const char* replace_char(char srch, char replace, char* str){
    for(int i = 0; i < strlen(str); ++i)
        if(str[i] == srch)
            str[i] = replace;

    return str;
}

void message( const char* msg, int type){
    // recalculate size of arrays
    char msg_type_str[60];
    char temp_str[40];

    msg_type_str[0] = '\0';
    temp_str[0] = '\0';

    switch (type)
    {
        case NONE:
            set_color(GREEN);
            strcat(temp_str, "[ ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
        case INFO:
            set_color(BLUE);
            strcat(temp_str, "[ INF ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
        case WARN:
            set_color(YELLOW);
            strcat(temp_str, "[ WRN ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
        case ERROR:
            set_color(RED);
            strcat(temp_str, "[ ERR ");
            strcat(temp_str, curr_date_time());
            strcat(temp_str, "]");
            strcpy(msg_type_str, temp_str);
            break;
    }


    replace_char( '\n', ' ', msg_type_str);
    printf("%s\t", msg_type_str);
    reset_color();

    printf("%s\n", msg);
}

void info(const char* msg){
    message(msg, INFO);
}

void warning(const char* msg){
    message(msg, WARN);
}

void error(const char* msg){
    message(msg, ERROR);
}
