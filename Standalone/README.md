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

    source /data/user/vkhriste/setup.sh

    cmake ../ -DEIGEN_HOME=/data/user/vkhriste/eigen/eigen -DOpenCL_INCLUDE_DIR=/usr/local/cuda-9.2/include
    
    make
    
    
    
Generate events:

    ./gen/gen_data -13
    
Run fit:

    ./multifit_cpu/multifit_cpu ../data/mysample_1000_-13.000_0.000_10_25.00_10.00_0.00_1.000_1.00_0.00_slew_1.00.root 
    
    ./multifit_gpu/multifit_gpu ../data/mysample_1000_-13.000_0.000_10_25.00_10.00_0.00_1.000_1.00_0.00_slew_1.00.root 
    
    
    