PRs in CMSSW Nov 2020
====

    https://github.com/cms-sw/cmssw/pull/31719
    
    
on lxplus

    cd /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/PR/

     
    cmsrel CMSSW_11_2_X_2020-11-09-1100
    cd CMSSW_11_2_X_2020-11-09-1100/src
    cmsenv
    
    git cms-init
    git branch CMSSW_11_2_X --track cms-sw/CMSSW_11_2_X
    
    git cms-merge-topic cms-patatrack:patatrack_integration_7_N_ecal_local_reco

    scramv1 b -j 20
    
    
    
    
    
    
    
    cmsrel CMSSW_11_2_0_pre8
    cd CMSSW_11_2_0_pre8/src
    
    cmsenv
    
    git cms-rebase-topic cms-patatrack:HeterogeneousCore_JobConfigurationGPURecord
    git cms-rebase-topic cms-patatrack:patatrack_integration_7_N_ecal_local_reco


    

    
    
Needs this PR merged:

    https://github.com/cms-sw/cmssw/pull/32122
    
    

Fix 

    git-cms-addpkg HeterogeneousCore/CUDACore

    
    
    grep -r "JobConfigurationGPURecord" .
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalMultifitParametersGPUESProducer.cc:#include "HeterogeneousCore/CUDACore/interface/JobConfigurationGPURecord.h"
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalMultifitParametersGPUESProducer.cc:  std::unique_ptr<EcalMultifitParametersGPU> produce(JobConfigurationGPURecord const&);
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalMultifitParametersGPUESProducer.cc:  findingRecord<JobConfigurationGPURecord>();
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalMultifitParametersGPUESProducer.cc:    JobConfigurationGPURecord const&) {
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitParametersGPUESProducer.cc:#include "HeterogeneousCore/CUDACore/interface/JobConfigurationGPURecord.h"
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitParametersGPUESProducer.cc:  std::unique_ptr<EcalRecHitParametersGPU> produce(JobConfigurationGPURecord const&);
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitParametersGPUESProducer.cc:  findingRecord<JobConfigurationGPURecord>();
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitParametersGPUESProducer.cc:    JobConfigurationGPURecord const&) {
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitProducerGPU.cc:#include "HeterogeneousCore/CUDACore/interface/JobConfigurationGPURecord.h"
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitProducerGPU.cc:  setup.get<JobConfigurationGPURecord>().get(recHitParametersHandle_);
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalUncalibRecHitProducerGPU.cc:#include "HeterogeneousCore/CUDACore/interface/JobConfigurationGPURecord.h"
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalUncalibRecHitProducerGPU.cc:  const edm::ESGetToken<EcalMultifitParametersGPU, JobConfigurationGPURecord> multifitParametersToken_;
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalUncalibRecHitProducerGPU.cc:      multifitParametersToken_{esConsumes<EcalMultifitParametersGPU, JobConfigurationGPURecord>()} {
    ./RecoLocalCalo/EcalRecProducers/test/testEcalRechitProducer_cfg.py:#   No "JobConfigurationGPURecord" record found in the EventSetup.n



    
    
    
    
    
    
Again:

    cmsrel CMSSW_11_2_0_pre9
    cd CMSSW_11_2_0_pre9/src
    
    cmsenv
    
    git cms-rebase-topic cms-patatrack:HeterogeneousCore_JobConfigurationGPURecord
    git cms-rebase-topic cms-patatrack:patatrack_integration_7_N_ecal_local_reco
    git cms-rebase-topic fwyzard:HeterogeneousCore_ConvertingESProducerT
    git cms-rebase-topic mariadalfonso:from-CMSSW_11_2_0_pre9_fit


It works

    hbhe ??    
    

Bocci has rebaser on top of CMSSW_11_2_0_pre10



    cmsrel CMSSW_11_2_0_pre10
    cd CMSSW_11_2_0_pre10/src
    
    cmsenv
    
    git cms-rebase-topic cms-patatrack:HeterogeneousCore_JobConfigurationGPURecord
    git cms-rebase-topic cms-patatrack:patatrack_integration_7_N_ecal_local_reco
    
    
    
    
    
    
 
    git checkout -b amassiro-ecal-rechit-gpu-fixpr-502
    
    git commit ......
    
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b amassiro-ecal-rechit-gpu-fixpr-502

    git push -u origin amassiro-ecal-rechit-gpu-fixpr-502

    
    
    
    
    
    

