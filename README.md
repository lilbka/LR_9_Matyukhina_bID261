# Лабораторная работа №9

## 1. Условие задачи номер 3 (вариант 18)
Написать программу, выводящую на экран заданную геометрическую фигуру, нарисованную с помощью заданного с клавиатуры символа, условие заполнения фигуры и задаваемые параметры фигуры в таблице (остальные можно взять константные)

https://sun9-83.vkuserphoto.ru/s/v1/ig2/qLASd0oKu215PFXrqwpOWO-QcCdxkfBOFHQ_BRrH9j2olvrVcKbDxFEgJOHyKCCRVRfOvceBR_Pu3Y5aMVGQ_Tfe.jpg?quality=95&as=32x6,48x9,72x13,108x20,160x29,240x44,360x66,480x88,540x99,640x117,720x132,828x152&from=bu&u=Ecsm9Znqb-bKkrCsdsX9KR4IiNxcJ98NtczrN0-4RX8&cs=828x0

## Блок-схема к заданию 3

https://sun9-82.vkuserphoto.ru/s/v1/ig2/9zYrtc6jgV1LIEPRY6JAqalx0ZitLJlBAyo0sbOS2elbLD1VXe8sreoGaRYAcn1v7yRc9iVkvs_g4q_H9t3ErjsD.jpg?quality=95&as=32x21,48x32,72x48,108x72,160x106,240x159,360x239,480x319,540x359,640x425,720x478,1080x717,1280x850&from=bu&u=53_iUWtGTZMnrEkxK-dQEif_L3e3cGHKiZPz7U26E6Q&cs=1280x0

## 2. Реализация программы
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>

int parallelogram(int h, int a, int alpha, char symbol);

int main()
{
	setlocale(LC_ALL, "RUS");

      char quit;

    do
    {
        int h, a, alpha;
        char symbol;

        printf("\n\n\nвведите высоту: ");
        scanf("%d", &h);

        printf("введите основание: ");
        scanf("%d", &a);

        printf("введите угол наклона (в градусах): ");
        scanf("%d", &alpha);

        printf("введите символ для контура: ");
        scanf(" %c", &symbol);

        if (h < 2 || a < 2)
        {
            printf("высота и основание должны быть >= 2 для пустой фигуры.\n");
            continue;
        }
        if (alpha <= 0 || alpha >= 90)
        {
            printf("угол должен быть в диапазоне (0; 90).\n");
            continue;
        }

        int count = parallelogram(h, a, alpha, symbol);

        printf("\n[напечатано %d символов контура]\n", count);

        printf("\nпродолжить выполнять? (y/n): ");
        scanf(" %c", &quit);

    } 
    
    while (quit == 'y' || quit == 'Y');

    return 0;
}

int parallelogram(int h, int a, int alpha, char symbol)
{
    int count = 0;

    double rad = alpha * M_PI / 180.0; 
    int shift = (int)(1.0 / tan(rad)); // вычисляем, на сколько пробелов сдвигать каждую строку

    if (shift < 1)
    {
        shift = 1;
    }

    for (int i = 0; i < h; i++)
    {
        for (int s = 0; s < i * shift; s++) // рисуем увеличивающиеся сдвиги с каждой строкой
        {
            printf(" ");
        }

        if (i == 0 || i == h - 1) // сама строка
        {
            for (int j = 0; j < a; j++)
            {
                printf("%c", symbol);
                count++;
            }
        }
        else
        {
            printf("%c", symbol);
            count++;

            for (int j = 0; j < a - 2; j++)
            {
                printf(" ");
            }

            printf("%c", symbol);
            count++;
        }
        printf("\n");
    }

    return count; // возвращаем количество напечатанных символов
}

## 3. Результаты работы программы
введите высоту: 5
введите основание: 6
введите угол наклона (в градусах): 45
введите символ для контура: #
######
 #    #
  #    #
   #    #
    ######

[напечатано 18 символов контура]

продолжить выполнять? (y/n): n

## 4. Информация о разработчике
Матюхина Софья, бИД-261
