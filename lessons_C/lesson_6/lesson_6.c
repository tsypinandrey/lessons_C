// lesson_6.cpp 
// Цыпин А.Н.
// IDE: Visual Studio
// подсчет символов(русских и английских) и цифр

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    wchar_t ch;
    printf("Введите ваш текс:\n");
    printf("Для завершения нажмите <Ctrl-Z>.");
    int digit = 0, symbol = 0, other = 0;
    while ((ch = getwchar()) != WEOF)
    {
        switch (ch)
        {
            case '1':case '2':case'3':case'4':case'5':case '6':case '7':case'8':case'9':case'0':
                ++digit;
                break;
            case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':case 'i':case 'j':case 'k':case 'l':case 'm':
            case 'n':case 'o':case 'p':case 'q':case 'r':case 's':case 't':case 'u':case 'v':case 'w':case 'x':case 'y':case 'z':
            case 'A':case 'B':case 'C':case 'D':case 'E':case 'F':case 'G':case 'H':case 'I':case 'J':case 'K':case 'L':case 'M':
            case 'N':case 'O':case 'P':case 'Q':case 'R':case 'S':case 'T':case 'U':case 'V':case 'W':case 'X':case 'Y':case 'Z':
            case L'а':case L'б':case L'в':case 'г':case L'д':case L'е':case L'ё':case L'ж':case L'з':case L'и':case L'й':case L'к':case L'л':
            case L'м':case L'н':case L'о':case L'п':case L'р':case L'с':case L'т':case L'у':case L'ф':case L'х':case L'ц':case L'ч':case L'ш':
            case L'щ':case L'ъ':case L'ы':case L'ь':case L'э':case L'ю':case L'я':
            case L'А':case L'Б':case L'В':case L'Г':case L'Д':case L'Е':case L'Ё':case L'Ж':case L'З':case L'И':case L'Й':case L'К':case L'Л':
            case L'М':case L'Н':case L'О':case L'П':case L'Р':case L'С':case L'Т':case L'У':case L'Ф':case L'Х':case L'Ц':case L'Ч':case L'Ш':
            case L'Щ':case L'Ъ':case L'Ы':case L'Ь':case L'Э':case L'Ю':case L'Я':
                ++symbol;
                break;
            case '\n':case '^Z': // исключаем подсчет новой строки и ввода <Ctrl-Z>
                break;
            default: ++other;
                break;
        }
    }
    printf("Цифр - %d, букв - %d, другие символы - %d\n", digit, symbol, other);

}
