// 26.03.2022
// Цыпин А.Н.
// lesson_1.c
// возведение целого числа в степень

#include <stdio.h>
#include <Windows.h>

double power(int number, int degree) // функция возведения целого числа в степень
{
    double p;
    int d;
    d = degree;
    if (d < 0) // взятие по модулю
    {
        d = d * (-1);
    }
    for (p = 1; d > 0; --d)
    {
        p = p * number;
    }
    if (degree < 0) // при отрицательной степени
        p = 1 / p;

    return p;
}

int NumberInput() // функция проверка ввода числа
{
    int n;
    while (scanf_s("%d", &n)  == 0) // если вы ввели не число повторяем ввод снова
    {
        fseek(stdin, 0, SEEK_SET); // очистка буфера ввода при неправильно вводе
        printf("Ошибка! Необходимо ввести число: ");
    }
    return n;
}

int main()
{
    SetConsoleOutputCP(1251);
    int number, degree;
    char ch = ' ';
    while (ch != 'q')
    {
        printf("Возведение целого числа в степень.\n");
        printf("Введите целое число: ");
        number = NumberInput();
        printf("Введите степень числа: ");
        degree = NumberInput();
        while (getchar() != '\n') // очистка буфера ввода
            continue;
        printf("Результат возведения числа %d в степень %d равно: %f\n\n", number, degree, power(number, degree));
        printf("Для завершения нажмите <q>, для продолжения нажмите любую клавишу: ");
        ch = getchar();
        system("cls"); // системный вызов очистки экрана
    }
    return 0;
}