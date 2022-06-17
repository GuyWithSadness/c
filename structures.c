int main()
{

}

/* Structures in C

	-- Defining a Structure --

	struct [structure tag]{
		member definition;
		member definition;
		....
	} [structure variables];

	example

	struct Test{
		int i;
		int j;
		unsigned int x;
		char a;
		char *str;
		char str2[10];
	} test;

	-- Accessing Structure members --

	member access operator (.)

	struct Test test1 // declare test1 of type struct Test
	test1.i = 12;
	test1.j = 23;

	-- Structure as Function Arguments --

	Pass the tructure like how you would pass any other things

	void printstruct(struct Test test)
	{
		-- does something with the struct here--
	}

	int main()
	{
		struct Test test1;
		printstrct(test1);
	}

	-- Pointers to structures--

	declare pointers like how you would declare to a variable

	struct Test *struct_ptr;

	Store address of a structre variable in the pointer
	struct_ptr = &test;

	Acces members of Strcutre
	struct_ptr->title;

	--Bit Fields--

	Allows the packing of data in a structure
	we talk about this later

	struct test{
		unsigned int f1:1 (this allocates 1 bit to the variable f1)
		unsigned int f2:4 (this allocates 4 bits to the variable f2)
	}

*/

/* Unions

	Like Structure, but only one variahble can be access at a time
	You can define a union with many members, but only one can have value at a time

	union [union tag]{
		member definition;
		...
	} [one or more union variables]

	example

	union Data {
		int i;
		float j;
		char str[20];
	}

	The memory occupied by a union will be large enough to hold the largest member of the union

	-- Accessing Union Members--

	Use the member access operator (.)
	union Data data;

	data.i = 10;
	data.j = 2220.5;

*/

/* Bit Fields

	struct{
		type [member_name] : width;
	}
	Lets say we are trying to make a strcut that contains TRUE or FALSE (1 or 0)
	we only need to store 0 and 1 in the first bit out of the 8 bytes of memory space in int

	Therefore
	struct{
		unsigned int condition1 : 1;
		unsigned int condition2 : 1;
	} status;

	The above strcutre requires 4 bytes
	Only 2 bits will be used to store the values
	1 bytes = 8 bits
	|--------| this is one byte
	structures minimum require 4 bytes of memory space no matter how small the bit fields are
	|(conduition1)(Condition2)-----||--------||--------||--------|
	Once the strucutre exceeds 32 bytes (say 33 bytes), it will allocate the next slot of memo
*/

/* typedef

give a type a new name
usually used together with struct

typedef unsigned int BYTE;
now you can use BYTE to represetn unsigned int

BYTE x;
x = 10;

typedef struct Books(
	char *title;
	char *author;
	int pages;
) book

int main()
	book Book1;

*/
