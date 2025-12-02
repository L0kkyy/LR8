#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 16
#define MAX_NUMS 10

void greet_user(void) {
    char name[MAX_NAME];

    printf("Enter your name: ");
    if (scanf("%15s", name) != 1) {
        printf("Input error\n");
        return;
    }

    printf("Hello, %s!\n", name);
}

void sum_numbers(void) {
    int n;

    // ЦИКЛ: повторюємо запит, поки користувач не введе валідне число
    while (1) {
        printf("How many numbers to sum (1..%d)? ", MAX_NUMS);
        if (scanf("%d", &n) == 1 && n >= 1 && n <= MAX_NUMS) {
            break;  // виходимо з циклу
        }

        printf("Invalid number, try again.\n");

        // Очищення буфера вводу — інакше програма може зависати
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Allocation error\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);

        // ЦИКЛ: вводимо одне число, поки воно не валідне
        while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input, try again: ");

            // Очищення буфера для уникнення нескінченних циклів
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);
    free(arr);
}

int main(void) {
    greet_user();
    sum_numbers();
    return 0;
}

