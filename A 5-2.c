#include <stdio.h>

int main()
{
    FILE* file;
    char data[100];
    int count = 0;

    file = fopen("data.bin", "rb");

    if (file == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    while (!feof(file))
    {
        fread(&data, sizeof(char), 100, file);

        for (int i = 0; i < 100; i++)
        {
            if (data[i] == '\0') break;
            printf("%c", data[i]);
        }

        count += 100;
    }

    fclose(file);

    printf("\nRead %d bytes from file\n", count);

    return 0;
}

