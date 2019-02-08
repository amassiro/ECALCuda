On lxplus:

     lxplus

     /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/CMSSW_10_5_X_2019-01-27-2300/src

Machine:

    cmg-gpu1080.cern.ch
     
First time:

    cp /data/patatrack/vkhriste/cmssw_releases/CMSSW_10_5_X_2019-01-27-2300/config/toolbox/slc7_amd64_gcc700/tools/selected/eigen.xml ../config/toolbox/slc7_amd64_gcc700/tools/selected/
    
    git cms-init

    git checkout -b test_ecal_cuda
    
    git cms-merge-topic vkhristenko:ecal_reco_cuda_with_condformats
    git cms-merge-topic vkhristenko:ecal_reco_cuda_head
    
    
    scram b -v -j 16

    scramv1 b -j 20
    
New:

    git cms-merge-topic vkhristenko:ecal_reco_cuda_head_tmp_withtimealgo
    
    
NB:

    you need to compile while being on the machine: 
    cmg-gpu1080.cern.ch
    
    
My code:

    mkdir ECALValidation
    cd ECALValidation/
    git clone git@github.com:amassiro/EcalLocalRecoToolKit.git

Config by Viktor

    /data/patatrack/vkhriste/cmssw_configs/raw2digi_ecalonly.py
    
    cmsRun raw2digi_ecalonly.py inputType=globalRun          year=2017      

    
Test file:

    
    nvidia-smi
    
 +-----------------------------------------------------------------------------+
| NVIDIA-SMI 410.72       Driver Version: 410.72       CUDA Version: 10.0     |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|===============================+======================+======================|
|   0  GeForce GTX 108...  Off  | 00000000:04:00.0 Off |                  N/A |
| 35%   61C    P2   206W / 250W |  10781MiB / 11178MiB |     27%      Default |
+-------------------------------+----------------------+----------------------+
|   1  GeForce GTX 108...  Off  | 00000000:05:00.0 Off |                  N/A |
| 23%   40C    P2    57W / 250W |   6304MiB / 11178MiB |      0%      Default |
+-------------------------------+----------------------+----------------------+
|   2  GeForce GTX 108...  Off  | 00000000:08:00.0 Off |                  N/A |
| 17%   29C    P0    56W / 250W |      0MiB / 11178MiB |      0%      Default |
+-------------------------------+----------------------+----------------------+
|   3  GeForce GTX 108...  Off  | 00000000:09:00.0 Off |                  N/A |
| 46%   77C    P2   228W / 250W |  10793MiB / 11178MiB |     96%      Default |
+-------------------------------+----------------------+----------------------+
|   4  GeForce GTX 108...  Off  | 00000000:83:00.0 Off |                  N/A |
| 19%   39C    P0    54W / 250W |      0MiB / 11178MiB |      6%      Default |
+-------------------------------+----------------------+----------------------+
|   5  GeForce GTX 108...  Off  | 00000000:84:00.0 Off |                  N/A |
| 23%   36C    P8     8W / 250W |  10695MiB / 11178MiB |      0%      Default |
+-------------------------------+----------------------+----------------------+
|   6  GeForce GTX 108...  Off  | 00000000:87:00.0 Off |                  N/A |
| 38%   65C    P2   242W / 250W |  10793MiB / 11178MiB |     56%      Default |
+-------------------------------+----------------------+----------------------+
|   7  GeForce GTX 108...  Off  | 00000000:88:00.0 Off |                  N/A |
| 27%   47C    P2    77W / 250W |  10795MiB / 11178MiB |      0%      Default |

    
     
    export CUDA_VISIBLE_DEVICES=1     ----> use the number 1

    cmsRun raw2digi_ecal.py inputType=globalRunHighPU          year=2017      

    
Data files:

    on cmg-gpu1080.cern.ch
    
    2018 high PU  --> /data/patatrack/dalfonso/data/2018/Run2018E_HLTPhysics_325308/FB454F42-97B6-DC4B-88FF-0063C79B9F6C.root
    2018 normal PU  --> /data/patatrack/dalfonso/data/2018/Run2018B_HLTPhysics_319300/D6C0583D-5881-E811-9EB8-FA163EAFECF2.root
    

Compare two reconstructions:

    cmsRun raw2digi_ecal_and_dump_compare.py inputType=globalRunStandardPU          year=2017         outputFile=StandardPU-compare.root
    
    r99t StandardPU-compare.root    plot/drawDifference.cxx
    
    r99t StandardPU-compare.root    plot/drawDifferenceAll.cxx
    
    
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"onlineEnergy\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"chi2\",200,0,10\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeM1\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeM2\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeM3\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeM4\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeM5\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeP1\",200,0,200\)    
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeP2\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeP3\",200,0,200\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"outOfTimeAmplitudeP4\",200,0,200\)
    
    
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"jitter\",400,-200,200,0\)
    r99t StandardPU-compare.root    plot/drawDifferenceOne.cxx\(\"jitter\",400,-200,200,2\)
    
    
    
    
    
//   float _onlineEnergyEB[61200];
//   float _chi2EB[61200];
//   float _jitterEB[61200];
//   float _amplitudeErrorEB[61200];
//   float _outOfTimeAmplitudeM1EB[61200];
//   float _outOfTimeAmplitudeM2EB[61200];
//   float _outOfTimeAmplitudeM3EB[61200];
//   float _outOfTimeAmplitudeM4EB[61200];
//   float _outOfTimeAmplitudeM5EB[61200];
//   float _outOfTimeAmplitudeP1EB[61200];
//   float _outOfTimeAmplitudeP2EB[61200];
//   float _outOfTimeAmplitudeP3EB[61200];
//   float _outOfTimeAmplitudeP4EB[61200];
 
 
 

    
Measure time and throughput
====


Prepare the cmsrun file to be run

    cmsRun raw2digi_ecal_cpu.py
    export CUDA_VISIBLE_DEVICES=1; cmsRun raw2digi_ecal_gpu.py
    
    edmConfigDump raw2digi_ecal_gpu.py > dump_ecal_gpu.py
    edmConfigDump raw2digi_ecal_cpu.py > dump_ecal_cpu.py

     
Download toolkit and run:

    git clone git@github.com:cms-patatrack/patatrack-scripts.git
    
    https://github.com/cms-patatrack/patatrack-scripts/


    nvprof cmsRun ECALValidation/EcalLocalRecoToolKit/test/dump_ecal_cpu.py  
         ---> cpu, nothing
    nvprof cmsRun ECALValidation/EcalLocalRecoToolKit/test/dump_ecal_gpu.py

    
    
Results:

     ==24999== Profiling application: cmsRun ECALValidation/EcalLocalRecoToolKit/test/dump_ecal_gpu.py 
     ==24999== Profiling result:
            Type  Time(%)      Time     Calls       Avg       Min       Max  Name
     GPU activities:   99.81%  86.2914s       200  431.46ms  2.1945ms  790.87ms  ecal::multifit::kernel_reconstruct(unsigned short const *, unsigned int const *, EcalPedestal const *, EcalMGPAGainRatio const *, EcalXtalGroupId const *, EcalPulseShape const *, EcalPulseCovariance const *, EcalUncalibratedRecHit*, Eigen::Matrix<double, int=10, int=10, int=0, int=10, int=10> const *, unsigned int)
                    0.19%  161.50ms      1800  89.722us  1.0880us  4.9233ms  [CUDA memcpy HtoD]
                    0.01%  4.6880ms       200  23.440us  4.1600us  41.538us  [CUDA memcpy DtoH]
      API calls:   35.50%  217.799s      1800  121.00ms  8.6400us  3.01056s  cudaMalloc
                   32.20%  197.539s      2000  98.769ms  11.101us  3.03407s  cudaMemcpy
                   15.97%  97.9850s      1800  54.436ms  7.6110us  3.03822s  cudaFree
                   15.05%  92.3316s       200  461.66ms  2.1912ms  1.51643s  cudaDeviceSynchronize
                    1.27%  7.79243s       200  38.962ms  23.713us  1.52196s  cudaLaunchKernel
                    0.00%  1.8430ms        96  19.198us     233ns  831.23us  cuDeviceGetAttribute
                    0.00%  1.1869ms       800  1.4830us     215ns  21.207us  cudaGetLastError
                    0.00%  345.17us         1  345.17us  345.17us  345.17us  cuDeviceTotalMem
                    0.00%  248.70us         1  248.70us  248.70us  248.70us  cuDeviceGetName
                    0.00%  12.174us         1  12.174us  12.174us  12.174us  cuDeviceGetPCIBusId
                    0.00%  3.5990us         3  1.1990us     334ns  2.6400us  cuDeviceGetCount
                    0.00%  1.6740us         2     837ns     286ns  1.3880us  cuDeviceGet
                    0.00%     427ns         1     427ns     427ns     427ns  cuDeviceGetUuid
    

    https://developer.nvidia.com/nvidia-visual-profiler
    
    
    
Other:
    
    ./patatrack-scripts/benchmark ECALValidation/EcalLocalRecoToolKit/test/dump_ecal_cpu.py 
    ./patatrack-scripts/benchmark ECALValidation/EcalLocalRecoToolKit/test/dump_ecal_gpu.py 

    
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

     
     
     
         
Prepare single rechit dataset (by Vincenzo)
====

First prepare sample with digis

    cmsRun raw2onlydigi_ecal.py    inputType=globalRunStandardPU          year=2017 



    
    
    