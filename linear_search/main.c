#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 1. ГЛОВАЛЬНЫЕ ПЕРЕМЕННЫЕ - подсчет итераций
int iterations_f12 = 0;
int iterations_f23 = 0;
int iterations_f13 = 0;

// 2. ОБЪЯВЛЕНИЕ МАТЕМАТИЧЕСКИХ ФУНКЦИЙ 
float f1(float x) { 
    return 0.6f * x + 3.0f; 
}

float f2(float x) { 
    return powf(x - 2.0f, 3.0f) - 1.0f; 
}

float f3(float x) { 
    return 3.0f / x; 
}

// Тестовые функции 
float f_test_line(float x) { return x; }
float f_test_zero(float x) { (void)x; return 0.0f; }
float f_test_quad(float x) { return x * x; }

// 3. ПОДПРОГРАММЫ ВЫЧИСЛЕНИЙ
float root(float (*f)(float), float (*g)(float), float a, float b, float eps1, int *iter_count) {
    float fa = f(a) - g(a);
    float fb = f(b) - g(b);
    int it = 0;
    float c = a;
    while (fabsf(b - a) > eps1 && it < 100000) {
        c = a - fa * (b - a) / (fb - fa);
        float fc = f(c) - g(c);
        if (fabsf(fc) < eps1) break;
        if (fa * fc < 0.0f) { b = c; fb = fc; } 
        else { a = c; fa = fc; }
        it++;
    }
    if (iter_count) *iter_count = it;
    return c;
}

float integral(float (*f)(float), float a, float b, float eps2) {
    int n = 10; 
    float s_old = 0.0f, s_new = 0.0f;
    float h = (b - a) / n;
    float sum = 0.5f * (f(a) + f(b));
    for (int i = 1; i < n; i++) sum += f(a + i * h);
    s_new = sum * h;
    do {
        s_old = s_new;
        n *= 2;
        h = (b - a) / n;
        sum = 0.5f * (f(a) + f(b));
        for (int i = 1; i < n; i++) sum += f(a + i * h);
        s_new = sum * h;
    } while (fabsf(s_new - s_old) / 3.0f > eps2);
    return s_new;
}

// 4. ФУНКЦИЯ ОТРЕСОВКИ ГРАФИКА
void plot_gnuplot(float x13, float x23, float x12) {
    FILE *f_data = fopen("funcs.dat", "w");
    if (!f_data) return;
    for (float x = 0.2f; x <= 5.0f; x += 0.01f) {
        fprintf(f_data, "%f %f %f %f\n", x, f1(x), f2(x), f3(x));
    }
    fclose(f_data);

    FILE *f_pts = fopen("points.dat", "w");
    if (!f_pts) return;
    fprintf(f_pts, "%f %f \"A\"\n", x13, f1(x13));
    fprintf(f_pts, "%f %f \"B\"\n", x23, f3(x23));
    fprintf(f_pts, "%f %f \"C\"\n", x12, f1(x12));
    fclose(f_pts);

    FILE *f_script = fopen("plot.gnu", "w");
    if (!f_script) return;

    fprintf(f_script, "set title 'Визуализация площади фигуры'\n");
    fprintf(f_script, "set grid\n");
    fprintf(f_script, "set xrange [0.2:5.0]\n");
    fprintf(f_script, "set yrange [-2.0:7.0]\n");
    fprintf(f_script, "set key top left\n");
    fprintf(f_script, "set style fill transparent solid 0.4 noborder\n");
    
    fprintf(f_script, "plot 'funcs.dat' using 1:(($1>=%f && $1<=%f) ? $4 : $2):2 with filledcurves title 'Area 1 (f1-f3)' lc rgb 'orange', \\\n", x13, x23);
    fprintf(f_script, "     'funcs.dat' using 1:(($1>=%f && $1<=%f) ? $3 : $2):2 with filledcurves title 'Area 2 (f1-f2)' lc rgb 'coral', \\\n", x23, x12);
    fprintf(f_script, "     'funcs.dat' using 1:2 with lines title 'f1(x) = 0.6x + 3' lw 2 lc rgb 'blue', \\\n");
    fprintf(f_script, "     'funcs.dat' using 1:3 with lines title 'f2(x) = (x-2)^3 - 1' lw 2 lc rgb 'green', \\\n");
    fprintf(f_script, "     'funcs.dat' using 1:4 with lines title 'f3(x) = 3/x' lw 2 lc rgb 'red', \\\n");
    fprintf(f_script, "     'points.dat' using 1:2 with points pt 7 ps 1.5 lc rgb 'black' notitle, \\\n");
    fprintf(f_script, "     'points.dat' using 1:($2+0.3):3 with labels font 'Arial,10' notitle\n");
    
    fprintf(f_script, "pause -1 'Нажмите Enter для выхода...'\n");
    fclose(f_script);

    printf("\nЗапуск Gnuplot для отображения графика...\n");
    int status = system("gnuplot plot.gnu");
    (void)status; 
}

void print_help() {
    printf("Допустимые ключи командной строки:\n");
    printf("  -help       Вывести эту справку\n");
    printf("  -roots      Напечатать абсциссы точек пересечения кривых\n");
    printf("  -iterations Напечатать число итераций при поиске точек пересечения\n");
    printf("  -test       Запустить режим тестирования функций root и integral\n");
}

// 5. ПРОГРАММА
int main(int argc, char *argv[]) {
    float eps1 = 1e-5f;
    float eps2 = 1e-4f;
    int show_roots = 0, show_iterations = 0, run_test = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-help") == 0) { print_help(); return 0; } 
        else if (strcmp(argv[i], "-roots") == 0) show_roots = 1;
        else if (strcmp(argv[i], "-iterations") == 0) show_iterations = 1;
        else if (strcmp(argv[i], "-test") == 0) run_test = 1;
        else { printf("Неизвестный ключ: %s\n", argv[i]); print_help(); return 1; }
    }

    if (run_test) {
        printf("--- Режим тестирования ---\n");
        float r_t = root(f_test_line, f_test_zero, -1.0f, 1.0f, 1e-5f, NULL);
        printf("Тест root (ожидается ~0.0): %f\n", r_t);
        float i_t = integral(f_test_quad, 0.0f, 3.0f, 1e-4f);
        printf("Тест integral x^2 на (ожидается ~9.0): %f\n", i_t);
        return 0;
    }

    float x13 = root(f1, f3, 0.5f, 1.5f, eps1, &iterations_f13);
    float x23 = root(f2, f3, 2.0f, 4.0f, eps1, &iterations_f23);
    float x12 = root(f1, f2, 3.0f, 4.5f, eps1, &iterations_f12);

    if (show_roots) {
        printf("Абсциссы точек пересечения кривых:\n");
        printf("  x (f1 = f3): %f\n", x13);
        printf("  x (f2 = f3): %f\n", x23);
        printf("  x (f1 = f2): %f\n", x12);
    }

    if (show_iterations) {
        printf("Число итераций при поиске корней:\n");
        printf("  Для f1 = f3: %d\n", iterations_f13);
        printf("  Для f2 = f3: %d\n", iterations_f23);
        printf("  Для f1 = f2: %d\n", iterations_f12);
    }

    float area1 = integral(f1, x13, x23, eps2) - integral(f3, x13, x23, eps2);
    float area2 = integral(f1, x23, x12, eps2) - integral(f2, x23, x12, eps2);
    float total_area = area1 + area2;

    printf("\nПлощадь фигуры, образуемая данными уравнениями: %f\n", total_area);

    plot_gnuplot(x13, x23, x12);

    return 0;
}
