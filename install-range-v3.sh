#!/bin/bash

# range-v3 relies on boost
sudo apt install libboost-dev

# download and install the range-v3 library
git clone https://github.com/ericniebler/range-v3
cd range-v3
mkdir build ;and cd build
cmake .. ;and make -j8
sudo make install
