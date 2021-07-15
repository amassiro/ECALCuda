

void plotPulses() {
  
  TCanvas* cc_EB = new TCanvas ("cc_EB", "", 800, 600);
  
  TTree* tree = (TTree*) _file0->Get("PulseTreeProducer/tree");
  
  
  UInt_t          run;
  UShort_t        lumi;
  UShort_t        bx;
  UInt_t          event;
  Float_t         digi_ped_subtracted_EB[612000];
  Float_t         amplitude_EB[61200];
  Float_t         amplitude_second_EB[61200];
  Float_t         chi2_EB[61200];
  Float_t         chi2_second_EB[61200];
  Float_t         amplitudeError_EB[61200];
  Float_t         amplitudeError_second_EB[61200];
  Int_t           ieta[61200];
  Int_t           iphi[61200];
  Float_t         digi_ped_subtracted_EE[146480];
  Float_t         amplitude_EE[14648];
  Float_t         amplitude_second_EE[14648];
  Float_t         chi2_EE[14648];
  Float_t         chi2_second_EE[14648];
  Float_t         amplitudeError_EE[14648];
  Float_t         amplitudeError_second_EE[14648];
  Int_t           ix[14648];
  Int_t           iy[14648];
  Int_t           iz[14648];
  Int_t           size_EB;
  Int_t           size_EE;


  tree->SetBranchAddress("run", &run);
  tree->SetBranchAddress("lumi", &lumi);
  tree->SetBranchAddress("bx", &bx);
  tree->SetBranchAddress("event", &event);
  tree->SetBranchAddress("digi_ped_subtracted_EB", digi_ped_subtracted_EB);
  tree->SetBranchAddress("amplitude_EB", amplitude_EB);
  tree->SetBranchAddress("amplitude_second_EB", amplitude_second_EB);
  tree->SetBranchAddress("chi2_EB", chi2_EB);
  tree->SetBranchAddress("chi2_second_EB", chi2_second_EB);
  tree->SetBranchAddress("amplitudeError_EB", amplitudeError_EB);
  tree->SetBranchAddress("amplitudeError_second_EB", amplitudeError_second_EB);
  tree->SetBranchAddress("ieta", ieta);
  tree->SetBranchAddress("iphi", iphi);
  tree->SetBranchAddress("digi_ped_subtracted_EE", digi_ped_subtracted_EE);
  tree->SetBranchAddress("amplitude_EE", amplitude_EE);
  tree->SetBranchAddress("amplitude_second_EE", amplitude_second_EE);
  tree->SetBranchAddress("chi2_EE", chi2_EE);
  tree->SetBranchAddress("chi2_second_EE", chi2_second_EE);
  tree->SetBranchAddress("amplitudeError_EE", amplitudeError_EE);
  tree->SetBranchAddress("amplitudeError_second_EE", amplitudeError_second_EE);
  tree->SetBranchAddress("ix", ix);
  tree->SetBranchAddress("iy", iy);
  tree->SetBranchAddress("iz", iz);
  tree->SetBranchAddress("size_EB", &size_EB);
  tree->SetBranchAddress("size_EE", &size_EE);
  
  
  int MAXEVENTS=1;
  
  for (int ievent = 0; ievent<MAXEVENTS; ievent++) {
    tree->GetEntry(ievent);
    
    
  }
  
  
  
}

