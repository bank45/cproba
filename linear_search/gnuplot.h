#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



/**
 * Функция генерации данных и вызова Gnuplot для визуализации
 */
void plot_gnuplot(float x13, float x23, float x12) {
    // 1. Создаем файл данных для графиков функций
    FILE *f_data = fopen("funcs.dat", "w");
    if (!f_data) return;
    
    // Записываем координаты точек для построения графиков от 0.2 до 5.0
    for (float x = 0.2f; x <= 5.0f; x += 0.01f) {
        fprintf(f_data, "%f %f %f %f\n", x, f1(x), f2(x), f3(x));
    }
    fclose(f_data);

    // 2. Создаем файл точек пересечения
    FILE *f_pts = fopen("points.dat", "w");
    if (!f_pts) return;
    fprintf(f_pts, "%f %f \"A\"\n", x13, f1(x13));
    fprintf(f_pts, "%f %f \"B\"\n", x23, f3(x23));
    fprintf(f_pts, "%f %f \"C\"\n", x12, f1(x12));
    fclose(f_pts);

    // 3. Создаем файл инструкций (скрипт) для Gnuplot
    FILE *f_script = fopen("plot.gnu", "w");
    if (!f_script) return;

    fprintf(f_script, "set title 'Визуализация площади фигуры'\n");
    fprintf(f_script, "set grid\n");
    fprintf(f_script, "set xrange [0.2:5.0]\n");
    fprintf(f_script, "set yrange [-2.0:7.0]\n");
    fprintf(f_script, "set key top left\n");
    
    // Задаем закраску областей (интегралов) между кривыми
    fprintf(f_script, "set style fill transparent solid 0.4 noborder\n");
    
    // Команда рисования: графики функций, закраска и подписи точек
    fprintf(f_script, "plot 'funcs.dat' using 1:(($1>=%f && $1<=%f) ? $4 : $2):2 with filledcurves title 'Area 1 (f1-f3)' lc rgb 'orange', \\\n", x13, x23);
    fprintf(f_script, "     'funcs.dat' using 1:(($1>=%f && $1<=%f) ? $3 : $2):2 with filledcurves title 'Area 2 (f1-f2)' lc rgb 'coral', \\\n", x23, x12);
    fprintf(f_script, "     'funcs.dat' using 1:2 with lines title 'f1(x) = 0.6x + 3' lw 2 lc rgb 'blue', \\\n");
    fprintf(f_script, "     'funcs.dat' using 1:3 with lines title 'f2(x) = (x-2)^3 - 1' lw 2 lc rgb 'green', \\\n");
    fprintf(f_script, "     'funcs.dat' using 1:4 with lines title 'f3(x) = 3/x' lw 2 lc rgb 'red', \\\n");
    fprintf(f_script, "     'points.dat' using 1:2 with points pt 7 ps 1.5 lc rgb 'black' notitle, \\\n");
    fprintf(f_script, "     'points.dat' using 1:($2+0.3):3 with labels font 'Arial,10' notitle\n");
    
    // Оставляем окно открытым (актуально для Linux/WSL)
    fprintf(f_script, "pause -1 'Нажмите Enter для выхода...'\n");
    fclose(f_script);

    // 4. Вызываем gnuplot через командную строку системы
    printf("\nЗапуск Gnuplot для отображения графика...\n");
    int status = system("gnuplot plot.gnu");
    (void)status;
}
