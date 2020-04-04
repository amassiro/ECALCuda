For PR in CMSSW_11_1_X_patatrack
====

Where:

    cmgGpu
    
    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/
    
Install at the beginning:
    
    cmsrel CMSSW_11_1_0_pre5_Patatrack
    cd CMSSW_11_1_0_pre5_Patatrack/src
    cmsenv
    
    git cms-init -x cms-patatrack
    git branch CMSSW_11_1_X_Patatrack --track cms-patatrack/CMSSW_11_1_X_Patatrack
    
    git checkout cms-patatrack/CMSSW_11_1_X_Patatrack -b amassiro-ecal-rechit-11_1_0
    
    git diff $CMSSW_VERSION --name-only --no-renames | cut -d/ -f-2 | uniq | xargs -r git cms-addpkg
    git cms-checkdeps -a
    scram b -j
    
Get packages:
    
    git cms-addpkg     CUDADataFormats/EcalRecHitSoA
    git cms-addpkg     RecoLocalCalo/EcalRecAlgos
    git cms-addpkg     RecoLocalCalo/EcalRecProducers

    scramv1 b -j 20

    git cms-addpkg     CalibCalorimetry/EcalLaserCorrection
    git cms-addpkg     HeterogeneousCore/CUDACore
    
    
Write and add new modules:

    
    scramv1 b -j 20

Add: 

    scram b -j
    ...
    git add ...
    git commit
    git push -u my-cmssw HEAD:my_development_branch
    
    
Test

    nvidia-smi
    export CUDA_VISIBLE_DEVICES=0;

    cmsRun testEcalRechitProducer_cfg.py
    
    
    
    