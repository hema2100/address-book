#include<stdio.h>
#include"contact.h"

void listContacts( AddressBook *Book)
{
int i;
 if (Book->contactCount == 0)
    {
        printf("No contacts available.\n");
        return;
    }
    printf("\nName\t\tPhone\t\tEmail\n");
    printf("-----------------------------------------------\n");

for(i=0;i<Book->contactCount;i++)
{
    printf("%s %s %s\n", Book->contacts[i].name, Book->contacts[i].phone, Book->contacts[i].email);
}

}