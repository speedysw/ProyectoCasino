#include <stdio.h>
#include <stdlib.h>

int main(void){
    char password[20];
    printf("aaaaa");
    int x;
    for(int i = 0 ; i < 20 ; i = x) {
        password[i] = getch();
        if(password[i] == 13) {
            password[i] = '\0';
            break;
        }
        if(password[i] == 8) {
            if(i > 0) {
                x = i - 1;
                printf("\b \b");
            }
        } else {
            printf("*");
            x++;
        }
    }
    printf("\n%s", password);
    return 0;
}

