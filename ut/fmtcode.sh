#! /bin/bash  
for f in $(find . -name '*.c' -or -name '*.cpp' -or -name '*.h' -type f)  
do  
     astyle --style=kr --indent=spaces=4 --indent-switches --suffix=none $f  
done  
# after formate the code,we need to rm '*.orig' files  
for f in $(find . -name '*.orig' -type f)  
do  
     rm $f  
done  
