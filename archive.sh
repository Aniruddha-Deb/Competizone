size=`expr $# - 1`
target="old/$BASH_ARGV"
mkdir -p $target
i=1
while [ $i -le $size ]
do
	mv "src/${!i}" $target
	((i+=1))
done
