//A Sampe program for creating a shell using c 
#include <stdio.h>
main()
{
    char *path, *argv[20], buf[80], n, *p;
    int m, status, inword, continu;

    while(1) {

        inword = 0;
        p = buf;
        m = 0;
        continu=0;

        printf( "\nNewShell->> ");
        while ( ( n = getchar() ) != '\n'  || continu ) {
            if ( n ==  ' ' ) {
                if ( inword ) {
                    inword = 0;
                    *p++ = 0;
                }
            }
            else if ( n == '\n' ) continu = 0;
            else if ( n == '\\' && !inword ) continu = 1;
            else {
                if ( !inword ) {
                    inword = 1;
                    argv[m++] = p;
                    *p++ = n;
                }
                else
                    *p++ = n;
            }
        }  
        *p++ = 0;
        argv[m] = 0;
        //Exit shell on typing quit.
        if ( strcmp(argv[0],"quit") == 0 ) exit (0);

        if ( fork() == 0 )
        {
            execvp( argv[0], argv );//System call
            printf ( " didn't exec \n ");//Displays when no system call found
        }

        wait(&status);
    }
}
