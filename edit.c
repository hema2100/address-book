#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

void editContact(AddressBook *Book)
{
    char search_name[50];
    char search_value[50];
    int i, j;
    int found = -1;
    int count = 0;
    int choice;
    int search_choice;

    printf("Enter name to edit: ");
    scanf(" %[^\n]", search_name);

    for(i = 0; i < Book->contactCount; i++)
    {
        if(strcmp(search_name, Book->contacts[i].name) == 0)
        {
            count++;
            found = i;
        }
    }

    if(count == 0)
    {
        printf("Contact not found.\n");
        return;
    }

    if(count > 1)
    {
        printf("\nDuplicate name found.\n");
        printf("Search the contact using:\n");
        printf("1. Phone\n");
        printf("2. Email\n");
        printf("Enter choice: ");
        scanf("%d", &search_choice);

        if(search_choice == 1)
        {
            printf("Enter phone number: ");
            scanf("%s", search_value);

            found = -1;

            for(i = 0; i < Book->contactCount; i++)
            {
                if(strcmp(search_name, Book->contacts[i].name) == 0 &&
                   strcmp(search_value, Book->contacts[i].phone) == 0)
                {
                    found = i;
                    break;
                }
            }
        }
        else if(search_choice == 2)
        {
            printf("Enter email: ");
            scanf("%s", search_value);

            found = -1;

            for(i = 0; i < Book->contactCount; i++)
            {
                if(strcmp(search_name, Book->contacts[i].name) == 0 &&
                   strcmp(search_value, Book->contacts[i].email) == 0)
                {
                    found = i;
                    break;
                }
            }
        }
        else
        {
            printf("Invalid choice.\n");
            return;
        }

        if(found == -1)
        {
            printf("Contact not found.\n");
            return;
        }
    }

    printf("\nContact found\n");
    printf("Name  : %s\n", Book->contacts[found].name);
    printf("Phone : %s\n", Book->contacts[found].phone);
    printf("Email : %s\n", Book->contacts[found].email);

    printf("\n1. Edit Name\n");
    printf("2. Edit Phone\n");
    printf("3. Edit Email\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            char new_name[50];

            printf("Enter new name: ");
            scanf(" %[^\n]", new_name);

            if(new_name[0] == '\0')
            {
                printf("Invalid name.\n");
                return;
            }

            for(j = 0; new_name[j] != '\0'; j++)
            {
                if(!isalpha(new_name[j]) &&
                   new_name[j] != ' ')
                {
                    printf("Invalid name. Only alphabets and spaces are allowed.\n");
                    return;
                }
            }

            strcpy(Book->contacts[found].name, new_name);
            break;
        }

        case 2:
        {
            char new_phone[20];

            printf("Enter new phone: ");
            scanf("%s", new_phone);

            if(strlen(new_phone) != 10)
            {
                printf("Invalid phone number. Enter exactly 10 digits.\n");
                return;
            }

            for(j = 0; new_phone[j] != '\0'; j++)
            {
                if(!isdigit(new_phone[j]))
                {
                    printf("Invalid, Only digits are allowed.\n");
                    return;
                }
            }

            strcpy(Book->contacts[found].phone, new_phone);
            break;
        }
        case 3:
        {
            char new_email[50];

            printf("Enter new email: ");
            scanf("%s", new_email);

            if(strchr(new_email, '@') == NULL)
            {
                printf("Invalid email. @ is missing.\n");
                return;
            }

            if(strstr(new_email, ".com") == NULL)
            {
                printf("Invalid email. .com is missing.\n");
                return;
            }

            if(strcmp(strrchr(new_email, '.'), ".com") != 0)
            {
                printf("Invalid email.\n");
                return;
            }

            for(j = 0; new_email[j] != '\0'; j++)
            {
                if(isupper(new_email[j]))
                {
                    printf("Invalid email. Use lowercase letters only.\n");
                    return;
                }
            }

            strcpy(Book->contacts[found].email, new_email);

            break;
        }

        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("\nContact updated successfully!\n");
}