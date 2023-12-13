#include <stdio.h>
#include <math.h>
#define PI 3.14159265359
#define MAX_ERROR 0.000001

/* Declaring a function to calculate the cosine of a number */
double my_cos(double);

/* Declaring a function to calculate the factorial of a number */
double factorial(double);

/* Declaring a function to normalize an angle to the range [0, 2 * pi) */
double modPI(double num);

int test1_my_cos();

int main() {
    double num, myCosine, actualCosine;

    /* Get user input for the angle in radians */
    printf("Enter the radian to calculate its cosine value: \n");
    scanf("%lf", &num);

    /* Print the entered angle */
    printf("The number you entered is: %f\n", num);

    /* Calculate cosine values */
    myCosine = my_cos(num);
    actualCosine = cos(num);

    /* Print results */
    printf("Cos(%f) is approximately : %.10f\n", num, myCosine);
    printf("Cos(%f) is actually: %.10f\n", num, actualCosine);

     /* test1_my_cos(); */
    return 0;
}

/* Function to calculate cosine using a series expansion */
double my_cos(double num) {
    double cos = 0;
    int i = 0;

    /* Normalize the angle to the range [0, 2 * pi) */
    num = modPI(num);

    /* Calculate the cosine using a series expansion until the error is within acceptable limits */
    while (fabs(pow(num, 2 * i) / factorial(2 * i)) >= MAX_ERROR) {
        cos += pow(-1, i) * pow(num, 2 * i) / factorial(2 * i);
        ++i;
    }

    return cos;
}

/* Function to calculate the factorial of a number */
double factorial(double num) {
    int i = 0;
    double result = num;
    if (num == 0)
        return 1;

    /* Calculate the factorial of a number */
    for (i = num - 1; i > 0; --i) {
        result *= i;
    }
    return result;
}

/* Function to normalize an angle to the range [0, 2 * pi) */
double modPI(double num) {
    num = fabs(num);

    /* Normalize the angle to the range [0, 2 * pi) */
    while (num > (2 * PI)) {
        num = num - (2 * PI);
    }

    return num;
}

int test1_my_cos()
{
    printf("Testing started\n");
    int i = 0;
    for(i; i < 1000; ++i)
    {
        if(abs(my_cos(i) - cos(i)) > MAX_ERROR)
            printf("You have failed the test");
    }
    printf("The test ended\n");
    return 0;
}
