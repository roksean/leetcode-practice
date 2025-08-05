#!/bin/bash

if [ $# -eq 0 ]; then 
    echo "Usage: $0 <filename>"
    exit 1
fi

file="$1"

if [ ! -f "$file" ]; then
    echo "Error: File $file does not exist"
    exit 2
fi

full_path="$(realpath "$file")"
problem_name="$(basename "$full_path" .cpp)"
difficulty="$(basename "$(dirname "$full_path")")"
category="$(basename "$(dirname "$(dirname "$full_path")")")"

today="$(date +"%Y-%m-%d")"

comment_text=$(sed -n '/\/\*/,/\*\//p' "$full_path")

if [ -z "$comment_text" ]; then
    echo "add the multiline comment at the end of the file"
    exit 3
fi

#get rid of /* and */ 
comment_text=$(echo "$comment_text" | sed '1d;$d')
#get rid of trailing and leading spaces
comment_text=$(echo "$comment_text" | sed 's/^[[:space:]]*//; s/[[:space:]]*$//')
#get rid of newline characters
comment_text=$(echo "$comment_text" | tr '\n' ' ')
#put it all in quotes
comment_text="\"$comment_text\""

csv_file="$(dirname "$(realpath "$0")")/leetcode_log.csv"

header="problem_name,problem_difficulty,problem_category,date,comments"

if [ ! -f "$csv_file" ] || [ "$(head -n 1 "$csv_file")" != "$header" ]; then
    echo "$header" > "$csv_file"
fi

if echo "$problem_name,$difficulty,$category,$today,$comment_text" >> "$csv_file"; then
    echo "Entry added to $csv_file"
else
    echo "Failed to add entry to $csv_file"
fi

