echo "Installation script V1 by arabi"
sleep 1
echo "Updating system"
sleep 1
sudo apt update -y
echo "Upgrading system"
sleep 1
sudo apt upgrade -y
sleep 1
echo "Installing dependencies"
sleep 1
sudo apt install build-essential git m4 scons zlib1g zlib1g-dev \
    libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev \
    python3-dev libboost-all-dev pkg-config

sudo apt install libpng-dev libpng++-dev libhdf5-dev
sudo apt install libhdf5-openmpi-hl-cpp-100 libhdf5-mpich-hl-cpp-100 libhdf5-hl-cpp-100
echo "Cloning GEM5 repo"
sleep 1
git clone https://gem5.googlesource.com/public/gem5
echo "Navigating to GEM5 folder"
sleep 1
echo "Building GEM5 for ARM with scons"
sleep 1
sh build.sh
