#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} date;

void calc_difference_date(date *d1, date *d2);

int main() {
    date d1, d2;


    printf("Please ,ENTER date 1 : day : month  : year : ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);

    printf("Please ,ENTER date 2 : day : month  : year : ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);


    calc_difference_date(&d1, &d2);

    return 0;
}

void calc_difference_date(date *d1, date *d2) {
    int dif_d = 0, dif_m = 0, dif_y = 0;

    if (d1->day < d2->day) {
        d1->day += 30;
        dif_d = d1->day - d2->day;
    } else {
        dif_d = d1->day - d2->day;
    }

    if (d1->month < d2->month) {
        d1->year -= 1;
        d1->month += 12;
        dif_m = d1->month - d2->month;
    }
    else {
        dif_m = d1->month - d2->month;
    }

    dif_y = d1->year - d2->year;

    printf("difference: %d year, %d month, %d day\n", dif_y, dif_m, dif_d);
}
