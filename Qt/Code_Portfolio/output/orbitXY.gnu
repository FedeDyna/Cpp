#!/usr/local/bin/gnuplot -persist
set border 31 back linetype -1 linewidth 2.000


set term post color portrait enhanced "Helvetica" 20
set size square
set out "4pl_stableXY.eps"

#set grid
set xrange [-1.:1.]
set yrange [-1:1.]

LABEL = "Asteroid"
#set obj 2 rect at 0.6,0.0  size char strlen(LABEL)-0.6, char 1.2 
#set obj 2 fillstyle solid border -1 front
set label 2 at 0.75,-0.1 LABEL tc rgb "black" center front font "Helvetica,16"

LABEL = "Sun"
#set obj 2 rect at -0.5,0.0  size char strlen(LABEL)-0.6, char 1.2 
#set obj 2 fillstyle solid border -1 front
set label 3 at -0.2,0.0 LABEL tc rgb "black" center front font "Helvetica,16"

FILE_IN = 'Results_integration.txt'
 
# for the 4-planet
set xlabel "{/=20 x-coordinate}"
set ylabel "{/=20 y-coordinate}" offset 1,0

t0 = 0.0

plot FILE_IN u ($0<10000 ? $2:1/0):3 w p pt 7 ps 0.4 not,\
     FILE_IN u ($0== t0 ? $2:1/0):3 w p pt 7 ps 1.5 lc rgb 'black' not,\
     FILE_IN u ($0== t0 ? $2:1/0):3 w p pt 7 ps 1.2 lc rgb 'red' not,\
     'star.dat' w p pt 7 ps 2.5 lc rgb 'black' not,\
     'star.dat' w p pt 7 ps 2.0 lc rgb 'yellow' not 

system("csh fix.sh") 
system("gv 4pl_stableXY.eps")
