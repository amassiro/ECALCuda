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
    
    
    
Do on top of: 

    https://github.com/cms-patatrack/cmssw/pull/443
    
    
Otherwise all "size" for uncalibrechit is lost.

    git push -u my-cmssw HEAD:amassiro-ecal-rechit-11_1_0


Where:

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/TEST/CMSSW_11_1_0_pre5_Patatrack/src/
    
Merge with Viktor:


    git cms-merge-topic vkhristenko:ecal_unpacker_patatrack_110x

    git cms-merge-topic amassiro:amassiro-ecal-rechit-11_1_0
    
  Some did not merge automatically. Fix locally then:

    git commit ...
    
And push:

    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b  amassiro-ecal-rechit-11_1_0-PR

    git push -u origin amassiro-ecal-rechit-11_1_0-PR

    amassiro-ecal-rechit-11_1_0-PR
    
    
        
    git push -u origin amassiro-ecal-rechit-11_1_0

    git push -u origin amassiro-ecal-rechit-11_1_0

    

And merge with Bocci's one too:

    git cms-merge-topic fwyzard:patatrack-ECAL_unpacker_cleanup

and push:

    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b  amassiro-ecal-rechit-11_1_0-PR-2

    git push -u origin amassiro-ecal-rechit-11_1_0-PR-2

    amassiro-ecal-rechit-11_1_0-PR-2
    
     

    
    
    
    
    
Use night build (not existing):
    
    cmsrel CMSSW_11_1_Patatrack_X_2020-04-04-2300
    cd CMSSW_11_1_Patatrack_X_2020-04-04-2300
    cmsenv
    cd src

