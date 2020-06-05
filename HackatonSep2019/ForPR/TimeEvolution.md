

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

PR

    https://github.com/cms-patatrack/cmssw/pull/457

    

14 May
====


Rebase:
    
    cd /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/Rebase
    
    cmsrel CMSSW_11_1_Patatrack_X_2020-05-13-2300
    cd CMSSW_11_1_Patatrack_X_2020-05-13-2300/src
    cmsenv
    
    git cms-merge-topic CMSSW_11_1_Patatrack_X

    git cms-merge-topic amassiro:amassiro-ecal-rechit-11_1_0-PR-2

now fix conflicts.

    git add ....... <changed files>
    
    git commit
    
    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin

    git checkout -b amassiro-ecal-rechit-11_1_0-PR-3
    
    git push -u origin amassiro-ecal-rechit-11_1_0-PR-3

    
    
Now go for rebase:

    cd /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/Rebase/forPR
    
    cmsrel CMSSW_11_1_Patatrack_X_2020-05-13-2300
    cd CMSSW_11_1_Patatrack_X_2020-05-13-2300/src
    cmsenv

    git cms-rebase-topic amassiro:amassiro-ecal-rechit-11_1_0-PR-3
    
fix fix fix stuff

    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin

    git checkout -b amassiro-ecal-rechit-11_1_0-PR-4
    
    git push -u origin amassiro-ecal-rechit-11_1_0-PR-4
    
    
    
 
This one is ok:

    cd /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/Rebase

    amassiro-ecal-rechit-11_1_0-PR-3
    
    scram build code-checks    
    
    

15 May 
====

Cleaning the PR
 
    https://github.com/cms-patatrack/cmssw/pull/462
    
    
EventFilter/EcalRawToDigi/BuildFile.xml

    git checkout e8b26023f549286f7b3ffecb78f5960a4fbb2b6a~1 -- EventFilter/EcalRawToDigi/BuildFile.xml

    git checkout e8b26023f549286f7b3ffecb78f5960a4fbb2b6a~1 -- CondFormats/EcalObjects/interface/EcalChannelStatusCode.h

    

Cleaning:

    scram b llvm-ccdb
    
    cd src/
    
    clang-tidy -fix-errors -header-filter="$CMSSW_BASE/src/.*" -checks=-clang-diagnostic-unused-command-line-argument --format-style=file $(find PACKAGES -name '*.cc')
    
    for example:
    
     clang-tidy -fix-errors -header-filter="$CMSSW_BASE/src/.*" -checks=-clang-diagnostic-unused-command-line-argument --format-style=file $(find RecoLocalCalo -name '*.cc')
     clang-tidy -fix-errors -header-filter="$CMSSW_BASE/src/.*" -checks=-clang-diagnostic-unused-command-line-argument --format-style=file $(find CondFormats -name '*.cc')
     clang-tidy -fix-errors -header-filter="$CMSSW_BASE/src/.*" -checks=-clang-diagnostic-unused-command-line-argument --format-style=file $(find CUDADataFormats -name '*.cc')
     clang-tidy -fix-errors -header-filter="$CMSSW_BASE/src/.*" -checks=-clang-diagnostic-unused-command-line-argument --format-style=file $(find EventFilter -name '*.cc')
     clang-tidy -fix-errors -header-filter="$CMSSW_BASE/src/.*" -checks=-clang-diagnostic-unused-command-line-argument --format-style=file $(find DataFormats -name '*.cc')

    git push -u origin amassiro-ecal-rechit-11_1_0-PR-3
    
    
    
    
Change of "if" to "for" 

Error:

    cudaCheck(cudaMemsetAsync(scratchGPU.pChannelsCounter, 0, sizeof(uint32_t) * 2, cudaStream));
    cudaErrorInvalidValue: invalid argument

    
    


18 May 
====

... now it works (and no changes??)


Run reconstruction:

    cmsRun testEcalUncalibRechitProducer_cfg.py
    cmsRun testEcalRechitProducer_cfg.py


Run validation:

    makeEcalMultifitResultsGpuValidationPlots   test_uncalib.root   plotValidation_uncalibrechit.root
    makeEcalRechitValidationPlots               testRechit.root     plotValidation_calibrechit.root


Back to clang tidy up.

    sh cms-format  (by A. Bocci)
    
    
    
Uncalibrrechit --> flags not ok??

       
       
    
19 May
====

Check flags for uncalibrechit -> why they appear now?

    not isolated in some flags
    
    require > 1 ADC count

    not fixed 
    
Speed test






    
20-21 May
====

Speed test.

    cmsRun testEcalUncalibRechitProducer_speed_cfg.py
    cmsRun testEcalRechitProducer_speed_cfg.py

Prepare the cmsrun file to be run

    edmConfigDump testEcalRechitProducer_speed_cfg.py > dump_testEcalRechitProducer_speed_cfg.py

Download toolkit and run:

    cd /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/Rebase/

    git clone git@github.com:cms-patatrack/patatrack-scripts.git
    
    https://github.com/cms-patatrack/patatrack-scripts/

    cd patatrack-scripts/

    nvprof cmsRun ../CMSSW_11_1_Patatrack_X_2020-05-13-2300/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py  
    

        
Results:


      dropped waiting message count 0
      ==38232== Profiling application: cmsRun ../CMSSW_11_1_Patatrack_X_2020-05-13-2300/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py
      ==38232== Profiling result:
                  Type  Time(%)      Time     Calls       Avg       Min       Max  Name
       GPU activities:   84.80%  842.34ms      1000  842.34us  334.35us  4.6143ms  ecal::multifit::kernel_minimize(unsigned int const *, unsigned int const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, EcalPulseCovariance const *, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1> const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, float*, float*, char*, int, int, unsigned int, unsigned int)
                    5.35%  53.134ms      1000  53.134us  36.129us  98.530us  void ecal::raw::kernel_unpack_test<int=32>(unsigned char const *, unsigned int const *, int const *, unsigned short*, int const *, unsigned int*, unsigned short*, unsigned short*, unsigned int const , unsigned int)
                    3.24%  32.160ms      1000  32.160us  14.529us  134.08us  ecal::multifit::kernel_prep_2d(Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1> const *, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, double const *, double const *, double const *, double const *, double const *, double const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, EcalPulseShape const *, bool const *, bool const *, bool const *, unsigned int, unsigned int)
                    2.39%  23.714ms      3077  7.7060us     960ns  4.4264ms  [CUDA memcpy HtoD]
                    1.69%  16.786ms     11000  1.5250us     416ns  12.801us  [CUDA memcpy DtoH]
                    1.57%  15.594ms      1000  15.594us  11.489us  310.22us  ecal::rechit::kernel_create_ecal_rehit(int const *, unsigned int, bool, bool, bool, bool, bool, bool, bool, float, float, float, float, int const *, unsigned int const *, unsigned int const *, unsigned int, unsigned int, float const *, float const *, unsigned short const *, float const *, float const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, __int64, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, float const *, unsigned int const *, unsigned int const *, unsigned int*, float*, float*, float*, unsigned int*, unsigned int*, int, unsigned int, unsigned int)
                    0.86%  8.5166ms      1000  8.5160us  5.3130us  106.12us  ecal::multifit::kernel_prep_1d_and_initialize(EcalPulseShape const *, unsigned short const *, unsigned int const *, unsigned short const *, unsigned int const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, float const *, float const *, float const *, float const *, float const *, float const *, bool*, bool*, bool*, float*, float*, float*, unsigned int*, unsigned int*, char*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, unsigned int, unsigned int, bool, bool, int)
                    0.11%  1.0767ms      1000  1.0760us     960ns  2.7840us  [CUDA memset]
      API calls:   25.95%  464.67ms     12039  38.596us  4.1030us  6.9884ms  cudaFreeHost
                   17.21%  308.14ms         3  102.71ms  20.317us  308.10ms  cudaMemGetInfo
                   13.33%  238.60ms     12039  19.818us  5.4640us  13.026ms  cudaHostAlloc
                   11.83%  211.84ms         1  211.84ms  211.84ms  211.84ms  cudaDeviceReset
                    9.88%  176.89ms     14045  12.594us  4.2660us  4.5253ms  cudaMemcpyAsync

                    
      https://developer.nvidia.com/nvidia-visual-profiler
    

       
                     Type  Time(%)      Time     Calls       Avg       Min       Max  Name
    GPU activities:   84.80%  842.34ms      1000  842.34us  334.35us  4.6143ms  ecal::multifit::kernel_minimize
                       5.35%  53.134ms      1000  53.134us  36.129us  98.530us  void ecal::raw::kernel_unpack_test<int=32>
                       3.24%  32.160ms      1000  32.160us  14.529us  134.08us  ecal::multifit::kernel_prep_2d
                       2.39%  23.714ms      3077  7.7060us     960ns  4.4264ms  [CUDA memcpy HtoD]
                       1.69%  16.786ms     11000  1.5250us     416ns  12.801us  [CUDA memcpy DtoH]
                       1.57%  15.594ms      1000  15.594us  11.489us  310.22us  ecal::rechit::kernel_create_ecal_rehit
                       0.86%  8.5166ms      1000  8.5160us  5.3130us  106.12us  ecal::multifit::kernel_prep_1d_and_initialize
                       0.11%  1.0767ms      1000  1.0760us     960ns  2.7840us  [CUDA memset]
         API calls:   25.95%  464.67ms     12039  38.596us  4.1030us  6.9884ms  cudaFreeHost
                      17.21%  308.14ms         3  102.71ms  20.317us  308.10ms  cudaMemGetInfo
                      13.33%  238.60ms     12039  19.818us  5.4640us  13.026ms  cudaHostAlloc
                      11.83%  211.84ms         1  211.84ms  211.84ms  211.84ms  cudaDeviceReset
                       9.88%  176.89ms     14045  12.594us  4.2660us  4.5253ms  cudaMemcpyAsync    
       
       
       
    
    
    
Other:
    
    ./benchmark ../CMSSW_11_1_Patatrack_X_2020-05-13-2300/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py

    
    ./patatrack-scripts/benchmark ECALValidation/EcalLocalRecoToolKit/test/dump_ecal_cpu.py 

    
    CPU
 
    Running 4 times over 4200 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
 
     2.9 ±   0.0 ev/s (2400 events)
     2.9 ±   0.0 ev/s (2400 events)
    --------------------
     2.9 ±   0.0 ev/s


     
     GPU 
     
     1.3 ±   0.0 ev/s (2400 events)
     1.3 ±   0.0 ev/s (2400 events)
     1.3 ±   0.0 ev/s (2400 events)
     1.3 ±   0.0 ev/s (2400 events)
     --------------------
     1.3 ±   0.0 ev/s

     
     



22 May
====

To be fixed:

    ThroughputService
    
--> added (true) explicitly in the original cfg file




25 May
====

move to new cmssw

    cmsrel CMSSW_11_1_Patatrack_X_2020-05-20-2300
    
    cd CMSSW_11_1_Patatrack_X_2020-05-20-2300/src
    
    
    cmsrel CMSSW_11_1_0_pre7
    
    cd CMSSW_11_1_0_pre7/src/
    
    cmsenv
    
    git cms-merge-topic CMSSW_11_1_Patatrack_X

    git cms-merge-topic amassiro:amassiro-ecal-rechit-11_1_0-PR-3

small fix and compile a lot


    ./benchmark ../CMSSW_11_1_Patatrack_X_2020-05-20-2300/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py

    
    

26 May
====

move to new cmssw

    cmsrel CMSSW_11_1_Patatrack_X_2020-05-20-2300
    
    cd CMSSW_11_1_Patatrack_X_2020-05-20-2300/src
    
    
    cmsrel CMSSW_11_1_0_pre7_Patatrack
    
    cd CMSSW_11_1_0_pre7_Patatrack/src/
    
    cmsenv
    
    git cms-merge-topic CMSSW_11_1_Patatrack_X

    git cms-merge-topic amassiro:amassiro-ecal-rechit-11_1_0-PR-3

small fix and compile a lot


    ./benchmark ../CMSSW_11_1_Patatrack_X_2020-05-20-2300/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py




27 May
====

move to new cmssw

    cmsrel CMSSW_11_1_0_pre8_Patatrack
    
    cd CMSSW_11_1_0_pre8_Patatrack/src/
    
    cmsenv
    
    git cms-merge-topic CMSSW_11_1_Patatrack_X

    git cms-merge-topic amassiro:amassiro-ecal-rechit-11_1_0-PR-3

small fix and compile a lot


    ./benchmark ../CMSSW_11_1_Patatrack_X_2020-05-20-2300/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py


    
    git checkout -b amassiro-ecal-rechit-11_1_0-PR-5

    git remote add origin git@github.com:amassiro/cmssw
 
    git fetch origin

    git checkout -b amassiro-ecal-rechit-11_1_0-PR-5
    
    git push -u origin amassiro-ecal-rechit-11_1_0-PR-5
    
    ---> previous instructions only for bookkeeping
    
    
    git checkout -b amassiro-ecal-rechit-11_1_0-PR-3
    
    git push -u origin amassiro-ecal-rechit-11_1_0-PR-3
    
    
    /afs/cern.ch/work/a/amassiro/ECAL/GPU/onGPU/1Apr2020/Rebase/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    
Move to HLT GPU machines

    instructions under "performance"

    
    
    
29 May
====

In

    /nfshome0/amassiro/TestGPUnoMerge/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test

without merging of my PR, it runs.

With my PR, problem with usual

    cudaErrorInvalidDeviceFunction: invalid device function

    
By A. Bocci:

    CUDADataFormats/EcalRecHitSoA
    EventFilter/EcalRawToDigi
    RecoLocalCalo/EcalRecAlgos
    RecoLocalCalo/EcalRecProducers
    
    
    

4 June
====

    comments by Bocci and Matti implemented
 
Add Cuda protection

PR merged



