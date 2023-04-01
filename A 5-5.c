#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *input_file = fopen("data.txt", "r");
    FILE *output_file = fopen("statistics.txt", "w");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    
    int letter_counts[26] = {0};

    
    int c;
    while ((c = fgetc(input_file)) != EOF) {
        if (isalpha(c)) {
            letter_counts[tolower(c) - 'a']++;
        }
    }

    
    for (int i = 0; i < 26; i++) {
        fprintf(output_file, "%c: %d\n", 'a' + i, letter_counts[i]);
    }

    
    fclose(input_file);
    fclose(output_file);

    return 0;
}

