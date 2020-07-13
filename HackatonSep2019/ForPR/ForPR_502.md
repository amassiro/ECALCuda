For PR 502

    https://github.com/cms-patatrack/cmssw/pull/502
    
on cmggpu-1080

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/10Jul2020

    cmsrel CMSSW_11_1_0_pre8_Patatrack
    cd CMSSW_11_1_0_pre8_Patatrack/src
    cmsenv
    
    git cms-init -x cms-patatrack
    git branch CMSSW_11_1_X_Patatrack --track cms-patatrack/CMSSW_11_1_X_Patatrack
    
    git cms-merge-topic vkhristenko:multigpu_hcal_ecal

    scramv1 b -j 20
    
    

    
Add

    process.load("RecoLocalCalo.EcalRecProducers.ecalMultifitParametersGPUESProducer_cfi")
    process.load("RecoLocalCalo.EcalRecProducers.ecalRecHitParametersGPUESProducer_cfi")

    
-> MissingParameter: ParameterSet 'flagsMapDBReco' not found.



        modified:   ../plugins/EcalRecHitParametersGPUESProducer.cc
        modified:   ../plugins/EcalRecHitProducerGPU.cc
        modified:   testEcalRechitProducer_cfg.py
        modified:   testEcalUncalibRechitProducer_cfg.py

        
 
    git checkout -b amassiro-ecal-rechit-gpu-fixpr-502
    
    git commit ......
    
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b amassiro-ecal-rechit-gpu-fixpr-502

    git push -u origin amassiro-ecal-rechit-gpu-fixpr-502

    
    
    
    
    
    