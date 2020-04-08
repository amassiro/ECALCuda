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
    
    
    
    
Use night build (not existing):
    
    cmsrel CMSSW_11_1_Patatrack_X_2020-04-04-2300
    cd CMSSW_11_1_Patatrack_X_2020-04-04-2300
    cmsenv
    cd src


Debug:

  BAD

    TimeReport   0.000019     0.000019     0.000019  TriggerResults
    TimeReport   0.000003     0.000003     0.000003  bunchSpacing
    TimeReport   0.000046     0.000046     0.000046  bunchSpacingProducer
    TimeReport   0.000023     0.000023     0.000023  digiPath
    TimeReport   0.000000     0.000000     0.000000  ecalCPUDigisProducer
    TimeReport   0.000000     0.000000     0.000000  ecalCPUUncalibRecHitProducer
    TimeReport   0.000376     0.000376     0.000376  ecalDetIdToBeRecovered
    TimeReport   0.047395     0.047395     0.047395  ecalDigis
    TimeReport   1.135577     1.135577     1.135577  ecalMultiFitUncalibRecHit
    TimeReport   0.016959     0.067837     0.016959  ecalRawToDigiGPU
    TimeReport   1.581286     1.581286     1.581286  ecalRecHit
    TimeReport   0.000000     0.000000     0.000000  ecalUncalibRecHitProducerGPU
    TimeReport   0.000010     0.000010     0.000010  finalize
    TimeReport   0.000000     0.000000     0.000000  out
    TimeReport   0.000011     0.000011     0.000011  recoPath
    TimeReport  per event     per exec    per visit  Name

  GOOD

    TimeReport ---------- Module Summary ---[Real sec]----
    TimeReport  per event     per exec    per visit  Name  
    TimeReport   0.000003     0.000003     0.000003  TriggerResults  
    TimeReport   0.000002     0.000002     0.000002  bunchSpacing  
    TimeReport   0.000013     0.000013     0.000013  bunchSpacingProducer
    TimeReport   0.000003     0.000003     0.000003  digiPath
    TimeReport   0.000617     0.000617     0.000617  ecalCPUDigisProducer
    TimeReport   0.000766     0.000766     0.000766  ecalCPUUncalibRecHitProducer
    TimeReport   0.000228     0.000228     0.000228  ecalDetIdToBeRecovered
    TimeReport   0.014173     0.014173     0.014173  ecalDigis
    TimeReport   0.263644     0.263644     0.263644  ecalMultiFitUncalibRecHit
    TimeReport   0.004154     0.004154     0.004154  ecalRawToDigiGPU
    TimeReport   0.372200     0.372200     0.372200  ecalRecHit
    TimeReport   0.004456     0.004456     0.004456  ecalUncalibRecHitProducerGPU
    TimeReport   0.000008     0.000008     0.000008  finalize
    TimeReport   0.113421     0.113421     0.113421  out
    TimeReport   0.000002     0.000002     0.000002  recoPath
    TimeReport  per event     per exec    per visit  Name
  