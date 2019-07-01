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
        
        salloc -p gpu --nodes=1 --exclusive --gres=gpu:2 --constraint=v100
        
        srun hostname
        
        then ssh there ->
        
    
    
Perform the scan:

    Download toolkit and run:

    git clone git@github.com:cms-patatrack/patatrack-scripts.git
    git clone https://github.com/cms-patatrack/patatrack-scripts.git
     
    https://github.com/cms-patatrack/patatrack-scripts/

    mkdir ECALValidation
    cd ECALValidation/
    git clone git@github.com:amassiro/EcalLocalRecoToolKit.git
    
    ./patatrack-scripts/benchmark ECALValidation/EcalLocalRecoToolKit/test/gpu/ecalOnly_gpu_FI.py

    
    

    
    
New version (next tests):

    ecal_patatrack_v2_head
    
    git cms-merge-topic ecal_patatrack_v2_head
    
    
    
    
 
 
 
 
 