Performance studies
====

    https://github.com/cms-patatrack/patatrack-scripts
    
    git clone git@github.com:cms-patatrack/patatrack-scripts.git
    
Twiki:

    https://twiki.cern.ch/twiki/bin/viewauth/CMS/TriggerDevelopmentWithGPUs

    
Connect:

    ssh cmsusr.cern.ch -t ssh gpu-c2d41-12-01.cms
    
Source:

    export VO_CMS_SW_DIR=/data/cmssw
    export SCRAM_ARCH=slc7_amd64_gcc820
    source $VO_CMS_SW_DIR/cmsset_default.sh

    
NVIDIA:

    nvidia-smi

Setup github

    ssh -f -N cmsusr.cms

Install

    cd /nfshome0/amassiro/TestGPU
    
    cmsrel CMSSW_11_1_0_pre8_Patatrack
    cd CMSSW_11_1_0_pre8_Patatrack/src
    cmsenv
 
    git cms-merge-topic amassiro:amassiro-ecal-rechit-11_1_0-PR-3

    scramv1 b -j 20
    
    
    
    git-cms-addpkg CUDADataFormats/EcalRecHitSoA
    git-cms-addpkg EventFilter/EcalRawToDigi
    git-cms-addpkg RecoLocalCalo/EcalRecAlgos
    git-cms-addpkg RecoLocalCalo/EcalRecProducers
 
    
    
Input files:

    sourceFromRawHLTmachine_cff.py
    
    copy one file to test
    
    
Run:

    nvidia-smi
    export CUDA_VISIBLE_DEVICES=0;

    cd /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test
    cmsRun testEcalUncalibRechitProducer_cfg.py
    
    
    
Test:

    edmConfigDump  testEcalRechitProducer_cfg.py > dump_testEcalRechitProducer_cfg.py
    
    cp dump_testEcalRechitProducer_cfg.py dump_testEcalRechitProducer_speed_cfg.py

    
    cd /data/user/amassiro/

    git clone git@github.com:cms-patatrack/patatrack-scripts.git

    ./patatrack-scripts/benchmark /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py

    ./patatrack-scripts/scan /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_cfg.py

    
    
Run 

    cmsRun testEcalRechitProducer_speed_cpu_cfg.py
    cmsRun testEcalRechitProducer_speed_gpu_cfg.py

    edmConfigDump testEcalRechitProducer_speed_gpu_cfg.py > dump_testEcalRechitProducer_speed_gpu_cfg.py
    edmConfigDump testEcalRechitProducer_speed_cpu_cfg.py > dump_testEcalRechitProducer_speed_cpu_cfg.py

    
    cd /data/user/amassiro/

    ./patatrack-scripts/benchmark /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_gpu_cfg.py

    ./patatrack-scripts/scan /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_gpu_cfg.py
    
    
    
 
Tests:


fu-c2d41-12-01

    ssh cmsusr.cern.ch -t ssh gpu-c2d41-12-01.cms

    source ~/setupCMSSW.sh
    
    cd /data/user/amassiro/

    cmsrel CMSSW_11_1_0_pre8_Patatrack
    
    cd CMSSW_11_1_0_pre8_Patatrack/src/
    
    cmsenv
    
    git cms-init -x cms-patatrack
    git checkout CMSSW_11_1_X_Patatrack

 #   runTheMatrix.py -l 10824.512
    
    
    git-cms-addpkg RecoLocalCalo/EcalRecProducers
    git-cms-addpkg RecoLocalCalo/EcalRecAlgos
    git-cms-addpkg CUDADataFormats/EcalRecHitSoA
    git-cms-addpkg  EventFilter/EcalRawToDigi

    scramv1 b -j 20
 
 
 
    cd ../../
    
    git clone git@github.com:cms-patatrack/patatrack-scripts.git    

    ./patatrack-scripts/benchmark /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/dump_testEcalRechitProducer_speed_gpu_cfg.py

    ./patatrack-scripts/benchmark /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only.py

    
    
    export CUDA_VISIBLE_DEVICES=0;
    
    cmsRun /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only.py
    
    cmsRun /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only_gpu_all.py
    
    
    ./patatrack-scripts/benchmark /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only.py
    ./patatrack-scripts/benchmark /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only_gpu_all.py

    ./patatrack-scripts/scan /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only.py
    ./patatrack-scripts/scan /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only_gpu_all.py

    
    /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only.py
    process.recoPathGPUonlyUncalib
     6.1 ±   0.1 ev/s
     6.0 ±   0.2 ev/s (with 16 nchannels_per_block):


    /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only_gpu_all.py
    process.recoPathGPUall

    
 
 
    nvprof cmsRun    /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only_gpu_all.py
    
    
TimeReport ---------- Module Summary ---[Real sec]----
TimeReport  per event     per exec    per visit  Name
TimeReport   0.000004     0.000004     0.000004  TriggerResults
TimeReport   0.000002     0.000002     0.000002  bunchSpacing
TimeReport   0.000005     0.000005     0.000005  bunchSpacingProducer
TimeReport   0.000003     0.000003     0.000003  digiPath
TimeReport   0.000546     0.000546     0.000546  ecalCPURecHitProducer
TimeReport   0.005586     0.005586     0.005586  ecalDigis
TimeReport   0.000646     0.000646     0.000646  ecalRawToDigiGPU
TimeReport   0.000288     0.000288     0.000288  ecalRecHitConvertGPU2CPUFormat
TimeReport   0.001141     0.001141     0.001141  ecalRecHitProducerGPU
TimeReport   0.012741     0.012741     0.012741  ecalUncalibRecHitProducerGPU
TimeReport   0.000008     0.000008     0.000008  finalize
TimeReport   0.104566     0.104566     0.104566  out
TimeReport   0.000002     0.000002     0.000002  recoPathGPUall
TimeReport  per event     per exec    per visit  Name





            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
    GPU activities:   86.97%  1.49509s      1000  1.4951ms  702.08us  16.900ms  ecal::multifit::kernel_minimize(unsigned int const *, unsigned int const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, EcalPulseCovariance const *, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1> const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, float*, float*, char*, int, int, unsigned int, unsigned int)
                    5.95%  102.30ms      1000  102.30us  63.967us  147.10us  void ecal::raw::kernel_unpack_test<int=32>(unsigned char const *, unsigned int const *, int const *, unsigned short*, int const *, unsigned int*, unsigned short*, unsigned short*, unsigned int const , unsigned int)
           24.604ms          2.22%  38.211ms      1000  38.210us  17.760us  119.26us  ecal::multifit::kernel_prep_2d(Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1> const *, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, double const *, double const *, double const *, double const *, double const *, double const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, EcalPulseShape const *, bool const *, bool const *, bool const *, unsigned int, unsigned int)
                    1.41%  24.303ms      1000  24.303us  18.752us  29.280us  ecal::rechit::kernel_create_ecal_rehit(int const *, unsigned int, bool, bool, bool, bool, bool, bool, bool, float, float, float, float, int const *, unsigned int const *, unsigned int const *, unsigned int, unsigned int, float const *, float const *, unsigned short const *, float const *, float const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, __int64, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, float const *, unsigned int const *, unsigned int const *, unsigned int*, float*, float*, float*, unsigned int*, unsigned int*, int, unsigned int, unsigned int)
                    1.38%  23.761ms      3109  7.6420us  1.0560us  5.1054ms  [CUDA memcpy HtoD]
                    1.14%  19.669ms     11000  1.7880us     928ns  12.544us  [CUDA memcpy DtoH]
                    0.86%  14.702ms      1000  14.702us  10.880us  29.664us  ecal::multifit::kernel_prep_1d_and_initialize(EcalPulseShape const *, unsigned short const *, unsigned int const *, unsigned short const *, unsigned int const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, float const *, float const *, float const *, float const *, float const *, float const *, bool*, bool*, bool*, float*, float*, float*, unsigned int*, unsigned int*, char*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, unsigned int, unsigned int, bool, bool, int)
                    0.06%  1.1143ms      1000  1.1140us  1.0560us  5.7600us  [CUDA memset]
      API calls:   32.74%  810.45ms     12055  67.229us  3.7490us  16.922ms  cudaFreeHost
                   16.82%  416.41ms         3  138.80ms  21.430us  416.36ms  cudaMemGetInfo
                   15.17%  375.55ms     12055  31.152us  5.8310us  16.663ms  cudaHostAlloc
                    9.67%  239.37ms     14045  17.043us  3.7980us  5.2259ms  cudaMemcpyAsync
                    6.73%  166.68ms      5000  33.336us  6.9340us  2.1699ms  cudaLaunchKernel
                    5.20%  128.78ms         1  128.78ms  128.78ms  128.78ms  cudaDeviceReset
                    4.71%  116.63ms      4000  29.157us  5.2710us  7.1872ms  cudaStreamAddCallback
                    2.22%  54.960ms      3000  18.320us  1.2420us  4.5303ms  cudaEventRecord
                    1.88%  46.655ms      9030  5.1660us     699ns  1.0035ms  cudaEventQuery
                    1.06%  26.300ms      6000  4.3830us  1.0170us  582.08us  cudaEventSynchronize
                    0.94%  23.365ms      7102  3.2890us     570ns  68.715us  cudaSetDevice
                    0.81%  19.957ms      1000  19.957us  6.8910us  342.32us  cudaMemsetAsync
                    0.79%  19.609ms     19065  1.0280us     317ns  690.07us  cudaGetDevice
                    0.62%  15.436ms       335  46.076us  7.1010us  951.17us  cudaFree
                    0.37%  9.1216ms       335  27.228us  3.7060us  1.7855ms  cudaMalloc
                    0.09%  2.3332ms      5000     466ns     157ns  23.309us  cudaGetLastError
                    0.04%  1.0138ms         1  1.0138ms  1.0138ms  1.0138ms  cuDeviceTotalMem
                    0.04%  951.46us        39  24.396us  2.1280us  241.67us  cudaEventCreateWithFlags
                    0.02%  518.49us         8  64.810us  20.875us  242.06us  cudaStreamCreateWithFlags
                    0.02%  480.76us        64  7.5110us  4.5560us  31.310us  cudaMemcpy
                    0.01%  233.71us         1  233.71us  233.71us  233.71us  cudaGetDeviceProperties
                    0.01%  225.70us        97  2.3260us     269ns  89.270us  cuDeviceGetAttribute
                    0.01%  149.74us         8  18.717us  8.6080us  71.900us  cudaStreamDestroy
                    0.00%  105.26us        39  2.6980us  1.4940us  16.999us  cudaEventDestroy
                    0.00%  35.698us         1  35.698us  35.698us  35.698us  cuDeviceGetName
                    0.00%  17.481us         1  17.481us  17.481us  17.481us  cudaDeviceSynchronize
                    0.00%  15.075us         1  15.075us  15.075us  15.075us  cuDeviceGetPCIBusId
                    0.00%  12.129us         5  2.4250us     842ns  8.2930us  cudaDeviceGetLimit
                    0.00%  6.8050us         1  6.8050us  6.8050us  6.8050us  cudaSetDeviceFlags
                    0.00%  6.5210us         9     724ns     225ns  3.6600us  cudaGetDeviceCount
                    0.00%  2.6770us         1  2.6770us  2.6770us  2.6770us  cudaGetDeviceFlags
                    0.00%  2.5430us         3     847ns     374ns  1.5120us  cuDeviceGetCount
                    0.00%  1.3370us         2     668ns     361ns     976ns  cuDeviceGet
                    0.00%     521ns         1     521ns     521ns     521ns  cuDeviceGetUuid




Possible optimization:

1)


    maxNumberHits = cms.uint32(20000), 
    -->
    maxNumberHits = cms.uint32(10000), 
    
    
   Result: minor effect, see below 
    
     9.6 ±   0.3 ev/s
     
     (with 16 nchannels_per_block):
     9.9 ±   0.2 ev/s

     

    
     GPU activities:   86.78%  1.49888s      1000  1.4989ms  702.24us  17.019ms  ecal::multifit::kernel_minimize(unsigned int const *, unsigned int const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, EcalPulseCovariance const *, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1> const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, float*, float*, char*, int, int, unsigned int, unsigned int)
                    5.92%  102.31ms      1000  102.31us  63.839us  147.10us  void ecal::raw::kernel_unpack_test<int=32>(unsigned char const *, unsigned int const *, int const *, unsigned short*, int const *, unsigned int*, unsigned short*, unsigned short*, unsigned int const , unsigned int)
                    2.22%  38.324ms      1000  38.323us  18.816us  95.008us  ecal::multifit::kernel_prep_2d(Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1> const *, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, double const *, double const *, double const *, double const *, double const *, double const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, EcalPulseShape const *, bool const *, bool const *, bool const *, unsigned int, unsigned int)
                    1.63%  28.219ms      3109  9.0760us  1.0550us  7.9786ms  [CUDA memcpy HtoD]
                    1.41%  24.426ms      1000  24.426us  18.496us  29.568us  ecal::rechit::kernel_create_ecal_rehit(int const *, unsigned int, bool, bool, bool, bool, bool, bool, bool, float, float, float, float, int const *, unsigned int const *, unsigned int const *, unsigned int, unsigned int, float const *, float const *, unsigned short const *, float const *, float const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, __int64, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, float const *, unsigned int const *, unsigned int const *, unsigned int*, float*, float*, float*, unsigned int*, unsigned int*, int, unsigned int, unsigned int)
                    1.12%  19.378ms     11000  1.7610us  1.1200us  13.216us  [CUDA memcpy DtoH]
                    0.85%  14.652ms      1000  14.652us  10.784us  44.704us  ecal::multifit::kernel_prep_1d_and_initialize(EcalPulseShape const *, unsigned short const *, unsigned int const *, unsigned short const *, unsigned int const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, float const *, float const *, float const *, float const *, float const *, float const *, bool*, bool*, bool*, float*, float*, float*, unsigned int*, unsigned int*, char*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, unsigned int, unsigned int, bool, bool, int)
                    0.06%  1.1158ms      1000  1.1150us  1.0240us  12.576us  [CUDA memset]
      API calls:   30.33%  744.58ms     12055  61.764us  4.4790us  14.091ms  cudaFreeHost
                   17.47%  428.84ms     12055  35.573us  4.0270us  16.240ms  cudaHostAlloc
                   12.76%  313.26ms     14045  22.304us  3.7520us  14.088ms  cudaMemcpyAsync
                    9.65%  236.90ms         3  78.967ms  17.020us  236.86ms  cudaMemGetInfo
                    8.37%  205.45ms      5000  41.090us  6.2850us  1.1833ms  cudaLaunchKernel
                    6.67%  163.74ms      4000  40.935us  7.3320us  6.6619ms  cudaStreamAddCallback
                    4.57%  112.23ms         1  112.23ms  112.23ms  112.23ms  cudaDeviceReset
                    2.43%  59.697ms      9030  6.6110us     898ns  1.0167ms  cudaEventQuery
                    1.86%  45.675ms      3000  15.224us  1.6450us  1.6874ms  cudaEventRecord
                    1.38%  33.906ms      6000  5.6510us     893ns  330.70us  cudaEventSynchronize
                    1.16%  28.453ms      7102  4.0060us     445ns  212.51us  cudaSetDevice
                    1.06%  26.022ms     19065  1.3640us     290ns  1.0876ms  cudaGetDevice
                    0.96%  23.615ms      1000  23.614us  7.5560us  616.21us  cudaMemsetAsync
                    0.61%  14.988ms       335  44.741us  7.2590us  970.97us  cudaFree
                    0.41%  10.041ms       335  29.972us  5.2910us  474.28us  cudaMalloc
                    0.12%  2.9394ms      5000     587ns     140ns  38.405us  cudaGetLastError
                    0.06%  1.5168ms        39  38.892us  1.8930us  313.82us  cudaEventCreateWithFlags
                    0.04%  949.61us         1  949.61us  949.61us  949.61us  cuDeviceTotalMem
                    0.03%  640.88us        64  10.013us  6.4210us  35.833us  cudaMemcpy
                    0.02%  420.64us         8  52.580us  18.578us  115.75us  cudaStreamCreateWithFlags
                    0.01%  212.22us        97  2.1870us     255ns  83.323us  cuDeviceGetAttribute
                    0.01%  191.89us         1  191.89us  191.89us  191.89us  cudaGetDeviceProperties
                    0.01%  125.04us         8  15.630us  9.0680us  53.784us  cudaStreamDestroy
                    0.00%  105.20us        39  2.6970us  1.7510us  16.859us  cudaEventDestroy
                    0.00%  83.899us         1  83.899us  83.899us  83.899us  cuDeviceGetName
                    0.00%  12.993us         1  12.993us  12.993us  12.993us  cudaDeviceSynchronize
                    0.00%  10.678us         1  10.678us  10.678us  10.678us  cuDeviceGetPCIBusId
                    0.00%  8.8990us         5  1.7790us     655ns  6.0480us  cudaDeviceGetLimit
                    0.00%  6.7860us         1  6.7860us  6.7860us  6.7860us  cudaSetDeviceFlags
                    0.00%  5.4090us         9     601ns     185ns  2.8230us  cudaGetDeviceCount
                    0.00%  2.2530us         3     751ns     316ns  1.3400us  cuDeviceGetCount
                    0.00%  2.1800us         1  2.1800us  2.1800us  2.1800us  cudaGetDeviceFlags
                    0.00%  1.2540us         2     627ns     338ns     916ns  cuDeviceGet
                    0.00%     549ns         1     549ns     549ns     549ns  cuDeviceGetUuid
    
    
    
    
    
    
    
    
    
    
    
    
    
    
2)  with 20k max channels

    nchannels_per_block 16 -> 32
    
    and recompile
    
    
Result:

     9.8 ±   0.1 ev/s
    
     It was "     9.6 ±   0.3 ev/s "  -> slight improvement



     GPU activities:   86.92%  1.49445s      1000  1.4944ms  697.63us  16.983ms  ecal::multifit::kernel_minimize(unsigned int const *, unsigned int const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, EcalPulseCovariance const *, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1> const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10> const *, float*, float*, char*, int, int, unsigned int, unsigned int)
                    5.83%  100.21ms      1000  100.21us  62.847us  143.23us  void ecal::raw::kernel_unpack_test<int=32>(unsigned char const *, unsigned int const *, int const *, unsigned short*, int const *, unsigned int*, unsigned short*, unsigned short*, unsigned int const , unsigned int)
                    2.22%  38.228ms      1000  38.228us  17.664us  78.783us  ecal::multifit::kernel_prep_2d(Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1> const *, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, double const *, double const *, double const *, double const *, double const *, double const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, EcalPulseShape const *, bool const *, bool const *, bool const *, unsigned int, unsigned int)
                    1.53%  26.257ms      3109  8.4450us  1.0870us  7.1860ms  [CUDA memcpy HtoD]
                    1.43%  24.604ms      1000  24.604us  18.688us  36.224us  ecal::rechit::kernel_create_ecal_rehit(int const *, unsigned int, bool, bool, bool, bool, bool, bool, bool, float, float, float, float, int const *, unsigned int const *, unsigned int const *, unsigned int, unsigned int, float const *, float const *, unsigned short const *, float const *, float const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, float const *, float const *, float const *, __int64 const *, __int64 const *, __int64 const *, __int64, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, float const *, unsigned int const *, unsigned int const *, unsigned int*, float*, float*, float*, unsigned int*, unsigned int*, int, unsigned int, unsigned int)
                    1.15%  19.788ms     11000  1.7980us     992ns  13.344us  [CUDA memcpy DtoH]
                    0.85%  14.669ms      1000  14.668us  10.816us  36.192us  ecal::multifit::kernel_prep_1d_and_initialize(EcalPulseShape const *, unsigned short const *, unsigned int const *, unsigned short const *, unsigned int const *, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<float, int=10, int=1, int=0, int=10, int=1>*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, float const *, float const *, float const *, float const *, float const *, float const *, bool*, bool*, bool*, float*, float*, float*, unsigned int*, unsigned int*, char*, Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1>*, unsigned int, unsigned int, bool, bool, int)
                    0.07%  1.1282ms      1000  1.1280us  1.0560us  4.4800us  [CUDA memset]
      API calls:   38.66%  915.21ms     12055  75.919us  4.0630us  17.227ms  cudaFreeHost
                   15.91%  376.52ms     12055  31.233us  2.6590us  16.165ms  cudaHostAlloc
                   10.08%  238.50ms         3  79.498ms  17.091us  238.46ms  cudaMemGetInfo
                    9.39%  222.28ms     14045  15.826us  3.7690us  7.3993ms  cudaMemcpyAsync
                    6.72%  158.99ms      5000  31.797us  7.2140us  1.6207ms  cudaLaunchKernel
                    5.62%  132.95ms      4000  33.237us  6.7720us  7.2113ms  cudaStreamAddCallback
                    4.73%  112.03ms         1  112.03ms  112.03ms  112.03ms  cudaDeviceReset
                    2.04%  48.299ms      9030  5.3480us     706ns  655.18us  cudaEventQuery
                    1.94%  45.812ms      3000  15.270us  1.1730us  3.7203ms  cudaEventRecord
                    1.11%  26.328ms      6000  4.3880us     986ns  1.0293ms  cudaEventSynchronize
                    1.00%  23.777ms      7102  3.3470us     443ns  993.90us  cudaSetDevice
                    0.79%  18.660ms     19065     978ns     286ns  36.688us  cudaGetDevice
                    0.72%  17.049ms      1000  17.049us  7.1490us  223.01us  cudaMemsetAsync
                    0.59%  13.946ms       331  42.132us  6.9510us  452.60us  cudaFree
                    0.43%  10.136ms       335  30.255us  4.5230us  459.04us  cudaMalloc
                    0.11%  2.6424ms      4000     660ns     175ns  556.66us  cudaGetLastError
                    0.05%  1.2197ms        39  31.275us  2.1680us  238.84us  cudaEventCreateWithFlags
                    0.04%  1.0461ms         1  1.0461ms  1.0461ms  1.0461ms  cuDeviceTotalMem
                    0.03%  621.10us        64  9.7040us  6.1480us  39.397us  cudaMemcpy
                    0.02%  402.86us         8  50.357us  18.660us  132.64us  cudaStreamCreateWithFlags
                    0.01%  227.60us        97  2.3460us     265ns  89.447us  cuDeviceGetAttribute
                    0.01%  201.38us         1  201.38us  201.38us  201.38us  cudaGetDeviceProperties
                    0.00%  117.09us         8  14.636us  9.0540us  47.419us  cudaStreamDestroy
                    0.00%  94.520us        39  2.4230us  1.7640us  7.6810us  cudaEventDestroy
                    0.00%  34.027us         1  34.027us  34.027us  34.027us  cuDeviceGetName
                    0.00%  12.452us         1  12.452us  12.452us  12.452us  cudaDeviceSynchronize
                    0.00%  12.235us         1  12.235us  12.235us  12.235us  cuDeviceGetPCIBusId
                    0.00%  8.9870us         5  1.7970us     628ns  6.1510us  cudaDeviceGetLimit
                    0.00%  7.1020us         1  7.1020us  7.1020us  7.1020us  cudaSetDeviceFlags
                    0.00%  5.4350us         9     603ns     186ns  2.9990us  cudaGetDeviceCount
                    0.00%  2.5590us         3     853ns     417ns  1.4770us  cuDeviceGetCount
                    0.00%  2.2450us         1  2.2450us  2.2450us  2.2450us  cudaGetDeviceFlags
                    0.00%  1.4050us         2     702ns     393ns  1.0120us  cuDeviceGet
                    0.00%     474ns         1     474ns     474ns     474ns  cuDeviceGetUuid

    
    
    
Scan: not working
    
Test back HCAL configuration 



Only ECAL uncalibrechit 


Running 4 times over 1000 events with 1 jobs, each with 1 threads, 1 streams and 1 GPUs
     9.2 ±   0.0 ev/s (900 events)
     9.1 ±   0.0 ev/s (900 events)
     9.2 ±   0.0 ev/s (900 events)
     9.2 ±   0.0 ev/s (900 events)
 --------------------
     9.2 ±   0.0 ev/s

Running 4 times over 1000 events with 1 jobs, each with 2 threads, 2 streams and 1 GPUs
    16.6 ±   0.0 ev/s (900 events)
    16.7 ±   0.1 ev/s (900 events)
    16.7 ±   0.0 ev/s (900 events)
    16.5 ±   0.0 ev/s (900 events)
 --------------------
    16.6 ±   0.1 ev/s

Running 4 times over 1000 events with 1 jobs, each with 3 threads, 3 streams and 1 GPUs
    16.4 ±   0.1 ev/s (900 events)
    16.3 ±   0.1 ev/s (900 events)
    17.3 ±   0.0 ev/s (900 events)
    16.5 ±   0.1 ev/s (900 events)
 --------------------
    16.6 ±   0.5 ev/s

    
    
    
    
    
    
Only i/o

Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    1231.2 ±  14.8 ev/s (900 events)
    688.8 ± 114.6 ev/s (900 events)
    938.7 ±  98.9 ev/s (900 events)
    789.7 ±  44.1 ev/s (900 events)
 --------------------
    912.1 ± 236.2 ev/s

    
    
    
Only ECAL unpacker
 
Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    606.2 ± 103.7 ev/s (900 events)
    626.0 ± 112.6 ev/s (900 events)
    739.4 ±  63.3 ev/s (900 events)
    673.1 ± 107.7 ev/s (900 events)
  --------------------
    661.2 ±  59.2 ev/s
 
 
 
 
Unpacker + uncalibrechit 

Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    1174.4 ±   9.4 ev/s (900 events)
    1170.0 ±  13.3 ev/s (900 events)
    1199.2 ±   5.5 ev/s (900 events)
    1127.6 ±  15.8 ev/s (900 events)
 --------------------
    1167.8 ±  29.7 ev/s


    
    
    
Unpacker + uncalibrechit + copy back to host 

Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    951.5 ±  21.5 ev/s (900 events)
    928.4 ±  10.6 ev/s (900 events)
    924.9 ±  12.8 ev/s (900 events)
    957.7 ±  16.8 ev/s (900 events)
 --------------------
    940.6 ±  16.4 ev/s



Unpacker + uncalibrechit + copy back to host + copy to host digis and run ecalDetIdToBeRecovered

Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    985.8 ±  20.2 ev/s (900 events)
    938.9 ±  15.0 ev/s (900 events)
    931.5 ±  12.2 ev/s (900 events)
    982.3 ±  21.9 ev/s (900 events)
 --------------------
    959.6 ±  28.4 ev/s

    
    
    
Unpacker + uncalibrechit + copy back to host + copy to host digis and run ecalDetIdToBeRecovered + rechit on cpu
    
Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    929.2 ±  14.6 ev/s (900 events)
    872.6 ±  10.4 ev/s (900 events)
    918.8 ±  16.1 ev/s (900 events)
    999.2 ±  13.4 ev/s (900 events)
 --------------------
    930.0 ±  52.3 ev/s
    
    
    
    
    
    
    
    
    
Unpacker + uncalibrechit + rechit + copy to host digis and run ecalDetIdToBeRecovered 
    
Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    1268.7 ±   6.9 ev/s (900 events)
    1294.3 ±   5.5 ev/s (900 events)
    1030.8 ±   9.3 ev/s (900 events)
    1049.9 ±  19.7 ev/s (900 events)
 --------------------
    1160.9 ± 139.9 ev/s
    
    
    
    
    
Unpacker + uncalibrechit + rechit + copy to host digis and run ecalDetIdToBeRecovered + copy rechit on cpu and convert to legacy

Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    938.3 ±  17.2 ev/s (900 events)
    964.2 ±  17.3 ev/s (900 events)
    997.9 ±  16.8 ev/s (900 events)
    950.7 ±  14.4 ev/s (900 events)
 --------------------
    962.8 ±  25.7 ev/s



 
 
 
Final comparison

    ./patatrack-scripts/scan  raw2reco_ecalonly.py

Unpacker + uncalibrechit + rechit + copy to host digis and run ecalDetIdToBeRecovered + copy rechit on cpu and convert to legacy

Running 4 times over 1000 events with 1 jobs, each with 1 threads, 1 streams and 1 GPUs
    373.8 ±   4.5 ev/s (900 events)
    355.9 ±   2.9 ev/s (900 events)
    368.2 ±   3.9 ev/s (900 events)
    361.9 ±   3.5 ev/s (900 events)
 --------------------
    364.9 ±   7.7 ev/s

    
    

    ./patatrack-scripts/scan  raw2digi_ecalonly.py
    
Unpacker + uncalibrechit + copy back to host + copy to host digis and run ecalDetIdToBeRecovered + rechit on cpu
     
Running 4 times over 1000 events with 1 jobs, each with 1 threads, 1 streams and 1 GPUs
    263.6 ±   1.6 ev/s (900 events)
    266.7 ±   2.3 ev/s (900 events)
    268.4 ±   1.2 ev/s (900 events)
    269.6 ±   3.1 ev/s (900 events)
 --------------------
    267.1 ±   2.6 ev/s
     
     
     
     
     
     
     
    ./patatrack-scripts/scan  raw2reco_ecalonly_cpu.py
     
all on cpu + rechit on cpu
     

Running 4 times over 1000 events with 1 jobs, each with 1 threads, 1 streams and 1 GPUs
    20.4 ±   0.0 ev/s (900 events)
    20.1 ±   0.0 ev/s (900 events)
    20.3 ±   0.0 ev/s (900 events)
    20.3 ±   0.0 ev/s (900 events)
 --------------------
    20.3 ±   0.1 ev/s
     
     
Running 4 times over 1000 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
    138.9 ±   0.4 ev/s (900 events)
    138.8 ±   0.4 ev/s (900 events)
    139.3 ±   0.4 ev/s (900 events)
    139.1 ±   0.4 ev/s (900 events)
 --------------------
    139.1 ±   0.2 ev/s
     
     
     
Plot:

    r99t draw_time.cxx\(\"data_time.txt\"\)
    r99t draw_time.cxx\(\"data_time_steps.txt\"\)
    r99t draw_time.cxx\(\"data_time_2cpu.txt\"\)
    r99t draw_time.cxx\(\"data_time_8jobs.txt\"\)
     
     
     
     
     
Skim ECAL fed only
====
(see Jun 2019)

    ssh cmsusr.cern.ch -t ssh gpu-c2a02-37-03.cms
    
    cmsRun skim_EcalFed.py

Then run on amassiro@fu-c2a02-37-03

    r99t draw_time.cxx\(\"data_time_8jobs_onlyEcalFed.txt\"\)


allow_hyperthreading -> now set to true

    r99t draw_time.cxx\(\"data_time_8jobs_onlyEcalFed_allow_hyperthreading_True.txt\"\)

    r99t draw_time.cxx\(\"data_time_1job_onlyEcalFed_allow_hyperthreading_True.txt\"\)
    

Remember:

    streams ---> cmssw
    thread ----> operating system
    
Test i/o

    ./patatrack-scripts/scan  test_io.py
    
    
    
    
    
Tests:

    - try 10k events
    - try full raw data vs ecal fed only
    - remove chi2 float in gpu rechit (leave only extra that has it packed) -> see improvement
    
    
    
10k events

    r99t draw_time.cxx\(\"data_time_8jobs_onlyEcalFed_allow_hyperthreading_True_10kevents.txt\"\)

    
Raw vs only ECAL FED 

    r99t draw_time.cxx\(\"data_time_8jobs_AllFed_allow_hyperthreading_True_10kevents.txt\"\)
    r99t draw_time.cxx\(\"data_time_8jobs_onlyEcalFed_allow_hyperthreading_True_10kevents.txt\"\)

    
    
    
Tests: 

    - run on high pu sample
    
fu-c2a02-37-03 
    /data/user/dalfonso/CMSSW_11_1_0_pre8_Patatrack_ECALHCAL/src/skim_hcalfeds.py

    cmsRun skim_EcalFed_forBU.py
    
    raw2reco_ecalonly_cpu_highPU.py
    raw2digi_ecalonly_highPU.py
    raw2reco_ecalonly_highPU.py

    
    ./patatrack-scripts/scan     raw2reco_ecalonly_cpu_highPU.py
    ./patatrack-scripts/scan     raw2digi_ecalonly_highPU.py
    ./patatrack-scripts/scan     raw2reco_ecalonly_highPU.py
    
    
    
    r99t draw_time.cxx\(\"data_time_1jobs_onlyEcalFed_allow_hyperthreading_True_10kevents_highPU.txt\"\)
    r99t draw_time.cxx\(\"data_time_8jobs_onlyEcalFed_allow_hyperthreading_True_10kevents_highPU.txt\"\)
    
    
    
    
    
    
    
    
    