PRs in CMSSW Nov 2020
====

    https://github.com/cms-sw/cmssw/pull/31719
    
    
on lxplus

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/PR/

     
    cmsrel CMSSW_11_2_X_2020-11-09-1100
    cd CMSSW_11_2_X_2020-11-09-1100/src
    cmsenv
    
    git cms-init
    git branch CMSSW_11_2_X --track cms-sw/CMSSW_11_2_X
    
    git cms-merge-topic cms-patatrack:patatrack_integration_7_N_ecal_local_reco

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

    
    
    
    
    
    

