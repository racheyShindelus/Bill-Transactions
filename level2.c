#include <stdio.h>

int bills(int amount);
int getAmount();
void inputDenominations(int denominations[]);
int optimalBills(int amount, int denominations[]);

int main() {
    int amount = getAmount();
    int numBills = bills(amount);
    
    printf("You get %d bills back.\n", numBills);
    
    int customDenominations[5];
    
    inputDenominations(customDenominations);
    
    int optimalNumBills = optimalBills(amount, customDenominations);
    
    printf("(Custom denominations) You get %d bills back.\n", optimalNumBills);
}
// min num of bills needed for transaction
int bills(int amount) {
    int numBills = 0;
    const int denominations[] = {100, 20, 10, 5, 1};    // US denominations (bills)

    for (int i = 0; i < 5; i++) {
        numBills += amount / denominations[i];
        amount %= denominations[i];
    }

    return numBills;
}

// Function to get a valid positive dollar amount from the user
int getAmount() {
    int amount;

    do {
        printf("Enter a dollar amount: ");
        scanf("%d", &amount);

        if (amount < 0) {
            printf("Please enter a positive number.\n");
        }
    } while (amount < 0);

    return amount;
}

// Custom denominations input
void inputDenominations(int denominations[]) {
    printf("Enter five denominations:\n");

    for (int i = 0; i < 5; i++) {
        printf("Denomination %d: ", i + 1);
        scanf("%d", &denominations[i]);
    }
}

// Finds the most optimal num of bills to make change
int optimalBills(int amount, int denominations[]) {
    int numBills = 0;

    for (int i = 0; i < 5; i++) {
        numBills += amount / denominations[i];
        amount %= denominations[i];
    }
    return numBills;
}
