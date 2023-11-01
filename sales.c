#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *file = fopen("salesinput.txt", "r");

    float money[12];
    int numLines = 0;

    while (numLines < 12 && fscanf(file, "%f", &money[numLines]) == 1) {
        numLines++;
    }

    fclose(file);

    printf("Monthly sales report for 2022:\nMonth\t\tSales\n");

    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    float minValue = money[0];
    char *minMonth = months[0];
    float maxValue = money[0];
    char *maxMonth = months[0];
    float averageValue = 0;

    for (int i = 0; i < 12; i++) {
        printf("%s\t\t$%.2f\n", months[i], money[i]);

        if (money[i] < minValue) {
            minValue = money[i];
            minMonth = months[i];
        }

        if (money[i] > maxValue) {
            maxValue = money[i];
            maxMonth = months[i];
        }

        averageValue += money[i];
    }

    averageValue = averageValue / 12;

    printf("\nSales Summary:\nMinimum sales: $%.2f\t(%s)\nMaximum sales: $%.2f\t(%s)\nAverage sales: $%.2f\n", minValue, minMonth, maxValue, maxMonth, averageValue);

    printf("\nSix-Month Moving Average Report: \n");
    printf("January - June\t\t$%.2f\n", (money[0] + money[1] + money[2] + money[3] + money[4] + money[5]) / 6);
    printf("February - July\t\t$%.2f\n", (money[1] + money[2] + money[3] + money[4] + money[5] + money[6]) / 6);
    printf("March - August\t\t$%.2f\n", (money[2] + money[3] + money[4] + money[5] + money[6] + money[7]) / 6);
    printf("April - September\t$%.2f\n", (money[3] + money[4] + money[5] + money[6] + money[7] + money[8]) / 6);
    printf("May - October\t\t$%.2f\n", (money[4] + money[5] + money[6] + money[7] + money[8] + money[9]) / 6);
    printf("June - November\t\t$%.2f\n", (money[5] + money[6] + money[7] + money[8] + money[9] + money[10]) / 6);
    printf("July - December\t\t$%.2f\n", (money[6] + money[7] + money[8] + money[9] + money[10] + money[11]) / 6);

    printf("\nSales Report (Highest to Lowest):\nMonth\t\tSales");

    // Create a copy of the sales data for sorting
    float sortedMoney[12];
    char *sortedMonths[12];
    for (int i = 0; i < 12; i++) {
        sortedMoney[i] = money[i];
        sortedMonths[i] = months[i];
    }

    // Sort the sales data in descending order
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sortedMoney[i] < sortedMoney[j]) {
                float tempMoney = sortedMoney[i];
                sortedMoney[i] = sortedMoney[j];
                sortedMoney[j] = tempMoney;

                char *tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    // Print the sorted sales data
    for (int i = 0; i < 12; i++) {
        printf("\n%s\t\t$%.2f", sortedMonths[i], sortedMoney[i]);
    }

    printf("\n");

    return 0;
}