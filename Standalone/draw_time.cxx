void draw_time(std::string nameFile = "data_time.txt") {
  
  TGraph* gr_time_cpu = new TGraph();
  TGraph* gr_time_gpu = new TGraph();
  TGraph* gr_time_gpu_new = new TGraph();
  
  std::ifstream file (nameFile); 
  std::string buffer;
  float value_number;
  float value_cpu;
  float value_gpu;
  float value_gpu_new;
  
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
      line >> value_cpu; 
      line >> value_gpu; 
      line >> value_gpu_new; 
      
      gr_time_cpu->SetPoint(ipoint, value_number, value_cpu);
      gr_time_gpu->SetPoint(ipoint, value_number, value_gpu);
      gr_time_gpu_new->SetPoint(ipoint, value_number, value_gpu_new);
      
      ipoint++;
      
    } 
  }
  
  gr_time_cpu -> SetTitle("CPU");
  gr_time_cpu -> SetMarkerSize(2);
  gr_time_cpu -> SetMarkerStyle(20);
  gr_time_cpu -> SetMarkerColor(kRed);
  gr_time_cpu -> SetLineColor(kRed);
  gr_time_cpu -> SetLineWidth(2);

  gr_time_gpu -> SetTitle("GPU");
  gr_time_gpu -> SetMarkerSize(2);
  gr_time_gpu -> SetMarkerStyle(21);
  gr_time_gpu -> SetMarkerColor(kBlue);
  gr_time_gpu -> SetLineColor(kBlue);
  gr_time_gpu -> SetLineWidth(2);

  gr_time_gpu_new -> SetTitle("GPU new");
  gr_time_gpu_new -> SetMarkerSize(2);
  gr_time_gpu_new -> SetMarkerStyle(22);
  gr_time_gpu_new -> SetMarkerColor(kGreen);
  gr_time_gpu_new -> SetLineColor(kGreen);
  gr_time_gpu_new -> SetLineWidth(2);
  
  TMultiGraph* mg = new TMultiGraph();
  mg->Add(gr_time_cpu);
  mg->Add(gr_time_gpu);
  mg->Add(gr_time_gpu_new);
  
  mg -> Draw("APL");
  mg -> GetXaxis () -> SetTitle ("# crystals"); 
  mg -> GetYaxis () -> SetTitle ("Time (#mus)"); 
  
  gPad->BuildLegend();
  
}




