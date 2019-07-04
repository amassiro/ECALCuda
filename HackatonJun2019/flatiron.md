Test on flatiron
====

Logic:

- laptop -> machine -> rusty -> resources

Instructions:

- google-authenticator

    http://www.nongnu.org/oath-toolkit/

    sudo apt-get install libxmlsec1-dev

    /home/amassiro/Downloads/oath-toolkit-2.6.1
    ./configure
    make
    make install
    
    or
    
    https://play.google.com/store/apps/details?id=com.google.android.apps.authenticator2&hl=it
    or "authy"
    
    
    
    
    
- login

    amassironi
    
    https://docs.simonsfoundation.org/index.php/RemoteConnect#ssh.2Fscp_instructions
    
    ssh ...
    
    use the password and the code from the phone
    
    
- go to runsty

    ssh amassironi@rusty
    
- load cmssw

    //   cp /mnt/home/vkhristenko/cms_envs.sh .
    
    source /mnt/home/amassironi/cms_envs.sh
 

- slurm is a submission system

    //   cp /mnt/home/vkhristenko/slurm_cmds.md .
    - `sinfo -Nel -p gpu` list nodes from `gpu` partition
    - `salloc -p gpu --nodes=1 --exclusive --gres=gpu:2 --constraint=v100`
    
    module add slurm
    
    https://docs.simonsfoundation.org/index.php/Public:SlurmNotes
    
    
    
Install cmssw

    cd /mnt/home/amassironi/cmssw_releases
    
    cmsrel CMSSW_10_6_0_Patatrack
    
    cmsenv
    
    git cms-init -x cms-patatrack

    // get the head 
    
    git branch CMSSW_10_6_X_Patatrack --track cms-patatrack/CMSSW_10_6_X_Patatrack

    git checkout cms-patatrack/CMSSW_10_6_X_Patatrack -b my_development_branch

    # check out the modified packages and their dependencies
    git cms-addpkg $(git diff $CMSSW_VERSION --name-only | cut -d/ -f-2 | sort -u)
    git cms-checkdeps -a
    
    scramv1 b -j 10
    
    --> compile on the node is faster than on rusty!
    
        module add slurm
        
        sinfo -Nel -p gpu
        --> check which resources are avilable
        
        salloc -p gpu --nodes=1 --exclusive --gres=gpu:2 --constraint=v100

        salloc -p gpu --nodes=1 --exclusive --gres=gpu:1 --constraint=v100

        salloc -p gpu --nodes=1 --exclusive --gres=gpu:1 --constraint=p100

        salloc -p gpu --nodes=1 --gres=gpu:1 -c 16 --constraint=v100
        ---> 16 cores I requested (-c 16)
        ---> share the machine, but cpu will belong on my
            -> to see which cpus are ok for me: 
                taskset -c -p $$
                     -->   these cores are all for me!   "pid 2464852's current affinity list: 6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36"
        
        
        srun hostname
        
        then ssh there ->
        
to free resources:

    squeue  | grep amassi
    scancel <job id>
    
    
    
Perform the scan:

    /mnt/home/amassironi/cmssw_releases/v1/CMSSW_10_6_0_Patatrack/src

   
    Download toolkit and run:

    git clone git@github.com:cms-patatrack/patatrack-scripts.git
    git clone https://github.com/cms-patatrack/patatrack-scripts.git
     
    https://github.com/cms-patatrack/patatrack-scripts/

    mkdir ECALValidation
    cd ECALValidation/
    git clone git@github.com:amassiro/EcalLocalRecoToolKit.git
    
    export CUDA_VISIBLE_DEVICES=0;  cmsRun  ECALValidation/EcalLocalRecoToolKit/test/gpu/ecalOnly_gpu_FI.py
    
    edmConfigDump ecalOnly_gpu_FI.py > dump_ecal_gpu.py

    export CUDA_VISIBLE_DEVICES=0;  cmsRun  ECALValidation/EcalLocalRecoToolKit/test/gpu/dump_ecal_gpu.py
    export CUDA_VISIBLE_DEVICES=0;  cmsRun  ecalOnly.py
    
    
    ./patatrack-scripts/benchmark ECALValidation/EcalLocalRecoToolKit/test/gpu/dump_ecal_gpu.py
    export CUDA_VISIBLE_DEVICES=0;  ../patatrack-scripts/benchmark  ecalOnly.py
    
    
    
          Tesla P100-PCIE-16GB 
    
          Running 4 times over 4200 events with 1 jobs, each with 8 threads, 8 streams and 1 GPUs
             258.1 ±   1.4 ev/s (4000 events)
             247.6 ±   0.7 ev/s (4000 events)
             249.0 ±   0.5 ev/s (4000 events)
             249.4 ±   0.5 ev/s (4000 events)
           --------------------
             251.0 ±   4.8 ev/s
    
    

    export CUDA_VISIBLE_DEVICES=0;  ../patatrack-scripts/scan  ecalOnly.py

    
    
    
    
New version (V2):
    
    New branch: ecal_patatrack_v2_head rebased on top of CMSSW_10_6_X_Patatrack
    
    /mnt/home/amassironi/cmssw_releases/v2/

    /mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src

    ecal_patatrack_v2_head

    cmsrel CMSSW_10_6_0_Patatrack
    cmsenv
    git cms-init -x cms-patatrack

    // get the head 
    git branch CMSSW_10_6_X_Patatrack --track cms-patatrack/CMSSW_10_6_X_Patatrack
    git checkout cms-patatrack/CMSSW_10_6_X_Patatrack -b my_development_branch

    # check out the modified packages and their dependencies
    git cms-addpkg $(git diff $CMSSW_VERSION --name-only | cut -d/ -f-2 | sort -u)
    git cms-checkdeps -a

    git cms-merge-topic vkhristenko:ecal_patatrack_v2_head
    
    process.ecalUncalibRecHitProducerGPU.kernelsVersion = 0
    ---> to be added to ecalonly.py.    0, 1, 2, 3, 4 to be tested
    
 
 
    export CUDA_VISIBLE_DEVICES=0;  ../patatrack-scripts/scan  ecalOnly.py
    
    
    //pin
    
    CUDA_VISIBLE_DEVICES=0 taskset -c 0-39:2  ../../patatrack-scripts/scan  ecal_gpu_only.py
    
    CUDA_VISIBLE_DEVICES=0 taskset -c 0-39:2  ../../patatrack-scripts/scan  ecal_gpu_only_unpacker.py

    CUDA_VISIBLE_DEVICES=0 taskset -c 0-39:2  ../../patatrack-scripts/scan  ecal_gpu_only_read_data.py
    
    
    
    
Plotting: 
 
    ./plot_scan.py  scan.from_1_to_12_v100_exclusively_only_read_data.csv \
                    scan.from_1_to_12_v100_exclusively_only_unpacker.csv \
                    scan.from_1_to_12_v100_exclusively_V1_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k0_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k1_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k2_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k3_with_tc.csv

    ./plot_scan.py  scan.from_1_to_12_v100_exclusively_only_read_data.csv \
                    scan.from_1_to_12_v100_exclusively_only_unpacker.csv \
                    scan.from_1_to_12_v100_exclusively_cpu_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V1_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k0_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k1_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k2_with_tc.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k3_with_tc.csv
 

 
    ./plot_scan.py  scan.from_1_to_12_v100_exclusively_only_read_data_jetht.csv \
                    scan.from_1_to_12_v100_exclusively_only_unpacker_jetht.csv \
                    scan.from_1_to_12_v100_exclusively_V1_with_tc_jetht.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k2_with_tc_jetht.csv \
                    scan.from_1_to_12_v100_exclusively_V2_k3_with_tc_jetht.csv
 
 
 
 
     ./plot_scan.py  scan.from_1_to_12_v100_exclusively_only_read_data_jetht.csv \
                     scan.from_1_to_12_v100_exclusively_only_read_data.csv 
 
     ./plot_scan.py  scan.from_1_to_12_v100_exclusively_only_unpacker_jetht.csv \
                     scan.from_1_to_12_v100_exclusively_only_unpacker.csv 
 
     ./plot_scan.py  scan.from_1_to_12_v100_exclusively_V2_k3_with_tc_jetht.csv \
                     scan.from_1_to_12_v100_exclusively_V2_k3_with_tc.csv 
 
     ./plot_scan.py  scan.from_1_to_12_v100_exclusively_V2_k2_with_tc_jetht.csv \
                     scan.from_1_to_12_v100_exclusively_V2_k2_with_tc.csv 

     ./plot_scan.py  scan.from_1_to_12_v100_exclusively_V2_k1_with_tc_jetht.csv \
                     scan.from_1_to_12_v100_exclusively_V2_k1_with_tc.csv 

     ./plot_scan.py  scan.from_1_to_12_v100_exclusively_V2_k0_with_tc_jetht.csv \
                     scan.from_1_to_12_v100_exclusively_V2_k0_with_tc.csv 
                     
 
 
 
     ./plot_scan.py  scan.allFED_run321177.csv \
                     scan.EcalFED_run321177.csv 
                     
 
 
     ./plot_scan.py  scan.allFED_run321177_EcalLocalReco_k0.csv \
                     scan.EcalFED_run321177_EcalLocalReco_k0.csv
 
 
     ./plot_scan.py  scan.allFED_run321177_EcalLocalReco_k1.csv \
                     scan.EcalFED_run321177_EcalLocalReco_k1.csv
 
     ./plot_scan.py  scan.allFED_run321177_EcalLocalReco_k2.csv \
                     scan.EcalFED_run321177_EcalLocalReco_k2.csv
 
     --> different node
     ./plot_scan.py  scan.allFED_run321177_EcalLocalReco_k3.csv \
                     scan.EcalFED_run321177_EcalLocalReco_k3.csv

     ./plot_scan.py  scan.allFED_run321177_EcalLocalReco_k4.csv \
                     scan.EcalFED_run321177_EcalLocalReco_k4.csv
 
 
     ./plot_scan.py  scan.EcalFED_run321177_EcalLocalReco_k0.csv   \
                     scan.EcalFED_run321177_EcalLocalReco_k1.csv   \
                     scan.EcalFED_run321177_EcalLocalReco_k2.csv   \
                     scan.EcalFED_run321177_EcalLocalReco_k3.csv   \
                     scan.EcalFED_run321177.csv 
 
 
 
 
 
 
 
 
 
 
 