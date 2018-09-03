From HCAL:

    https://github.com/cms-sw/cmssw/pull/23332
    https://github.com/cms-sw/cmssw/pull/23386
    https://github.com/cms-sw/cmssw/pull/23495
    https://github.com/cms-sw/cmssw/pull/23579 
    
    https://github.com/vkhristenko/cmssw/tree/hcal_mahi_cuda
    
    https://github.com/cms-sw/cmssw/pulls?q=is%3Apr+author%3Avkhristenko+is%3Aclosed
    

Where:

    /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/CMSSW_10_3_0_pre2/src
    
    
Prepare:

    cmsenv
    
    git cms-init
    
    git-cms-addpkg  DataFormats/EcalDetId
    git-cms-addpkg  DataFormats/EcalDigi
    git-cms-addpkg  FWCore/Common
