Performance studies
====

    https://github.com/cms-patatrack/patatrack-scripts
    
    git clone git@github.com:cms-patatrack/patatrack-scripts.git
    
Twiki:

    https://twiki.cern.ch/twiki/bin/viewauth/CMS/TriggerDevelopmentWithGPUs

    
Connect:

    ssh cmsusr.cern.ch -t ssh gpu-c2d41-12-01.cms
    
Source:

    export VO_CMS_SW_DIR=/data/cmssw
    export SCRAM_ARCH=slc7_amd64_gcc820
    source $VO_CMS_SW_DIR/cmsset_default.sh

    
NVIDIA:

    nvidia-smi

Setup github

    ssh -f -N cmsusr.cms

Install

    cd /nfshome0/amassiro/TestGPU
    
    cmsrel CMSSW_11_1_0_pre8_Patatrack
    cd CMSSW_11_1_0_pre8_Patatrack/src
    cmsenv
 
    git cms-merge-topic amassiro:amassiro-ecal-rechit-11_1_0-PR-3

    scramv1 b -j 20
    
    
    git-cms-addpkg CUDADataFormats/EcalRecHitSoA
    git-cms-addpkg EventFilter/EcalRawToDigi
    git-cms-addpkg RecoLocalCalo/EcalRecAlgos
    git-cms-addpkg RecoLocalCalo/EcalRecProducers
 
    
    
Input files:

    sourceFromRawHLTmachine_cff.py
    
    copy one file to test
    
    
Run:

    nvidia-smi
    export CUDA_VISIBLE_DEVICES=0;

    cmsRun testEcalUncalibRechitProducer_cfg.py
    
    

