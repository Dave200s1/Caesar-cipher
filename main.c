#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define FILE_NAME "text.txt"
#define SHIFT 3 

void greeting(){
    printf("Hello please enter the desired message here: ");
}

int createTextFile(char* input) {
    FILE* file_ptr = fopen(FILE_NAME, "w");
    
    if (file_ptr == NULL) {
        printf("Error opening the file %s", FILE_NAME);
        return -1;
    }
    //write the contents into the file
    fprintf(file_ptr, "%s\n", input);  

    // Close the file
    fclose(file_ptr);

    printf("\nText file has been created\n");  

    return 0;  
}

char* encryptValues(char* input[400], int key){
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] = input[i] + key; 
        }
    printf("\nmessage has been encrypted");
    return input;
}


char* decryptValues(char* input[400], int key) {
    for (int i = 0; input[i] != '\0'; i ++) {
        input[i] = input[i] - key; 
    }
    printf("\ndencrypted message: ");
    return input;
}

int readContents() {
    FILE* file_ptr;
    char ch;
    char buffer[400];
    file_ptr = fopen(FILE_NAME, "r");
    if (NULL == file_ptr) {
        printf("File cannot be opened!\n");
        return -1;
    }


    // Read and decrypt the contents of the file
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        char* decrypted = decryptValues(buffer, SHIFT);
        printf("%s", decrypted);
    }

    fclose(file_ptr);
    return 0;
}


int main (){
    char text[400];
    greeting();
    fgets(text, sizeof(text),stdin);
    char* result =  encryptValues(text, SHIFT);
    createTextFile(result);
    readContents();

    return 0;
}

