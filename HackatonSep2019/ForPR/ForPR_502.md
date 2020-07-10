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
    
    

    
    

