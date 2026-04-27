#include <stdio.h>
#include <string.h>

#define SIZE 15 

typedef struct {
    char items[SIZE];
    int mkan_dafe3;  
    int mkan_sahb;   
    int count;       
} MyBuffer;


void add_char(MyBuffer *buf, char c) {
    if (buf->count < SIZE) {
        buf->items[buf->mkan_dafe3] = c;
        buf->mkan_dafe3 = (buf->mkan_dafe3 + 1) % SIZE; // حركة دائرية
        buf->count++;
    } else {
        printf("\n[!] المخزن ممتلئ! : %c", c);
    }
}

char get_char(MyBuffer *buf) {
    if (buf->count > 0) {
        char c = buf->items[buf->mkan_sahb];
        buf->mkan_sahb = (buf->mkan_sahb + 1) % SIZE;
        buf->count--;
        return c;
    }
    return '\0'; // مخزن فارغ
}

int main() {
    // تعيين المتغيرات الابتدائية (صفر)
    MyBuffer myBuf = {{0}, 0, 0, 0};
    char input[50];
    char extra[] = " CE-ESY";

    printf("ادخل النص: ");
    scanf("%s", input);
    strcat(input, extra); 
    printf("\n--- جاري التخزين ---\n");
    for (int i = 0; i < strlen(input); i++) {
        add_char(&myBuf, input[i]);
    }
    printf("\n\n--- جاري القراءة ---\n");
    while (myBuf.count > 0) {
        printf("%c", get_char(&myBuf));
    }
    
    printf("\n\n-- تم--\n");

    return 0;
}
