#include <stdio.h>
#include <string.h>
#include "finallogin.c"
#include "admin.c"
#include "user.c"


int main()
{
    printf("------------- Welcome to XYZ Banking System -------------\n");
    int ans;
    ans = finallogin();

    switch (ans)
    {
    case 0:
        perror("Error opening file");
        break;

    case 1:
        printf("Logged in successfully\n");
        user();
        break;
    
    case 2:
        printf("Entered username and password doesnot match.");
        printf("\n Press R to try again ");
        printf("\n Press C to create new account ");
        pritnf("\n Press any other key to exit ");
        char ch;
        ch = getchar();
        if (ch == 'R' || ch == 'r')
        {
            main();
        }
        else if (ch == 'C' || ch == 'c')
        {
            admin();
        }
        else
        {
            printf("Exiting the system\n");
            break();
        }
        break;

    default:
        break;
    }

    return 0;
}