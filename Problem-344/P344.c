#include <string.h>

char* reverseString(char* s);

char* reverseString(char* s) {
    char *p = s;
    char * q = s + strlen(s) - 1;
    while (p < q) {
        *p = *p ^ *q;
        *q = *q ^ *p;
        *p = *p ^ *q;
        ++p;
        --q;
    }
    return s;
}
