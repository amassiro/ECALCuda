For PR 502

    https://github.com/cms-patatrack/cmssw/pull/502
    
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

changes 

    maxChannels  
->
    maxChannelsEE
    maxChannelsEB
    
    
Compile

    scramv1 b -j 20
    
    
PR:
 
    git checkout -b amassiro-ecal-maxchannels-ebee
    
    git commit ......
    
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b amassiro-ecal-maxchannels-ebee

    git push -u origin amassiro-ecal-maxchannels-ebee

    
    
    
    
    
    