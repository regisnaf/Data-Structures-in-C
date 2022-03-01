/*
 * Name: Regis Negreiros de Andrade Filho
 * Student Number: 991617976
 * Assignment 1 - PROG20799
 * Date: October 1st, 2021
 * References: https://www.tutorialspoint.com/cprogramming/index.htm
 *             https://www.tutorialspoint.com/cprogramming/c_pointers.htm
 *             https://www.tutorialspoint.com/cprogramming/c_memory_management.htm
 *             https://www.tutorialspoint.com/cprogramming/c_recursion.htm
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_SIZE 200
#define MAX_DIGITS 5
int Fn(int n);
void recursiveSeq(int*, int);
void removeCharacters(char*);
void removeDuplicates(char*);

int main() {

    int *values;
    int size;
    char str[MAX_DIGITS + 1];

    do {
        printf("How many numbers you want to print (1-200)? ");
        fgets(str, MAX_DIGITS + 1, stdin);
        //converting string to integer
        size = strtol(str, NULL, 10);
    } while (size < 1 || size > 200);

    //generating the list for values
    values = (int *) malloc(size * sizeof(int));
    recursiveSeq(values, size);

    //printing out the sequence
    printf("Series: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", values[i]);
    }
    printf("\n");

    //generating the string
    char newString[MAX_SIZE + 1];
    int newStringIdx = 0;

    //include the alphanumeric values
    //convert integers to ASCII characters
    for ( int i = 0; i < size; ++i) {
        //take alphanumeric values
        if ((values[i] >= '0' && values[i] <= '9') ||
            (values[i] >= 'A' && values[i] <= 'Z') ||
            (values[i] >= 'a' && values[i] <= 'z')) {
            newString[newStringIdx] = (char)values[i];
            newStringIdx += 1;
        }
    }

    //null-terminate the string
    newString[newStringIdx] = '\0';

    printf("String: %s\n", newString);

    //getting uppercase strings
    removeCharacters(newString);

    printf("Upper-case String: %s\n", newString);

    //removing duplicates
    removeDuplicates(newString);

    printf("Unique String: %s\n", newString);

    return 0;
}

//Recursive function Fn
int Fn(int n) {
    if (n>= 0 && n <= 2)
        return 10;
    else
        return 2*n + 1 + Fn(n-1) % 50;
}//end of recursive function Fn

//Recursive Sequence
void recursiveSeq(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = Fn(i);
    }
}//end of recursive sequence

//Remove Characters
void removeCharacters(char *input) {
    //new uppercase character array
    char *upString = (char *) malloc(MAX_SIZE + 1);
    //index of the uppercase Array
    int upStringIdx = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            upString[upStringIdx] = input[i];
            //increment the index
            upStringIdx += 1;
        }
    }
    //terminate by \0
    upString[upStringIdx] = '\0';
    for (int i = 0; upString[i] != '\0'; ++i) {
        input[i] = upString[i];
    }
    //terminate the input by \0
    input[upStringIdx]='\0';
}//end of removeCharacters

//Remove duplicates and modifies the character array
void removeDuplicates(char* input) {
    //new character array to hold unique characters
    char *unString = (char*) malloc(MAX_SIZE + 1);
    int unStringIdx = 0;
    short found;
    for (int i = 0; input[i] != '\0'; ++i) {
        found = 0;
        //check if the char is present
        for (int j = 0; j < unStringIdx; ++j) {
            if(unString[j] == input[i]) {
                found = 1;
                break;
            }
        }
        //if the char is not found, then it is a unique character
        if (!found) {
            //add char to the unString
            unString[unStringIdx] = input[i];
            //increment index by 1
            unStringIdx += 1;
        }
    }
    //null terminate the string
    unString[unStringIdx] = '\0';
    //replace values of unString to the original string
    for (int i = 0; i < unStringIdx; ++i) {
        input[i] = unString[i];
    }
    //null terminate the original string
    input[unStringIdx] = '\0';

}//end of remove duplicates

