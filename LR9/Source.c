#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES 
#include <locale.h>
#include <stdio.h>
#include <math.h>

int full_table(void);
int triangle(void);
int shape(int rows, int cols, char symbol);

int threes(long long n);
int last(long long n);
int chet(long long n);
int five(long long n);
int sum_nechet(long long n);
int sum_seven(long long n);
double proizv_zero(long long n);
int proizv_numb(long long n);
int sum_chet(long long n);
int count_same(long long n);
int halves_equal(long long n);
double proizv_chet_nechet(long long n);

int parallelogram(int h, int a, int alpha, char symbol);

int main()
{
	setlocale(LC_ALL, "RUS");
	char repeat;

    // задание 1, вариант 1

    do
    {
        // полная таблица умножения 

        int count1 = full_table();
        printf("[напечатано %d элементов]\n\n", count1);

        // треугольник по пифагору

        int count2 = triangle();
        printf("[напечатано %d элементов]\n\n", count2);

        // индивидуальная таблица

        int r, c;
        char sym;
        printf("введите количество строк: ");
        scanf("%d", &r);
        printf("введите количество столбцов: ");
        scanf("%d", &c);
        printf("введите символ для заполнения: ");
        scanf(" %c", &sym);

        int count3 = shape(r, c, sym);
        printf("\n[напечатано %d символов]\n", count3);

        printf("\nЗапустить программу снова? (y/n): ");
        scanf(" %c", &repeat);

    } 
    
    while (repeat == 'y' || repeat == 'Y');

	// задание 2

    long long num;
    char choice;

    do
    {
        printf("\n\n\nвведите длинное число: ");

        if (scanf("%lld", &num) != 1) {
            printf("введите целое число!\n\n");
            while (getchar() != '\n'); // очистка на случай ввода букв
            continue; // перепрыгиваем в конец, чтобы не делить буквы 
        }

        if (num < 0) num = -num;

        printf("1) количество цифр 3: %d\n", threes(num));
        printf("2) повторений последней цифры: %d\n", last(num));
        printf("3) количество четных цифр: %d\n", chet(num));
        printf("4) количество цифр > 5: %d\n", five(num));
        printf("5) сумма нечетных цифр: %d\n", sum_nechet(num));
        printf("6) сумма цифр >= 7: %d\n", sum_seven(num));
        printf("7) произведение цифр (без 0): %.0lf\n", proizv_zero(num));

        int res8 = proizv_numb(num);
        if (res8 == -1)
        {
            printf("8) число слишком короткое.\n");
        }
        else
        {
            printf("8) произведение второй и предпоследней цифры числа: %d\n", res8);
        }

        printf("9) сумма четных (без последней): %d\n", sum_chet(num));
        printf("10) количество пар одинаковых подряд: %d\n", count_same(num));

        int res11 = halves_equal(num);
        if (res11 == -1)
        {
            printf("11) число слишком короткое.\n");
        }
        else if (res11 == 1)
        {
            printf("11) сумма половин равны\n");
        }
        else
        {
            printf("11) сумма половин не равны\n");
        }

        printf("12) произведение сумм четных/нечетных разрядов: %.0lf\n", proizv_chet_nechet(num));

        printf("\nначать заново? (y/n): ");
        scanf(" %c", &choice);

    } 
    
    while (choice == 'y' || choice == 'Y');

	// задание 3, вариант 18

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

int full_table(void)
{
    int count = 0;

    for (int row = 1; row <= 9; row++)
    {

        for (int col = 1; col <= 9; col++)
        {
            printf("%4d", col * row);
            count++;
        }
        printf("\n");
    }

    return count;
}

int triangle(void)
{
    int count = 0;

    for (int row = 1; row <= 9; row++)
    {

        for (int col = 1; col <= row; col++)
        {
            printf("%4d", col * row);
            count++;
        }
        printf("\n");
    }

    return count;
}

int shape(int rows, int cols, char symbol)
{
    int count = 0;

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            printf(" %c ", symbol);
            count++;
        }

        
        printf("\n");
    }
    return count;
}

int threes(long long n) 
{
    int count = 0;

    while (n > 0) 
    {
        if (n % 10 == 3) count++;
        n /= 10; // меняем только копию числа, не его оригинал
    }

    return count;
}

int last(long long n)
{
    int last = n % 10; // запоминаем последнюю цифру
    int count = 0;

    while (n > 0) 
    {
        if (n % 10 == last) count++;
        n /= 10;
    }

    return count;
}

int chet(long long n) 
{
    int count = 0;

    while (n > 0) 
    {
        if ((n % 10) % 2 == 0) count++;
        n /= 10;
    }

    return count;
}

int five(long long n) 
{
    int count = 0;

    while (n > 0) 
    {
        if (n % 10 > 5) count++;
        n /= 10;
    }

    return count;
}

int sum_nechet(long long n) 
{
    int sum = 0;

    while (n > 0) 
    {
        int d = n % 10;
        if (d % 2 != 0) sum += d;
        n /= 10;
    }

    return sum;
}

int sum_seven(long long n) 
{
    int sum = 0;

    while (n > 0) 
    {
        int d = n % 10;
        if (d >= 7) sum += d;
        n /= 10;
    }

    return sum;
}

double proizv_zero(long long n) 
{
    double prod = 1.0;

    if (n == 0)
    {
        return 0;
    }

    while (n > 0) 
    {
        int d = n % 10;
        if (d != 0) prod *= d;
        n /= 10;
    }

    return prod;
}

int proizv_numb(long long n) 
{

    long long temp = n;
    int len = 0;
    while (temp > 0) 
    { 
        len++; temp /= 10; 
    }

    if (len < 2)
    {
        return -1; // число из одной цифры
    }

    int predposl = (n / 10) % 10; 

    long long div = 1;
    for (int i = 0; i < len - 2; i++) div *= 10;
    int second = (n / div) % 10;

    return second * predposl;
}

int sum_chet(long long n) 
{
    n /= 10;
    int sum = 0;
    while (n > 0) 
    {
        int d = n % 10;
        if (d % 2 == 0) sum += d;
        n /= 10;
    }

    return sum;
}

int count_same(long long n) 
{
    int count = 0;
    int prev = n % 10;
    n /= 10;
    while (n > 0)
    {
        int curr = n % 10;
        if (curr == prev) count++;
        prev = curr;
        n /= 10;
    }

    return count;
}

int halves_equal(long long n) 
{
    long long temp = n;
    int len = 0;
    while (temp > 0) 
    { 
        len++; temp /= 10;
    }

    if (len < 2)
    {
        return -1;
    }

    int half = len / 2;
    int sum_right = 0, sum_left = 0;

    for (int i = 0; i < half; i++)
    {
        sum_right += n % 10;
        n /= 10;
    }

    if (len % 2 != 0)
    {
        n /= 10;
    }

    while (n > 0) 
    {
        sum_left += n % 10;
        n /= 10;
    }

    return (sum_left == sum_right) ? 1 : 0;
}

double proizv_chet_nechet(long long n) 
{
    int sum_nechet = 0;
    int sum_chet = 0;
    int pos = 1;

    while (n > 0) 
    {
        int d = n % 10;
        if (pos % 2 != 0)
        {
            sum_nechet += d;
        }

        else
        {
            sum_chet += d;
        }

        pos++;
        n /= 10;
    }

    return (double)(sum_nechet * sum_chet);
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