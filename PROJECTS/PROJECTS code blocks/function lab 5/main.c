#include <stdio.h>
// Function prototypes
void circle_area(float r);
void circle_perimeter(float r);

int main()
{
    float radius;
    printf("Enter Circle Radius  \t");
    scanf("%f",&radius);
    printf("%f",radius);
    printf("\n");


    circle_area(radius);
    circle_perimeter(radius);

    return 0;
}
void circle_area(float r){
    if (r < 0)
        printf( "Radius cannot be negative");
    else{
       float area;
       area=3.14*r*r;
       printf("Circle Area Equal %f \n",area);
   }
}

void circle_perimeter(float r){
    if (r < 0)
        printf( "Radius cannot be negative");
    else{
       float perimeter;
       perimeter=3.14*2*r;
       printf("Circle perimeter Equal %f \n",perimeter);
    }
}
