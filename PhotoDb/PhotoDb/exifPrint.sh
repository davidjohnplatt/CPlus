#!/bin/bash
#
#  script to create exifdata file for the targeted file
#
if [ $# -ne 1 ]
then
    echo "Usage: printExif.sh Month"
    exit 1
fi
exifprobe $1 -L > /tmp/out.txt
/home/david/cProg/PhotoDb/PhotoDb/PhotoDb
