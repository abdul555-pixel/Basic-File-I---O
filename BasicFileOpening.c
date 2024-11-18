#include <stdio.h>
#include <ctype.h>

int main(){
    FILE *file;
    char filename[100];
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Enter the File Name : ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erroe : Could not open file %s\n", filename);
        return 1;
    }
    
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;
        
        if (ch == '\n')
        {
            lines++;
        }

        if (isspace(ch))
        {
            inWord = 0;
        }else if (!inWord)
        {
            inWord = 1;
            words++;
        }
    }
    
    if (characters > 0 && ch == EOF && inWord)
    {
        lines++;
    }
    
    fclose(file);

    printf("File Statistics :\n");
    printf("Characters : %d\n", characters);
    printf("Words : %d\n", words);
    printf("Lines : %d\n", lines);

    return 0;
}