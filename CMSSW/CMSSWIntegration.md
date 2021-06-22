Tests after integration
====

    https://twiki.cern.ch/twiki/bin/viewauth/CMS/TriggerDevelopmentWithGPUs

Login:

    from lxplus
    
    ssh cmsusr.cern.ch -t ssh  gpu-c2a02-39-02.cms

I am here:

    [amassiro@fu-c2a02-39-02 ~]$ 

    patatrack02 Nvidia T4

Source:

    export VO_CMS_SW_DIR=/data/cmssw
    export SCRAM_ARCH=slc7_amd64_gcc900
    source $VO_CMS_SW_DIR/cmsset_default.sh

Install:

    cd /nfshome0/amassiro/TestGPU

Instructions by Bruno

    cmsrel CMSSW_11_3_0_pre5

    cd CMSSW_11_3_0_pre5/src/
    cmsenv
    
    git cms-merge-topic configuration_for_andrea_m

    scramv1 b -j 20


    branch: 




I managed to get the amplitude mismatch plots above using CMSSW_11_3_0_pre5, running on patatrack02 Nvidia T4.
Please use this branch (configuration_for_andrea_m), and run the following commands from within a clean CMSSW_11_3_0_pre5 release:

CUDA_VISIBLE_DEVICES=0 cmsRun RecoLocalCalo/EcalRecProducers/test/testEcalUncalibRechitProducer_cfg.py
DQMIO2histo.py -in defaultUncalibRecHitsDQM.root -o plots_amplitudes_RECALL.root
python RecoLocalCalo/EcalRecProducers/python/plotUncalib.py plots_amplitudes_RECALL.root RECALL

file RECALL_filt1.png



