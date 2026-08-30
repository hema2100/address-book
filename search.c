#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

void searchContact(AddressBook *Book)
{
    int option, flag = 0;
    int i, j;

    printf("\nSearch by:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Choose your option: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
        {
            char search_name[20];
            char temp_name[20];

            printf("Enter name to search: ");
            scanf(" %19[^\n]", search_name);

            for(j = 0; search_name[j] != '\0'; j++)
            {
                search_name[j] = tolower(search_name[j]);
            }

            for(i = 0; i < Book->contactCount; i++)
            {
                strcpy(temp_name, Book->contacts[i].name);

                for(j = 0; temp_name[j] != '\0'; j++)
                {
                    temp_name[j] = tolower(temp_name[j]);
                }

                if(strstr(temp_name, search_name) != NULL)
                {
                    printf("%s %s %s\n",
                           Book->contacts[i].name,
                           Book->contacts[i].phone,
                           Book->contacts[i].email);

                    flag = 1;
                }
            }
            break;
        }

        case 2:
        {
            char search_phone[20];

            printf("Enter phone number to search: ");
            scanf("%19s", search_phone);

            for(i = 0; i < Book->contactCount; i++)
            {
                if(strcmp(search_phone, Book->contacts[i].phone) == 0)
                {
                    printf("%s %s %s\n",
                           Book->contacts[i].name,
                           Book->contacts[i].phone,
                           Book->contacts[i].email);

                    flag = 1;
                    break;
                }
            }
            break;
        }

        case 3:
        {
            char search_email[50];

            printf("Enter email to search: ");
            scanf("%49s", search_email);

            for(i = 0; i < Book->contactCount; i++)
            {
                if(strcmp(search_email, Book->contacts[i].email) == 0)
                {
                    printf("%s %s %s\n",
                           Book->contacts[i].name,
                           Book->contacts[i].phone,
                           Book->contacts[i].email);

                    flag = 1;
                    break;
                }
            }
            break;
        }

        default:
            printf("Invalid choice. Please try again.\n");
            return;
    }

    if(flag == 0)
    {
        printf("Contact not found\n");
    }
}