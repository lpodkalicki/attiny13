#!/bin/sh

for example in `ls`
do
	if [ -d $example ]; then
		echo "Building example: ${example}"
		cd ${example} && make || echo "failed .."
		cd ..
	fi
done
