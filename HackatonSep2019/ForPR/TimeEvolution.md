

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


