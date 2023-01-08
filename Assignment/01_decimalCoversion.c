#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num)
{
    if (num == 0)
    {
        printf("0");
        return;
    }

    // Stores binary representation of number.
    int binaryNum[32];
    int i = 0;

    while (num > 0)
    {
        binaryNum[i++] = num % 2;
        num /= 2;
    }

    // Prints array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

void decimalToOctal(int num)
{
    if (num == 0)
    {
        printf("0");
        return;
    }

    // Stores binary representation of number.
    int binaryNum[32];
    int i = 0;

    while (num > 0)
    {
        binaryNum[i++] = num % 8;
        num /= 8;
    }

    // Prints array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

int main()
{
    int num, choice;

    while (1)
    {
        printf("\n1. Enter a number: ");
        printf("\n2. To Binary: ");
        printf("\n3. To Octal: ");
        printf("\n4. To Hexadecimal: ");
        printf("\n5. Exit: ");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter a decimal number: ");
            scanf("%d", &num);
            break;
        case 2:
            decimalToBinary(num);
            break;
        case 3:
            decimalToOctal(num);
            break;
        case 4:
            // decimalToHexadecimal(num);
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong Input");
        }
    }
}