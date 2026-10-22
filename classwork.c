#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ROW 9
#define COL 9

int task1();
int task2();
int task3();

int pifagor();
int ugol();
int chisla();
int chetn(int n);
int treug(int a, int b, char c);

int main()
{
    setlocale(LC_ALL, ".UTF8");
    task1();
    task2();
    task3();
    return 0;
}

int task1()
{
    printf("Задание 1.1 (Таблица Пифагора):\n");
    pifagor();

    printf("\nЗадание 1.2 (Нижний треугольник):\n");
    ugol();

    printf("\nЗадание 1.3 (Числа по варианту 3):\n");
    chisla();
    return 0;
}

int task2()
{
    int n, res;
    char a;

    printf("\nЗадание 2:\n");
    do
    {
        printf("Введите число: ");
        scanf("%d", &n);

        res = chetn(n);
        printf("Количество четных цифр: %d\n", res);

        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &a);
    } while (a != 'n');
    return 0;
}

int task3()
{
    int a, b, cont;
    char c;

    printf("\nЗадание 3 (ДЗ):\n");
    do
    {
        printf("Введите символ из которого будет строиться фигура: ");
        scanf(" %c", &c);
        printf("Введите высоту a: ");
        scanf("%d", &a);
        printf("Введите ширину b: ");
        scanf("%d", &b);

        if (a <= 0 || b <= 0)
        {
            printf("Ошибка: размеры должны быть положительными\n");
        }
        else
        {
            printf("Прямоугольный треугольник:\n\n");
            treug(a, b, c);
        }

        printf("\nПродолжить? (Да - введите любое число, Нет - введите 0): ");
        scanf("%d", &cont);
    } while (cont != 0);
    return 0;
}

int pifagor()
{
    int row, col;

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= COL; col++)
        {
            printf("%5d", col * row);
        }
        printf("\n");
    }
    return 0;
}

int ugol()
{
    int row, col;

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%5d", col * row);
        }
        printf("\n");
    }
    return 0;
}

int chisla()
{
    int row, col;

    for (row = 4; row <= 7; row++)
    {
        for (col = 1; col <= 10; col++)
        {
            printf("%5d", row * 10 + col);
        }
        printf("\n");
    }
    return 0;
}

int chetn(int n)
{
    int k, d;

    k = 0;
    n = abs(n);

    if (n == 0)
    {
        return 1;
    }

    while (n > 0)
    {
        d = n % 10;
        if (d % 2 == 0)
        {
            k++;
        }
        n = n / 10;
    }
    return k;
}

int treug(int a, int b, char c)
{
    int row, col, len;

    for (row = 1; row <= a; row++)
    {
        len = (row * b + a - 1) / a;
        for (col = 1; col <= len; col++)
        {
            putchar(c);
        }
        putchar('\n');
    }
    return 0;
}