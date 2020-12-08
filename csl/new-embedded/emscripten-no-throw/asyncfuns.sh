#!/bin/bash

declare -a FUNS
declare -a JSFUNS
i=0
j=0

while IFS= read -r line; do
  #echo "$line"
  if [[ $line =~ ^([a-zA-Z_][a-zA-Z0-9_]*).*?\.cpp.*?$ ]] ;
  then
    FUNS[i]="\"${BASH_REMATCH[1]}\""
    i=$((i+1))
    #echo "$line"
  elif [[ $line =~ ^([a-zA-Z_][a-zA-Z0-9_]*).*?\.js.*?$ ]];
  then
    JSFUNS[j]="\"${BASH_REMATCH[1]}\""
    j=$((j+1))
  fi
done <<< "$(sort -u "$@")"

cfuns="-s 'ASYNCIFY_ONLY=["
delim=""
for item in "${FUNS[@]}"; do
  cfuns="$cfuns$delim$item"
  delim=","
done
cfuns+="]'"

jsimports="-s 'ASYNCIFY_IMPORTS=[\"web_async_read\", \"web_async_write\""
delim=""
for item in "${JSFUNS[@]}"; do
  jsimports="$jsimports$delim$item"
  delim=","
done
jsimports+="]'"

#echo "$cfuns"
#echo "$jsimports"