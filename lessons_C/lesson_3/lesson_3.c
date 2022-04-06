// 29.03.2022
// Цыпин А.Н.
//lesson_3.cpp
//При вводе текста с клавиатуры, все табуляции заменяються на 2 пробела

#include <stdio.h>
#include <Windows.h>
#include <limits.h>

int main(int arcs, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int ch;
 
    printf("Введите несколько предложений:\n");
    while((ch = getchar()) != EOF)
    {
        if ((char)ch == '\t')
        {
            (char)ch = ' ';
            for (int i = 0; i < 2; ++i)
            {
                printf("%c", (char)ch);
            }

        }
        else {
            printf("%c", (char)ch);
        }
    }
    return 0;
}

