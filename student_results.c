#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    char regNo[20];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s;

    // First create a sample binary file (for testing)
    fp = fopen("results.dat", "wb");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    // Sample data
    struct Student students[] = {
        {"Alice Wanjiku", "REG001", 78.5},
        {"Brian Otieno", "REG002", 65.0},
        {"Carol Njeri", "REG003", 82.0}
    };

    fwrite(students, sizeof(struct Student), 3, fp);
    fclose(fp);

    // Now read and display
    fp = fopen("results.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Student Results:\n");
    printf("-----------------------------\n");
    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        printf("Name: %s\n", s.name);
        printf("Reg No: %s\n", s.regNo);
        printf("Marks: %.2f\n\n", s.marks);
    }

    fclose(fp);
    return 0;
}
