#include <stdio.h>
/* This program is a currency converter that converts amounts from Israeli Shekels (NIS) to U.S. Dollars (USD)
   based on a user-provided conversion rate. */
int main()
{
    /* Declare variables to store sums and input values */
    double c; /* Temporary variable to store each input value */
    double sumIS = 0;      /* Total sum of converted amounts in Shekels */
    double sumUSD = 0;     /* Total sum of original amounts in U.S. Dollars */
    double shekels;        /* Amount in Shekels for each iteration */
    double conversion;     /* Conversion rate between NIS to USD */

    /* Asking the user for the conversion rate and instructions */
    printf("Write the conversion rate between NIS to USD,\n"
           "and after that write all of the numbers that you want to convert one by one separated by a blank space.\n"
           "When finished, press enter and then ctrl + d twice.\n");

    /* Receiving the conversion rate from the user */
    scanf("%lf", &conversion);

    /* Display header for the conversion table */
    printf("$\t\t\t\t\tIS\n");

    /* Loop to read input values and perform currency conversion */
    while (scanf("%lf", &c) == 1)
    {
        /* Perform currency conversion */
        shekels = c * conversion;

        /* Display the original and converted amounts in the correct format */
        printf("%.2f\t\t\t\t\t%.2f\n", c, shekels);

        /* Update total sums */
        sumIS += shekels;
        sumUSD += c;
    }

    /* Display the total sums */
    printf("%.2f\t\t\t\t\t%.2f\n", sumUSD, sumIS);

    /* Return 0 to indicate successful execution */
    return 0;
}
