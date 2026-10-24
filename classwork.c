#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ROW 9
#define COL 9

int pifagor(int row, int col);
int chisla(int row, int col);
int chetn(int n);
char treug(int row, int col, int a, int b, char c);

int main()
{
    int row, col, val;
    int n, res;
    char yn;
    int a, b, cont;
    char c, ch;

    setlocale(LC_ALL, ".UTF8");

    printf("Задание 1.1 (Таблица Пифагора):\n");
    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= COL; col++)
        {
            val = pifagor(row, col);
            printf("%5d", val);
        }
        printf("\n");
    }

    printf("\nЗадание 1.2 (Нижний треугольник):\n");
    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
        {
            val = pifagor(row, col);
            printf("%5d", val);
        }
        printf("\n");
    }

    printf("\nЗадание 1.3 (Числа по варианту 3):\n");
    for (row = 4; row <= 7; row++)
    {
        for (col = 1; col <= 10; col++)
        {
            val = chisla(row, col);
            printf("%5d", val);
        }
        printf("\n");
    }

    printf("\nЗадание 2:\n");
    do
    {
        printf("Введите число: ");
        scanf("%d", &n);

        res = chetn(n);
        printf("Количество четных цифр: %d\n", res);

        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &yn);
    } while (yn != 'n');

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
            for (row = 1; row <= a; row++)
            {
                for (col = 1; col <= b; col++)
                {
                    ch = treug(row, col, a, b, c);
                    putchar(ch);
                }
                putchar('\n');
            }
        }

        printf("\nПродолжить? (Да - введите любое число, Нет - введите 0): ");
        scanf("%d", &cont);
    } while (cont != 0);
    return 0;
}

int pifagor(int row, int col)
{
    return row * col;
}

int chisla(int row, int col)
{
    return row * 10 + col;
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

char treug(int row, int col, int a, int b, char c)
{
    int len;

    len = (row * b + a - 1) / a;
    if (col <= len)
    {
        return c;
    }
    else
    {
        return ' ';
    }
}
