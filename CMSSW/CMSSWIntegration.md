Tests after integration
====

    https://twiki.cern.ch/twiki/bin/viewauth/CMS/TriggerDevelopmentWithGPUs

patatrack02
    
    from lxplus

    ssh patatrack02.cern.ch
    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/24Jun2021/
    
Login for p5 machines:

    from lxplus
    
    ssh cmsusr.cern.ch -t ssh  gpu-c2a02-39-02.cms

I am here:

    [amassiro@fu-c2a02-39-02 ~]$ 

    patatrack02 Nvidia T4

Source:

    export VO_CMS_SW_DIR=/data/cmssw
    export SCRAM_ARCH=slc7_amd64_gcc900
    source $VO_CMS_SW_DIR/cmsset_default.sh

NVIDIA:

    nvidia-smi

    export CUDA_VISIBLE_DEVICES=0;

    
Setup github

    ssh -f -N cmsusr.cms

Install:

    cd /nfshome0/amassiro/TestGPU

Instructions by Bruno:

    https://github.com/b-fontana/cmssw/tree/configuration_for_andrea_m
    
Install and compile:

    cmsrel CMSSW_11_3_0_pre5

    cd CMSSW_11_3_0_pre5/src/
    cmsenv
    
    git cms-merge-topic b-fontana:configuration_for_andrea_m

    scramv1 b -j 20

    
Input data:

    cp /gpu_data/store/data/Run2018D/EphemeralHLTPhysics/FED/v1/run323775/source_cff.py     RecoLocalCalo/EcalRecProducers/test/sourceFromRawCmggpu_cff.py
    
    
Run:

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/24Jun2021/CMSSW_11_3_0_pre5/src
    
    
    CUDA_VISIBLE_DEVICES=0 cmsRun RecoLocalCalo/EcalRecProducers/test/testEcalUncalibRechitProducer_cfg.py
    
    or (after the export)
    
    cmsRun RecoLocalCalo/EcalRecProducers/test/testEcalUncalibRechitProducer_cfg.py
    
    cmsRun RecoLocalCalo/EcalRecProducers/test/testEcalUncalibRechitProducer_cfg.py   outName=/tmp/TEST_
    
    
    (all production chain had to be set by hand)

Plot:

    DQMIO2histo.py -in defaultUncalibRecHitsDQM.root -o plots_amplitudes_RECALL.root
    python RecoLocalCalo/EcalRecProducers/python/plotUncalib.py plots_amplitudes_RECALL.root RECALL

    
    DQMIO2histo.py -in /tmp/TEST_UncalibRecHitsDQM.root -o plots_amplitudes_RECALL.root
    python RecoLocalCalo/EcalRecProducers/python/plotUncalib.py plots_amplitudes_RECALL.root RECALL

 
Copy results:

    kinit amassiro@CERN.CH
    
    cp plots_amplitudes_RECALL.root  
    
    
    
Debug:

    git-cms-addpkg RecoLocalCalo/EcalRecAlgos 
    git-cms-addpkg CondFormats/EcalObjects
    git-cms-addpkg DataFormats/EcalDigi
    git-cms-addpkg CUDADataFormats/EcalRecHitSoA    
    
    git-cms-addpkg DataFormats/CaloRecHit
    --> fnnls
    

    
    
Plot

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/24Jun2021/CMSSW_11_3_0_pre5/src/ECALValidation/EcalPulseDumper/test/
    cmsRun runDump.py  inputFiles=file:/tmp/TEST_UncalibRecHitsOut.root   outputFile=test.root   maxEvents=20
    cmsRun runDump.py  inputFiles=file:/tmp/TEST_UncalibRecHitsOut.root   outputFile=test.root
    cmsRun runDump.py  inputFiles=file:/tmp/TEST_UncalibRecHitsOut.root   outputFile=/tmp/amassiro/test.root

    cd /home/amassiro/Cern/Code/ECAL/Cuda/ECALCuda/CMSSW/
    
    r99t  plots_amplitudes_RECALL.root  plot.cc
      
      
      
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/24Jun2021/CMSSW_11_3_0_pre5/src/ECALValidation/EcalPulseDumper/test/test_numEvent20.root . 
    
    r99t test_numEvent20.root  plotPulses.cc
    r99t test.root  plotPulses.cc

    r99t TEST_UncalibRecHitsDQM.root  plot.cc
    
    
    
    r99t test.root  plotCompare.cc
    
    
    
    
    
Check timing

    process.ecalUncalibRecHitProducerGPU.shouldRunTimingComputation = cms.bool(True)
    process.ecalCPUUncalibRecHitProducer.containsTimingInformation = cms.bool(True)


    process.ecalMultiFitUncalibRecHit.algoPSet = cms.PSet( 
      timealgo = cms.string( "RatioMethod" ),   # ----> now timing active
    ...
      
    see https://github.com/cms-sw/cmssw/blob/master/RecoLocalCalo/EcalRecProducers/plugins/EcalUncalibRecHitWorkerMultiFit.cc


    
    
    
    
    ssh patatrack02.cern.ch
    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/24Jun2021/CMSSW_11_3_0_pre5/src
    cmsenv
    nvidia-smi 
    export CUDA_VISIBLE_DEVICES=0;
    cmsRun RecoLocalCalo/EcalRecProducers/test/testEcalUncalibRechitProducer_cfg.py   outName=/tmp/TEST_
        
    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/24Jun2021/CMSSW_11_3_0_pre5/src/ECALValidation/EcalPulseDumper/test/    
    cmsRun runDump.py  inputFiles=file:/tmp/TEST_UncalibRecHitsOut.root   outputFile=/tmp/amassiro/test.root
    
    cp /tmp/amassiro/test.root /eos/user/a/amassiro/ECAL/
    rm /eos/user/a/amassiro/ECAL/test.root 

    
    scp amassiro@lxplus.cern.ch:/eos/user/a/amassiro/ECAL/*.root .
    
    r99t test.root  plotCompareTime.cc

    r99t test.root  plotPulsesTime.cc
    
    
