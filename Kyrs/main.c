#include <stdio.h>
#include <getopt.h>
#include "integral.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
        printf("Use the --help argument to open help window.\n");

    int arg = 0;

    const struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"info", no_argument, NULL, 'i'},
        {"test", no_argument, NULL, 't'},
        {"result", no_argument, NULL, 'r'},
        {0, 0, 0, 0}
    };

    while ( (arg = getopt_long(argc, argv, "hitr", long_options, NULL)) != -1) {
        switch(arg) {
            case 'h':
                printf("--help     print this help menu.\n");
                printf("--info     print info about prog.\n");
                printf("--test     print info about test func and result of prog with test function.\n");
                printf("--result   print result of prog\n");
            break;
            case 'i':
                printf("The prog calcs the area of a figure given by the equations:\n");
                printf("1. f1(x) = 0.6*x + 3\n");
                printf("2. f2(x) = (x-2)**3 - 1\n");
                printf("3. f3(x) = 3/x\n");
            break;
            case 't':
                printf("Test func is f(x) = 2, limits of integration is [0,2].\n");
                printf("The rectangle method is used to calculate the integral.\n");
                printf("Area of test fucn is %f\n", calcIntegralSquare(0, 2, 1000, testf));
            break;
            case 'r':
                printf("Getting roots by linear method with tolerance 0,0001:\n");
                printf("f1f2 root = %f\n", rootFindLineSearch(3, 4, (float)0.0001, f1f2));
                printf("f1f3 root = %f\n", rootFindLineSearch(0, 2, (float)0.0001, f1f3));
                printf("f2f3 root = %f\n", rootFindLineSearch(2, 4, (float)0.0001, f2f3));

                printf("Getting area by integration using the ractangle method:\n");
                printf("Square of figure is %f\n", 
                                            (calcIntegralSquare(rootFindLineSearch(0, 2, (float)0.0001, f1f3), rootFindLineSearch(2, 4, (float)0.0001, f2f3), 10000, f1) -
                                            calcIntegralSquare(rootFindLineSearch(0, 2, (float)0.0001, f1f3), rootFindLineSearch(2, 4, (float)0.0001, f2f3), 10000, f3)) +
                                            (calcIntegralSquare(rootFindLineSearch(2, 4, (float)0.0001, f2f3), rootFindLineSearch(3, 4, (float)0.0001, f1f2), 10000, f1) -
                                            calcIntegralSquare(rootFindLineSearch(2, 4, (float)0.0001, f2f3), rootFindLineSearch(3, 4, (float)0.0001, f1f2), 10000, f2))                                           
                );
            break;

        }
    }

    return 0;
}