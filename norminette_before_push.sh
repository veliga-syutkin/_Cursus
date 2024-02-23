#!/bin/bash
norm $(norminette | grep 'Error' | wc -l)

if (( $? == 0 )); then
	(make git_push)
else
	echo "Norminette failed, I presume you are plenty of MAJOR SKILL ISSUE."
	norminette
fi