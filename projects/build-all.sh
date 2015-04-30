#!/bin/sh

for project in `ls`
do
	if [ -d $project ]; then
		echo "Building example: ${example}"
		cd ${project} && make || echo "failed .."
		cd ..
	fi
done
