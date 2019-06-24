Test standalone
====

Working on:

    cmg-gpu1080

Clone:

    git clone git@github.com:vkhristenko/test-cuda.git
    
Setup correct gcc

    source /data/patatrack/vkhriste/standalone_env.sh

Compile: 

    cd fnnls
    
    sh build.sh
    
Run:

    ./main <number of channels> <nthreads per block>
    
    ./main   1000 10
    
    
    
    
    
