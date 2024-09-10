/*
Kaiden Fees
9/10/2024
This is my own work, KAF
This program is essentially a homemade ls command,
it lists all files in current directory or the one given.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

//main function
int main(int argc, char* argv[])
{
    //create directory object
    DIR *OGdir;

    
    if(argc == 1) //if no input for directory name, use current directory
    {
        OGdir = opendir(".");
    }
    else if(argc == 2)//else use directory name chosen
    {
        OGdir = opendir(argv[argc - 1]);
    }
    else //too many arguments, kills program
    {
        printf("\nToo many arguments\n");
        exit(1);
    }

    struct dirent *OGdp;

    //tests if directory opens
    if(OGdir == NULL)
    {
        printf("\nUnable To Open Directory\n");
        return(-1);
    }

    //loops through directory and prints each item within it
    while((OGdp = readdir(OGdir)) != NULL)
    {
        printf("%s\n", OGdp->d_name);
    }

    return(0); //end
}