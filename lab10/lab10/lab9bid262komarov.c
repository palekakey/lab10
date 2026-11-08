#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <math.h>

//task 1
double fa(double x) {
    return (x * x) - 4 * x;
}

double fb(double x) {
    return cos(x);
}

void run_task_1() {
    double x;
    int choice;

    printf("\n=== ЗАДАНИЕ 1: Конструирование базовых функций ===\n");
    printf("Введите значение x: ");
    if (scanf("%lf", &x) != 1) return;

    double val_a = fa(x);
    double val_b = fb(x);

    printf("fa(x) = %lf, fb(x) = %lf\n", val_a, val_b);

    do {
        printf("\n--- Меню Задания 1 ---");
        printf("\n1. Произведение функций");
        printf("\n2. Разность квадратов функций");
        printf("\n3. Удвоенная сумма функций");
        printf("\n0. Вернуться в главное меню");
        printf("\nВыберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n[Результат] Произведение: %lf\n", val_a * val_b);
            break;
        case 2:
            printf("\n[Результат] Разность квадратов: %lf\n", (val_a * val_a) - (val_b * val_b));
            break;
        case 3:
            printf("\n[Результат] Удвоенная сумма: %lf\n", 2.0 * (val_a + val_b));
            break;
        case 0:
            printf("Выход из Задания 1.\n");
            break;
        default:
            printf("Неверный пункт!\n");
        }
    } while (choice != 0);
}

// task 2
double sin_n(double x, int N) {
    double sum = x;
    double term = x;
    for (int n = 1; n < N; n++) {
        term = term * (-x * x) / ((2 * n) * (2 * n + 1));
        sum += term;
    }
    return sum;
}

double sin_eps(double x, double eps) {
    double sum = x;
    double term = x;
    int n = 1;
    while (fabs(term) > eps) {
        term = term * (-x * x) / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }
    return sum;
}

void run_task_2() {
    double x, eps;
    int N;

    printf("\n=== ЗАДАНИЕ 2: Три способа расчета sin(x) ===\n");
    printf("Введите x (в радианах): ");
    if (scanf("%lf", &x) != 1) return;
    printf("Введите число членов ряда N: ");
    scanf("%d", &N);
    printf("Введите точность вычисления eps (например, 0.00001): ");
    scanf("%lf", &eps);


    double res_std = sin(x);
    double res_n = sin_n(x, N);
    double res_eps = sin_eps(x, eps);

    printf("\n--- Сравнение результатов ---");
    printf("\n1) Стандартный sin(x):     %.15lf", res_std);
    printf("\n2) Свой sin_n (N=%d):      %.15lf", N, res_n);
    printf("\n3) Свой sin_eps (eps=%g):   %.15lf", eps, res_eps);
    printf("\n\nПогрешность метода sin_n:   %.15lf", fabs(res_std - res_n));
    printf("\nПогрешность метода sin_eps: %.15lf\n", fabs(res_std - res_eps));
}

//dz
void print_definition() {
    printf("\n--- Определение фигуры ---\n");
    printf("Прямоугольник — это четырехугольник, у которого все четыре угла прямые (равны 90 градусам).\n");
    printf("Противоположные стороны прямоугольника равны друг другу.\n");
}


float area_rectangle(float a, float b) {
    return a * b;
}

void draw_rectangle(int a, int b, char sym) {
    printf("\n--- Рисунок фигуры ---\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%c ", sym);
        }
        printf("\n");
    }
}

void run_task_3() {
    int choice;
    float side_a, side_b;
    char draw_sym;

    printf("\n=== ЗАДАНИЕ 3: Работа с фигурой (Прямоугольник) ===\n");
    printf("Введите длину стороны A (высота): ");
    if (scanf("%f", &side_a) != 1) return;
    printf("Введите длину стороны B (ширина): ");
    scanf("%f", &side_b);

    while (getchar() != '\n');

    printf("Введите символ для рисования: ");
    scanf("%c", &draw_sym);

    do {
        printf("\n--- Меню Задания 3 ---");
        printf("\n1) Рассчитать площадь");
        printf("\n2) Вывести определение фигуры");
        printf("\n3) Нарисовать фигуру");
        printf("\n0) Вернуться в главное меню");
        printf("\nВыберите операцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nПлощадь прямоугольника: %.2f\n", area_rectangle(side_a, side_b));
            break;
        case 2:
            print_definition();
            break;
        case 3:
            draw_rectangle((int)side_a, (int)side_b, draw_sym);
            break;
        case 0:
            printf("Выход из Задания 3.\n");
            break;
        default:
            printf("Неверный пункт!\n");
        }
    } while (choice != 0);
}

int main() {
    setlocale(LC_ALL, ".UTF8");
    int global_choice;

    do {
        printf("\n=======================================");
        printf("\nГЛАВНОЕ МЕНЮ ЛАБОРАТОРНОЙ РАБОТЫ №10");
        printf("\n=======================================");
        printf("\n1. Запустить Задание 1 (Функции и расчеты)");
        printf("\n2. Запустить Задание 2 (Ряды Тейлора для sin(x))");
        printf("\n3. Запустить Задание 3 (Геометрическая фигура)");
        printf("\n0. Завершить работу всей программы");
        printf("\nПреподаватель, выберите задание для проверки: ");

        if (scanf("%d", &global_choice) != 1) {
            printf("Ошибка ввода кода задания!\n");
            break;
        }

        switch (global_choice) {
        case 1:
            run_task_1();
            break;
        case 2:
            run_task_2();
            break;
        case 3:
            run_task_3();
            break;
        case 0:
            printf("\nПрограмма успешно завершена. Спасибо за проверку!\n");
            break;
        default:
            printf("\nТакого задания нет! Выберите пункт от 0 до 3.\n");
        }
    } while (global_choice != 0);

    return 0;
}