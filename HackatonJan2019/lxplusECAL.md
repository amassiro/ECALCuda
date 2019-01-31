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
 
 
 

    
    
    
    
    
    