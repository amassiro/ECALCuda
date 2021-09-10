#include  <algorithm>


void setupTGraph(TGraph* histo, int icolor) {
  
//   Int_t color[100];
//   Double_t Red[]    = {0., 0.0, 1.0, 1.0, 1.0};
//   Double_t Green[]  = {0., 0.0, 0.0, 1.0, 1.0};
//   Double_t Blue[]   = {0., 1.0, 0.0, 0.0, 1.0};
//   Double_t Length[] = {0., .25, .50, .75, 1.0};
//   Int_t FI = TColor::CreateGradientColorTable(5, Length, Red, Green, Blue, 100);
//   for (int i=0;i<100;i++) color[i] = FI+i;
  

  Int_t color[200];
  for (int i=0;i<200;i++) color[i] = TColor::GetColorBright(i);
  
   
//   Color_t* color = new Color_t [200];
//   color[0] = kRed ;
//   color[1] = kAzure + 10 ;
//   color[2] = kYellow + 2 ;
//   color[3] = kGreen ;
//   color[4] = kGreen + 4 ;
//   color[5] = kBlue ;
//   color[6] = kCyan ;
//   color[7] = kPink + 1 ;
//   color[8] = kBlack ;
//   color[9] = kYellow + 4 ;
//   for (int i=0; i<30; i++) {
//     color[i+10] = kBlue + i;
//   }
  
  
  
  histo->SetLineWidth(2);
  histo->SetLineColor(color[icolor]);
  histo->SetMarkerColor(color[icolor]);
  histo->SetMarkerSize(1);
  histo->SetMarkerStyle(20+icolor);
}





void plotPulses() {
  
  TCanvas* cc_EB = new TCanvas ("cc_EB", "EB", 800, 600);
  
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
  
  
  int MAXPULSES = 100;
  TGraph* graphs_pulses_EB[MAXPULSES];
  int iPulse_EB = 0;
  
  float threshold = 0.1; // 0.01; // relative difference
  
  int MAXEVENTS=1000;
  
  MAXEVENTS = std::min(MAXEVENTS, (int) (tree->GetEntries()));
  
  std::cout << " MAXEVENTS = " << MAXEVENTS << std::endl;
  
  for (int ievent = 0; ievent<MAXEVENTS; ievent++) {
    tree->GetEntry(ievent);
    
    for (int iEBchannel = 0; iEBchannel<61200; iEBchannel++) {
      if (amplitude_EB[iEBchannel] > 1) {
        //
        // do the plot only when the two reconstruction algorithms give different values
        //
        
//         std::cout << "amplitude_EB[iEBchannel] - amplitude_second_EB[iEBchannel] = " << amplitude_EB[iEBchannel] - amplitude_second_EB[iEBchannel] << " = " <<  amplitude_EB[iEBchannel] << " - " <<  amplitude_second_EB[iEBchannel] << std::endl;
        if ( fabs((amplitude_EB[iEBchannel] - amplitude_second_EB[iEBchannel]) / amplitude_EB[iEBchannel]) > threshold) {
          std::cout << "amplitude_EB[" << iEBchannel << "] - amplitude_second_EB[" << iEBchannel << "] = " << amplitude_EB[iEBchannel] - amplitude_second_EB[iEBchannel] << " = " <<  amplitude_EB[iEBchannel] << " - " <<  amplitude_second_EB[iEBchannel] << std::endl;          
          if (iPulse_EB < MAXPULSES) {
            graphs_pulses_EB[iPulse_EB] = new TGraph();
            for (int iSample = 0; iSample < 10; iSample++) {
              //       hashedIndex() *10 + iSample
              graphs_pulses_EB[iPulse_EB]->SetPoint(iSample, iSample, digi_ped_subtracted_EB[iEBchannel*10+iSample] );
            }
            iPulse_EB++;
          }
        
        }
        
      }   
    }
    
  }
  
  
  
  
  TGraph* graphs_pulses_EE[MAXPULSES];
  
  int iPulse_EE = 0;
  
  for (int ievent = 0; ievent<MAXEVENTS; ievent++) {
    tree->GetEntry(ievent);
    
    for (int iEEchannel = 0; iEEchannel<14648; iEEchannel++) {
      if (amplitude_EE[iEEchannel] > 1) {
        //
        // do the plot only when the two reconstruction algorithms give different values
        //
        
        //         std::cout << "amplitude_EE[iEEchannel] - amplitude_second_EE[iEEchannel] = " << amplitude_EE[iEEchannel] - amplitude_second_EE[iEEchannel] << " = " <<  amplitude_EE[iEEchannel] << " - " <<  amplitude_second_EE[iEEchannel] << std::endl;
        if ( fabs((amplitude_EE[iEEchannel] - amplitude_second_EE[iEEchannel]) / amplitude_EE[iEEchannel]) > threshold) {
          std::cout << "amplitude_EE[" << iEEchannel << "] - amplitude_second_EE[" << iEEchannel << "] = " << amplitude_EE[iEEchannel] - amplitude_second_EE[iEEchannel] << " = " <<  amplitude_EE[iEEchannel] << " - " <<  amplitude_second_EE[iEEchannel] << std::endl;
          if (iPulse_EE < MAXPULSES) {
            graphs_pulses_EE[iPulse_EE] = new TGraph();
            for (int iSample = 0; iSample < 10; iSample++) {
              //       hashedIndex() *10 + iSample
              graphs_pulses_EE[iPulse_EE]->SetPoint(iSample, iSample, digi_ped_subtracted_EE[iEEchannel*10+iSample] );
            }
            iPulse_EE++;
          }
          
        }
        
      }   
    }
    
  }

  // plot
  
  std::cout << " iPulse = " << iPulse_EB << std::endl;
  
  TMultiGraph* mg_EB = new TMultiGraph();
  for (int ip = 0; ip<iPulse_EB; ip++) {
    setupTGraph( graphs_pulses_EB[ip], ip);
    mg_EB->Add( graphs_pulses_EB[ip] );
  }
  
  mg_EB->Draw("apl");
  mg_EB->GetYaxis()->SetTitle("ADC");
  mg_EB->GetXaxis()->SetTitle("BX");
  
  
  
  TCanvas* cc_EE = new TCanvas ("cc_EE", "EE", 800, 600);
  
  std::cout << " iPulse = " << iPulse_EE << std::endl;
  
  TMultiGraph* mg_EE = new TMultiGraph();
  for (int ip = 0; ip<iPulse_EE; ip++) {
    setupTGraph( graphs_pulses_EE[ip], ip);
    mg_EE->Add( graphs_pulses_EE[ip] );
  }
  
  mg_EE->Draw("apl");
  mg_EE->GetYaxis()->SetTitle("ADC");
  mg_EE->GetXaxis()->SetTitle("BX");
  
    
}


