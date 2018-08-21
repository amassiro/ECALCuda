Instructions
----


Where:

    /home/amassiro/Cern/Code/ECAL/Cuda/ECALCuda
    
Instructions:

    ssh amassiro@vinavx2.cern.ch

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/Cuda/Standalone
    
    git clone git@github.com:vkhristenko/test-regression.git
    
    cd test-regression
    
    
    <repo> and cd <repo>
mkdir build and cd build
cmake ../ -DEIGEN_HOME=<path to eigen root dir>
cmake ../ -DDOpenCL_INCLUDE_DIR=<path to opencl root dir>
cmake ../ -DDEBUG=ON to compile in debug mode>
cmake ../ -DTURNOFF_CUDA=ON to disable cuda>
cmake ../ -DTURNOFF_OPENCL=ON to disable opencl>
if u r @vinavx2 use: cmake ../ -DEIGEN_HOME=/data/user/vkhriste/eigen/eigen -DOpenCL_INCLUDE_DIR=/usr/local/cuda-9.2/include