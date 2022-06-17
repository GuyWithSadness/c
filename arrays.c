#include <stdio.h>
void main()
{
	char a[] = "testing";
	char *ptr;
	ptr = a;

	while (*ptr != '\0')
	{
		printf("%c", *ptr);
		ptr++; // ok so this works LMAO
	}
    /* Arrays

    type arrayName [ arraySize ];
    type arrayName [] = {elements}
    Accessing Array Elements

    variable = array[no. thingy]

    */

    /* Array in detail

    */

    /* Multi-dimensional arrays

    There are 3d arrays whaT?

    (type name[size1][size2]...[sizeN];)
    Example of a 3d array

    int threedim[5][10][4];

    */

    /* 2d Arrays

    type arrayName [ x ][ y ];
    is a table
    with x number of rows and y number of column

    Initializing Two Dimensional Arrays

    int a[3][4] = {
    {0, 1, 2, 3} ,   ( initializers for row indexed by 0 )
    {4, 5, 6, 7} ,   ( initializers for row indexed by 1 )
    {8, 9, 10, 11}   ( initializers for row indexed by 2 )
    };

    or

    int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

    Accessing 2-D array element

    - a[i][j]

    How to Store strings in a 2-D array element

    a[Number of strings][length of each string]
    char a[][256] = {"AAA", "BBB", "CCC"};

    TO accessing a word
    a[ith word]

    a[0] = "AAA"

    */

    /* Passing Array as Functions (How to use arrays in functions)

        Way 1 (usually do this)
            void myFunction(int *param) {
               .
               .
               .
            }

        Way 2
            void myFunction(int param[10]) {
               .
               .
               .
            }

        Way 3
            void myFunction(int param[]) {
               .
               .
               .
            }

    */
    /* Return Array From Function
	Just return the pointer to the array initialize in the function
	oh and make it static or else it values will not save outside the function

	int *array()
	{
		static a[] = {1,2,3,4,5,6};
		return (a);
	}

    */
    /* Pointer to an Array in C

	int a[10];

	a is a pointer to &a[0];

	int *p;
	p = a is the same as p = &a[0]

	you can access the elements by doing
	*p, *(p+1), *(p+2), *(p+3)...

	or just use a[n] lmao;

	*/
}

