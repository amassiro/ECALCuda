Instructions
----


Where:

    /home/amassiro/Cern/Code/ECAL/Cuda/ECALCuda
    
Instructions:

    ssh amassiro@vinavx2.cern.ch

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/Cuda/Standalone
 
    cd /afs/cern.ch/user/a/amassiro/work/ECAL/Cuda/Standalone/code/
 
    git clone git@github.com:vkhristenko/test-regression.git
    
    cd test-regression
    
    mkdir build
    cd build

    source /data/user/vkhriste/setup.sh

    cmake ../ -DEIGEN_HOME=/data/user/vkhriste/eigen/eigen -DOpenCL_INCLUDE_DIR=/usr/local/cuda-9.2/include
    
    make
    
    
    
Generate events:

    ./gen/gen_data -13

                 temporal_shift      number_of_events       NSAMPLES       NFREQ     nPU    signalAmplitude    sigmaNoise     puFactor  wf_name_string    pu_shift     noise-correlation    pedestal  distortion_sample_4
    ./gen/gen_data -13                  100                  10               25       0         10                 1             0         CRRC43            0               0.5               0.0         1.0
    ./gen/gen_data -13                  100                  10               25      10         10                 1            10         CRRC43            0               0.5               0.0         1.0
    ./gen/gen_data -13                  100                  10               25      10         10                 1           100         CRRC43            0               0.5               0.0         1.0
    ./gen/gen_data -13                  100                  10               25      10         10                 1          1000         CRRC43            0               0.5               0.0         1.0
    

    ./gen/gen_data -13                  10000                10               25      10         10                 1            10         CRRC43            0               0.5               0.0         1.0
    
    
    
    
    
Plot:

    r99t  plot/plotPulseInput.cxx\(\"data/mysample_1000_-13.000_0.000_10_25.00_10.00_0.00_1.000_1.00_0.00_slew_1.00.root\"\)
    r99t  plot/plotPulseInput.cxx\(\"data/mysample_1000_-13.000_0.000_10_25.00_10.00_0.00_1.000_1.00_0.00_slew_1.00.root\",2\)

    r99t  plot/plotPulseInput.cxx\(\"data/mysample_100_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root\",2\)

    r99t  plot/plotPulseInput.cxx\(\"data/mysample_100_-13.000_0.000_10_25.00_10.00_10.00_1.000_100.00_0.00_slew_1.00.root\",2\)
    
    r99t  plot/plotPulseInput.cxx\(\"data/mysample_100_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root\",2\)

    
    
    r99t  plot/plotPulseOutput.cxx\(\"build/output_cpu.root\",2\)

    
    
    
    
        
Run fit:



    ./multifit_cpu/multifit_cpu ../data/mysample_1000_-13.000_0.000_10_25.00_10.00_0.00_1.000_1.00_0.00_slew_1.00.root 
    ./multifit_cpu/multifit_cpu ../data/mysample_100_-13.000_0.000_10_25.00_10.00_10.00_1.000_1000.00_0.00_slew_1.00.root
    
    ./legacy_multifit_cpu/legacy_multifit_cpu ../data/mysample_100_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root
    ./legacy_multifit_cpu/legacy_multifit_cpu ../data/mysample_100_-13.000_0.000_10_25.00_10.00_0.00_1.000_0.00_0.00_slew_1.00.root
    
    
    ./legacy_multifit_cpu/legacy_multifit_cpu     ../data/mysample_100_-13.000_0.000_10_25.00_10.00_0.00_1.000_0.00_0.00_slew_1.00.root
    ./legacy_multifit_gpu/legacy_multifit_gpu     ../data/mysample_100_-13.000_0.000_10_25.00_10.00_0.00_1.000_0.00_0.00_slew_1.00.root
    ./multifit_cpu/multifit_cpu                   ../data/mysample_100_-13.000_0.000_10_25.00_10.00_0.00_1.000_0.00_0.00_slew_1.00.root
    ./multifit_gpu/multifit_gpu                   ../data/mysample_100_-13.000_0.000_10_25.00_10.00_0.00_1.000_0.00_0.00_slew_1.00.root
                                                 
    
    ./multifit_gpu/multifit_gpu ../data/mysample_1000_-13.000_0.000_10_25.00_10.00_0.00_1.000_1.00_0.00_slew_1.00.root 
    
    
    ./multifit_cpu/multifit_cpu ../data/mysample_100_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root
    ./multifit_gpu/multifit_gpu ../data/mysample_100_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root
    
    
    ./legacy_multifit_cpu/legacy_multifit_cpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root
    ./legacy_multifit_gpu/legacy_multifit_gpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root
                          
    ./legacy_multifit_cpu/legacy_multifit_cpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    10000
    ./legacy_multifit_gpu/legacy_multifit_gpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    10000
                          
    ./legacy_multifit_cpu/legacy_multifit_cpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    5000
    ./legacy_multifit_gpu/legacy_multifit_gpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    5000
                          
    ./legacy_multifit_cpu/legacy_multifit_cpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    1000
    ./legacy_multifit_gpu/legacy_multifit_gpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    1000
                          
    ./legacy_multifit_cpu/legacy_multifit_cpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    500
    ./legacy_multifit_gpu/legacy_multifit_gpu ../data/mysample_10000_-13.000_0.000_10_25.00_10.00_10.00_1.000_10.00_0.00_slew_1.00.root    10    500

Plot:

    r99t draw_time.cxx
    

Source:

    source /data/user/vkhriste/setup.sh

    backup
    /eos/user/a/amassiro/GPU/setup.sh
    
    
