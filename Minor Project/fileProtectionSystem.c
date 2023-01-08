// File Protection System using File Handling in C by Sourabh Jangra & Akhil Kalsi

// Header Files
#include <stdio.h>   // FILE, printf() etc.
#include <stdlib.h>  // system()
#include <windows.h> // Sleep()
#include <conio.h>

FILE *fptr, *fptr2; // Declaring File Pointers

char ch;
char path[50];     // Char Array - Path or Name of file
char password[12]; // Password in the file

// Declaration of functions
void mainMenu();
void setPassword();
void aboutDev();
void showChoices();
int createFile();
void writeFile();
void openFile();
void checkPassword();
void readPassword();
void readFile();

// Execution starts - main()
int main()
{
    mainMenu();

    return 0;
}

void mainMenu()
{
    int choice;

    system("cls"); // clrscr();

    // Do-While loop containing Switch-Case to setPassword();
    do
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t    File Protection System\n");
        printf("\t\t\t\t\t------------------------------\n");
        printf("\t\t\t\t\t------------------------------\n\n");
        printf("\n\n\t\t\t\t\t  1) Set Password");
        printf("\n\t\t\t\t\t  2) About the developer");
        printf("\n\t\t\t\t\t  3) Exit\n");
        printf("\n\t\t\t\t  Enter your Choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            setPassword();
            break;
        case 2:
            aboutDev();
        case 3:
            exit(0);
        default:
            system("cls");
            printf("Invalid Input. Press any key to try again\n");
            getch();
            mainMenu();
        }
    } while (1);
}

void setPassword()
{
    char setPass[12], confirmPass[12], check[12];

    char passwordFile[30] = "passwordFile";

    system("cls"); // clrscr();

    printf("Enter password to set: ");
    scanf("%s", &setPass);
    // gets(setPass);

    // fflush(stdin); //.

    printf("Confirm Password: ");
    scanf("%s", &confirmPass);
    // gets(confirmPass);

    // fflush(stdin); //.

    if (strcmp(setPass, confirmPass) == 0)
    {
        fptr2 = fopen(passwordFile, "w+");

        fputs(confirmPass, fptr2);

        // system("attrib +h passwordFile"); // If the file is hidden we can't overwrite its contents.

        fclose(fptr2);

        fclose(fptr);

        printf("\nPassword has been set.\nPress any key to continue...");
        getch();

        showChoices();
    }
    else
    {
        printf("\nPassword didn't matched.\n");
        printf("Press any button to try again...");
        getch();
        setPassword();
        // exit(0);
    }
}

void aboutDev()
{
    system("cls");

    printf("\n\n\n\n\n\n\tThe Project \"File Protection System\" is the original work of Sourabh Jangra - 34 & Akhil Kalsi - 03,");
    printf("\n\tstudent of MCA-1st Sem (Morning). This project is developed under the guidance of Dr. Rohini Sharma.");
    printf("\n\tThe project is a BETA version and is under continuous development");
    printf("\n\n\n\t\t\t\t\tPress any key to go back........!");

    getch();

    mainMenu();
}

void showChoices()
{
    int choice;

    system("cls"); // clrscr();

    // Do-While loop containing Switch-Case to createFile(), openFile(), exit();
    do
    {
        fflush(stdin);
        system("cls");

        printf("\n1) To Create a File");
        printf("\n2) To Open a File");
        printf("\n3) To Set New Password");
        printf("\n4) To Exit\n");
        printf("\n\nEnter your Choice: ");

        // fflush(stdin); //.

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createFile();
            break;
        case 2:
            openFile();
            break;
        case 3:
            setPassword();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Input... Try Again...");
        }
    } while (1);
}

int createFile()
{
    char toWrite;

    system("cls");

    printf("Enter path / file name to create: ");
    scanf("%s", &path);

    // gets(path);

    fptr = fopen(path, "a");

    if (fptr == NULL)
    {
        printf("\nError in opening the file %s", path);
        exit(0);
    }
    else
    {
        printf("File has been created.");

        printf("\n\nPress [Y] - Write or [N] - Not Write - ");
        printf("\nEnter your Choice: ");

        fflush(stdin);

        scanf("%c", &toWrite);

        if (toWrite == 'Y' || toWrite == 'y')
        {
            writeFile();
        }
        else
        {
            fclose(fptr);
            return 0;
        }
    }
}

void writeFile()
{
    char str[100];

    printf("\nEnter content of the file: ");

    fflush(stdin);
    gets(str);

    /* write to file using fputs() function */
    fputs(str, fptr);

    printf("\nFile has been updated with the content.\nPress any key to continue...");
    getch();

    fclose(fptr);
}

void openFile()
{
    system("cls");

    printf("Enter path / file name to open: ");
    scanf("%s", &path);
    // gets(path);

    fptr = fopen(path, "r");

    if (fptr == NULL)
    {
        printf("\nError in opening the file %s", path);
        exit(0);
    }
    else
    {
        checkPassword();
    }
}

void checkPassword()
{
    char code[12];

    readPassword();

    printf("\n\nEnter File Password:\t");
    scanf("%s", &code);

    if (strcmp(code, password) == 0)
    {
        readFile();
    }
    else
    {
        printf("\n\t\t\t\tWrong Password...System is Closing for security concerns.");
        Sleep(500);
        exit(0);
    }
}

void readPassword()
{
    fptr2 = fopen("passwordFile", "r");
    fgets(password, 12, fptr2);

    fclose(fptr2);
}

void readFile()
{
    fptr = fopen(path, "r");

    // if no errors are there file will be opened .
    printf("\n\t\t\t\tOpening File...wait\n");
    Sleep(1000);

    // Printing what is written in file.
    // character by character using loop.
    fflush(stdin);
    do
    {
        ch = fgetc(fptr);
        printf("%c", ch);
        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);

    // Closing the file
    fclose(fptr);

    Sleep(1000);
    printf("\n\t\t\t\tPress any key to close the file.");
    getch();
}