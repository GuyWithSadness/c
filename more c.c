#import <stdio.h>


extern int a;

int plus(){
    static int x = 19;
    return ++x;
}
void main(){

    // this is not my first program in C
    printf("UnHello your world \n");
    int a = 2;
    printf("%d\n", a);

    /* integer stuff
    Following are other examples of various types of integer literals −

        85         decimal
        0213       octal
        0x4b       hexadecimal
        30         int
        30u        unsigned int
        30l        long
        30ul       unsigned long
    */

    printf("test" "lol" "stuff");

    /* how to define a constant

    #define LENGTH 10
    #define WIDTH  5
    #define NEWLINE '\n'

    or

    const int  LENGTH = 10;
    const int  WIDTH = 5;
    const char NEWLINE = '\n';

    its better to define constant in CAPITALS
    */

    /* Storage Classes

    Auto
    - your average storage
    - int month;
    - auto int month;

    Register
    - does not have a memory address
    - stored in the (whats a register)
    - used for variables that require quick access such as counters (i)
    - register int i
        for i in rage bla bla

    Static
    - how do i say this uhhh
    - maintain its value between functions

        #include<stdio.h>
        int fun()
        {
          static int count = 0;
          count++;
          return count;
        }

        int main()
        {
          printf("%d ", fun()); -- count becomes 1
          printf("%d ", fun()); -- count becomes 2 (remembers previous function caused it to become 1)
          return 0;
        }


    Extern
    - global variable visible to ALL program files
    - most commonly used when there are two or more files sharing the same global variables or functions.

    for example:
        First File: main.c

            #include <stdio.h>

            int count ;
            extern void write_extern();

            main() {
               count = 5;
               write_extern();
            }

        Second File: support.c

            #include <stdio.h>

            extern int count;

            void write_extern(void) {
               printf("count is %d\n", count);
            }

    */

    printf("%d\n", plus());
    printf("%d\n", plus());

}
