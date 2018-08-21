Instructions
----


Where:

    /home/amassiro/Cern/Code/ECAL/Cuda/ECALCuda
    
Instructions:

    ssh amassiro@vinavx2.cern.ch

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/Cuda/Standalone
    
    git clone git@github.com:vkhristenko/test-regression.git
    
    cd test-regression
    
    mkdir build
    cd build

    cmake ../ -DEIGEN_HOME=/data/user/vkhriste/eigen/eigen -DOpenCL_INCLUDE_DIR=/usr/local/cuda-9.2/include
    
    
    
    