#include <stdio.h>
int main()
{
	FILE *ptr;
	ptr = fopen("/tmp/test.txt","w+");
	fputs("Testing 123\n", ptr);
	fputs("reee\n", ptr);
	fputs("Testing 123\n", ptr);
	fclose(ptr);
	ptr = fopen("/tmp/test.txt","r");
	char buff;
	int a;
	while (1)
	{
		buff = fgetc(ptr);
		if (buff == EOF)
			break;
		printf("%c",buff);
	}
	fclose(ptr);
}

/* C - Input and Output

Input - feed some data into a program
	  - Can be givin in the form of a file or form the command line

Output - display some data on screen

Standard file

standard input - stdin - 0
standard output - stdout - 1
standard error - stderr - 2
*/

/* C Handling files

Opening files
FILE *fopen (const char * filename, const char *  mode);
fopen returns a pointer to FILE (used in the below functions)

modes
r - open an existing text file for reading purpose
w - open a text file for writing // create a new one
	- program starts writing from the beginning
a - open a text file for writing in appending mode
	- program starts writing from the end
r+ - open a text file for reading and writing
w+ - open a text file for btoh reading and writing
	- deletes the entire content of the file if it exists
a+ - open a text file for reading and writing
	- read from the start, write at the end

--Closing a file--

int fclose(FILE *fp)
	- returns zero on success
	- returns 0 on success, or EOF (a constent in stdio.h) if failed

--Writing a File--

int fputc(int c, FILE *fp);
	- returns the written character if success, EOF if error
int fputs(const char *s, FILE *fp);
	- returns a non negative value if success, EOF if error
you can use a int fprintf(FILE *fp, const char *format,...) function to write string into a file

you must have a /tmp directory

--Reading a File--

int fgetc (FILE *fp)
	- return the value of the character read, EOF if error

char *fgets( char *buf, int n, FILE *fp)
	reads up to n-1 charcters from the input stream referenced by fp.
	copies the read string into the buffer, appendin a null character to terminate the string
	function will stop if it encounters a \n character or a end of the file EOF
		returns only the characters read up to that point

int fscanf (FILE *fp, const char *format, ...)
	stops reading after the first space character

Binary I/O Functions

size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

*/
