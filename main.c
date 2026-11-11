#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define PI 3.14159265358979323846
double area_pentagon(double R);
void definition_pentagon(void);
void draw_pentagon(int a);

int main(void) {
    setlocale(LC_ALL, "Russian");

    int choice;
    int a;
    double R;

    printf("Введите радиус R: ");
    if (scanf("%lf", &R) != 1 || R <= 0) {
        printf("Ошибка: радиус должен быть положительным числом.\n");
        return 1;
    }
    do {
        printf("\n==========================================\n");
        printf("Выберите операцию:\n");
        printf("1 - Рассчитать площадь\n");
        printf("2 - Вывести определение фигуры\n");
        printf("3 - Нарисовать фигуру\n");
        printf("0 - Выход из программы\n");
        printf("Ваш выбор: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода. Завершение программы.\n");
            break; 
        }

        switch (choice) {
            case 1:
                printf("\nПлощадь = %.2f\n", area_pentagon(R));
                break;
            case 2:
                printf("\n");
                definition_pentagon();
                break;
            case 3:
                printf("\nВведите размер рисунка (от 2 до 20): ");
                if (scanf("%d", &a) != 1 || a < 2 || a > 20) {
                    printf("Неверный размер.\n");
                    // Очистка буфера ввода на случай, если ввели буквы вместо цифр
                    while (getchar() != '\n'); 
                    break;
                }
                printf("\n");
                draw_pentagon(a);
                break;
            case 0:
                printf("\nВыход из программы. До свидания!\n");
                break;
            default:
                printf("\nНеверный номер операции. Попробуйте еще раз.\n");
                break;
        }

    } while (choice != 0); // Проверка условия: если choice == 0, цикл завершается

    return 0;
}

double area_pentagon(double R) {
    return 5.0 * R * R * sin(2.0 * PI / 5.0) / 2.0;
}

void definition_pentagon(void) {
    printf("Правильный пятиугольник (пентагон) - это фигура,\n");
    printf("которая имеет пять равных сторон и пять равных углов.\n");
    printf("Каждый внутренний угол равен 108 градусам.\n");
}

void draw_pentagon(int a) {
    int i, j;
    for (i = 0; i <= a; i++) {
        for (j = 0; j < a - i + 1; j++) printf(" ");
        printf("*");
        if (i > 0) {
            for (j = 0; j < 2 * i - 1; j++) printf(" ");
            printf("*");
        }
        printf("\n");
    }
    for (i = 1; i <= a / 2; i++) {
        for (j = 0; j < i + 1; j++) printf(" ");
        if (i == a / 2) {
            for (j = 0; j < 2 * (a - i) + 1; j++) printf("*");
        } else {
            printf("*");
            for (j = 0; j < 2 * (a - i) - 1; j++) printf(" ");
            printf("*");
        }
        printf("\n");
    }
}
