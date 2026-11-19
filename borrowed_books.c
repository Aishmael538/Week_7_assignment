#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char title[100];

    fp = fopen("borrowed_books.txt", "a");   // append mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter book title: ");
    fgets(title, sizeof(title), stdin);

    // remove trailing newline if present
    title[strcspn(title, "\n")] = 0;

    fprintf(fp, "%s\n", title);
    fclose(fp);

    printf("Book title successfully stored.\n");

    return 0;
}
