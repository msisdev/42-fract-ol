#!/bin/bash

BIN_DIR="./bin"
          
# For each executable file in the folder
find "$BIN_DIR" -type f -name '*_test' -print0 | while IFS= read -r -d $'\0' bin_path; do
	# Skip non-executable file
	[ -x "$bin_path" ] || continue

	# Execute the binary
	echo "Running: $bin_path"
	"$bin_path"

	# Check result
	if [ $? -ne 0 ]; then
		echo "Error running $bin_path"
		exit 1
	fi
done
