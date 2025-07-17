#include <stdio.h>
#include "file.h"

/*1. Epley Formula: 1RM = Weight * (1 + (Repetitions / 30))
This formula adds a percentage to the weight based on the number of repetitions performed. 
2. Brzycki Formula: 1RM = Weight / (1.0278 - (0.0278 * Repetitions))
This formula divides the weight by a factor that decreases with each repetition. */

int main(){

    float original_max = initial_read();
    float weight;
    float reps;
    
    //Calculate One rep max
    printf("\n Enter weight lifted: ");
    scanf("%f", &weight); 
    printf(" Enter amount of repetitions: ");
    scanf("%f", &reps);
    float oneRep = weight * (1.0 + (reps / 30.0));
    printf(" Your one rep max is: %.2f lbs \n", oneRep);

    //Write data to file
    write(oneRep);

    //Read data from file
    read(oneRep);

    //Calculate changes in max
    float diff = oneRep - original_max;
    printf("\n Your max changed by: %.2f lbs \n\n", diff);

    float repsMax;
    float newWeight;

    for(int i = 1; i < 5; i++){
        newWeight = oneRep - (weight*0.1*i);
        repsMax = 30.0 * ((oneRep / newWeight) - 1.0);
        printf(" Your reps for %.2f lbs is: %.1f \n", newWeight, repsMax);
    }

    printf("\n Press Enter to exit...");
    int exit;
    while ((exit = getchar()) != '\n' && exit != EOF); 

    do {
        exit = getchar();
    } while (exit != '\n' && exit != EOF);

    return 0;

}

