#include <stdio.h>
#include <conio.h>
#include <stdlib.h>//for rand()
#include <time.h>
#include <stdbool.h>//to use bool to create function

// Structure to store account details
typedef struct {
    unsigned int accountNumber;
    char username[50];
    char password[50];
    double balance;
} BankAccount;

// Function to generate a random 8-digit account number
unsigned int generateAccountNumber() {
    return (rand() % 90000000) + 10000000; // Ensuring it's 8 digits
}

// Function to check if the account number already exists
bool accountNumberExists(unsigned int accNum) {
    FILE *fp = fopen("info.dat", "rb");
    if (fp == NULL) {
        return false; // No file means no accounts yet
    }

    BankAccount temp;
    while (fread(&temp, sizeof(BankAccount), 1, fp)) {
        if (temp.accountNumber == accNum) {
            fclose(fp);
            return true;
        }
    }

    fclose(fp);
    return false;
}

int main() {
    srand(time(NULL));
    printf("Welcome!!! You can create your bank account here....\n");

    BankAccount account;
    FILE *fp;

    // Ensure unique account number
    do {
        account.accountNumber = generateAccountNumber();
    } while (accountNumberExists(account.accountNumber));

    // Initialize balance to 0
    account.balance = 0.0;

    // Take user input
    printf("\nEnter username: ");
    scanf("%s", account.username);

    printf("\nEnter password: ");
    scanf("%s", account.password);

    // Store account details
    fp = fopen("individual.txt", "wb");
    fwrite(&account, sizeof(BankAccount), 1, fp);
    fclose(fp);

    // Display account details
    printf("\nAccount Created Successfully!\n");
    printf("\nDetails:\n Account Number: %u \n Username: %s \n Balance: %.2lf\n", account.accountNumber, account.username, account.balance);

    getch();
    return 0;
}
