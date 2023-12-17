#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int feet;
    int inches;
} distance;

int main()
{
    distance distance1, distance2;

    printf("Enter distance 1 feet inches : ");
    scanf("%d %f", &distance1.feet, &distance1.inches);

    printf("Enter distance 2 feet inches: ");
    scanf("%d %f", &distance2.feet, &distance2.inches);

    int total_distance= addDistances(&distance1, &distance2);

    // Display the total distance
    printf("total distance in  feet : %d  \n", total_distance);

    return 0;
}

int addDistances(const distance *distance1, const distance *distance2) {
    distance total;
    // add inches
    total.inches = distance1->inches + distance2->inches;

    total.feet = (distance1->feet + distance2->feet);
    total.inches=(total.inches / 12);
     int total_dis =total.feet+total.inches;

    return total_dis;

}
