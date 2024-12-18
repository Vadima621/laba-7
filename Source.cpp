#include <stdio.h>
#include <stdlib.h>


int letter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return c;
    else
        return 0;
}


char up(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}


void capital(char* str) {
    int in_word = 0; 
    for (char* p = str; *p != '\0'; p++) {
        if (letter(*p) != 0) {
            if (in_word == 0) {
                *p = up(*p);
                in_word = 1;
            }
        }
        else {
            in_word = 0;
        }
    }
}
char* inputt() {
    char* str = NULL;
    int size = 0, index = 0;
    char ch;

    printf("Введите строку: ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (index + 1 >= size) {
                
                size +=2;

            char* temp = (char*)realloc(str, size);
          
            str = temp;
        }
        str[index++] = ch;
    }

        str[index] = '\0'; 
    

    return str;
}


int main() {
   
    char* input = inputt();

    capital(input);

 
    printf("Результат: %s\n", input);
  
    free(input);

    return 0;
}
