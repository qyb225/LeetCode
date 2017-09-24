#include <stdio.h>
#include <string.h>

int isValid(char* s) {
    int lenth = strlen(s);
    char* stackBottom = (char*) malloc(lenth);
    int i, stackTopPtr = -1;
    for (i = 0; i < lenth; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stackBottom[++stackTopPtr] = s[i];
        } else if ((s[i] == ')' && stackBottom[stackTopPtr] == '(')
                    || (s[i] == ']' && stackBottom[stackTopPtr] == '[')
                    || (s[i] == '}' && stackBottom[stackTopPtr] == '{')) {
            --stackTopPtr;
        } else {
            free(stackBottom);
            return 0;
        }
    }
    free(stackBottom);
    return stackTopPtr == -1;
}