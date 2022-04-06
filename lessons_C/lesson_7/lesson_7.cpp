// lesson_7.c
// Цыпин А.Н.
// Создание меню выбора

#include <stdio.h>
#include <Windows.h>

#define START 1

static int s_fihish = 1;

void GlMenu() // функция главного меню
{
    printf("%d) Функция для переворачивания строки.\n", START);
    printf("%d) Next function.\n", ++s_fihish);
    printf("%d) Завершить!\n", ++s_fihish);
    printf("Выберите пункт меня для продолжения: ");
}

int NumberInput() // функция проверка ввода числа
{
    int n = 1;
    while (scanf_s("%d", &n) == 0 || n < START || n > s_fihish) // если вы ввели не число повторяем ввод снова
    {
            fseek(stdin, 0, SEEK_SET); // очистка буфера ввода при неправильно вводе
            printf("Ошибка! Необходимо ввести число от %d до %d: ", START, s_fihish);
    }
    while (getchar() != '\n') // очистка буфера ввода
        continue;
    return n;
}

void reverse()
{
    printf("Введите слово: ");
    char s[255];
    s[0] = '\0';
    int i, j;
    char ch;
    scanf_s("%s", &s, 255);
    for (i = 0, j = strlen(s) - 1; j > i; ++i, --j)
    {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
    printf("%s\n", s);
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    GlMenu(); // функция главного меню
    int digit = NumberInput(); // номер выбраного меню
    switch (digit)
    {
    case 1: reverse();
        break;
    case 2: break;
    case 3: break;
    }
    printf("Well Don!\n");
    return 0;
}
