// lesson_7.c
// Цыпин А.Н.
// Создание меню выбора

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <Windows.h>

static int s_start = 1; // первая строка меню
static int s_fihish = 1; // последняя строка меню

void GlMenu(); // функция главного меню
int NumberInput(); // функция проверка ввода числа
void Task(wchar_t& ch, int digit); // Запуск какой либо функции

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int digit = 0; // для выбора номера меню
    wchar_t ch = ' ';
    while (digit != s_fihish) {
        GlMenu(); // функция главного меню
        digit = NumberInput(); // номер выбраного меню
        switch (digit)
        {
        case 1:
            Task(ch, digit);
            break;
        case 2:
            Task(ch, digit); 
            break;
        case 3:
            Task(ch, digit);
            break;
        default :
            break;
        }
        ch = ' ';
     }
    system("cls"); // системный вызов очистки экрана для ОС Window 
    return 0;
}

void GlMenu() // функция главного меню
{
    system("cls"); // системный вызов очистки экрана для ОС Window 
    // при каждом вызовве функции меню обновляем счетчики первой и последней строки меню
    s_start = 1; // первая строка меню при каждом вызове эта переменная обновляеться
    s_fihish = 1; // последняя строка меню при каждом вызове эта переменная обновляеться
    printf("%d) Программа 1.\n", s_start); // первая строка нашего меню
    printf("%d) Программа 2.\n", ++s_fihish); // следующая строка нашего меню
    printf("%d) Программа 3.\n", ++s_fihish); // следующая строка нашего меню
    printf("%d) Завершить!\n", ++s_fihish); // посленяя строка нашего меню
    printf("Выберите пункт меню: ");
}

int NumberInput() // функция проверка ввода числа
{
    int n = 1;
    while (scanf_s("%d", &n) == 0 || n < s_start || n > s_fihish) // если вы ввели не число повторяем ввод снова
    {
        fseek(stdin, 0, SEEK_SET); // очистка буфера ввода при неправильном вводе
        printf("Ошибка! Необходимо ввести число от %d до %d: ", s_start, s_fihish);
    }
    return n;
}
void Task(wchar_t& ch, int digit) // Запуск какой либо функции
{
    while (ch != 'n' && ch != 'N' && ch != L'н' && ch != L'Н')
    {
        fseek(stdin, 0, SEEK_SET); // очистка буфера ввода
        printf("Это меню № %d\n", digit); // Вместо этой строки вставляем свою функцию для выполнения
        printf("Для продолжения <Y>/<Д>, для завершения <N>/<Н>: ");
        ch = getwchar();
    }
}
