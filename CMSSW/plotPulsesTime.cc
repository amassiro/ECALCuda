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





void plotPulsesTime() {
  
  TCanvas* cc_EB = new TCanvas ("cc_EB", "EB", 800, 600);
  
  TTree* tree = (TTree*) _file0->Get("PulseTreeProducer/tree");
  
  UInt_t          run;
  UShort_t        lumi;
  UShort_t        bx;
  UInt_t          event;
  Float_t         digi_ped_subtracted_EB[612000];
  Float_t         amplitude_EB[61200];
  Float_t         amplitude_second_EB[61200];
  Float_t         time_EB[61200];
  Float_t         time_second_EB[61200];
  Float_t         chi2_EB[61200];
  Float_t         chi2_second_EB[61200];
  Float_t         amplitudeError_EB[61200];
  Float_t         amplitudeError_second_EB[61200];
  Int_t           ieta[61200];
  Int_t           iphi[61200];
  Float_t         digi_ped_subtracted_EE[146480];
  Float_t         amplitude_EE[14648];
  Float_t         amplitude_second_EE[14648];
  Float_t         time_EE[14648];
  Float_t         time_second_EE[14648];
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
  tree->SetBranchAddress("time_EB", time_EB);
  tree->SetBranchAddress("time_second_EB", time_second_EB);
  tree->SetBranchAddress("chi2_EB", chi2_EB);
  tree->SetBranchAddress("chi2_second_EB", chi2_second_EB);
  tree->SetBranchAddress("amplitudeError_EB", amplitudeError_EB);
  tree->SetBranchAddress("amplitudeError_second_EB", amplitudeError_second_EB);
  tree->SetBranchAddress("ieta", ieta);
  tree->SetBranchAddress("iphi", iphi);
  tree->SetBranchAddress("digi_ped_subtracted_EE", digi_ped_subtracted_EE);
  tree->SetBranchAddress("amplitude_EE", amplitude_EE);
  tree->SetBranchAddress("amplitude_second_EE", amplitude_second_EE);
  tree->SetBranchAddress("time_EE", time_EE);
  tree->SetBranchAddress("time_second_EE", time_second_EE);
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
  
  float threshold = 0.01; // 0.1; // 0.0001; // 0.1; //0.0001; //0.1; // 0.01; // relative difference
  float threshold_max = 0.1; // 100.2; // 0.0002; // 100; // 0.0002; // 0.01; // relative difference
  
  
  MAXEVENTS = std::min(MAXEVENTS, (int) (tree->GetEntries()));
  
  std::cout << " MAXEVENTS = " << MAXEVENTS << std::endl;
  
  
  TH1F* histo_ratio_CPUminusGPUoverGPU_EB = new TH1F ("histo_ratio_CPUoverGPU_EB", "(CPU-GPU)/CPU EB", 1000, -0.3, 0.3 );
  TH1F* histo_ratio_CPUminusGPUoverGPU_EE = new TH1F ("histo_ratio_CPUoverGPU_EE", "(CPU-GPU)/CPU EE", 1000, -0.3, 0.3 );
  
  for (int ievent = 0; ievent<MAXEVENTS; ievent++) {
    tree->GetEntry(ievent);
  
    for (int iEBchannel = 0; iEBchannel<61200; iEBchannel++) {
      if (amplitude_EB[iEBchannel] > 0.000001 && fabs(time_EB[iEBchannel]) > 10 ) {
        histo_ratio_CPUminusGPUoverGPU_EB->Fill( (time_EB[iEBchannel]-time_second_EB[iEBchannel])/time_EB[iEBchannel]);   
      }
    }

    for (int iEEchannel = 0; iEEchannel<14648; iEEchannel++) {
      if (amplitude_EE[iEEchannel] > 0.000001 && fabs(time_EE[iEEchannel]) > 10 ) {
        histo_ratio_CPUminusGPUoverGPU_EE->Fill( (time_EE[iEEchannel]-time_second_EE[iEEchannel])/time_EE[iEEchannel]);   
      }
    }
    
  }
  
  for (int ievent = 0; ievent<MAXEVENTS; ievent++) {
    tree->GetEntry(ievent);
    
    for (int iEBchannel = 0; iEBchannel<61200; iEBchannel++) {
      if (amplitude_EB[iEBchannel] > 0.000001 && fabs(time_EB[iEBchannel]) > 10 ) {
        //
        // do the plot only when the two reconstruction algorithms give different values
        //
        
        if ( fabs((time_EB[iEBchannel] - time_second_EB[iEBchannel]) / time_EB[iEBchannel]) > threshold &&
             fabs((time_EB[iEBchannel] - time_second_EB[iEBchannel]) / time_EB[iEBchannel]) < threshold_max
        ) {
          std::cout << "amplitude_EB[" << iEBchannel << "] - amplitude_second_EB[" << iEBchannel << "] = " << amplitude_EB[iEBchannel] - amplitude_second_EB[iEBchannel] << " = " <<  amplitude_EB[iEBchannel] << " - " <<  amplitude_second_EB[iEBchannel] << " ----> time_EB[" << iEBchannel << "] - time_second_EB[" << iEBchannel << "] = " << time_EB[iEBchannel] - time_second_EB[iEBchannel] << " = " <<  time_EB[iEBchannel] << " - " <<  time_second_EB[iEBchannel] << std::endl;          
          if (iPulse_EB < MAXPULSES) {
            graphs_pulses_EB[iPulse_EB] = new TGraph();
            for (int iSample = 0; iSample < 10; iSample++) {
              //       hashedIndex() *10 + iSample
              graphs_pulses_EB[iPulse_EB]->SetPoint(iSample, iSample, digi_ped_subtracted_EB[iEBchannel*10+iSample] );
            }
            EB_value[iPulse_EB] = time_EB[iEBchannel];
            EB_value_second[iPulse_EB] = time_second_EB[iEBchannel];            
            iPulse_EB++;
          }
        
        }
        
      }   
    }
    
  }
  
  
  
  
  TGraph* graphs_pulses_EE[MAXPULSES];
  float EE_value[MAXPULSES];
  float EE_value_second[MAXPULSES];
  
  int iPulse_EE = 0;
  
  for (int ievent = 0; ievent<MAXEVENTS; ievent++) {
    tree->GetEntry(ievent);
    
    for (int iEEchannel = 0; iEEchannel<14648; iEEchannel++) {
      if (amplitude_EE[iEEchannel] > 0.000001 && fabs(time_EE[iEEchannel]) > 10 ) {
        //
        // do the plot only when the two reconstruction algorithms give different values
        //
        
        if ( fabs((time_EE[iEEchannel] - time_second_EE[iEEchannel]) / time_EE[iEEchannel]) > threshold &&
          fabs((time_EE[iEEchannel] - time_second_EE[iEEchannel]) / time_EE[iEEchannel]) < threshold_max
        ) {
          std::cout << "amplitude_EE[" << iEEchannel << "] - amplitude_second_EE[" << iEEchannel << "] = " << amplitude_EE[iEEchannel] - amplitude_second_EE[iEEchannel] << " = " <<  amplitude_EE[iEEchannel] << " - " <<  amplitude_second_EE[iEEchannel] << " ---> time_EE[" << iEEchannel << "] - time_second_EE[" << iEEchannel << "] = " << time_EE[iEEchannel] - time_second_EE[iEEchannel] << " = " <<  time_EE[iEEchannel] << " - " <<  time_second_EE[iEEchannel] << std::endl;
          if (iPulse_EE < MAXPULSES) {
            graphs_pulses_EE[iPulse_EE] = new TGraph();
            for (int iSample = 0; iSample < 10; iSample++) {
              //       hashedIndex() *10 + iSample
              graphs_pulses_EE[iPulse_EE]->SetPoint(iSample, iSample, digi_ped_subtracted_EE[iEEchannel*10+iSample] );
            }
            EE_value[iPulse_EE] = time_EE[iEEchannel];
            EE_value_second[iPulse_EE] = time_second_EE[iEEchannel];
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
  
    
  
  TCanvas* cc_EB_all[iPulse_EB];
  TLine* line_nominal_EB[iPulse_EB]; 
  TLine* line_nominal_second_EB[iPulse_EB];   
  for (int ip = 0; ip<iPulse_EB; ip++) {
    cc_EB_all[ip] = new TCanvas(TString::Format("EB_%d", ip), TString::Format("EB_%d", ip), 800, 600);
    graphs_pulses_EB[ip]->Draw("APL");
    graphs_pulses_EB[ip]->GetYaxis()->SetTitle("ADC");
    graphs_pulses_EB[ip]->GetXaxis()->SetTitle("BX");
    graphs_pulses_EB[ip]->GetYaxis()->SetRangeUser(0, 1.2 * TMath::MaxElement(10,graphs_pulses_EB[ip]->GetY()));
    std::cout << " EB_value[" << ip << "] = " << EB_value[ip] << "     EB_value_second (GPU)[" << ip << "] = " << EB_value_second[ip] << std::endl;
    line_nominal_EB[iPulse_EB] = new TLine (3.8, 0.0, 3.8, EB_value[ip]);
    line_nominal_EB[iPulse_EB]->SetLineColor(kBlue);
    line_nominal_EB[iPulse_EB]->SetLineStyle(2);
    line_nominal_EB[iPulse_EB]->SetLineWidth(3);
    line_nominal_EB[iPulse_EB]->Draw();
    line_nominal_second_EB[iPulse_EB] = new TLine (4.2, 0.0, 4.2, EB_value_second[ip]);
    line_nominal_second_EB[iPulse_EB]->SetLineColor(kRed);
    line_nominal_second_EB[iPulse_EB]->SetLineStyle(1);
    line_nominal_second_EB[iPulse_EB]->SetLineWidth(3);
    line_nominal_second_EB[iPulse_EB]->Draw();
  }
    
 
 
 
 TCanvas* cc_EE_all[iPulse_EE];
 TLine* line_nominal_EE[iPulse_EE]; 
 TLine* line_nominal_second_EE[iPulse_EE]; 
 for (int ip = 0; ip<iPulse_EE; ip++) {
   cc_EE_all[ip] = new TCanvas(TString::Format("EE_%d", ip), TString::Format("EE_%d", ip), 800, 600);
   graphs_pulses_EE[ip]->Draw("APL");
   graphs_pulses_EE[ip]->GetYaxis()->SetTitle("ADC");
   graphs_pulses_EE[ip]->GetXaxis()->SetTitle("BX");
   graphs_pulses_EE[ip]->GetYaxis()->SetRangeUser(0, 1.2 * TMath::MaxElement(10,graphs_pulses_EE[ip]->GetY()));
   std::cout << " EE_value[" << ip << "] = " << EE_value[ip] << "     EE_value_second (GPU)[" << ip << "] = " << EE_value_second[ip] << std::endl;
   line_nominal_EE[iPulse_EE] = new TLine (3.8, 0.0, 3.8, EE_value[ip]);
   line_nominal_EE[iPulse_EE]->SetLineColor(kBlue);
   line_nominal_EE[iPulse_EE]->SetLineStyle(2);
   line_nominal_EE[iPulse_EE]->SetLineWidth(3);
   line_nominal_EE[iPulse_EE]->Draw();
   line_nominal_second_EE[iPulse_EE] = new TLine (4.2, 0.0, 4.2, EE_value_second[ip]);
   line_nominal_second_EE[iPulse_EE]->SetLineColor(kRed);
   line_nominal_second_EE[iPulse_EE]->SetLineStyle(1);
   line_nominal_second_EE[iPulse_EE]->SetLineWidth(3);
   line_nominal_second_EE[iPulse_EE]->Draw();
   
 }
 
 
 
 gStyle->SetOptStat(111111);
 
 TCanvas* cc_ratio_CPUoverGPU = new TCanvas ("cc_ratio_CPUoverGPU", "(CPU-GPU)/CPU", 1200, 600);
 cc_ratio_CPUoverGPU->Divide(2,1);
 cc_ratio_CPUoverGPU->cd(1);
 histo_ratio_CPUminusGPUoverGPU_EB->Draw();
 gPad->SetLogy();
 cc_ratio_CPUoverGPU->cd(2);
 histo_ratio_CPUminusGPUoverGPU_EE->Draw();
 gPad->SetLogy();
 
 
 
}


