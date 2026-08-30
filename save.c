#include <stdio.h>
#include <string.h>
#include "contact.h"

void saveContactsToFile(AddressBook *Book)
{
    FILE *fp;

    fp = fopen("output.txt", "w");

    if (fp == NULL)
    {
        perror("File opening failed!");
        return;
    }

    fprintf(fp, "%d\n", Book->contactCount);

    int i;

    for (i = 0; i < Book->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                Book->contacts[i].name,
                Book->contacts[i].phone,
                Book->contacts[i].email);
    }

    fclose(fp);

    printf("Contacts saved successfully!\n\n");
}