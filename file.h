#include <stdio.h>
#include <stdlib.h>

float write(float x){
    printf("\n Writing to file...\n");
    FILE *data;
    data = fopen("log.txt", "w");
    if (data == NULL) {
        printf(" Error opening file for writing!\n");
    }
    fprintf(data, "%.2f", x);
    fclose(data);
}

float read(float x){
    char stringOneRep[50]; // Declare a buffer to store the string
    snprintf(stringOneRep, sizeof(stringOneRep), "%.2f", x);
    FILE *fptr;
    fptr = fopen("log.txt", "r");
    if (fptr == NULL) {
        printf(" Error opening file for reading!\n");
    }
    while (fgets(stringOneRep, sizeof(stringOneRep), fptr) != NULL) {
        printf(" New one rep max saved: %s lbs \n", stringOneRep);
    }
    fclose(fptr);
    return x;
}

float initial_read(){
    char stringOneRep[50]; // Declare a buffer to store the string
    FILE *fptr;
    fptr = fopen("log.txt", "r");
    if (fptr == NULL) {
        printf("\n No existing max data.\n");
    }
    while (fgets(stringOneRep, sizeof(stringOneRep), fptr) != NULL) {
        printf("\n Original Max: %s lbs \n", stringOneRep);
    }
    fclose(fptr);
    float x = atof(stringOneRep);
    return x;
}