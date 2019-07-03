

Install

    source /data/patatrack/cmssw/cmsset_default.sh

    cmsrel CMSSW_10_6_0_pre2_Patatrack
    
    cmsrel CMSSW_10_6_0_Patatrack
    
    cmsenv
    
    git cms-init -x cms-patatrack
    
    
    git cms-merge-topic vkhristenko:ecal_patatrack_v2
    
    
    scramv1 b -j 10
    
    
Where:

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/24Jun2019/CMSSW_10_6_0_Patatrack/src/
    
    
Test:

    from: /data/patatrack/vkhriste/cmssw_configs
    
    
    cd /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/24Jun2019/CMSSW_10_6_0_Patatrack/src/ECALValidation/EcalLocalRecoToolKit/test/gpu
    ecalOnly.py 
    
    nvidia-smi
    export CUDA_VISIBLE_DEVICES=3;    cmsRun ecalOnly.py   
    
    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/24Jun2019/CMSSW_10_6_0_Patatrack/test/slc7_amd64_gcc700/validateGPU   test.root    mio.root    
    


    
Tasks:

    1) test on flatiron and scan  with head cmssw_10_6_patatrack

    2) filter raw data to have only ECAL feds. For pixels it gave a factor x4 in speed for I/O
    

Remember:

    streams ---> cmssw
    thread ----> operating system
    
    
    
    