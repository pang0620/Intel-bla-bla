#include <fcntl.h> //O_WRONLY, O_CREAT...
#include <stdio.h>
#include <string.h>
#include <sys/stat.h> //These 2 sys...h are set menu
#include <sys/types.h>
#include <unistd.h> //read, open, write... System call functions
/* manual for system call functions: man 2 open */
/* std: man 3 strlen */

int main(int argc, char **argv) {
    int n, in, out;
    char buf[500];
    int i = 0;
    int j = 0;

#if 0
	printf("argc: %d\n", argc);
	while(1)
	{
		if(argv[i]==NULL)
			break;
		printf("argv[%d] : %s\n", i, argv[i]);
		for(j=0; j<strlen(argv[i]);j++)
			printf("argv[i][j] : %c \n", argv[i][j]);
		if (argv[i]==NULL)
			break;
		i++;
	}
#endif
    printf("argc: %d\n", argc);
    while (*argv != NULL)
	{
        printf("argv : %s\n", *argv);
        for (j = 0; j < strlen(*argv); j++)
            while (**argv != '\0')
			{
				//a[i] == *(a+i) == *(argv++)	?
				//a[i][j] == *(*(a+i)+j) == *(*argv)++
                printf("argv : %c \n", *(*argv)++);
            }
        argv++;
    }

    // no negative digit return for main()!!

    // error: not enough arguments
    if (argc < 3) {
        // write(2, "Usage: copy file1 file2\n", 25);
        printf("Usage: %s file1 file2\n", *argv);
        return 1;
    }

    // open the origin file with read mode
    if ((in = open(argv[1], O_RDONLY)) < 0) { // in = 3
        perror(argv[1]);
        return 2;
    }

    // open the target file with write mod
    // (write only | new file | delete old)
    // mod 664
    // out = 4
    if ((out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
                    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) < 0) {
        perror(argv[2]);
        return 3;
    }

    // read origin file and paste it to target file
    do {
        // read 500bytes from buffer
        n = read(in, buf, sizeof(buf));
        printf("n : %d\n", n);

        if (n > 0)
            // no sizeof for write (garbage value collapses)
            write(out, buf, n);
        else if (n == 0) {
            fputs("done.\n", stderr);
            break;
        } else {
            perror("read()");
            break;
        }

    } while (1);

    // close files
    close(out);
    close(in);

    return 0;
}
