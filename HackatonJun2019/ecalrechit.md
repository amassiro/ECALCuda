ecalrechit
====

Porting of ecalrechit on gpu

Where:

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/3July2019/CMSSW_10_6_0_Patatrack/src
    
Install:

    source /data/patatrack/cmssw/cmsset_default.sh

    cmsrel CMSSW_10_6_0_Patatrack
    
    cmsenv
    
    git cms-init -x cms-patatrack
    
    git branch CMSSW_10_6_X_Patatrack --track cms-patatrack/CMSSW_10_6_X_Patatrack

    git checkout cms-patatrack/CMSSW_10_6_X_Patatrack -b my_development_branch

    # check out the modified packages and their dependencies
    git cms-addpkg $(git diff $CMSSW_VERSION --name-only | cut -d/ -f-2 | sort -u)
    git cms-checkdeps -a
    
    scramv1 b -j 10

    

    git cms-addpkg     CUDADataFormats/EcalRecHitSoA
    
    
    
My branch:

    from "cms-patatrack/CMSSW_10_6_X_Patatrack"

    git checkout cms-patatrack/CMSSW_10_6_X_Patatrack -b  amassiro_ECALrechit_on_GPU
    
    
    git remote add origin git@github.com:amassiro/cmssw
    
    git fetch origin
    
    git checkout -b    amassiro_patatrack_ECALrechit_on_GPU
    
    
    
    
    
    
    
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b    amassiro_patatrack_ECALrechit_on_GPU
    
    git commit -m  .........

    git push -u origin  amassiro_patatrack_ECALrechit_on_GPU

    
Notes:

    - in DeclsForKernels.h the core
    
    - if on device (GPU) you need ptr (pointers) to move around, and you need "size"
    - if on host, you can access the size using "size" from std::vector