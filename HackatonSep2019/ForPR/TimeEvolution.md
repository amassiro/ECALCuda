

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

    
11 May
====

Create branch and email

    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin
    
    git checkout -b  amassiro-ecal-rechit-11_1_0-TestIssuePR

    git push -u origin amassiro-ecal-rechit-11_1_0-TestIssuePR


    
Test

    ecalEmpty.py   ----> it works
       with nothing!
    
    ecalEmpty.1.py   ----> it works
       add more loading
       and digi
       
    ecalEmpty.2.py   ----> it crashes
       adding unpackergpu
       
    ecalEmpty.3.py   ----> tests ongoing
       adding unpackergpu but leaving only the "cudaCheck", and remove the core of the code.
       Use the unpacker as a dummy module
       
       -> this is the one that is crashing: "kernel_unpack_test"
       
       

    
12 May
====

    ecalEmpty.3.py   ----> tests ongoing

    Exception Message:
    A std::exception was thrown.

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/TestESproducer/CMSSW_11_1_0_pre5_Patatrack/src/EventFilter/EcalRawToDigi/src/UnpackGPU.cu, line 487:
    cudaCheck(cudaGetLastError());
    cudaErrorInvalidDeviceFunction: invalid device function


    still ... cudaErrorInvalidDeviceFunction
    
    no combination without that error
    

13 May
====


    using EcalTestStatusGPUESProducer = EcalESProducerGPU<
        EcalTestStatusGPU,
        EcalGainRatios,
        EcalGainRatiosRcd
        >;
 
The previous one works

Now this:

    using EcalTestStatusGPUESProducer = EcalESProducerGPU<
        EcalTestStatusGPU,
        EcalChannelStatus,
        EcalChannelStatusRcd
        >;

and it works ... strange ...

Now they are identical ... but one does not compile!!!

Try scramv1 b distclean and recompile ...

Still crashing when using EcalChannelStatusGPUESProducer

    cudaCheck(cudaGetLastError());
    cudaErrorInvalidDeviceFunction: invalid device function

Workaround:

    ecalRechitChannelStatusGPU

name changed and it works. Follow this procedure from now on.

        
Now back to 

    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/TEST/CMSSW_11_1_0_pre5_Patatrack/src/

to finally fix it.


Now this:

    process.load("RecoLocalCalo.EcalRecProducers.ecalADCToGeVConstantGPUESProducer_cfi")

yet the same error:

    cudaCheck(cudaGetLastError());
    cudaErrorInvalidDeviceFunction: invalid device function

-> changing the name and ... it works




Run reconstruction:

    cmsRun ecalRawDecodingAndMultifit.py
    cmsRun testEcalRechitProducer_cfg.py


Run validation:

    makeEcalMultifitResultsGpuValidationPlots   test.root         plotValidation_uncalibrechit.root
    makeEcalRechitValidationPlots               testRechit.root   plotValidation_calibrechit.root

Nice.

git commit and push now

    git push -u origin amassiro-ecal-rechit-11_1_0-PR-2







       
       
    
    
    
    



 
 
 