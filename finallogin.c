#include <stdio.h>
#include <string.h>  // for using string functions
#include <dirent.h>  // for manipulating directories
#include "global.h"

struct login
{
    char pass[20];
    int acc_no;
} l[2];

struct data
{
    int acc_no;
    char username[100], password[32];
    float balance;
}d1;

char logged_in_user_file[256];

int finallogin()
{

    printf("Enter acc_no: ");
    scanf("%d", &l[1].acc_no);
    printf("Enter password: ");
    scanf("%s", l[1].pass);

    DIR *folder = opendir("."); 
    struct dirent *file; 

    while (file = readdir(folder))    
    {
        if (strstr(file->d_name, ".txt") != NULL)    
        {
            FILE *fp; 
            fp = fopen(file->d_name, "rb");   
            if (fp == NULL)  
            {
                return 0;
            }
            fread(&d1, sizeof(d1), 1, fp);  

            if (  d1.acc_no == l[1].acc_no && strcmp(d1.password, l[1].pass) == 0)  
            {
                strcpy(logged_in_user_file, file->d_name);
                fclose(fp);
                closedir(folder);
                return 1;
            }
        }
    }

    closedir(folder); 
    return 2; 
}
