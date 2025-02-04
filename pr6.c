#include <stdio.h>
#include <stdlib.h>

void calculateCommentPercentage(const char *fileName);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <source file>\n", argv[0]);
        return 1;
    }

    calculateCommentPercentage(argv[1]);

    return 0;
}

void calculateCommentPercentage(const char *fileName)
{
    FILE *file;
    char ch, prevCh = 0;
    int inSingleLineComment = 0, inMultiLineComment = 0;
    int totalChars = 0, commentChars = 0;

    // Open the source file in read mode
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", fileName);
        exit(1);
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF)
    {
        totalChars++;
        if (inSingleLineComment)
        {
            commentChars++;
            if (ch == '\n')
            {
                inSingleLineComment = 0;
            }
        }
        else if (inMultiLineComment)
        {
            commentChars++;
            if (prevCh == '*' && ch == '/')
            {
                inMultiLineComment = 0;
            }
        }
        else
        {
            if (prevCh == '/' && ch == '/')
            {
                inSingleLineComment = 1;
                commentChars += 2; // To include the '//' characters
            }
            else if (prevCh == '/' && ch == '*')
            {
                inMultiLineComment = 1;
                commentChars += 2; // To include the '/*' characters
            }
        }
        prevCh = ch;
    }

    fclose(file);

    if (totalChars == 0)
    {
        printf("The file is empty.\n");
        return;
    }

    double commentPercentage = ((double)commentChars / totalChars) * 100;
    printf("Total characters: %d\n", totalChars);
    printf("Comment characters: %d\n", commentChars);
    printf("Percentage of characters that are part of comments: %.2f%%\n", commentPercentage);
}
