set -o history -o histexpand


fullPath=$(realpath $0)
curDir=$(dirname $fullPath)
baseDir=$(dirname $curDir)
echo -e "basedir: $baseDir"
g++ ${curDir}/argumenets-to-main.cpp -o ${baseDir}/build/say
echo !!
