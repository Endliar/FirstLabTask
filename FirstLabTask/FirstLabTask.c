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
    fgets(r.start, sizeof(r.start), stdin);
    r.start[strcspn(r.start, "\n")] = '\0';

    printf("Enter the endpoint: ");
    fgets(r.end, sizeof(r.end), stdin);
    r.end[strcspn(r.end, "\n")] = '\0';

    printf("Enter the route number: ");
    scanf("%d%*с", &r.number);

    fprintf(file, "%s\n%s\n%d\n", r.start, r.end, r.number);
}

bool askToAddData() {
    char answer;
    printf("Do you want to add data? (y/n): ");
    scanf("%c%*c", &answer);
    return answer == 'y' || answer == 'Y';
}

int main()
{
    FILE* file = fopen("Spravka.dat", "a+");
    if (file == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    if (askToAddData())
    {
        addData(file);
        fflush(file);
        fclose(file); // Закрыть файл

        file = fopen("Spravka.dat", "r"); // Снова открыть для чтения
        if (file == NULL) {
            printf("Не удалось переоткрыть файл\n");
            return 1;
        }
    }

    rewind(file);

    if (file != NULL) {
        bool found = false;
        int searchNumber;
        printf("Enter the route number: ");
        scanf("%d", &searchNumber);
        
        Route r;
        while (fgets(r.start, sizeof(r.start), file) != NULL &&
            fgets(r.end, sizeof(r.end), file) != NULL &&
            fscanf(file, "%d", &r.number) != EOF)
        {
            if (r.number == searchNumber) {
                found = true;
                printf("Route data:\n");
                printf("Starting point: %s\n", r.start);
                printf("Endpoint: %s\n", r.end);
                printf("Route number: %d\n", r.number);
                printf("\n");
                break;
            }
        }
        if (!found)
        {
            printf("Route number %d was not found. \n", searchNumber);
        }
        fclose(file);
    }
    else {
        printf("Не удалось создать файл\n");
    }
    return 0;
}