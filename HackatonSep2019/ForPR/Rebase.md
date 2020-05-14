https://cms-sw.github.io/tutorial-resolve-conflicts.html









Switched to a new branch 'amassiro-ecal-rechit-11_1_0-PR-3'
Created branch amassiro-ecal-rechit-11_1_0-PR-3 to follow amassiro-ecal-rechit-11_1_0-PR-3 from repository amassiro
First, rewinding head to replay your work on top of it...
Applying: raw to digi is adapted to 110x patatrack branch
Using index info to reconstruct a base tree...
M       EventFilter/EcalRawToDigi/BuildFile.xml
M       EventFilter/EcalRawToDigi/plugins/BuildFile.xml
.git/rebase-apply/patch:27: trailing whitespace.
// this is basically a view 
.git/rebase-apply/patch:128: trailing whitespace.
    std::vector<uint32_t, CUDAHostAllocator<uint32_t>> nchannels; 
.git/rebase-apply/patch:129: trailing whitespace.
    
.git/rebase-apply/patch:185: trailing whitespace.
        cudaCheck( cudaMalloc((void**)&data, 
.git/rebase-apply/patch:241: trailing whitespace.
          uint8_t const dccid, uint8_t const towerid, 
warning: squelched 60 whitespace errors
warning: 65 lines add whitespace errors.
Falling back to patching base and 3-way merge...
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/src/UnpackGPU.cu
Auto-merging EventFilter/EcalRawToDigi/src/UnpackGPU.cu
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/src/ElectronicsMappingGPU.cc
Auto-merging EventFilter/EcalRawToDigi/src/ElectronicsMappingGPU.cc
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/plugins/EcalRawToDigiGPU.cc
Auto-merging EventFilter/EcalRawToDigi/plugins/EcalRawToDigiGPU.cc
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/plugins/EcalRawESProducersGPUDefs.cc
Auto-merging EventFilter/EcalRawToDigi/plugins/EcalRawESProducersGPUDefs.cc
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/plugins/EcalRawESProducerGPU.h
Auto-merging EventFilter/EcalRawToDigi/plugins/EcalRawESProducerGPU.h
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/plugins/EcalCPUDigisProducer.cc
Auto-merging EventFilter/EcalRawToDigi/plugins/EcalCPUDigisProducer.cc
Auto-merging EventFilter/EcalRawToDigi/plugins/BuildFile.xml
CONFLICT (content): Merge conflict in EventFilter/EcalRawToDigi/plugins/BuildFile.xml
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/interface/UnpackGPU.h
Auto-merging EventFilter/EcalRawToDigi/interface/UnpackGPU.h
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/interface/ElectronicsMappingGPU.h
Auto-merging EventFilter/EcalRawToDigi/interface/ElectronicsMappingGPU.h
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/interface/ElectronicsIdGPU.h
Auto-merging EventFilter/EcalRawToDigi/interface/ElectronicsIdGPU.h
CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/interface/DeclsForKernels.h
Auto-merging EventFilter/EcalRawToDigi/interface/DeclsForKernels.h
Auto-merging EventFilter/EcalRawToDigi/BuildFile.xml
CONFLICT (content): Merge conflict in EventFilter/EcalRawToDigi/BuildFile.xml
CONFLICT (add/add): Merge conflict in CUDADataFormats/EcalDigi/interface/DigisCollection.h
Auto-merging CUDADataFormats/EcalDigi/interface/DigisCollection.h
CONFLICT (add/add): Merge conflict in CUDADataFormats/EcalDigi/BuildFile.xml
Auto-merging CUDADataFormats/EcalDigi/BuildFile.xml
error: Failed to merge in the changes.
Patch failed at 0001 raw to digi is adapted to 110x patatrack branch
hint: Use 'git am --show-current-patch' to see the failed patch
Resolve all conflicts manually, mark them as resolved with
"git add/rm <conflicted_files>", then run "git rebase --continue".
You can instead skip this commit: run "git rebase --skip".
To abort and get back to the state before "git rebase", run "git rebase --abort".





git add EventFilter/EcalRawToDigi/src/UnpackGPU.cu
git add EventFilter/EcalRawToDigi/src/ElectronicsMappingGPU.cc
git add EventFilter/EcalRawToDigi/plugins/EcalRawToDigiGPU.cc
git add EventFilter/EcalRawToDigi/plugins/EcalRawESProducersGPUDefs.cc
git add EventFilter/EcalRawToDigi/plugins/EcalRawESProducerGPU.h
git add EventFilter/EcalRawToDigi/plugins/EcalCPUDigisProducer.cc
git add EventFilter/EcalRawToDigi/plugins/BuildFile.xml
git add EventFilter/EcalRawToDigi/interface/UnpackGPU.h
git add EventFilter/EcalRawToDigi/interface/ElectronicsMappingGPU.h
git add EventFilter/EcalRawToDigi/interface/ElectronicsIdGPU.h
git add EventFilter/EcalRawToDigi/interface/DeclsForKernels.h
git add EventFilter/EcalRawToDigi/BuildFile.xml
git add CUDADataFormats/EcalDigi/interface/DigisCollection.h
git add CUDADataFormats/EcalDigi/BuildFile.xml


CONFLICT (add/add): Merge conflict in EventFilter/EcalRawToDigi/bin/makeEcalRaw2DigiGpuValidationPlots.cpp


CONFLICT (content): Merge conflict in CUDADataFormats/EcalRecHitSoA/src/classes_def.xml
CONFLICT (content): Merge conflict in CUDADataFormats/EcalRecHitSoA/interface/EcalUncalibratedRecHit_soa.h






git add  RecoLocalCalo/EcalRecAlgos/src/inplace_fnnls.h
git add  RecoLocalCalo/EcalRecAlgos/src/inplace_fnnls.cu
git add  RecoLocalCalo/EcalRecAlgos/src/TimeComputationKernels.h
git add  RecoLocalCalo/EcalRecAlgos/src/TimeComputationKernels.cu
git add  RecoLocalCalo/EcalRecAlgos/src/KernelHelpers.h
git add  RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu
git add  RecoLocalCalo/EcalRecAlgos/src/AmplitudeComputationKernels.h
git add  RecoLocalCalo/EcalRecAlgos/src/AmplitudeComputationKernels.cu
git add  RecoLocalCalo/EcalRecAlgos/src/AmplitudeComputationCommonKernels.h
git add  RecoLocalCalo/EcalRecAlgos/src/AmplitudeComputationCommonKernels.cu
git add  RecoLocalCalo/EcalRecAlgos/interface/EcalUncalibRecHitMultiFitAlgo_gpu_new.h


git rebase --continue




CONFLICT (content): Merge conflict in RecoLocalCalo/EcalRecProducers/plugins/EcalUncalibRecHitProducerGPU.cc
CONFLICT (content): Merge conflict in RecoLocalCalo/EcalRecProducers/plugins/EcalESProducerGPU.h
CONFLICT (add/add): Merge conflict in RecoLocalCalo/EcalRecProducers/plugins/EcalCPUUncalibRecHitProducer.cc
