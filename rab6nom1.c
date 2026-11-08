#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main()
{
    int yeas;          // год который вводим
    int ostatok;       // остаток от деления на 4
    int visokos = 0;   // 1 - високосный, 0 - нет

    setlocale(LC_ALL, "Rus");

    // приглашение и ввод года
    printf("Введите год: ");
    if (scanf("%d", &yeas) != 1 || yeas <= 0)
    {
        printf("Ошибка! Год должен быть целым числом больше 0\n");
        return 1;
    }

    // пункт 1 - считаем остаток от деления на 4
    ostatok = yeas % 4;
    printf("Остаток от деления на 4: %d\n", ostatok);

    if (ostatok == 0)
        printf("Если считать только по 4: год %d високосный\n", yeas);
    else
        printf("Если считать только по 4: год %d не високосный\n", yeas);

    // пункт 2 - точное условие (кратен 4 но не кратен 100, или кратен 400)
    if ((yeas % 4 == 0 && yeas % 100 != 0) || yeas % 400 == 0)
        visokos = 1;

    if (visokos == 1)
        printf("По точному условию: год %d високосный\n", yeas);
    else
        printf("По точному условию: год %d не високосный\n", yeas);

    return 0;
}
