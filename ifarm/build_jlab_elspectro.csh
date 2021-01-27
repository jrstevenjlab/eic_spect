# Build of ROOT 6.22 with GCC 9.2.0 compatible with elspectro
source setup_root.csh

setenv BUILD_DIR /path/for/build/
cd $BUILD_DIR

git clone --recurse-submodules https://github.com/dglazier/elSpectro
cd elSpectro
setenv ELSPECTRO `pwd`
setenv PATH ${PATH}:${ELSPECTRO}/bin

mkdir build; cd build; /apps/cmake/bin/cmake ../ -DCMAKE_C_COMPILER=/apps/gcc/9.2.0/bin/gcc -DCMAKE_CXX_COMPILER=/apps/gcc/9.2.0/bin/g++

/apps/cmake/bin/cmake --build . --target install
