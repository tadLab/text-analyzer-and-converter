#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
TO START THIS PROJECT:

1. COMPILE IT:
    gcc -o proj proj.c
    
2. RUN IT:
    ./proj

    THAT WILL AUTOMATICALLY SHOW YOU INSTRUCTIONS.
    
    OPTIONS:
    1. Find the length of a string (max 100 characters).
    2. Count the number of digits and letters in a string.
    3. Convert all uppercase letters to lowercase in a string.
    4. Replace a specified character in a string with '_'.
    5. Apply Caesar cipher to a string using a shift value.
    6. Compare two strings for equality.

USAGE EXAMPLES:
1. To get the length of a string:
    ./proj 1
    Enter your string.

2. To count digits and letters in a string:
    ./proj 2
    Enter your string.

3. To convert string to lowercase:
    ./proj 3
    Enter your string.

4. To replace a character in the string:
    ./proj 4 [character_to_replace]
    Enter your string.

5. To apply Caesar cipher:
    ./proj 5 [shift_value]
    Enter your string.

6. To compare two strings:
    ./proj 6
    Enter both strings.

7. Count words in string:
    ./proj 7
    Enter your string.

*/

// Function to calculate the length of the string
int STR_Len(char string[]) {
    int count = 0;

    for(int index = 0; string[index] != '\0'; index++) {
        count++;
    }

    return count;
}

// Function to count digits in the string
int STR_Digits(char string[]) {
    int count = 0;

    for(int index = 0; string[index] != '\0'; index++) {
        if(string[index] <= '9' && string[index] >= '0') {
            count++;
        }
    }

    return count;
}

// Function to count letters in the string
int STR_Letters(char string[]) {
    int count = 0;

    for(int index = 0; string[index] != '\0'; index++) {
        if((string[index] <= 'Z' && string[index] >= 'A') || (string[index] <= 'z' && string[index] >= 'a')) {
            count++;
        }
    }

    return count;
}

// Function to convert all uppercase letters to lowercase
void STR_Lower(char string[]) {
    for(int index = 0; string[index] != '\0'; index++) {
        if(string[index] <= 'Z' && string[index] >= 'A') {
            string[index] = string[index] + 32; // Convert uppercase to lowercase
        }
    }

    printf("Lowercase: %s\n", string);
}

// Function to replace a specific character in the string with '_'
void STR_Delete(char string[], char delCharacter) {
    for(int index = 0; string[index] != '\0'; index++) {
        if(string[index] == delCharacter) {
            string[index] = '_'; // Replace character with '_'
        }
    }

    printf("New version of your string: %s\n", string);
}

// Function to apply Caesar cipher with a given shift
void STR_Caesar(char string[], int shift) {
    int max = string[0];

    for(int index = 0; string[index] != '\0'; index++) {
        if((string[index] <= 'Z' && string[index] >= 'A') || (string[index] <= 'z' && string[index] >= 'a')) {
            // Check for wrap-around for letters
            if(((string[index] + shift) > 90 && ((string[index] + shift) < 96)) || ((string[index] + shift) > 123)) {
                string[index] = (string[index] + shift) - 64; // Shift and wrap
            } else {
                string[index] = string[index] + shift; // Normal shift
            }
        }
    }

    printf("Your new Secret code: %s\n", string);
}

// Function to compare two strings for equality
int STR_Compare(char string01[], char string02[]) {
    int length01 = 0;
    int length02 = 0;

    // Calculate length of string01
    for(int index = 0; string01[index] != '\0'; index++) {
        length01++;
    }
    
    // Calculate length of string02
    for(int index = 0; string02[index] != '\0'; index++) {
        length02++;
    }

    // Compare the lengths
    if(length01 == length02) {
        // If lengths are the same, compare characters one by one
        for(int index = 0; string01[index] != '\0'; index++) {
            if(string01[index] != string02[index]) {
                return 1; // Strings are different
            }
        }
    }

    return 0; // Strings are the same
}

// Function to count words in the string
int STR_WordCount(char string[]) {
    int words = 0;
    int inWord = 0; 

    // Traverse the string character by character
    for(int index = 0; string[index] != '\0'; index++) {
        // Check for non-whitespace character (indicating part of a word)
        if(string[index] != ' ' && string[index] != '\t' && string[index] != '\n') {
            if (!inWord) {
                words++;    // New word detected
                inWord = 1; // Set flag to indicate we're inside a word
            }
        } else {
            inWord = 0; // End of word
        }
    }

    return words; // Return total word count
}

int main(int argc, char const *argv[]) {
    char string[101];  // Array to hold the input string, max 100 characters
    char string02[101]; // Array to hold second string for comparison

    // If no arguments are passed, display instructions
    if(argc == 1) {
        printf("INSTRUCTIONS:\n");
        printf("1. Find the length of a string (max 100 characters).\n");
        printf("2. Count the number of digits and letters in a string.\n");
        printf("3. Convert all uppercase letters to lowercase in a string.\n");
        printf("4. Replace a specified character in a string with '_'.\n");
        printf("5. Apply Caesar cipher to a string using a shift value.\n");
        printf("6. Compare two strings for equality.\n");
        printf("7. Count how many words are present in the string.\n");
        printf("To use these options, run the program with the corresponding number.\n");
        printf("Example: ./proj 1\n");
        return 0;
    }

    // Switch to handle different functionalities based on the argument provided
    switch (atoi(argv[1])) {
        case 1:
            // Case for string length
            printf("Please provide your string here:\n");
            scanf("%100s", string);  // Get the string input
            printf("Your string has %d characters.\n", STR_Len(string));
            break;

        case 2:
            // Case for counting digits and letters
            printf("Please provide your string here:\n");
            scanf("%100s", string);  // Get the string input
            printf("Your string has %d digits and %d letters.\n", STR_Digits(string), STR_Letters(string));
            break;

        case 3:
            // Case for converting to lowercase
            printf("Please provide your string here:\n");
            scanf("%100s", string);  // Get the string input
            STR_Lower(string);       // Convert to lowercase and display
            break;

        case 4:
            // Case for replacing a character with '_'
            if(argc < 3) {
                printf("Please specify the character to replace.\n");
                return 1;
            }
            printf("Please provide your string here:\n");
            scanf("%100s", string);  // Get the string input
            STR_Delete(string, argv[2][0]);  // Replace specified character
            break;

        case 5:
            // Case for Caesar cipher
            if(argc < 3) {
                printf("Please provide the shift value for the Caesar cipher.\n");
                return 1;
            }
            printf("Please provide your string here:\n");
            scanf("%100s", string);  // Get the string input
            STR_Caesar(string, atoi(argv[2])); // Apply Caesar cipher
            break;

        case 6:
            // Case for comparing two strings
            printf("Please provide your first string:\n");
            scanf("%100s", string);  // Get the first string
            printf("Please provide your second string:\n");
            scanf("%100s", string02);  // Get the second string
            if(STR_Compare(string, string02) == 0) {
                printf("The strings are the same.\n");
            } else {
                printf("The strings are different.\n");
            }
            break;

        case 7:
            // Case for counting words in string
            printf("Please provide your string:\n");
            fgets(string, sizeof(string), stdin); // Get the entire input line
            printf("Your string has %d words.\n", STR_WordCount(string)); // Count and display words
            break;
            
        default:
            // Handle invalid options
            printf("Invalid option. Please choose a valid one.\n");
            break;
    }

    return 0;
}
