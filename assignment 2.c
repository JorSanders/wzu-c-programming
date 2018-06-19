/*
 * Made by:
 * Jor Gyo Sanders
 * Rakib Hassan Hemel
 * Odunlami sunday tunde
 * Gideon Gyasi
 */

#include <stdio.h>

void printLastDigit(int);

void printTenMultiple(int);

void printWholeNumber(int);

void printWithSpace(char *);

void printLastTwoDigit(int);

void askNumberAndPrint();

void main() {
    int times = 10;

    printf("Enter %d prices. Maximum is 9999.99\n\n", times);

    for (int i = 0; i < times; i++) {
        askNumberAndPrint();
    }

    getchar();
    getchar();
    getchar();
}

void printWithSpace(char *text) {
    printf("%s ", text);
}

void printLastDigit(int number) {
    switch (number) {
        case 1:
            printWithSpace("ONE");
            break;
        case 2:
            printWithSpace("TWO");
            break;
        case 3:
            printWithSpace("THREE");
            break;
        case 4:
            printWithSpace("FOUR");
            break;
        case 5:
            printWithSpace("FIVE");
            break;
        case 6:
            printWithSpace("SIX");
            break;
        case 7:
            printWithSpace("SEVEN");
            break;
        case 8:
            printWithSpace("EIGHT");
            break;
        case 9:
            printWithSpace("NINE");
            break;
    }
}

void printLastTwoDigit(int belowHundred) {
    int tenUnit = belowHundred / 10;

    // 10 - 19
    if (tenUnit == 1) {
        switch (belowHundred) {
            case 10:
                printWithSpace("TEN");
                break;
            case 11:
                printWithSpace("ELEVEN");
                break;
            case 12:
                printWithSpace("TWELVE");
                break;
            case 13:
                printWithSpace("THIRTEEN");
                break;
            case 14:
                printWithSpace("FOURTEEN");
                break;
            case 15:
                printWithSpace("FIFTEEN");
                break;
            case 16:
                printWithSpace("SIXTEEN");
                break;
            case 17:
                printWithSpace("SEVENTEEN");
                break;
            case 18:
                printWithSpace("EIGHTTEEN");
                break;
            case 19:
                printWithSpace("NINETEEN");
                break;
        }
        // 20 - 99
    } else if (belowHundred) {
        if (tenUnit) {
            printTenMultiple(tenUnit);
            belowHundred -= tenUnit * 10;
        }

        // 1 - 9
        printLastDigit(belowHundred);
    }
}

void printTenMultiple(int tenUnit) {
    switch (tenUnit) {
        case 2:
            printWithSpace("TWENTY");
            break;
        case 3:
            printWithSpace("THIRTY");
            break;
        case 4:
            printWithSpace("FOURTY");
            break;
        case 5:
            printWithSpace("FIFTY");
            break;
        case 6:
            printWithSpace("SIXTY");
            break;
        case 7:
            printWithSpace("SEVENTY");
            break;
        case 8:
            printWithSpace("EIGHTY");
            break;
        case 9:
            printWithSpace("NINETY");
            break;
    }
}

void printWholeNumber(int wholeNumber) {
    // 1000
    int thousand = wholeNumber / 1000;
    if (thousand) {
        printLastDigit(thousand);
        printWithSpace("THOUSAND");
        wholeNumber -= thousand * 1000;
    }


    // 100
    int hundred = wholeNumber / 100;
    if (hundred) {
        printLastDigit(hundred);
        printWithSpace("HUNDRED");
        wholeNumber -= hundred * 100;
    }

    printLastTwoDigit(wholeNumber);
}

void askNumberAndPrint() {
    printf("Enter a price: ");

    double usernumber;

    scanf("%lf", &usernumber);

    int paise = (int) usernumber;

    int rupees = (int) ((usernumber * 100)) % 100;

    if (paise) {
        printWholeNumber(paise);
    } else {
        printWithSpace("ZERO");
    }

    printWithSpace("AND PAISE");

    if (rupees) {
        printLastTwoDigit(rupees);
    } else {
        printWithSpace("ZERO");
    }

    printf("\n\n");
}