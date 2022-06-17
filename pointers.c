#include <stdio.h>

void main(){
    /* Memory Address

    Memory location of every variable can be accessed using & operator

   int  var1;
   char var2[10];

   printf("Address of var1 variable: %x\n", &var1  );  - print the address of var1 in lowercase hexadecimal
   printf("Address of var2 variable: %x\n", &var2  );  - print the address of var2 in lowercase hexadecimal
    */

    /* Pointers

    type *var-name;

    Variable whose value is the address of another variable

    1 - Define a pointer Variable
    2 - assign the address of the variable to the pointer
    3 - access the value at the address available using *

    * operator - returns the value of the variable located at the address specified by its operand

    NULL
    - Pointer variable assigned to a NULL value does not have an exact address to be assigned
    - 0

    if(ptr)      succeeds if p is not null
    if(!ptr)     succeeds if p is null

    */

    /* Pointer Arithmetic

    Pointes are integers, so you can perform arithmetic operation on them (fuck) ++ -- + and -

    For Example =
    x[] = {1,2,3,4,5}
    int *ptr
    ptr = &x[2]

    ptr++ will cause ptr to point to the next integer location (4 bytes next to the current location) - x[3]
    ptr-- will cause the ptr to point to the previous integer location - x[1]

    Pointer Comparisons

    while ( ptr <= &var[MAX - 1] )  - Repeats as long as the ptr does not point to the last character
    */

    /* Array of Pointers

    Array that store pointers to any other data type

    int *ptr[MAX]
    each element in ptr array holds a pointer to an int value

    Example
    ------------------------------------------------------------------------------------------------------------------------
    const int MAX = 3;

    int main () {

       int  var[] = {10, 100, 200};
       int i, *ptr[MAX];

       for ( i = 0; i < MAX; i++) {
          ptr[i] = &var[i]; -- assign the address of integer.
       }

       for ( i = 0; i < MAX; i++) {
          printf("Value of var[%d] = %d\n", i, *ptr[i] ); -- prints out the list of variable in var[] (faster)
       }

       return 0;
    =========================================================================================================================

    Array of Pointers can be used to store list of strings
    - Array of string pointers stores addresses of the strings present in the array

    ---------------------------------------------------------------------------------------------------------------------

    char *arr[]={
            "tree",
            "bowl",
            "hat",
            "mice",
            "toon"
          };

    ======================================================================================================================
    */

    /* Pointer to Pointer

    A pointer that contains the address of another pointer

    Pointer -> Pointer -> Value

    int **var

    */

    /* Passing Pointers to Functions

    void fun(int *pnt)
	to use the function
	fun(&variable)

    */

    /* Return pointer from Functions
    You need to declare a function returning a pointer

    ---------------------------------------------------------------------------------------------

    int * myFunction() {
        .
        .
        .
    }

    ============================================================================================

    You should define the local variable as a static variable (So that the value of the variable can be remembered or something idk)

    the following function will generate 10 random numbers and return them using an array name which represents a pointer

    ------------------------------------------------------------------------------------------

        -- Function to generate and return random numbers. --
        int * getRandom( ) {

           static int  r[10];
           int i;

        -- set the seed --
           srand( (unsigned)time( NULL ) );

           for ( i = 0; i < 10; ++i) {
              r[i] = rand();
              printf("%d\n", r[i] );
           }

           return r;
        }

        -- main function to call above defined function --
        int main () {

           int *p;
           int i;

           p = getRandom();

        -- a pointer to an int --
           int *p;
           int i;

           p = getRandom();

           for ( i = 0; i < 10; i++ ) {
              printf("*(p + [%d]) : %d\n", i, *(p + i) );
        }

    ==========================================================================================
    */

    char x[] = {'a', 'b', 'c', '\0'};
    char *ptr;
    ptr = &x[2];
    printf("%x\n", ptr);
    printf("%c\n", *ptr);
    ptr--;
    printf("%x\n", ptr);
    printf("%c", *ptr);
}
