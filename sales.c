#include <stdio.h>

int main() {
    FILE *fp;
    float amount, total = 0.0;

    // Create sample sales.txt for testing
    fp = fopen("sales.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "1500.50\n2300.00\n875.25\n1200.00\n");
        fclose(fp);
    }

    // Read and calculate total
    fp = fopen("sales.txt", "r");
    if (fp == NULL) {
        printf("Error opening sales.txt!\n");
        return 1;
    }

    while (fscanf(fp, "%f", &amount) == 1) {
        total += amount;
    }

    fclose(fp);

    printf("Total sales for the day: %.2f KES\n", total);

    return 0;
}
