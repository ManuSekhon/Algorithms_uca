/**
 * Spell a number
 * 0 >= num <= 999999
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// hash tables
static const char *ones[] = {"\0", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static const char *tens[] = {NULL, NULL, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
static const char *tens_one[] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
};

// prototypes
static void handle_tens (char *num);
static void handle_hundred (char *num);
static void handle_thousand (char *num);
static void handle_ten_thousand (char *num);
static void handle_lacs (char *num);
void intToWord (int num);

// store result in string array
static char result[10][20];
static int index1 = 0;

void intToWord (int num)
{
    index1 = 0;
    if (num == 0)
    {
        printf("zero");
        return;
    }

    // convert number to string
    char n[7];
    sprintf(n, "%d", num);
    int len = strlen(n);

    switch (len)
    {
        case 1: sprintf(result[index1++], "%s", ones[*n - '0']);
                break;
        case 2: handle_tens(n);  
                break;
        case 3: handle_hundred(n);  
                break;
        case 4: handle_thousand(n);
                break;
        case 5: handle_ten_thousand(n);
                break;
        case 6: handle_lacs(n);
                break;
        default: printf("Sorry! cant handle number this big!\n");
    }

    // print number (no whitespace at end)
    for (int i = 0; i < index1; i++)
    {
        if (i == index1 - 1)
            printf("%s", result[i]);
        else
            printf("%s ", result[i]);
    }
}

// handles two digit number
void handle_tens (char *n)
{
    if (atoi(n) == 0)
        return;

    switch (*n)
    {
        case '0': sprintf(result[index1++], "%s", ones[*(n + 1) - '0']);
                  break;
        case '1': sprintf(result[index1++], "%s", tens_one[*(n + 1) - '0']);
                  break;
        default : sprintf(result[index1++], "%s %s", tens[*n - '0'], ones[*(n + 1) - '0']);
                  break;
    }
}

// handles three digit number
void handle_hundred (char *n)
{
    char *p = n;
    switch (*p)
    {
        case '0':
            p++;
            handle_tens(p);
            break;

        default:
            sprintf(result[index1++], "%s hundred", ones[*p - '0']);
            p++;
            handle_tens(p);
            break;
    }
}

// handles four digit number
void handle_thousand (char *n)
{
    char *p = n;
    switch (*p)
    {
        case '0':
            p++;
            handle_hundred(p);
            break;
        
        default:
            sprintf(result[index1++], "%s thousand", ones[*n - '0']);
            p++;
            handle_hundred(p);
            break;
    }
}

// handle five digit number
void handle_ten_thousand (char *n)
{
    char *p = n;
    switch (*p)
    {
        case '0':
            p++;
            handle_thousand(p);
            break;
        
        default:
            handle_tens(p);
            sprintf(result[index1++], "thousand");
            p += 2;
            handle_hundred(p);
            break;
    }
}

// handle six digit number
void handle_lacs (char *n)
{
    char *p = n;

    switch (*p)
    {
        case '1':
            sprintf(result[index1++], "one lakh");
            break;
        default:
            sprintf(result[index1++], "%s lakhs", ones[*p - '0']);
            break;
    }
    p++;
    handle_ten_thousand(p);
}

int main (void)
{
    int num;
    scanf("%d", &num);

    intToWord(num);
}
