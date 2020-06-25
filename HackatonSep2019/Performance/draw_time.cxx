//
//
//

#include "tdrstyle.C"

void draw_time(std::string nameFile = "data_time.txt") {

  gStyle->SetOptStat(0);
  setTDRStyle();
  
  TGraphErrors* gr_time_cpu     = new TGraphErrors();
  TGraphErrors* gr_time_gpu     = new TGraphErrors();
  TGraphErrors* gr_time_gpu_new = new TGraphErrors();
  TGraphErrors* gr_time_io      = new TGraphErrors();
  
  std::ifstream file (nameFile); 
  std::string buffer;
  float value_number;
  float value_cpu;
  float value_gpu;
  float value_gpu_new;
  float value_io;
  float error_value_cpu;
  float error_value_gpu;
  float error_value_gpu_new;
  float error_value_io;
  std::string temp_char;
  
  if(!file.is_open()) {
    std::cerr << "** ERROR: Can't open '" << nameFile << "' for input" << std::endl;
    return false;
  }
  
  int ipoint = 0;
  
  while(!file.eof()) {
    getline(file,buffer);
    if (buffer != "" && buffer.at(0) != '#'){ ///---> save from empty line at the end!
      std::stringstream line( buffer );  
      
      line >> value_number; 
      std::cout << " value_number = " << value_number << std::endl;
      
      line >> value_cpu; 
      line >> temp_char;
      line >> error_value_cpu; 
      std::cout << " value_cpu = " << value_cpu << " +/- " << error_value_cpu << std::endl;
      
      line >> value_gpu; 
      line >> temp_char;
      line >> error_value_gpu; 
      std::cout << " value_gpu = " << value_gpu << " +/- " << error_value_gpu << std::endl;
      
      line >> value_gpu_new; 
      line >> temp_char;
      line >> error_value_gpu_new; 
      std::cout << " value_gpu_new = " << value_gpu_new << " +/- " << error_value_gpu_new << std::endl;
      
      std::cout << "----" << std::endl;
      
      if (! (line.eof())) {
        line >> value_io; 
        line >> temp_char;
        line >> error_value_io; 
        gr_time_io->SetPoint(ipoint, value_number, value_io);
        gr_time_io->SetPointError(ipoint, 0, error_value_io);
      }
      
      gr_time_cpu->SetPoint    (ipoint, value_number, value_cpu);
      gr_time_gpu->SetPoint    (ipoint, value_number, value_gpu);
      gr_time_gpu_new->SetPoint(ipoint, value_number, value_gpu_new);
      
      gr_time_cpu->SetPointError    (ipoint, 0, error_value_cpu);
      gr_time_gpu->SetPointError    (ipoint, 0, error_value_gpu);
      gr_time_gpu_new->SetPointError(ipoint, 0, error_value_gpu_new);

      ipoint++;
      
    } 
  }
  
  TCanvas* cc = new TCanvas ("cc", "", 900, 600);
  cc->SetRightMargin(0.2);
  
  gr_time_cpu -> SetTitle("CPU");
  gr_time_cpu -> SetMarkerSize(2);
  gr_time_cpu -> SetMarkerStyle(20);
  gr_time_cpu -> SetMarkerColor(kRed);
  gr_time_cpu -> SetLineColor(kRed);
  gr_time_cpu -> SetLineWidth(2);

  gr_time_gpu -> SetTitle("GPU rechit");
  gr_time_gpu -> SetMarkerSize(2);
  gr_time_gpu -> SetMarkerStyle(21);
  gr_time_gpu -> SetMarkerColor(kBlue);
  gr_time_gpu -> SetLineColor(kBlue);
  gr_time_gpu -> SetLineWidth(2);

  gr_time_gpu_new -> SetTitle("GPU uncalib + CPU rechit");
  gr_time_gpu_new -> SetMarkerSize(2);
  gr_time_gpu_new -> SetMarkerStyle(22);
  gr_time_gpu_new -> SetMarkerColor(kGreen);
  gr_time_gpu_new -> SetLineColor(kGreen);
  gr_time_gpu_new -> SetLineWidth(2);

  gr_time_io -> SetTitle("i/o ECAL FED");
  gr_time_io -> SetMarkerSize(2);
  gr_time_io -> SetMarkerStyle(23);
  gr_time_io -> SetMarkerColor(kMagenta);
  gr_time_io -> SetLineColor(kMagenta);
  gr_time_io -> SetLineWidth(2);


  TMultiGraph* mg = new TMultiGraph();
  mg->Add(gr_time_cpu);
  mg->Add(gr_time_gpu);
  mg->Add(gr_time_gpu_new);
  if (gr_time_io->GetN() != 0) {
    mg->Add(gr_time_io);
  }
  
  mg -> Draw("APL");
  mg -> GetXaxis () -> SetTitle ("#threads"); 
  mg -> GetYaxis () -> SetTitle ("events/s"); 
  
  
  TLegend* legend_useful = new TLegend(0.81,0.45,0.99,0.90);
  if (gr_time_io->GetN() != 0) {
    legend_useful->AddEntry(gr_time_io, TString::Format("i/o ECAL FED") ,"lp");
  }
  legend_useful->AddEntry(gr_time_gpu_new, TString::Format("gpu uncalib + cpu") ,"lp");
  legend_useful->AddEntry(gr_time_gpu,     TString::Format("gpu rechit")        ,"lp");
  legend_useful->AddEntry(gr_time_cpu,     TString::Format("cpu rechit")        ,"lp");
  legend_useful->Draw();
  
//   gPad->BuildLegend();
  
}




