#include <stdio.h>

int main(){
    char greetings[] = "My Balls!";
    printf("\n%s", greetings);
    int i;
    for (i = 0 ; i < (sizeof(greetings) / sizeof(greetings[0])) ; i++){
         printf("\n%c", greetings[i]);
    }

    printf("\n%d", (sizeof(greetings)));
    printf("\n%d", (sizeof(greetings[0])));

    char banana[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    printf("\n%s", banana);

    // \0 tells C that the string ends there//
    // thats why the total length of the array has a + 1//

    // user input//

    // Create an integer variable that will store the number we get from the user
    int myNum;

    // Ask the user to type a number
    printf("Type a number: \n");

    // Get and save the number the user types
    scanf("%d", &myNum);

    // Output the number the user typed
    printf("Your number is: %d", myNum);

    /*
    Memory Address

    Location where variable is stored on the computer

    printf("%p", &myAge); // Outputs 0x7ffe5367e044

    */

    /*
    Pointers

    Variable that stores the memory address of another variable as its value
    points to a data type

    */

    int wtf = 14;
    int* ptr = &wtf;
    printf("\n%d", wtf);
    printf("\n%p", &wtf);
    printf("\n%p", wtf); //this just prints the value of wtf in hex
    printf("\n%p", ptr);
    printf("\n%d", *ptr); // this is dereference //


    return 0;
}
