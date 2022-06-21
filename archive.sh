mv src/*.cpp old
mv src/*.py old

mv old/[0-9]* old/codeforces/
mv old/[A-Z]* old/codechef/
mv old/abc* old/atcoder/
mv old/arc* old/atcoder/
mv old/cses* old/cses/

# codeforces sorting
for q in old/codeforces/*.cpp; do 
mkdir -p "${q%[A-Z]*}"; 
mv "$q" "${q%[A-Z]*}"; 
done
rm -r old/codeforces/*.cpp

# atcoder sorting
for q in old/atcoder/*.cpp; do
mkdir -p "${q%_*}";
mv "$q" "${q%_*}";
done
# risky; a *.cpp dir is make in the folder if no such file exists
rm -r old/atcoder/*.cpp

# CSES sorting
for q in old/cses/*.cpp; do
mkdir -p "${q%_*}";
mv $q "${q%_*}";
done;
rm -r old/cses/*.cpp
