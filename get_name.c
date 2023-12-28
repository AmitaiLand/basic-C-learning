#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define maxValue 30
#define minValue 0
#define MAX_NAMES 30

const char* get_name();
int  str_compare(const char *s1, const char *s2);
char names[30][20];

int main()
{
    int i;
    int j;
    printf("Enter %d unique names (press Enter after each name):\n",MAX_NAMES);
    for (i = 0; i < MAX_NAMES; ++i)
    {
        scanf("%s", names[i]);
        for (j = 0; j < i; ++j)
        {
            if (str_compare(names[j], names[i]) == 0)
            {
                printf("The Code has stopped due to a duplicate.\n");
                return 1;
            }
        }
    }
    printf("\nYou entered the following names:\n");
    for (i = 0; i < MAX_NAMES; ++i)
    {
        printf("%s\n", names[i]);
    }

    printf("Here are 10 random names from the list: \n");
    for (i = 0; i < 10; ++i)
    {
        printf("%s\n",get_name());
    }

    return 0;
}
const char* get_name()
{
    int RandomNumber = rand() % (maxValue - minValue) + minValue;
    return names[RandomNumber];
}
int  str_compare(const char *s1, const char *s2)
{
    while (*s1 && *s2) {
        if (toupper(*s1) != toupper(*s2))
        {
            return toupper(*s1) - toupper(*s2);
        }
        s1++;
        s2++;
    }

    return toupper(*s1) - toupper(*s2);
}