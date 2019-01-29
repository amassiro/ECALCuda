On lxplus:

     lxplus

     /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/CMSSW_10_3_2/src -----> slc6, not good

     /afs/cern.ch/user/a/amassiro/work/ECAL/GPU/onGPU/CMSSW_10_3_2/src

Machine:

    cmg-gpu1080.cern.ch
    ssh -X amassiro@cmg-gpu1080.cern.ch
     
First time:

    git cms-init

    git cms-merge-topic vkhristenko:hcal_cuda_1

    https://github.com/vkhristenko/cmssw/tree/hcal_cuda_1

    cd ../config/toolbox/slc6_amd64_gcc700/tools/selected/
    cd ../config/toolbox/slc7_amd64_gcc700/tools/selected/
    
    cp /data/patatrack/vkhriste/cmssw_releases/CMSSW_10_3_X_2018-12-13-2300/config/toolbox/slc7_amd64_gcc700/tools/selected/eigen.xml .
    
    scramv1 b -j 20
    
NB:

    you need to compile while being on the machine: 
    cmg-gpu1080.cern.ch
    
    
Test file:

    cp /data/patatrack/vkhriste/cmssw_configs/raw2digi_hcal_ecal.py .
    
    cmsRun raw2digi_hcal_ecal.py
    
    
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
    cmsRun raw2digi_hcal_ecal.py inputType=globalRun year=2017

    cmsRun raw2digi_hcal_ecal_and_dump.py inputType=globalRunStandardPU      year=2017          outputFile=StandardPU.root
    cmsRun raw2digi_hcal_ecal_and_dump.py inputType=globalRunHighPU          year=2017          outputFile=HighPU.root
    
    cmsRun raw2digi_hcal_ecal.py inputType=globalRunStandardPU      year=2017      
    cmsRun raw2digi_hcal_ecal.py inputType=globalRunHighPU          year=2017      

    
Low pileup

    TimeReport   0.006541     0.006541     0.006541  ecalDigis
    TimeReport   0.051693     0.051693     0.051693  ecalMultiFitUncalibRecHit
    
    
High pileup

    TimeReport   0.012503     0.012503     0.012503  ecalDigis
    TimeReport   0.415560     0.415560     0.415560  ecalMultiFitUncalibRecHit

    
    
Data files:

    on cmg-gpu1080.cern.ch
    
    2018 high PU  --> /data/patatrack/dalfonso/data/2018/Run2018E_HLTPhysics_325308/FB454F42-97B6-DC4B-88FF-0063C79B9F6C.root
    2018 normal PU  --> /data/patatrack/dalfonso/data/2018/Run2018B_HLTPhysics_319300/D6C0583D-5881-E811-9EB8-FA163EAFECF2.root
    

Compare two reconstructions:

    cmsRun raw2digi_hcal_ecal_and_dump_compare.py inputType=globalRunStandardPU      year=2017          outputFile=StandardPU-compare.root


    
    