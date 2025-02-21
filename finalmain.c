#include <stdio.h>
#include <string.h>
#include "finallogin.c"
#include "edited_admin.c"
#include "user.c"


int main()
{
    printf("------------- Welcome to XYZ Banking System -------------\n");

    printf("Press 1 to sign in: \n");
    printf("Press 2 to create new account: \n");
    printf("Press 3 to exit: \n");
    int choice;
    scanf(" %d", &choice);
    switch(choice)
    {
        case 1:
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
                    printf("\n Press any other key to exit ");
                    char ch;
                    scanf(" %c",&ch);
                    if (ch == 'R' || ch == 'r')
                    {
                        main();
                    }
                    else if (ch == 'C' || ch == 'c')
                    {
                        edited_admin();
                    }
                    else
                    {
                        printf("Exiting the system\n");
                    }
                    break;
            
                default:
                    break;
                }
        case 2:
            edited_admin();
            break;
        case 3:
            printf("Exiting the system\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}
