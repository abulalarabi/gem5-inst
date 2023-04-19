sudo apt install build-essential git m4 scons zlib1g zlib1g-dev \
    libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    python3-dev libboost-all-dev pkg-config

git clone https://gem5.googlesource.com/public/gem5
cd gem5
scons build/ARM/gem5.opt -j 4