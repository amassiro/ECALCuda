On lxplus:

     lxplus

     /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/CMSSW_10_3_2/src

     /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/CMSSW_10_3_2/src

Machine:

    cmg-gpu1080.cern.ch
    ssh -X amassiro@cmg-gpu1080.cern.ch
     
First time:

    git cms-init

    git cms-merge-topic vkhristenko:hcal_cuda_1

    https://github.com/vkhristenko/cmssw/tree/hcal_cuda_1

    cd ../config/toolbox/slc6_amd64_gcc700/tools/selected/
    cd ../config/toolbox/slc7_amd64_gcc700/tools/selected/
    
    cp /data/patatrack/vkhriste/cmssw_releases/CMSSW_10_3_X_2018-12-13-2300/config/toolbox/slc7_amd64_gcc700/tools/selected/eigen.xml .
    
    scramv1 b -j 20
    
NB:

    you need to compile while being on the machine: 
    cmg-gpu1080.cern.ch
    
    
Test file:

    cp /data/patatrack/vkhriste/cmssw_configs/raw2digi_hcal_ecal.py .
    
    
    
Data files:

    2018 high PU  --> /data/patatrack/dalfonso/data/2018/Run2018E_HLTPhysics_325308/FB454F42-97B6-DC4B-88FF-0063C79B9F6C.root
    2018 normal PU  --> /data/patatrack/dalfonso/data/2018/Run2018B_HLTPhysics_319300/D6C0583D-5881-E811-9EB8-FA163EAFECF2.root
    
    
    