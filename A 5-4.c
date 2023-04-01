#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    char filename[MAX_LINE_LENGTH];
    char search_string[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    
    printf("Enter filename: ");
    fgets(filename, MAX_LINE_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0'; 

    printf("Enter search string: ");
    fgets(search_string, MAX_LINE_LENGTH, stdin);
    search_string[strcspn(search_string, "\n")] = '\0'; 

    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return 1;
    }

    
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (strstr(line, search_string) != NULL) {
            printf("%s", line);
        }
    }

    
    fclose(fp);

    return 0;
}

