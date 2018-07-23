Cuda for ECAL
====

    git clone git@github.com:amassiro/ECALCuda.git
    
    
Install for Hackaton:

    cmsrel CMSSW_10_2_0_pre3
    cd CMSSW_10_2_0_pre3/src
    cmsenv
    
    git cms-init
    
    git-cms-addpkg  DataFormats/DetId
    git-cms-addpkg  DataFormats/HcalDetId
    git-cms-addpkg  DataFormats/HcalDigi
    git-cms-addpkg  FWCore/Common
    git-cms-addpkg  DataFormats/EcalDetId
    

    git checkout -b hcal_digi4cuda_10_2_0_pre3
    
    
    git checkout hcal_digi4cuda_10_2_0_pre3
    git checkout -b vkhristenko:hcal_digi4cuda_10_2_0_pre3
    git checkout -b hcal_digi4cuda_10_2_0_pre3 vkhristenko-cmssw/hcal_digi4cuda_10_2_0_pre3
    git checkout vkhristenko-cmssw/hcal_digi4cuda_10_2_0_pre3
    
    


Changes for HCAL:

    hcal det id header file: https://github.com/cms-sw/cmssw/blob/master/DataFormats/HcalDetId/interface/HcalDetId.h 
    hcal det id tests: https://github.com/cms-sw/cmssw/blob/master/DataFormats/HcalDetId/test/test_hcal_detid.cu
    hcal qie11 data frame header file: https://github.com/cms-sw/cmssw/blob/master/DataFormats/HcalDigi/interface/QIE11DataFrame.h
    hcal qie11 data frame tests : https://github.com/cms-sw/cmssw/blob/master/DataFormats/HcalDigi/test/test_hcal_digi.cu
    

