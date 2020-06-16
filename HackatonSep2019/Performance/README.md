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


    /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only.py
    process.recoPathGPUonlyUncalib
    1217.9 ±  32.1 ev/s

    /nfshome0/amassiro/TestGPU/CMSSW_11_1_0_pre8_Patatrack/src/RecoLocalCalo/EcalRecProducers/test/test_ecal_only_gpu_all.py
    process.recoPathGPUall
    1148.8 ±  56.8 ev/s

    
 
 
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
                    2.22%  38.211ms      1000  38.210us  17.760us  119.26us  ecal::multifit::kernel_prep_2d(Eigen::Matrix<char, int=10, int=1, int=0, int=10, int=1> const *, unsigned int const *, unsigned int const *, float const *, float const *, float const *, float const *, float const *, double const *, double const *, double const *, double const *, double const *, double const *, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, Eigen::Matrix<float, int=10, int=10, int=0, int=10, int=10>*, EcalPulseShape const *, bool const *, bool const *, bool const *, unsigned int, unsigned int)
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








