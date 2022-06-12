#import <stdio.h>

void main(){
/* how to declare function

    return_type function_name( parameter list );


    always write in this order:-

    function declaration

    (main code and stuff)

    function definition i think.
*/

/* Function Arguments

    -what

*/

/* Call by value

Basically, changing the variable in the function does not affect any variable outside the function (if the same variable is used)

        void swap(int x, int y) {

            int temp;

            temp = x;
            x = y;
            y = temp;

            return;

        values will be swapped only in the function, not in the main()
*/

/* Call by Reference

Basically, changing the variable in the function affects any variable outside the function (if the same variable is used)
fantastic, we are using pointers now
uses the whatever address it called to access that address to change the value in the address thingy
Basically, just use this if you need the function to change the variable (OR JUST USE RETURN)


    void swap(int *x, int *y) { -> note how they used FUCKING POINTERS WOOOO)  (to access this function you gotta use swap(&x, &y))

       int temp;
       temp = *x;
       *x = *y;
       *y = temp;

       return;

    now swapping the values in the function will swap values in main()
*/

/* Scope Rule - basically where your variable can be

Local

- Variables declared inside a function or block
- used only by statements in the function

Global

- defined outside a function
- hold their values throughout the lifetime of the program

Formal

- Theres enough room only for one of us
- Local variable that have higher priority over global variable

*/

}
