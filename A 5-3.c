#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
    FILE *input_file, *output_file;
    char input_filename[] = "input.txt";
    char output_filename[] = "output.txt";
    char buffer[MAX_LENGTH];

    input_file = fopen(input_filename, "r");
    output_file = fopen(output_filename, "w");

    if (input_file == NULL) {
        printf("Could not open input file %s", input_filename);
        exit(1);
    }

    if (output_file == NULL) {
        printf("Could not open output file %s", output_filename);
        exit(1);
    }

    while (fgets(buffer, MAX_LENGTH, input_file)) {
        char *occurrence;
        while ((occurrence = strstr(buffer, "red")) != NULL) {
            strncpy(occurrence, "blue", 4);
        }
        fputs(buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Successfully replaced all occurrences of \"red\" with \"blue\" in %s and wrote the modified text to %s\n", input_filename, output_filename);

    return 0;
}

