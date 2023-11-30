#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void modifyVar(char* var);

// int main() {
//     static char* var = NULL;

//     // Allocate memory for var
//     var = (char*)malloc(20 * sizeof(char));
//     strcpy(var, "Initial Value");

//     // Call the function to modify var
//     modifyVar(var);

//     // After the function call, var might be modified
//     if (var != NULL) {
//         printf("Modified var: %s\n", var);
//     } else {
//         printf("var is null\n");
//     }

//     // Free allocated memory
//     free(var);

//     return 0;
// }

// Function definition
void modifyVar(char* var) {
    // Check if var is not null before making changes
    if (var != NULL) {
        strcpy(var, "Modified Value");
    }
    // Note: If var is null, no changes are made
}