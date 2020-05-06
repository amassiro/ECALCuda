

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
