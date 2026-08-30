#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"

void createContact(AddressBook *Book)
{
    if(Book->contactCount>=100)
    {
        printf("Address book is full");
        return;
    }
    int i, j;

    printf("Enter name: ");
    scanf(" %[^\n]", Book->contacts[Book->contactCount].name);

    for(j = 0; Book->contacts[Book->contactCount].name[j] != '\0'; j++)
    {
        if(!isalpha(Book->contacts[Book->contactCount].name[j]) &&
           Book->contacts[Book->contactCount].name[j] != ' ')
        {
            printf("Invalid name. Only alphabets and spaces are allowed.\n");
            return;
        }
    }

    printf("Enter phone number: ");
    scanf("%s", Book->contacts[Book->contactCount].phone);

    if(strlen(Book->contacts[Book->contactCount].phone) != 10)
    {
        printf("Invalid phone number. Enter exactly 10 digits.\n");
        return;
    }

    for(j = 0; Book->contacts[Book->contactCount].phone[j] != '\0'; j++)
    {
        if(!isdigit(Book->contacts[Book->contactCount].phone[j]))
        {
            printf("Invalid phone number. Only digits are allowed.\n");
            return;
        }
    }

    for(i = 0; i < Book->contactCount; i++)
    {
        if(strcmp(Book->contacts[i].phone,
                  Book->contacts[Book->contactCount].phone) == 0)
        {
            printf("Phone number already exists.\n");
            return;
        }
    }

    printf("Enter email: ");
    scanf("%s", Book->contacts[Book->contactCount].email);

    if(strchr(Book->contacts[Book->contactCount].email, '@') == NULL)
    {
        printf("Invalid email. @ is missing.\n");
        return;
    }

   if(strstr(Book->contacts[Book->contactCount].email, "gmail.com") == NULL &&
   strstr(Book->contacts[Book->contactCount].email, "yahoo.com") == NULL)
{
    printf("Invalid email. Use gmail.com, yahoo.com\n");
    return;
}

    for(j = 0; Book->contacts[Book->contactCount].email[j] != '\0'; j++)
    {
        if(isupper(Book->contacts[Book->contactCount].email[j]))
        {
            printf("Invalid email. Use lowercase letters only.\n");
            return;
        }
    }

    for(i = 0; i < Book->contactCount; i++)
    {
        if(strcmp(Book->contacts[i].email,
                  Book->contacts[Book->contactCount].email) == 0)
        {
            printf("Email already exists.\n");
            return;
        }
    }

    Book->contactCount++;

    printf("Contact created successfully!\n");
}