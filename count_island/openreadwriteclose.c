int main()
{

}

/* File Descriptor

File descriptor is integer that uniquely identifies an open file of the process.

AKA numbers that represent files

File Descriptor table

File descriptor table is the collection of integer array indices that are file descriptors in which elements are pointers to file table entries.
One unique file descriptors table is provided in operating system for each process.

AKA a collection of pointers to a file, 0 points to your keyboard, 1 points to your monitor

File Table Entry: File table entries is a structure In-memory surrogate for an open file,
which is created when process request to opens file and these entries maintains file position.

AKA i dont know

- your screen is a file (1)
- your keyboard is a file (0)
- your error.txt is a file (2)

0,1,2 are file table entry for a file called /dev/tty
*/


/* I/O Systemm calls

1. create = create a new empty file

int create(char *filename, mode_t mode)

filename = name of file you want to create
mode = indicate permission of new files

returns first unused file descriptor


2. open = open the file for reading, writing or both

int open(const char* Path, int Flags [, int mode ]);

Path: path to file which you want to use
	use "/", when you are not work in same directory
	use "file name and extension", when you are in the same directory

Flags
	O_RDONLY - read only
	O_WRONLY - write only
	O_RDWR - read and write
	O_CREAT - create file if doesnt exists
	O_EXCL - prevent creation if it already exists
	to write multiple flags, use |
	O_RDWR | O_CREAT


3. close = close the file

int close(int fd)
return 0 on success and -1 in error


4. read = read reads cnt bytes of input into the memory area indicated by buf
size_t read (int fd, void * buf, size_t cnt);
fd = file descriptor
buf = buffer to read data from
cnt = length of buffer

Returns how many bytes were actually read
	return 0 on EOF
	return -1 on error or on signal interrupt

buf	- needs to point to a valid memory location with length not smaller than specified size
fd	- should be a valid file descriptor returned from open();
cnt	- requsted number of bytes read


5. write - write cnt bytes from buf to the file

size_t write(int fd, void* buf, size_t cnt);

fd = file descriptor
buf = buffer to write data from
cnt = length of buffer

Returns how many bytes were actually written
	return 0 on EOF
	return -1 on error or on signal interrupt
*/
