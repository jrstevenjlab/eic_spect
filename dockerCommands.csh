##################################
## open docker on host terminal ##
##################################
# docker run -it -p8888:8888 -p 6080:6080 -v /Users/jrsteven/eic:/home/eicuser/epw/share electronioncollider/epic-gui

##################
## update ejana ##
##################

cd /container/app/ejana/dev/src/
git fetch origin
#git pull
git checkout e08fa915
cd /container/app/ejana/dev/cmake-build-debug/
cmake -Wno-dev -DCMAKE_INSTALL_PREFIX=/container/app/ejana/dev/compiled /container/app/ejana/dev&& cmake --build . -- -j 1&& cmake --build . --target install

######################
## update eic-smear ##
######################
cd /container/app/eic-smear/src/master/
git fetch origin
git pull
cd /container/app/eic-smear/build/master/
cmake -Wno-dev -DCMAKE_INSTALL_PREFIX=/container/app/eic-smear/eic-smear-master/ /container/app/eic-smear/src/master&& cmake --build . -- -j 1&& cmake --build . --target install

