Cuda for ECAL
====

    git clone git@github.com:amassiro/ECALCuda.git
    
    
Install:

    cmsrel CMSSW_10_2_0_pre3
    cd CMSSW_10_2_0_pre3/src
    cmsenv
    
    git-cms-addpkg  DataFormats/DetId
    git-cms-addpkg  DataFormats/HcalDetId
    git-cms-addpkg  DataFormats/HcalDigi
    git-cms-addpkg  FWCore/Common
    git-cms-addpkg  DataFormats/EcalDetId
    

    git checkout hcal_digi4cuda_10_2_0_pre3
    
    

    