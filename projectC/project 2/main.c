#include <stdio.h>
#include <stdlib.h>

// struct employee
typedef struct Employee {
    int employee_id;
    float work_hours;
    float pay_per_hour;
    double pay_amount;
};

// declare functions
void calc_total_outcome(struct Employee *employees, int num);
void best_employee(struct Employee *employees, int num);
void delete_worst_employee(struct Employee **employees, int *num);
void calc_pay_amount(struct Employee *employees, int num);
void distribute_bonus(struct Employee *employees, int num);

int main() {
    int num;
    printf("::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("::enter employees number : ");
    scanf("%i", &num);

    printf("\n");
    struct Employee *employees = (struct Employee *)malloc(num * sizeof(struct Employee));

    for (int i = 0; i < num; i++) {
        printf("::enter data for employee %i:\n", i + 1);
        employees[i].employee_id = i + 1;
        printf("::work hours: ");
        scanf("%f", &employees[i].work_hours);
        printf("::pay per 1 hour: ");
        scanf("%f", &employees[i].pay_per_hour);
    }

    // Perform calculations
    calc_pay_amount(employees, num);

    printf("::1 task : Total outcome : ..............\n\n ");
    calc_total_outcome(employees, num);

    printf("::2 task : best employee : ..............\n\n ");
    best_employee(employees, num);

    printf("::3 task : delete worst : ..............\n\n ");
    delete_worst_employee(&employees, &num);

    printf("::4 task : pay amount : ....................\n\n ");
    calc_pay_amount(employees, num);

    printf("::5 task : distribute bonus  : ..............\n\n ");
    distribute_bonus(employees, num);

    // Free allocated memory
    free(employees);

    return 0;
}

void calc_total_outcome(struct Employee *employees, int num) {
    double total = 0.0;

    for (int i = 0; i < num; i++) {
        total += employees[i].pay_amount;
    }

    printf("::total outcome for owner: %lf \n", total);
}

void best_employee(struct Employee *employees, int num) {
    int best = 0;
    double max_pay = employees[0].pay_amount;

    for (int i = 1; i < num; i++) {
        if (employees[i].pay_amount > max_pay) {
            max_pay = employees[i].pay_amount;
            best = i;
        }
    }

    printf("::best employee ::\n");
    printf("::employee id: %i\n", employees[best].employee_id);
    printf("::employee worked hours: %f\n", employees[best].work_hours);
    printf("::employee gain pay per hour: %f\n", employees[best].pay_per_hour);
    printf("::employee gain Pay Amount:  %lf\n", employees[best].pay_amount);
}

void delete_worst_employee(struct Employee **employees, int *num) {
    if (*num == 0) {
        printf("::Error : no employee to delete.\n");
        exit(0);
    }

    int worst = 0;
    double min_pay = (*employees)[0].pay_amount;

    for (int i = 1; i < *num; i++) {
        if ((*employees)[i].pay_amount < min_pay) {
            min_pay = (*employees)[i].pay_amount;
            worst = i;
        }
    }

    printf("::DELETE :: Worst Employee:\n");
    printf("::employee id: %i\n", (*employees)[worst].employee_id);
    printf("::employee worked hours: %f\n", (*employees)[worst].work_hours);
    printf("::employee gain pay per hour: %f\n", (*employees)[worst].pay_per_hour);
    printf("::employee gain Pay Amount:  %lf\n", (*employees)[worst].pay_amount);

    for (int i = worst; i < *num - 1; i++) {
        (*employees)[i] = (*employees)[i + 1]; // remove
    }

    // Reduce the number of employees
    *num = *num - 1;

    // re-allocate
    *employees = (struct Employee *)realloc(*employees, (*num) * sizeof(struct Employee));
}

void calc_pay_amount(struct Employee *employees, int num) {
    for (int i = 0; i < num; i++) {
        employees[i].pay_amount = employees[i].work_hours * employees[i].pay_per_hour;
    }

    printf("::done:: pay amount calculation process ....\n");
}

void distribute_bonus(struct Employee *employees, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (employees[j].pay_amount < employees[j + 1].pay_amount) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }

    // add bonus for top 5
    for (int i = 0; i < 5 && i < num; i++) {
        double bonus = 0.10 * employees[i].pay_amount;
        employees[i].pay_amount += bonus;
    }

    printf("::done:: distribute bonus .....................\n");
}
