

void plot() {

  TCanvas* cc_EB = new TCanvas ("cc_EB", "", 800, 600);
  
  TH1F* SOIAmplitudesEBGPU_CPUratio      = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEBGPU_CPUratio");
  TH1F* SOIAmplitudesEBGPU_CPUratio_th3  = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEBGPU_CPUratio_th3");
  TH1F* SOIAmplitudesEBGPU_CPUratio_th5  = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEBGPU_CPUratio_th5");
  TH1F* SOIAmplitudesEBGPU_CPUratio_th10 = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEBGPU_CPUratio_th10");
  
  SOIAmplitudesEBGPU_CPUratio->SetLineColor(kRed);
  SOIAmplitudesEBGPU_CPUratio_th3->SetLineColor(kOrange);
  SOIAmplitudesEBGPU_CPUratio_th5->SetLineColor(kBlue);
  SOIAmplitudesEBGPU_CPUratio_th10->SetLineColor(kGreen+2);
  
  SOIAmplitudesEBGPU_CPUratio->DrawNormalized();
  SOIAmplitudesEBGPU_CPUratio_th3->DrawNormalized("same");
  SOIAmplitudesEBGPU_CPUratio_th5->DrawNormalized("same");
  SOIAmplitudesEBGPU_CPUratio_th10->DrawNormalized("same");
  
  TLegend* leg_EB = new TLegend (0.8, 1.0, 0.8, 1.0);
  leg_EB->AddEntry(SOIAmplitudesEBGPU_CPUratio,      TString::Format("all      #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEBGPU_CPUratio->GetMean(), SOIAmplitudesEBGPU_CPUratio->GetRMS()));
  leg_EB->AddEntry(SOIAmplitudesEBGPU_CPUratio_th3,  TString::Format(">3 ADC   #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEBGPU_CPUratio_th3->GetMean(), SOIAmplitudesEBGPU_CPUratio_th3->GetRMS()));
  leg_EB->AddEntry(SOIAmplitudesEBGPU_CPUratio_th5,  TString::Format(">5 ADC   #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEBGPU_CPUratio_th5->GetMean(), SOIAmplitudesEBGPU_CPUratio_th5->GetRMS()));
  leg_EB->AddEntry(SOIAmplitudesEBGPU_CPUratio_th10, TString::Format(">10 ADC  #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEBGPU_CPUratio_th10->GetMean(), SOIAmplitudesEBGPU_CPUratio_th10->GetRMS()));
  
  leg_EB->Draw();
  
  cc_EB->SetLogy();
  
  
  
  
  
  TCanvas* cc_EE = new TCanvas ("cc_EE", "", 800, 600);
  
  TH1F* SOIAmplitudesEEGPU_CPUratio      = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEEGPU_CPUratio");
  TH1F* SOIAmplitudesEEGPU_CPUratio_th3  = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEEGPU_CPUratio_th3");
  TH1F* SOIAmplitudesEEGPU_CPUratio_th5  = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEEGPU_CPUratio_th5");
  TH1F* SOIAmplitudesEEGPU_CPUratio_th10 = (TH1F*) _file0->Get("DQMData/Run 323775/SOIAmplitudesEEGPU_CPUratio_th10");
  
  SOIAmplitudesEEGPU_CPUratio->SetLineColor(kRed);
  SOIAmplitudesEEGPU_CPUratio_th3->SetLineColor(kOrange);
  SOIAmplitudesEEGPU_CPUratio_th5->SetLineColor(kBlue);
  SOIAmplitudesEEGPU_CPUratio_th10->SetLineColor(kGreen+2);
  
  SOIAmplitudesEEGPU_CPUratio->DrawNormalized();
  SOIAmplitudesEEGPU_CPUratio_th3->DrawNormalized("same");
  SOIAmplitudesEEGPU_CPUratio_th5->DrawNormalized("same");
  SOIAmplitudesEEGPU_CPUratio_th10->DrawNormalized("same");
  
  TLegend* leg_EE = new TLegend (0.8, 1.0, 0.8, 1.0);
  leg_EE->AddEntry(SOIAmplitudesEEGPU_CPUratio,      TString::Format("all      #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEEGPU_CPUratio->GetMean(), SOIAmplitudesEEGPU_CPUratio->GetRMS()));
  leg_EE->AddEntry(SOIAmplitudesEEGPU_CPUratio_th3,  TString::Format(">3 ADC   #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEEGPU_CPUratio_th3->GetMean(), SOIAmplitudesEEGPU_CPUratio_th3->GetRMS()));
  leg_EE->AddEntry(SOIAmplitudesEEGPU_CPUratio_th5,  TString::Format(">5 ADC   #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEEGPU_CPUratio_th5->GetMean(), SOIAmplitudesEEGPU_CPUratio_th5->GetRMS()));
  leg_EE->AddEntry(SOIAmplitudesEEGPU_CPUratio_th10, TString::Format(">10 ADC  #mu = %.1f ; #sigma = %.2e", SOIAmplitudesEEGPU_CPUratio_th10->GetMean(), SOIAmplitudesEEGPU_CPUratio_th10->GetRMS()));
  
  leg_EE->Draw();
  
  cc_EE->SetLogy();
  
  
  
}

