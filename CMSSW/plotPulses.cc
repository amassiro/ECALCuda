

void plotPulses() {
  
  TCanvas* cc_EB = new TCanvas ("cc_EB", "", 800, 600);
  
  TTree* tree = (TTree*) _file0->Get("PulseTreeProducer/tree");
  
  
  tree->Draw("digi_ped_subtracted_EB", "digi_ped_subtracted_EB>0");
  
  
  
}

