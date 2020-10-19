#!/bin/bash

NAME="$1"

cat > in.txt

if [[ $NAME == *.c ]]; then cp templates/temp.c src/$NAME; \
elif [[ $NAME == *.cpp ]]; then cp templates/temp.cpp src/$NAME; \
elif [[ $NAME == *.py ]]; then cp templates/temp.py src/$NAME; \
elif [[ $NAME == *.java ]]; then cp templates/temp.java src/$NAME; \
else touch src/$NAME; \
fi

vim src/$NAME
