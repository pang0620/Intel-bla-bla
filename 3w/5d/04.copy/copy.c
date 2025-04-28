#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int n, in, out;
	char buf[BUFSIZ];	//1024

	// error: not enough arguments
	if (argc<3)
	{
		write(2, "Usage: copy file1 file2\n", 25);
		return -1;
	}

	// open the origin file with read mode
	if ((in = open(argv[1], O_RDONLY)) < 0)
	{
		perror(argv[1]);
		return -1;
	}

	// open the target file with write mod (new file | delete old)
	if ((out = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR))<0)
	{
		perror(argv[2]);
		return -1;
	}

	// read origin file and paste it to target file
	while ((n=read(in, buf, sizeof(buf))) > 0)
		write(out, buf, n);

	// close files
	close(out);
	close(in);

	return 0;
}
