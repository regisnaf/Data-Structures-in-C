/*
 * Name: Regis Negreiros de Andrade Filho
 * Student Number: 991617976
 * Assignment 2 - PROG20799
 * Date: October 23nd, 2021
 * References: https://www.programiz.com/dsa/selection-sort
 * https://www.programiz.com/c-programming/examples/lexicographical-order
 * https://www.tutorialspoint.com/c_standard_library/c_function_strcoll.htm
 * https://stackoverflow.com/questions/26502236/reading-lines-from-c-file-and-putting-the-strings-into-an-array
 * https://www.tutorialspoint.com/eof-getc-and-feof-in-c
 */


#include <string.h>
#include<stdio.h>
#include<stdlib.h>

// The name of the input file and output file
#define IN_FILE "C:\\Users\\back\\CLionProjects\\A2\\quotes.txt"
#define OUT_FILE "C:\\Users\\back\\CLionProjects\\A2\\output.txt"

// Defines how many quotes will be in the OUT_FILE
#define MAX_QUOTES 200
#define MAX_LEN 3000
#define MAX_LINES 200

// This function will be used in sorting to swap strings ("pointers").
void swap(char**, char**);

// Selection Sort function here.
void selection_sort(char**, size_t);

// Read quotes from file and add them to array of pointers.
// You also must user selection_sort inside this function!
void read_in(char**, size_t*);

// Print the quotes using array of pointers.
void print_out(char**, size_t);

// Save the sorted quotes in the OUT_FILE file.
void write_out(char**, size_t);

// Free memory pointed by pointers in the array of pointers!
void free_memory(char**, size_t);

int main() {

    // Create array of pointers. Each pointer should point to heap memory where each quote is kept.
    // I.e. quotes[0] points to smallest string.
    // We need +1 to insert the new quote at the end of the array and then re-sort.
    char* quotes[MAX_QUOTES+1]={NULL};
    char* lines[MAX_LINES]={NULL};
    size_t SIZE = MAX_QUOTES;

    FILE *fp;
    char str[MAX_LINES],longest[MAX_LEN];
    int len=0;
    int line=0;
    char c;
    fp=fopen(IN_FILE,"r");
    if(fp==NULL)
    {
        printf("Error");
        return 0;
    }
    while(fgets(str,sizeof(str),fp)!=NULL)
    {
        if(len<strlen(str))
        {
            strcpy(longest,str);
            len=strlen(str);
        }
    }
    printf("Longest Line is: \n%s\n",longest);
    printf("Characters of the Longest Line is: %zu",strlen(longest));

    // Read quotes from file and place them into array quotes.
    printf("\n---quotes.txt---\n");
    read_in(quotes, &SIZE);
    // Also, sort as you add them
    selection_sort(quotes, SIZE);
    printf("\n---output.txt---\n");

    // Print MAX_QUOTES shortest quotes
    print_out(quotes, SIZE);

    // Save MAX_QUOTES shortest quotes in the file OUT_FILE
    write_out(quotes, SIZE);

    // Free memory allocated by array of pointers
    free_memory(quotes, SIZE);

    return (0);
}

// Add all required functions below!
void swap(char* *s1, char* *s2){
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
void selection_sort(char* *quote, size_t size){
    for (int x = 0; x < size - 1; x++){
       int min_len = strlen(quote[x]);
       int min_idx = x;

       for (int i = x + 1; i < size; i++){
           if (strlen(quote[i]) < min_len) {
               min_len = strlen(quote[i]);
               min_idx = i;
           }

           else if (strlen(quote[i]) == min_len) {
               int temp = strcoll(quote[min_idx], quote[i]);
               if (temp > 0) {
                   swap(&quote[min_idx], &quote[i]);
               }
           }
       }
        swap(&quote[x], &quote[min_idx]);
    }
}

void read_in(char* *inFile, size_t *size){
    int bufferLen;
    int lines = 0;
    char *buffer;
    int ch = 0;
    int endLine;
    int bufferPositon;

FILE *fp = fopen(IN_FILE, "r");


if( fp == 0) {
    printf("Error! %s file not found.\n", IN_FILE);
    exit(0);
}
bufferPositon = 0;
bufferLen = MAX_LEN;
buffer = (char *) malloc(bufferLen * sizeof(char *));

while(ch != EOF) {
    endLine = 0;
    ch = fgetc(fp);
    if (ch == '\r') { continue; }
    else if (ch == EOF || ch == '\n') { endLine = 100; }
    else {
        buffer[bufferPositon] = ch;
        bufferPositon++;
    }
    if(endLine) {

        if (bufferPositon == 0) {continue;}

        buffer[bufferPositon++] = 0;
        inFile[lines] = buffer;
        lines++;

        bufferPositon = 0;
        bufferLen = MAX_LEN;
        buffer = (char *) malloc(bufferLen * sizeof(char *));
    }
}
    *size = lines;
    print_out(inFile, lines);
    fclose(fp);
}

void print_out(char** quotes, size_t size){
    for(int i=0; i < size; i++){
        printf("%zu. %s %zu\n", i+1, quotes[i], strlen(quotes[i]));
    }
}

void free_memory(char** quotes, size_t size){
    for(int i=0; i < size; i++){
        free(quotes[i]);
    }
}

void write_out(char** quotes, size_t size){
    FILE *fptr;
    fptr = fopen(OUT_FILE, "w");

    for(int i=0; i < size; i++){
        fprintf(fptr, "%s\n", quotes[i]);
    }
    fclose(fptr);
}