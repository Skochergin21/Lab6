/*
 * Вариант 14. Количество дней в году.
 *
 * Контрольные примеры:
 *   2023 -> 365 дней (не високосный)
 *   2024 -> 366 дней (високосный, кратен 4)
 *   1900 -> 365 дней (кратен 100 но не кратен 400 - не високосный)
 *   2000 -> 366 дней (кратен 400 - високосный)
 *   1    -> 365 дней (граница, самый маленький год)
 *   0    -> ошибка
 *   -5   -> ошибка
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
 
int visokosniy(int g);
int skolko_dney(int g);
 
int main()
{
    int god;
    int dni;
 
    setlocale(LC_ALL, "Rus");
 
    printf("Введите год: ");
    if (scanf("%d", &god) != 1 || god <= 0)
    {
        printf("Ошибка! Год должен быть целым числом больше 0\n");
        return 1;
    }
 
    dni = skolko_dney(god);
 
    printf("В %d году %d дней", god, dni);
    if (visokosniy(god) == 1)
        printf(" (год високосный)\n");
    else
        printf(" (год не високосный)\n");
 
    return 0;
}
 
/* Проверка года: 1 - високосный, 0 - не високосный */
int visokosniy(int g)
{
    int otvet;
    if (g % 400 == 0)
        otvet = 1;
    else if (g % 100 == 0)
        otvet = 0;
    else if (g % 4 == 0)
        otvet = 1;
    else
        otvet = 0;
    return otvet;
}
 
int skolko_dney(int g)
{
    int d;
    if (visokosniy(g) == 1)
        d = 366;
    else
        d = 365;
    return d;
}
