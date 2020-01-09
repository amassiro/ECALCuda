ecalrechit
====

Porting of ecalrechit on gpu

Where:

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/3July2019/CMSSW_10_6_0_Patatrack/src
    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/12Aug2019/CMSSW_10_6_0_Patatrack/src
    
    lxplus-ECAL-GPU
    
    
Install:

    source /data/patatrack/cmssw/cmsset_default.sh

    cmsrel CMSSW_10_6_0_Patatrack
    
    cd CMSSW_10_6_0_Patatrack/src 
    
    cmsenv
    
    git cms-init -x cms-patatrack
    
    git branch CMSSW_10_6_X_Patatrack --track cms-patatrack/CMSSW_10_6_X_Patatrack

    git checkout cms-patatrack/CMSSW_10_6_X_Patatrack -b my_development_branch

    # check out the modified packages and their dependencies
    git cms-addpkg $(git diff $CMSSW_VERSION --name-only | cut -d/ -f-2 | sort -u)
    git cms-checkdeps -a
    
    scramv1 b -j 10

    

    git cms-addpkg     CUDADataFormats/EcalRecHitSoA
    
    git cms-addpkg     CondFormats/DataRecord
    git cms-addpkg     CondFormats/EcalObjects
    git cms-addpkg     CalibCalorimetry/EcalLaserCorrection
    git cms-addpkg     DataFormats/EcalRecHit
    

    
My branch:

    from "cms-patatrack/CMSSW_10_6_X_Patatrack"

    git checkout cms-patatrack/CMSSW_10_6_X_Patatrack -b  amassiro_ECALrechit_on_GPU
    
    
    git remote add origin git@github.com:amassiro/cmssw
    
    git fetch origin
    
    git checkout -b    amassiro_patatrack_ECALrechit_on_GPU
    
    
    
    
    
    
    
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b    amassiro_patatrack_ECALrechit_on_GPU
    
    git commit -m  .........

    git push -u origin  amassiro_patatrack_ECALrechit_on_GPU


    
New version of unpacker:

    git cms-merge-topic vkhristenko:ecal_unpacker_patatrack

and then merge with mine:

    git cms-merge-topic amassiro:amassiro_patatrack_ECALrechit_on_GPU
    



Notes:

    - in DeclsForKernels.h the core
    
    - if on device (GPU) you need ptr (pointers) to move around, and you need "size"
    - if on host, you can access the size using "size" from std::vector
    
    
     From: https://github.com/cms-sw/cmssw/blob/master/RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitWorkerSimple.cc 
    
     - get ADCToGeVConstant     ---> done
     - get IC                   ---> done
     - get Laser Correction     ---> special treatment for HLT? ----> done in the standard way
                           https://github.com/cms-sw/cmssw/blob/5d27b6509171a20b6e6a4bbbaf29ca471d612913/CalibCalorimetry/EcalLaserCorrection/src/EcalLaserDbService.cc
            - apd/pn  -> done
            - linear corrections  -> done
            - alpha   -> done
            - apdpn ref   -> done
     - get the channel status   ---> done
    
     - correct from the "jitter" to "time" properly
    
     - what is "extra" ?  -> packed uint32_t for timeError, chi2, energyError
        See https://github.com/cms-sw/cmssw/blob/266e21cfc9eb409b093e4cf064f4c0a24c6ac293/DataFormats/EcalRecHit/interface/EcalRecHit.h#L226
        --> done

     - what is "flagBits" ? -> store rechit condition (see Flags enum) in a bit-wise way 
        See https://github.com/cms-sw/cmssw/blob/266e21cfc9eb409b093e4cf064f4c0a24c6ac293/DataFormats/EcalRecHit/interface/EcalRecHit.h#L223
        --> done
        
        
     -> add all the ES producers for GPU -> done
     
     
     
Run:

    nvidia-smi
    export CUDA_VISIBLE_DEVICES=0;

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/3July2019/CMSSW_10_6_0_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/12Aug2019/CMSSW_10_6_0_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    cmsRun testEcalRechitProducer_cfg.py
    
    edmConfigDump   testEcalRechitProducer_cfg.py > dump_testEcalRechitProducer_cfg.py

    
    // uncalibrechit version only
    cmsRun testEcalUncalibRechitProducer_cfg.py

    testEcalUncalibRechitProducer_cfg.py
    --> output "test.root"
    
    

Validation code for uncalibrechit:

    makeEcalMultifitResultsGpuValidationPlots   test.root   plotValidation_uncalibrechit.root
    
    -> ok, flags seems to match @uncalibrechit level, but NOT always
    

Validation code by Eissa:

    https://github.com/ealnasrallah/cmssw/tree/eissa_validation_3/RecoLocalCalo/EcalRecAlgos/bin

    EcalRecHit.h modified:
    
          
        uint32_t flagBits() const { return flagBits_; }
        
        uint32_t extra() const { return extra_; }
        

    cmsRun testEcalRechitProducer_cfg.py

    makeEcalRechitValidationPlots    test.root   plotValidation_calibrechit.root
        
    -> iLM is wrong
    -> the index was the issue, hashedId was to be used
    
    -> "extra" needed a lot of rewriting, since value encoded via different steps
    
    
    
    -> I can set the flags for gpu to any number --->         flagBits[ch] = 500;

    
    
uncalibrechit

    1) find where flags are set in cpu uncalibrechit
        -> DataFormats/EcalRecHit/interface/EcalUncalibratedRecHit.h
        -> DataFormats/EcalRecHit/src/EcalUncalibratedRecHit.cc
        -> RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo.cc
    2) try without timing in both cases and compare results (maybe timing is computed only for one of them)
        -> deactivated in both cases
    
    3) find the meaning of these flags @ uncaliberchit level

    
    
    
    
    
    