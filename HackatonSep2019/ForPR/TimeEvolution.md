

30 Apr
===

    cudaErrorInvalidDeviceFunction: invalid device function

For some reason this is the problem:

    process.load("RecoLocalCalo.EcalRecProducers.ecalChannelStatusGPUESProducer_cfi")

From

    https://docs.nvidia.com/cuda/cuda-runtime-api/group__CUDART__TYPES.html
    
    cudaErrorInvalidDeviceFunction = 98
    The requested device function does not exist or is not compiled for the proper device architecture.
    
Try to recompile everything.

    No, still not working
    


4 May
===

with this commented 

    #process.load("RecoLocalCalo.EcalRecProducers.ecalChannelStatusGPUESProducer_cfi")

and run 

    cmsRun ecalRawDecodingAndMultifit.py

it works.

The added part is namely:

    
    process.ecalChannelStatusGPUESProducer = cms.ESProducer("EcalChannelStatusGPUESProducer",
        ComponentName = cms.string(''),
        appendToDataLabel = cms.string(''),
        label = cms.string('') 
    )


6 May
===

Commented out all:

     cudaGetLastError

    ./EventFilter/EcalRawToDigi/src/UnpackGPU.cu://       cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/AmplitudeComputationKernels.cu://         cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://       cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://       cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://         cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://         cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://         cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://         cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://         cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecAlgos/src/EcalUncalibRecHitMultiFitAlgo_gpu_new.cu://         cudaCheck(cudaGetLastError());
    ./RecoLocalCalo/EcalRecProducers/plugins/EcalRecHitProducerGPU.cc://   cudaCheck(cudaGetLastError());
    
And "uncalibrechit" works.
And "rechit" works.

BUT

    0 channels??
    
    but without the problematic include, it works the uncalibrechit part (also the scatter plot)
    

Make plot of modules, by A. Bocci

    process.DependencyGraph = cms.Service("DependencyGraph")

    dot dependency.gv -Tpng -o dependency.png


NB:

    process.load("RecoLocalCalo.EcalRecProducers.ecalADCToGeVConstantGPUESProducer_cfi")

this is the other one failing.


Run validation:

    makeEcalMultifitResultsGpuValidationPlots   test.root   plotValidation_uncalibrechit.root
    makeEcalRechitValidationPlots               test.root   plotValidation_calibrechit.root





7 May
===

Failing:

    process.load("RecoLocalCalo.EcalRecProducers.ecalADCToGeVConstantGPUESProducer_cfi")
    process.load("RecoLocalCalo.EcalRecProducers.ecalChannelStatusGPUESProducer_cfi")

    
The code source:

    EcalGainRatiosGPU --> EcalChannelStatusGPU

No fix ...



8 May
===

Test with only 1 ESproducer for GPU

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/TestESproducer/CMSSW_11_1_0_pre5_Patatrack/src
    
    cmsrel CMSSW_11_1_0_pre5_Patatrack
    cd CMSSW_11_1_0_pre5_Patatrack/src
    cmsenv
    
    git cms-init -x cms-patatrack
    git branch CMSSW_11_1_X_Patatrack --track cms-patatrack/CMSSW_11_1_X_Patatrack
    
    git cms-merge-topic vkhristenko:ecal_unpacker_patatrack_110x

    
Then add

    EcalChannelStatusGPU

Problem reproduced with minimal change:

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/TestESproducer/CMSSW_11_1_0_pre5_Patatrack/src/RecoLocalCalo/EcalRecProducers/test

    
    
 
 
 