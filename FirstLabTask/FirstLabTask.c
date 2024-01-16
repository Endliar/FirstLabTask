#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma warning(disable : 4996)

typedef struct {
    char start[50];
    char end[50];
    int number;
} Route;

void addData(FILE* file) {
    Route r;

    printf("Enter the starting point: ");
    scanf("%49s", r.start);

    printf("Enter the endpoint: ");
    scanf("%49s", r.end);

    printf("Enter the route number: ");
    scanf("%d", &r.number);

    fwrite(&r, sizeof(Route), 1, file);
}

void findRouteByNumber(FILE* file, int routeNumber)
{
    Route r;

    rewind(file);

    while (fread(&r, sizeof(Route), 1, file) == 1)
    {
        if (r.number == routeNumber) {
            printf("Route found: Start: %s, End: %s, Number: %d", r.start, r.end, r.number);
            return;
        }
    }

    printf("Route with number %d not found.", routeNumber);
}

int main()
{
    FILE* file = fopen("routes.dat", "ab+"); // "ab+" позволяет и добавлять, и читать данные

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int addMore = 0;
    do {
        printf("Would you like to add a route? (1 for yes, 0 for no): ");
        scanf("%d", &addMore);
        while (getchar() != '\n');
        if (addMore) {
            addData(file);
            fflush(file); 
        }

    } while (addMore != 0);

    rewind(file);

    int routeNumber;
    do {
        printf("Enter route number to find(or enter '0' to finish) : "); 
        scanf("%d", &routeNumber);
        while (getchar() != '\n');
        if (routeNumber != 0) {
            findRouteByNumber(file, routeNumber);
        }
    } while (routeNumber != 0);

    fclose(file);

    return 0;
}