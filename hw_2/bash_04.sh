#!/bin/zsh

DIR_NAME="Linux"

if [ -d $DIR_NAME ];

then
    echo "course"
else
    echo "very easy"
    mkdir $DIR_NAME
fi