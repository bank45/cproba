set title 'Визуализация площади фигуры'
set grid
set xrange [0.2:5.0]
set yrange [-2.0:7.0]
set key top left
set style fill transparent solid 0.4 noborder
plot 'funcs.dat' using 1:(($1>=0.854103 && $1<=3.243928) ? $4 : $2):2 with filledcurves title 'Area 1 (f1-f3)' lc rgb 'orange', \
     'funcs.dat' using 1:(($1>=3.243928 && $1<=3.847760) ? $3 : $2):2 with filledcurves title 'Area 2 (f1-f2)' lc rgb 'coral', \
     'funcs.dat' using 1:2 with lines title 'f1(x) = 0.6x + 3' lw 2 lc rgb 'blue', \
     'funcs.dat' using 1:3 with lines title 'f2(x) = (x-2)^3 - 1' lw 2 lc rgb 'green', \
     'funcs.dat' using 1:4 with lines title 'f3(x) = 3/x' lw 2 lc rgb 'red', \
     'points.dat' using 1:2 with points pt 7 ps 1.5 lc rgb 'black' notitle, \
     'points.dat' using 1:($2+0.3):3 with labels font 'Arial,10' notitle
pause -1 'Нажмите Enter для выхода...'
