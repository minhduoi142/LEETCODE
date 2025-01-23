#include <stdio.h>

int main() {
    FILE *f = fopen("output.txt", "w");
    
    char c = 'A';
    fputc(c, f); // Ghi ký tự 'A' vào file

    fclose(f);
    return 0;
}
