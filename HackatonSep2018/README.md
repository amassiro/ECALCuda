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

    git-cms-addpkg  DataFormats/HcalDetId
    git-cms-addpkg  DataFormats/HcalDigi

    
    git-cms-addpkg  DataFormats/EcalRecHit
    
    
    git-cms-addpkg  RecoLocalCalo/EcalRecAlgos
    
    
    
    
Porting of new CPU implementation of NNLS:

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/CMSSW_10_3_0_pre2/src/RecoLocalCalo/EcalRecAlgos/src/PulseChiSqSNNLS.cc
    
from:

    https://github.com/vkhristenko/test-regression/blob/master/nnls/src/inplace_fnnls.cu

New CPU multifit:

    https://github.com/amassiro/cmssw/tree/amassiro-new-multifit-cpu

Test toolkit:

    https://github.com/amassiro/EcalLocalRecoToolKit
    
    
    