#pragma once

int main()
{
    FILE* file = fopen("Spravka.dat", "a+");
    if (file != NULL) {
        bool found = false;
        int searchNumber;
        printf("������� ����� �������� ��� ������: ");
        scanf("%d", &searchNumber);

        Route r;
        while (fscanf(file, "%s %s %d", r.start, r.end, r.number) != EOF)
        {
            if (r.number == searchNumber) {
                found = true;
                printf("������ � ��������:\n");
                printf("��������� �����: %s\n", r.start);
                printf("�������� �����: %s\n", r.end);
                printf("����� ��������: %d\n", r.number);
                printf("\n");
                break;
            }
        }
        if (!found)
        {
            printf("������� � ������� %d �� ������. \n", searchNumber);
        }
        fclose(file);
    }
    else {
        printf("�� ������� ������� ����\n");
    }
    return 0;
}
