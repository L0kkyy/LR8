#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 16
#define MAX_NUMS 10

void greet_user(void) {
    char name[MAX_NAME];

    printf("Enter your name: ");
    // УРАЗЛИВІСТЬ 1: потенційне переповнення буфера
    // scanf("%s", ...) не обмежує довжину рядка
    if (scanf("%s", name) != 1) {
        printf("Input error\n");
        return;
    }

    printf("Hello, %s!\n", name);
}

void sum_numbers(void) {
    int n;
    printf("How many numbers to sum (max %d)? ", MAX_NUMS);

    if (scanf("%d", &n) != 1) {
        printf("Invalid number\n");
        return;
    }

    if (n <= 0) {
        printf("Number must be positive\n");
        return;
    }

    // УРАЗЛИВІСТЬ 2: немає перевірки n > MAX_NUMS
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Allocation error\n");
        return;
    }

    // УРАЗЛИВІСТЬ 3: помилка off-by-one – i <= n, а не i < n
    // при i == n буде запис за межі виділеної пам’яті
    for (int i = 0; i <= n; i++) {
        printf("Enter number %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input\n");
            free(arr);
            return;
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
