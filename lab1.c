#include<stdio.h>
#include<stdlib.h>
struct Day {
    char* dayname;
    int date;
    char* activity;
};
struct Day* createCalendar(int numDays) {
    return (struct Day*)malloc(numDays * sizeof(struct Day));
}
void readDay(struct Day* day) {
    char buffer[100];
    printf("Enter Day name ");
    scanf("%s", buffer);
    day->dayname = strdup(buffer);
    printf("enter date");
    scanf("%d", &day->date);
    printf("Enter activity ");
    scanf("%s", buffer);
    day->activity = strdup(buffer);

}
void displayCalendar(struct Day* calendar, int numDays) {
    printf("\nWeek's Activity Detailt:\n");
    printf("---------------------------------------\n");
    printf("\n|%-10s|%-10s|%-20s|\n", "Day", "Date", "Activity");
    printf("---------------------------------------");
    for (int i = 0;i < numDays; i++)
        printf("\n|%-10s|%-10d|%-20s|\n", calendar[i].dayname, calendar[i].date, calendar[i].activity);
    printf("\n---------------------------------------\n");
}

int main() {
    int numDays;
    printf("Enter the number of days in the week: ");
    scanf("%d", &numDays);
    struct Day* calendar = createCalendar(numDays);
    for (int i = 0; i < numDays;i++)
    {
        printf("\nEnter details for day %d\n", i + 1);
        readDay(&calendar[i]);
    }
    displayCalendar(calendar, numDays);

    return 0;


}
























