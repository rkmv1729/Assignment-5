#include <stdio.h>

int main(void) {
    char *program = "#include <stdio.h>%c%cint main(void) {%c    char *program = %c%s%c;%c    printf(program, 10, 10, 10, 34, program, 34, 10, 10);%c    return 0;%c}%c";
    printf(program, 10, 10, 10, 34, program, 34, 10, 10);
    return 0;
}
