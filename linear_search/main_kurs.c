#include <stdio.h>
#include <math.h>

typedef float(*function)(float);

// float rootFindLineSearch(float xl, float xr, float eps, function f)
// {
// 	float minx = xl, nextstep;
// 	nextstep = fabs(xr - xl)/(1/eps);
// 	int stepcount = 0;
// 	for(float x=xl; x<xr; x += nextstep, stepcount++)
// 	{
// 		if(fabs(f(x)) < fabs(f(minx)))
// 			minx = x;
// 	}
// 	printf("Find Line root for %d steps\n", stepcount);
// 	return minx;

// }

// float f(float x)
// {
// 	return 8*x*x*x*x + 32*x*x*x + 40*x*x + 16*x + 1;
// }

int main() {
    // Открываем gnuplot
    FILE *gp = popen("gnuplot -persistent", "w");
    
    if (gp == NULL) {
        printf("Ошибка запуска gnuplot.\n");
        return 1;
    }

    // Настройка сетки и диапазонов отображения
    fprintf(gp, "set grid\n");
    fprintf(gp, "set xrange [-7:6]\n");
    fprintf(gp, "set yrange [-17:7]\n"); // Ограничиваем Y, чтобы гипербола не ломала масштаб

    // Объявляем три графика
    fprintf(gp, "plot '-' with lines lw 2 title '(x-2)^3 - 1', "
                 "'-' with lines lw 2 title '0.6*x + 3', "
                 "'-' with lines lw 2 title '3/x'\n");
    
    // 1. График: (x-2)^3 - 1
    for (double x = -7.0; x <= 6.0; x += 0.05) {
        double y = (x - 2) * (x - 2) * (x - 2) - 1;
        fprintf(gp, "%f %f\n", x, y);
    }
    fprintf(gp, "e\n");

    // 2. График: 0.6*x + 3
    for (double x = -7.0; x <= 6.0; x += 0.05) {
        double y = 0.6 * x + 3;
        fprintf(gp, "%f %f\n", x, y);
    }
    fprintf(gp, "e\n");

    // 3. График: 3/x (с обходом нуля)
    for (double x = -7.0; x <= 6.0; x += 0.05) {
        // Если x близок к нулю, делаем разрыв линии, отправляя пустую строку
        if (fabs(x) < 0.03) {
            fprintf(gp, "\n"); 
            continue;
        }
        double y = 3.0 / x;
        fprintf(gp, "%f %f\n", x, y);
    }
    fprintf(gp, "e\n");

    // Закрываем пайп
    pclose(gp);
    return 0;
}
