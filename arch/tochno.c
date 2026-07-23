#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    
    float a = 0.1f;
    float b = 0.2f;
    float c = a + b;

    // 1. Проверяем обычный вывод (кажется, что всё нормально)
    printf("Обычный вывод: %.1f + %.1f = %.1f\n", a, b, c);

    // 2. Выводим с высокой точностью (до 20 знаков)
    printf("\nРеальное содержимое памяти:\n");
    printf("a = %.20f\n", a);
    printf("b = %.20f\n", b);
    printf("c = %.20f\n", c);

    // 3. Пробуем сравнить в условии if
    printf("\nРезультат сравнения:\n");
    if (c == 0.3f) {
        printf("Идеально! 0.1 + 0.2 равно 0.3\n");
    } else {
        printf("Опасно! Компьютер считает, что 0.1 + 0.2 НЕ РАВНО 0.3\n");
    }

    return 0;
}
