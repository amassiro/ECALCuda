Purpose:

    - bring HCAL changes to ECAL
    - test in local
    - test in cmssw
    
GPU

    ssh amassiro@vinavx2.cern.ch
    ssh amassiro@cmg-gpu1080.cern.ch

    
Ideas
    
    - matrix should be fixed size -> templated   ---> it can take a lot to compile, but then much faster to run
    - pivoting
    - LHCb for 12x12 Cholevsky decomposition
    - 6x6 matrix already available
    - eigen for gpu
    
    - FPGA
    
    - kernel map assignment: different iterations per rechit
    

    cmg-gpu1080.cern.ch
    
    
    
PU:

    check standard and high pu differences
    

Measure time:

    https://github.com/cms-patatrack/patatrack-scripts/
    ./patatrack-scripts/benchmark dump.py
    ./patatrack-scripts/benchmark ECALValidation/EcalLocalRecoToolKit/test/dump.py 
    
    
    nvprof cmsRun dump.py
    nvprof cmsRun ECALValidation/EcalLocalRecoToolKit/test/dump.py
    
    git clone git@github.com:cms-patatrack/patatrack-scripts.git
    
    
    