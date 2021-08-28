#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string s = get_string("Text: ");
    int letter_count = count_letters(s); // call count_letters function below
    int word_count = count_words(s); // call count_words function below
    int sentence_count = count_sentences(s); // call count_sentences function below
    // printf("%i letter(s)\n", letter_count);
    // printf("%i word(s)\n", word_count);
    // printf("%i sentence(s)\n", sentence_count);

    float L = (float) letter_count / (float) word_count * 100; // compute L for Coleman-Liau index
    float S = (float) sentence_count / (float) word_count * 100; // compute S for Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8; // Coleman-Liau index formula

    int grade = round(index);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// function to count number of letters in input string s
int count_letters(string s)
{
    int n = strlen(s);

    int letter_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 65 && s[i] <= 90) // check if letter is uppercase A to Z ASCII numbers 65 to 90
        {
            letter_count++;
        }
        else if (s[i] >= 97 && s[i] <= 122) // check if letter is lowercase a to z ASCII numbers 97 to 122
        {
            letter_count++;
        }
    }
    return letter_count;
}

// function to count number of words in input string s
int count_words(string s)
{
    int n = strlen(s);

    int word_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 32) // check if char is a space, ASCII number 32
        {
            word_count++;
        }
    }
    word_count += 1; // add 1 to word_count for the last word in the string, which will not have a space after it
    return word_count;
}

// function to count number of sentences in input string s
int count_sentences(string s)
{
    int n = strlen(s);

    int sentence_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 33 || s[i] == 46 || s[i] == 63) // check if the char is a . or a ! or a ? ASCII codes 46, 33, and 63 respectively
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
