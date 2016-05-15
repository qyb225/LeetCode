#include <string.h>
char* reverseVowels(char* s);
    
char* reverseVowels(char* s) {
    char * p = NULL;
    char * q = NULL;
    char swap;
    int count_p = 0, count_q = 0;
    p = s;
    q = & s[strlen(s) - 1];
    while (p < q) {
        if (*p != 'a' && *p != 'e' && *p != 'i'
            && *p != 'o' && *p != 'u'
            && *p != 'A' && *p != 'E' && *p != 'I'
            && *p != 'O' && *p != 'U') {
            p++;
        }
        else {
            count_p = 1;
        }
        if (*q != 'a' && *q != 'e' && *q != 'i'
            && *q != 'o' && *q != 'u'
            && *q != 'A' && *q != 'E' && *q != 'I'
            && *q != 'O' && *q != 'U') {
            q--;
        }
        else {
            count_q = 1;
        }
        if (count_q == 1 && count_p == 1) {
            swap = *p;
            *p = *q;
            *q = swap;
            count_p = 0;
            count_q = 0;
            p++;
            q--;
        }
    }
    return s;
}