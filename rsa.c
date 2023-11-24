#include <stdio.h>
#include <stdlib.h>

void factorize(int number) {
    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            printf("%d=%d*%d\n", number, i, number / i);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[20];  
    while (fgets(line, sizeof(line), file) != NULL) {
        int number = atoi(line);
        factorize(number);
    }

    fclose(file);
    return 0;
}