#!/bin/bash
norm=$(norminette | grep 'Error' | wc -l)

if [ $norm == 0 ]
then
	(make git_auto)
else
	echo "Norminette failed"
	norminette
fi