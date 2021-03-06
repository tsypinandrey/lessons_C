// 26.03.2022
// Цыпин А.Н.
// lesson_2.c
// нахождение самой длинной строки при вводе, копирование её и вывод её на экран

#include <stdio.h>
#include <Windows.h>

#define MAXLINE 1000 // максимальный размер массива строки

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int c; // вводимый символ
    int i = 0; // счетчик для текущей строки
    int max = 0; // максимальная длина строки
   char line[MAXLINE]; // массив для вводимой строки
   char copyline[MAXLINE]; // массив для максимальной строки
   printf("Введите несколько предложений.\n");
   printf("Для завершения нажмите <Ctrl-Z>\n");
   while ((c = getchar()) != EOF) // считываем символя пока не достигнем конца файла
   {
       if ((char)c != '\n') // пока не достигнем символа новой строка
       {
           line[i] = (char)c; // записываем полученый символ в наш массив
           fflush(stdout); // сброс буфера
           ++i;
       }
       else // если достиги символа новой строка
       {
           line[i] = '\0'; // присваиваем значение конец строки 
           if (i > max) // если текуший размер строки больше максимального размера
           {
               max = i; // присваиваем максимальное значение строки
               int j = 0; // счетчик для 
               while (copyline[j] = line[j]) // копируем строку в массив максимальной строки
                   ++j;
           }
           i = 0;
       }
 
   }
   printf("%s", copyline);
    return 0;
}
