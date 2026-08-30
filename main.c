#include <stdio.h>
#include "contact.h"

int main()
{
    AddressBook Book;
    int choice;

    Book.contactCount = 0;
    loadContactsToFile(&Book);

    do
    {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Save contacts\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createContact(&Book);
                break;

            case 2:
                searchContact(&Book);
                break;

            case 3:
                editContact(&Book);
                break;

            case 4:
                deleteContact(&Book);
                break;

            case 5:
                listContacts(&Book);
                break;

            case 6:
                saveContactsToFile(&Book);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}