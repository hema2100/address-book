#include <stdio.h>
#include <string.h>
#include "contact.h"
void deleteContact(AddressBook *Book)
{
    int option, i;
    int foundCount = 0;
    int index = -1;
    char search[50];
    char confirm;

    printf("\nDelete contact by:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Choose your option: ");
    scanf("%d", &option);

    if(option < 1 || option > 3)
    {
        printf("Invalid choice!\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf(" %[^\n]", search);

    for(i = 0; i < Book->contactCount; i++)
    {
        if((option == 1 && strcmp(Book->contacts[i].name, search) == 0) ||
           (option == 2 && strcmp(Book->contacts[i].phone, search) == 0) ||
           (option == 3 && strcmp(Book->contacts[i].email, search) == 0))
        {
            printf("\n%d. %s  %s  %s\n",
                   i + 1,
                   Book->contacts[i].name,
                   Book->contacts[i].phone,
                   Book->contacts[i].email);

            foundCount++;
        }
    }

    if(foundCount == 0)
    {
        printf("Contact not found.\n");
        return;
    }

    if(foundCount > 1)
    {
        printf("\nDuplicate contacts found.\n");
        printf("Enter the index number of the contact you want to delete: ");
        scanf("%d", &index);

        if(index < 1 || index > Book->contactCount)
        {
            printf("Invalid index.\n");
            return;
        }

        index = index - 1;
    }
    else
    {

        for(i = 0; i < Book->contactCount; i++)
        {
            if((option == 1 && strcmp(Book->contacts[i].name, search) == 0) ||
               (option == 2 && strcmp(Book->contacts[i].phone, search) == 0) ||
               (option == 3 && strcmp(Book->contacts[i].email, search) == 0))
            {
                index = i;
                break;
            }
        }
    }

    printf("\nContact selected for deletion:\n");
    printf("Name  : %s\n", Book->contacts[index].name);
    printf("Phone : %s\n", Book->contacts[index].phone);
    printf("Email : %s\n", Book->contacts[index].email);

    printf("\nConfirmation to delete this contact? (y/n): ");
    scanf(" %c", &confirm);

    if(confirm == 'y')
    {
        for(i = index; i < Book->contactCount - 1; i++)
        {
            Book->contacts[i] = Book->contacts[i + 1];
        }

        Book->contactCount--;

        printf("Contact deleted successfully.\n");
    }
    else
    {
        printf("Not deleted.\n");
    }

}