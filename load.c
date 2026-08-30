#include <stdio.h>
#include <string.h>
#include "contact.h"

void loadContactsToFile(AddressBook *Book)
{
    FILE *fp;

    fp = fopen("output.txt", "r");

    if (fp == NULL)
    {
        Book->contactCount = 0;
        return;
    }

    if (fscanf(fp, "%d\n", &Book->contactCount) != 1)
    {
        Book->contactCount = 0;
        fclose(fp);
        return;
    }

    int i;

    for (i = 0; i < Book->contactCount; i++)
    {
        fscanf(fp, "%[^,],%[^,],%[^\n]\n",
               Book->contacts[i].name,
               Book->contacts[i].phone,
               Book->contacts[i].email);
    }

    fclose(fp);
}