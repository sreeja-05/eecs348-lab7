//Program to determine all possible scoring combinations for a given NFL score
#include <stdio.h>

//Function to find and display all scoring combinations for a given score
void find_combinations(int score){
    printf("Possible combinations of scoring plays for %d:\n", score);
    for (int td2 = 0; td2 * 8 <= score; td2++) { // TD + 2pt Conversion
        for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) { // TD + FG
            for (int fg = 0; fg * 3 + td1 * 7 + td2 * 8 <=score; fg++){ // Field Goals
                for (int safety = 0; safety * 2 + fg * 3 + td1 * 7 + td2 * 8 <= score; safety++) { // Safeties
                    if (safety * 2 + fg * 3 + td1 * 7 + td * 8 == score) {
                        printf("%d TD + 2pt, %d TD + FG, %d FG, %d Safety\n", td2, td1, fg, safety);
                    }
                }
            }
        }
    }
}

// Main function to handle user input and call the combination function
int main() {
    int score;
    while (1) {
        printf("Enter the NFL score (0 or 1 to STOP): ");
        scanf("%d", &score);
        if (score <= 1) break; // Terminate on 0 or 1 
        find_combinations(score);
    }
    return 0;
}