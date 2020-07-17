For EE and EB max channels
    
    https://github.com/cms-patatrack/patatrack-website/blob/master/wiki/PatatrackDevelopment.md
    
on cmggpu-1080

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/10Jul2020

    cmsrel CMSSW_11_2_0_pre2_Patatrack
    cd CMSSW_11_2_0_pre2_Patatrack/src
    cmsenv

    git-cms-addpkg CUDADataFormats/EcalRecHitSoA
    git-cms-addpkg EventFilter/EcalRawToDigi
    git-cms-addpkg RecoLocalCalo/EcalRecAlgos
    git-cms-addpkg RecoLocalCalo/EcalRecProducers
    git-cms-addpkg CUDADataFormats/EcalDigi


---> 11_2 not yet ready for development
      
    
        
changes 

    maxChannels  
->
    maxChannelsEB
    maxChannelsEE
    
    
    
    maxNumberHits
-> 
    maxNumberHitsEB
    maxNumberHitsEE


    In CMSSW_11_1_0_pre8_Patatrack
    
    EventFilter/EcalRawToDigi/plugins/EcalRawToDigiGPU.cc
    RecoLocalCalo/EcalRecProducers/plugins/EcalUncalibRecHitProducerGPU.cc
    EventFilter/EcalRawToDigi/interface/DeclsForKernels.h
    
    
    
    
    
    
    In CMSSW_11_2_0_pre2_Patatrack
    
    EventFilter/EcalRawToDigi/plugins/DeclsForKernels.h 
    EventFilter/EcalRawToDigi/plugins/EcalRawToDigiGPU.cc
    RecoLocalCalo/EcalRecProducers/plugins/DeclsForKernels.h 
    RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitProducerGPU.cc 
    RecoLocalCalo/EcalRecProducers/plugins/EcalUncalibRecHitProducerGPU.cc 
    RecoLocalCalo/EcalRecProducers/python/ecalRecHitGPU_cfi.py
    
    
Compile

    scramv1 b -j 20
    
    
PR 11_2:
 
    git checkout -b amassiro-ecal-maxchannels-ebee
    
    git commit ......
    
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b amassiro-ecal-maxchannels-ebee

    git push -u origin amassiro-ecal-maxchannels-ebee

    
    

PR 11_1:
 
    cmsrel CMSSW_11_1_0_Patatrack
    cd CMSSW_11_1_0_Patatrack/src
    cmsenv
    git cms-init -x cms-patatrack
    git branch CMSSW_11_1_X_Patatrack --track cms-patatrack/CMSSW_11_1_X_Patatrack

 
    git checkout cms-patatrack/CMSSW_11_1_X_Patatrack -b amassiro-ecal-maxchannels-ebee-11-1-v2
    
    git diff $CMSSW_VERSION --name-only --no-renames | cut -d/ -f-2 | sort -u | xargs -r git cms-addpkg
    git cms-checkdeps -a
    scram b -j


    git-cms-addpkg CUDADataFormats/EcalRecHitSoA
    git-cms-addpkg EventFilter/EcalRawToDigi
    git-cms-addpkg RecoLocalCalo/EcalRecAlgos
    git-cms-addpkg RecoLocalCalo/EcalRecProducers
    git-cms-addpkg CUDADataFormats/EcalDigi

    scram b -j 20
    
chenage code ...

    git commit ......
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b amassiro-ecal-maxchannels-ebee-11-1-v2

    git push -u origin amassiro-ecal-maxchannels-ebee-11-1-v2

    
    
    
 
 
 
 
When running:

    /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/10Jul2020/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    
    cmsRun testEcalRechitProducer_cfg.py
    
    
    %MSG-i ThreadStreamSetup:  (NoModuleName) 17-Jul-2020 17:00:54 CEST pre-events
    setting # threads 4
    setting # streams 4
    %MSG
    %MSG-i CUDAService:  (NoModuleName) 17-Jul-2020 17:01:01 CEST pre-events
    CUDA runtime successfully initialised, found 1 compute devices.


When NOT running

    /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/10Jul2020/ToCommit/NOCHANGESNOTHIG/CMSSW_11_1_0_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    
    cmsRun testEcalRechitProducer_cfg.py
    
    
    %MSG-i ThreadStreamSetup:  (NoModuleName) 17-Jul-2020 17:03:45 CEST pre-events
    setting # threads 4
    setting # streams 4
    %MSG
    %MSG-w CUDAService:  (NoModuleName) 17-Jul-2020 17:03:48 CEST pre-events
    Failed to initialize the CUDA runtime.
    Disabling the CUDAService.
    %MSG

    
Diagnosis:

    - no GPU available -> but actually, nvidia-smi, there are
    - old CUDA (likely)
    
    
    
    