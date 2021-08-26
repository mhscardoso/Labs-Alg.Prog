#include <stdio.h>

int main(void)
{
    int n;
    int before;
    int index;
    int i;

    printf("Type the range of the array: ");
    scanf("%i", &n);

    // In case of bad usage
    if (!n)
    {
        printf("Invalid value\n");
        return 1;
    }

    float arr[n];

    // Asking numbers for user
    for (i = 0; i < n; i++)
    {
        printf("%i: ", i + 1);
        scanf("%f", &arr[i]);

        if (arr[i] == '\0')
        {
            break;
        }
    }

    printf("\n%i elements\n", i);

    printf("Actual array\n");
    for (int b = 0; b < i; b++)
    {
        printf("%.2f\t", arr[b]);
    }
    printf("\n");

    // Sort the array
    for (int a = 0; a < i; ++a)
    {
        index = a;

        while (index > 0 && (arr[index] < arr[index - 1]))
        {
            before = arr[index - 1];
            arr[index - 1] = arr[index];
            arr[index] = before;

            index--;
        }

    }

    printf("\nSorted array\n");
    for (int b = 0; b < i; b++)
    {
        printf("%.2f\t", arr[b]);
    }
    printf("\n");

    return 0;
}