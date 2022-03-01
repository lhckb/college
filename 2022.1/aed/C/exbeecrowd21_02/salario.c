#include <stdio.h>
 
int main() 
{
 
    int number, worked_hours;
    float income_per_hour, salary;
    
    scanf("%d", &number);
    scanf("%d", &worked_hours);
    scanf("%f", &income_per_hour);
    
    salary = worked_hours * income_per_hour;
    
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", salary);
 
    return 0;
}