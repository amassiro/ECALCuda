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
  for (int i=0;i<200;i++) color[i] = TColor::GetColorBright(i+1);
  
  
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



void setupTH(TH1F* histo, int icolor) {
  
  Int_t color[200];
  for (int i=0;i<200;i++) color[i] = TColor::GetColorBright(i+1);
   
  histo->SetLineWidth(2);
  histo->SetLineColor(color[icolor]);
//   histo->SetMarkerColor(color[icolor]);
//   histo->SetMarkerSize(1);
//   histo->SetMarkerStyle(20+icolor);
}





void plotCompare() {
  
  
  gStyle->SetOptStat(0);
  
  
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
  
  int MAXEVENTS=1000;  
  int MAXPULSES = 20;
  TGraph* graphs_pulses_EB[MAXPULSES];
  float EB_value[MAXPULSES];
  float EB_value_second[MAXPULSES];
  
  int iPulse_EB = 0;
  
  float threshold = 0.0001; //0.1; // 0.01; // relative difference
  float threshold_max = 0.0002; // 0.01; // relative difference
  
  
  MAXEVENTS = std::min(MAXEVENTS, (int) (tree->GetEntries()));
  
  std::cout << " MAXEVENTS = " << MAXEVENTS << std::endl;
  
  std::vector<int> thresholds = {0, 1, 3, 5};
  
  TH1F* histo_ratio_CPUminusGPUoverGPU_EB[thresholds.size()];
  TH1F* histo_ratio_CPUminusGPUoverGPU_EE[thresholds.size()];

  TH1F* histo_mod_ratio_CPUminusGPUoverGPU_EB[thresholds.size()];
  TH1F* histo_mod_ratio_CPUminusGPUoverGPU_EE[thresholds.size()];
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    TString name_Histo; name_Histo.Form("histo_ratio_CPUoverGPU_EB_%d", ith);
    TString description_Histo; description_Histo.Form("(CPU-GPU)/CPU EB adc>%d", thresholds[ith]);   
    histo_ratio_CPUminusGPUoverGPU_EB[ith] = new TH1F (name_Histo.Data(), description_Histo.Data(), 1000, -0.3, 0.3 );
  }
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    TString name_Histo; name_Histo.Form("histo_ratio_CPUoverGPU_EE_%d", ith);
    TString description_Histo; description_Histo.Form("(CPU-GPU)/CPU EE adc>%d", thresholds[ith]);   
    histo_ratio_CPUminusGPUoverGPU_EE[ith] = new TH1F (name_Histo.Data(), description_Histo.Data(), 1000, -0.3, 0.3 );
  }
  
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    TString name_Histo; name_Histo.Form("histo_mod_ratio_CPUoverGPU_EB_%d", ith);
    TString description_Histo; description_Histo.Form("|(CPU-GPU)|/CPU EB adc>%d", thresholds[ith]);   
    histo_mod_ratio_CPUminusGPUoverGPU_EB[ith] = new TH1F (name_Histo.Data(), description_Histo.Data(), 20000, 0.0, 0.2 );
  }
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    TString name_Histo; name_Histo.Form("histo_mod_ratio_CPUoverGPU_EE_%d", ith);
    TString description_Histo; description_Histo.Form("|(CPU-GPU)|/CPU EE adc>%d", thresholds[ith]);   
    histo_mod_ratio_CPUminusGPUoverGPU_EE[ith] = new TH1F (name_Histo.Data(), description_Histo.Data(), 20000, 0.0, 0.2 );
  }
  
  
  
  TH2F* histoEB = new TH2F ("histoEB", "EB" ,  360, 0.5, 360.5,  171, -85.5, 85.5);
  histoEB->GetXaxis()->SetTitle("i#phi");
  histoEB->GetYaxis()->SetTitle("i#eta");
  
  TH2F* histoEE = new TH2F ("histoEE", "EE" ,  200, 0.5, 200.5,  100, 0.5, 100.5);
  histoEE->GetXaxis()->SetTitle("x");
  histoEE->GetYaxis()->SetTitle("y");
  
  
  
  
  
  
  for (int ievent = 0; ievent<MAXEVENTS; ievent++) {
    tree->GetEntry(ievent);
    
    for (int iEBchannel = 0; iEBchannel<61200; iEBchannel++) {
      for (int ith = 0; ith<thresholds.size(); ith++) {     
        if (amplitude_EB[iEBchannel] > thresholds[ith]) {
          histo_ratio_CPUminusGPUoverGPU_EB[ith]->Fill( (amplitude_EB[iEBchannel]-amplitude_second_EB[iEBchannel])/amplitude_EB[iEBchannel]);   
          histo_mod_ratio_CPUminusGPUoverGPU_EB[ith]->Fill( fabs(amplitude_EB[iEBchannel]-amplitude_second_EB[iEBchannel])/amplitude_EB[iEBchannel]);   

          if (fabs(amplitude_EB[iEBchannel]-amplitude_second_EB[iEBchannel])/amplitude_EB[iEBchannel] > 0.0001) {
            histoEB->Fill(iphi[iEBchannel], ieta[iEBchannel], 1);
          } 
          
        }      
        
        
      }
    }

    
    for (int iEEchannel = 0; iEEchannel<14648; iEEchannel++) {
      for (int ith = 0; ith<thresholds.size(); ith++) {     
        if (amplitude_EE[iEEchannel] > thresholds[ith]) {
          histo_ratio_CPUminusGPUoverGPU_EE[ith]->Fill( (amplitude_EE[iEEchannel]-amplitude_second_EE[iEEchannel])/amplitude_EE[iEEchannel]);   
          histo_mod_ratio_CPUminusGPUoverGPU_EE[ith]->Fill( fabs(amplitude_EE[iEEchannel]-amplitude_second_EE[iEEchannel])/amplitude_EE[iEEchannel]);   
          if (fabs(amplitude_EE[iEEchannel]-amplitude_second_EE[iEEchannel])/amplitude_EE[iEEchannel] > 0.0001) {
            histoEE->Fill(ix[iEEchannel] + 100*(iz[iEEchannel]>0), iy[iEEchannel], 1);
          } 

        }
        
        
      }
    }    
      
  }
  
  
  
  
  TCanvas* cc_Map_EB = new TCanvas ("cc_Map_EB", "", 800, 600);
  
  cc_Map_EB->cd();
  histoEB->Draw("colz");
   
  
  
  TCanvas* cc_Map_EE = new TCanvas ("cc_Map_EE", "", 800, 600);
  
  cc_Map_EE->cd();
  histoEE->Draw("colz");
  
  
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    setupTH( histo_ratio_CPUminusGPUoverGPU_EB[ith], ith );
    setupTH( histo_ratio_CPUminusGPUoverGPU_EE[ith], ith );
    setupTH( histo_mod_ratio_CPUminusGPUoverGPU_EB[ith], ith );
    setupTH( histo_mod_ratio_CPUminusGPUoverGPU_EE[ith], ith );
  }
  
  
  
  
  
  
  TCanvas* cc_EB = new TCanvas ("cc_EB", "", 800, 600);
  
  TLegend* leg_EB = new TLegend (0.8, 1.0, 0.8, 1.0);
  
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    if (ith==0) histo_ratio_CPUminusGPUoverGPU_EB[ith] -> DrawNormalized();
    else        histo_ratio_CPUminusGPUoverGPU_EB[ith] -> DrawNormalized("same");
  
    leg_EB->AddEntry(histo_ratio_CPUminusGPUoverGPU_EB[ith],      TString::Format(">%d ADC      #mu = %.1f ; #sigma = %.2e", thresholds[ith], histo_ratio_CPUminusGPUoverGPU_EB[ith]->GetMean(), histo_ratio_CPUminusGPUoverGPU_EB[ith]->GetRMS()));
  }
  
  leg_EB->Draw();
  
  cc_EB->SetLogy();
  
  
  
  
  TCanvas* cc_EE = new TCanvas ("cc_EE", "", 800, 600);
  
  TLegend* leg_EE = new TLegend (0.8, 1.0, 0.8, 1.0);
  
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    if (ith==0) histo_ratio_CPUminusGPUoverGPU_EE[ith] -> DrawNormalized();
    else        histo_ratio_CPUminusGPUoverGPU_EE[ith] -> DrawNormalized("same");
    
    leg_EE->AddEntry(histo_ratio_CPUminusGPUoverGPU_EE[ith],      TString::Format(">%d ADC      #mu = %.1f ; #sigma = %.2e", thresholds[ith], histo_ratio_CPUminusGPUoverGPU_EE[ith]->GetMean(), histo_ratio_CPUminusGPUoverGPU_EE[ith]->GetRMS()));
  }
  
  leg_EE->Draw();
  
  cc_EE->SetLogy();
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  TCanvas* cc_mod_EB = new TCanvas ("cc_mod_EB", "", 800, 600);
  
  TLegend* leg_mod_EB = new TLegend (0.8, 1.0, 0.8, 1.0);
  
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    if (ith==0) histo_mod_ratio_CPUminusGPUoverGPU_EB[ith] -> Draw();
    else        histo_mod_ratio_CPUminusGPUoverGPU_EB[ith] -> Draw("same");
    
    leg_mod_EB->AddEntry(histo_mod_ratio_CPUminusGPUoverGPU_EB[ith],      TString::Format(">%d ADC      #mu = %.1f ; #sigma = %.2e", thresholds[ith], histo_mod_ratio_CPUminusGPUoverGPU_EB[ith]->GetMean(), histo_mod_ratio_CPUminusGPUoverGPU_EB[ith]->GetRMS()));
  }
  
  leg_mod_EB->Draw();
  
  cc_mod_EB->SetLogy();
  cc_mod_EB->SetLogx();
  
  
  
  
  TCanvas* cc_mod_EE = new TCanvas ("cc_mod_EE", "", 800, 600);
  
  TLegend* leg_mod_EE = new TLegend (0.8, 1.0, 0.8, 1.0);
  
  
  for (int ith = 0; ith<thresholds.size(); ith++) {
    if (ith==0) histo_mod_ratio_CPUminusGPUoverGPU_EE[ith] -> Draw();
    else        histo_mod_ratio_CPUminusGPUoverGPU_EE[ith] -> Draw("same");
    
    leg_mod_EE->AddEntry(histo_mod_ratio_CPUminusGPUoverGPU_EE[ith],      TString::Format(">%d ADC      #mu = %.1f ; #sigma = %.2e", thresholds[ith], histo_mod_ratio_CPUminusGPUoverGPU_EE[ith]->GetMean(), histo_mod_ratio_CPUminusGPUoverGPU_EE[ith]->GetRMS()));
  }
  
  leg_mod_EE->Draw();
  
  cc_mod_EE->SetLogy();
  cc_mod_EE->SetLogx();
  
  
  
  
}


