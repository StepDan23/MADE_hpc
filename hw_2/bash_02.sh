#!/bin/zsh

MY_ARRAY=(this is test text with "two word" .)
for i in `seq ${#MY_ARRAY[@]}`
do
	echo ${MY_ARRAY[i]}
done