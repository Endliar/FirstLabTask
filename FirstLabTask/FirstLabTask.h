#pragma once

int main()
{
    FILE* file = fopen("Spravka.dat", "a+");
    if (file != NULL) {
        bool found = false;
        int searchNumber;
        printf("Введите номер маршрута для поиска: ");
        scanf("%d", &searchNumber);

        Route r;
        while (fscanf(file, "%s %s %d", r.start, r.end, r.number) != EOF)
        {
            if (r.number == searchNumber) {
                found = true;
                printf("Данные о маршруте:\n");
                printf("Начальный пункт: %s\n", r.start);
                printf("Конечный пункт: %s\n", r.end);
                printf("Номер маршрута: %d\n", r.number);
                printf("\n");
                break;
            }
        }
        if (!found)
        {
            printf("Маршрут с номером %d не найден. \n", searchNumber);
        }
        fclose(file);
    }
    else {
        printf("Не удалось создать файл\n");
    }
    return 0;
}
