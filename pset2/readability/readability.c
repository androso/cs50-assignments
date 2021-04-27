#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Getting string
    string text = get_string("Text: ");
    int nLetters = 0, nWords = 1, nSentences = 0, length = strlen(text);
    // Counting letters, words and sentences
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            nLetters++;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            nWords++;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            nSentences++;
        }
    }

    double averageL = nLetters * 100.00 / nWords;
    double averageS = nSentences * 100.00 / nWords;
    //printf("%f Letters per 100 words, %f sentences per 100 words", averageL, averageS);

    float grade = (0.0588 * averageL) - (0.296 * averageS) - 15.8;
    int final = round(grade);
    if (final >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (final < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", final);
    }
}
