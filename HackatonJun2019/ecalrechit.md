ecalrechit
====

Porting of ecalrechit on gpu

Where:

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/3July2019/CMSSW_10_6_0_Patatrack/src
    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/12Aug2019/CMSSW_10_6_0_Patatrack/src
    
    lxplus-ECAL-GPU
    
    
Install:

    source /data/patatrack/cmssw/cmsset_default.sh

    cmsrel CMSSW_10_6_0_Patatrack
    
    cd CMSSW_10_6_0_Patatrack/src 
    
    cmsenv
    
    git cms-init -x cms-patatrack
    
    git branch CMSSW_10_6_X_Patatrack --track cms-patatrack/CMSSW_10_6_X_Patatrack

    git checkout cms-patatrack/CMSSW_10_6_X_Patatrack -b my_development_branch

    # check out the modified packages and their dependencies
    git cms-addpkg $(git diff $CMSSW_VERSION --name-only | cut -d/ -f-2 | sort -u)
    git cms-checkdeps -a
    
    scramv1 b -j 10

    

    git cms-addpkg     CUDADataFormats/EcalRecHitSoA
    
    git cms-addpkg     CondFormats/DataRecord
    git cms-addpkg     CondFormats/EcalObjects
    
    
    
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


    
New version of unpacker:

    git cms-merge-topic vkhristenko:ecal_unpacker_patatrack

and then merge with mine:

    git cms-merge-topic amassiro:amassiro_patatrack_ECALrechit_on_GPU
    



Notes:

    - in DeclsForKernels.h the core
    
    - if on device (GPU) you need ptr (pointers) to move around, and you need "size"
    - if on host, you can access the size using "size" from std::vector
    
    
     From: https://github.com/cms-sw/cmssw/blob/master/RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitWorkerSimple.cc 
    
     - get ADCToGeVConstant     ---> done
     - get IC                   ---> done
     - get Laser Correction
     - get the channel status
    
     - correct from the "jitter" to "time" properly
    
     - what is "extra" ?

     -> add all the ES producers for GPU
     
Run:

    nvidia-smi
    export CUDA_VISIBLE_DEVICES=0;

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/3July2019/CMSSW_10_6_0_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/12Aug2019/CMSSW_10_6_0_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    cmsRun testEcalRechitProducer_cfg.py
    
    edmConfigDump   testEcalRechitProducer_cfg.py > dump_testEcalRechitProducer_cfg.py

    
    
    
    