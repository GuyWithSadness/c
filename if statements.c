#import <stdio.h>


void main(){
/* Decision Making

if statement

    your average if statement

    if (condition) {
     (thingy)
    )

if else statement

    your average if else statement

    if(boolean_expression) {
    (statement(s) will execute if the boolean expression is true)
    } else {
    (statement(s) will execute if the boolean expression is false)

if else if else statement

    if else statement with more if else

    if(boolean_expression 1) {
        (Executes when the boolean expression 1 is true)
    } else if( boolean_expression 2) {
        (Executes when the boolean expression 2 is true)
    } else if( boolean_expression 3) {
        (Executes when the boolean expression 3 is true)
    } else {
        (executes when the none of the above condition is true)
    }

nested if statement

    bruh come on

    if( boolean_expression 1) {
        (Executes when the boolean expression 1 is true)
        if(boolean_expression 2) {
          (Executes when the boolean expression 2 is true)
        }
    }

switch statement

    faster than if

    switch(expression) {

       case constant-expression  :
          statement(s);
          break; ( optional )

       case constant-expression  :
          statement(s);
          break; ( optional )

       ( you can have any number of case statements )
       default : ( Optional )
       statement(s);
    }

nested switch statement

    a switch statement in a switch statement

    switch(ch1) {

       case 'A':
          printf("This A is part of outer switch" );

          switch(ch2) {
             case 'A':
                printf("This A is part of inner switch" );
                break;
             case 'B': (case code)
          }

          break;
       case 'B': (case code *)
    }


? operator (short hand if)

(condition)? true do what : false do what

*/

/* Loop de Loop

while loop

    repeats loop as long as condition is true

for loop

    efficiently write a loop that needs to be executed for a specific number of times

    for (init (code that is executed first); condition; increment){
    }

do while loop

    like while, but checks the condition at the bottom instead of the top

    do {
       statement(s);
    } while( condition );

nested loops

    a loop in a loop thats it the end
*/

/* loop control statements

- break

    - loop is terminated immediately and then the program carries on after the loop
    - terminate a case after a switch case

- continue

    - skipping one instant of the iteration what the hell does that mean
    - just imagine it skipping only

- goto

    - jump to a specified statement
    - highly discouraged (difficult to trace the control flow)

    goto label;
    ..
    .
    label: statement;


*/

/* Infinite Loop

never becomes false

int main () {

   for( ; ; ) {
      printf("This loop will run forever.\n");
   }

   return 0;
}
/*


}
