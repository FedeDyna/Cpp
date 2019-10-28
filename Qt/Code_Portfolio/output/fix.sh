#!/bin/csh -f
#
foreach f ( 4pl_stableXY.eps )
  #echo Doing fixing of bounding box $f
  awk -f ./bbox_XY.awk < $f > $f.ps
  mv $f.ps $f
  set base=`basename $f .eps`
  #echo $base.png
  convert +antialias -quality 100 -density 800 -flatten $base.eps $base.png
end
