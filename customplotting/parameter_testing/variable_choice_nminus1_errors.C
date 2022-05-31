{
    gStyle->SetTitleYOffset(1.7);
    gStyle->SetOptStat(0);
    //gStyle->SetLabelSize(0.025);
    //gStyle->SetTitleSize(0.025);
    
    Float_t bar_width_sig = 0.2;
    Float_t bar_offset_sig = 0.5 - bar_width_sig*2;
    
    Float_t bar_width_bkg = 0.0625;
    Float_t bar_offset_bkg = 0.5 - bar_width_bkg*6;
    
    // =============== N-1 studies ===============
    
    //const char *nminus1varchoices[17] = {"Momentum","Angle","FGD1 E/L","FGD2 E/L","TPC2 mu pull","TPC2 pi pull","TPC2 p pull","TPC2 e pull", "TPC3 dE/dx (GQ)",
    //                               "nTPCs","ECal EM energy","ECal E/L", "ECal Circularity","ECal FBR", "ECal TMR", "ECal QRMS", "nSMRDs"};
    const char *nminus1varchoices[15] = {"FGD1 E/L","FGD2 E/L","TPC2 mu pull","TPC2 pi pull","TPC2 p pull","TPC2 e pull", "TPC3 dE/dx (GQ)",
                                   "nTPCs","ECal EM energy","ECal E/L", "ECal Circularity","ECal FBR", "ECal TMR", "ECal QRMS", "nSMRDs"};
    
    TH1F* Nminus1_musel_mu = new TH1F("Nminus1_musel_mu","#mu^{+} identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_musel_pi = new TH1F("Nminus1_musel_pi","#pi^{+} identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_musel_p = new TH1F("Nminus1_musel_p","p identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_musel_e = new TH1F("Nminus1_musel_e","e^{+} identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_pisel_mu = new TH1F("Nminus1_pisel_mu","#mu^{+} identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_pisel_pi = new TH1F("Nminus1_pisel_pi","#pi^{+} identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_pisel_p = new TH1F("Nminus1_pisel_p","p identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_pisel_e = new TH1F("Nminus1_pisel_e","e^{+} identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_psel_mu = new TH1F("Nminus1_psel_mu","#mu^{+} identified as p",15,0,15);
    TH1F* Nminus1_psel_pi = new TH1F("Nminus1_psel_pi","#pi^{+} identified as p",15,0,15);
    TH1F* Nminus1_psel_p = new TH1F("Nminus1_psel_p","p identified as p",15,0,15);
    TH1F* Nminus1_psel_e = new TH1F("Nminus1_psel_e","e^{+} identified as p",15,0,15);
    TH1F* Nminus1_esel_mu = new TH1F("Nminus1_esel_mu","#mu^{+} identified as e^{+}",15,0,15);
    TH1F* Nminus1_esel_pi = new TH1F("Nminus1_esel_pi","#pi^{+} identified as e^{+}",15,0,15);
    TH1F* Nminus1_esel_p = new TH1F("Nminus1_esel_p","p identified as e^{+}",15,0,15);
    TH1F* Nminus1_esel_e = new TH1F("Nminus1_esel_e","e^{+} identified as e^{+}",15,0,15);
    
    TH1F* Nminus1_musel_mu_diff = new TH1F("Nminus1_musel_mu_diff","#mu^{+} identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_musel_pi_diff = new TH1F("Nminus1_musel_pi_diff","#pi^{+} identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_musel_p_diff = new TH1F("Nminus1_musel_p_diff","p identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_musel_e_diff = new TH1F("Nminus1_musel_e_diff","e^{+} identified as #mu^{+}",15,0,15);
    TH1F* Nminus1_pisel_mu_diff = new TH1F("Nminus1_pisel_mu_diff","#mu^{+} identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_pisel_pi_diff = new TH1F("Nminus1_pisel_pi_diff","#pi^{+} identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_pisel_p_diff = new TH1F("Nminus1_pisel_p_diff","p identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_pisel_e_diff = new TH1F("Nminus1_pisel_e_diff","e^{+} identified as #pi^{+}",15,0,15);
    TH1F* Nminus1_psel_mu_diff = new TH1F("Nminus1_psel_mu_diff","#mu^{+} identified as p",15,0,15);
    TH1F* Nminus1_psel_pi_diff = new TH1F("Nminus1_psel_pi_diff","#pi^{+} identified as p",15,0,15);
    TH1F* Nminus1_psel_p_diff = new TH1F("Nminus1_psel_p_diff","p identified as p",15,0,15);
    TH1F* Nminus1_psel_e_diff = new TH1F("Nminus1_psel_e_diff","e^{+} identified as p",15,0,15);
    TH1F* Nminus1_esel_mu_diff = new TH1F("Nminus1_esel_mu_diff","#mu^{+} identified as e^{+}",15,0,15);
    TH1F* Nminus1_esel_pi_diff = new TH1F("Nminus1_esel_pi_diff","#pi^{+} identified as e^{+}",15,0,15);
    TH1F* Nminus1_esel_p_diff = new TH1F("Nminus1_esel_p_diff","p identified as e^{+}",15,0,15);
    TH1F* Nminus1_esel_e_diff = new TH1F("Nminus1_esel_e_diff","e^{+} identified as e^{+}",15,0,15);
    
    Nminus1_musel_mu->SetFillColor( kBlue);
    Nminus1_musel_pi->SetFillColor( kRed); //Nminus1_musel_pi->SetFillStyle(3305);
    Nminus1_musel_p->SetFillColor( kGreen); //Nminus1_musel_p->SetFillStyle(3305);
    Nminus1_musel_e->SetFillColor( kMagenta); //Nminus1_musel_e->SetFillStyle(3305);
    Nminus1_pisel_mu->SetFillColor( kBlue); //Nminus1_pisel_mu->SetFillStyle(3345);
    Nminus1_pisel_pi->SetFillColor( kRed); 
    Nminus1_pisel_p->SetFillColor( kGreen+1); //Nminus1_pisel_p->SetFillStyle(3345);
    Nminus1_pisel_e->SetFillColor( kMagenta+1); //Nminus1_pisel_e->SetFillStyle(3345);
    Nminus1_psel_mu->SetFillColor( kBlue+1); //Nminus1_psel_mu->SetFillStyle(3354);
    Nminus1_psel_pi->SetFillColor( kRed+1); //Nminus1_psel_pi->SetFillStyle(3354);
    Nminus1_psel_p->SetFillColor( kGreen); 
    Nminus1_psel_e->SetFillColor( kMagenta+2); //Nminus1_psel_e->SetFillStyle(3354);
    Nminus1_esel_mu->SetFillColor( kBlue+2); //Nminus1_esel_mu->SetFillStyle(3144);
    Nminus1_esel_pi->SetFillColor( kRed+2); //Nminus1_esel_pi->SetFillStyle(3144);
    Nminus1_esel_p->SetFillColor( kGreen+2); //Nminus1_esel_p->SetFillStyle(3144);
    Nminus1_esel_e->SetFillColor( kMagenta);
    
    Nminus1_musel_mu_diff->SetFillColor( kBlue);
    Nminus1_musel_pi_diff->SetFillColor( kRed); //Nminus1_musel_pi_diff->SetFillStyle(3305);
    Nminus1_musel_p_diff->SetFillColor( kGreen); //Nminus1_musel_p_diff->SetFillStyle(3305);
    Nminus1_musel_e_diff->SetFillColor( kMagenta); //Nminus1_musel_e_diff->SetFillStyle(3305);
    Nminus1_pisel_mu_diff->SetFillColor( kBlue); //Nminus1_pisel_mu_diff->SetFillStyle(3345);
    Nminus1_pisel_pi_diff->SetFillColor( kRed);
    Nminus1_pisel_p_diff->SetFillColor( kGreen+1); //Nminus1_pisel_p_diff->SetFillStyle(3345);
    Nminus1_pisel_e_diff->SetFillColor( kMagenta+1); //Nminus1_pisel_e_diff->SetFillStyle(3345);
    Nminus1_psel_mu_diff->SetFillColor( kBlue+1); //Nminus1_psel_mu_diff->SetFillStyle(3354);
    Nminus1_psel_pi_diff->SetFillColor( kRed+1); //Nminus1_psel_pi_diff->SetFillStyle(3354);
    Nminus1_psel_p_diff->SetFillColor( kGreen);
    Nminus1_psel_e_diff->SetFillColor( kMagenta+2); //Nminus1_psel_e_diff->SetFillStyle(3354);
    Nminus1_esel_mu_diff->SetFillColor( kBlue+2); //Nminus1_esel_mu_diff->SetFillStyle(3144);
    Nminus1_esel_pi_diff->SetFillColor( kRed+2); //Nminus1_esel_pi->SetFillStyle(3144);
    Nminus1_esel_p_diff->SetFillColor( kGreen+2); //Nminus1_esel_p->SetFillStyle(3144);
    Nminus1_esel_e_diff->SetFillColor( kMagenta);
    
    /*Nminus1_musel_mu->SetBarOffset(bar_offset + (bar_width*0)); Nminus1_musel_mu->SetBarWidth(bar_width);
    Nminus1_musel_pi->SetBarOffset(bar_offset + (bar_width*1)); Nminus1_musel_pi->SetBarWidth(bar_width);
    Nminus1_musel_p->SetBarOffset(bar_offset + (bar_width*2)); Nminus1_musel_p->SetBarWidth(bar_width);
    Nminus1_musel_e->SetBarOffset(bar_offset + (bar_width*3)); Nminus1_musel_e->SetBarWidth(bar_width);
    Nminus1_pisel_mu->SetBarOffset(bar_offset + (bar_width*4)); Nminus1_pisel_mu->SetBarWidth(bar_width);
    Nminus1_pisel_pi->SetBarOffset(bar_offset + (bar_width*5)); Nminus1_pisel_pi->SetBarWidth(bar_width);
    Nminus1_pisel_p->SetBarOffset(bar_offset + (bar_width*6)); Nminus1_pisel_p->SetBarWidth(bar_width);
    Nminus1_pisel_e->SetBarOffset(bar_offset + (bar_width*7)); Nminus1_pisel_e->SetBarWidth(bar_width);
    Nminus1_psel_mu->SetBarOffset(bar_offset + (bar_width*8)); Nminus1_psel_mu->SetBarWidth(bar_width);
    Nminus1_psel_pi->SetBarOffset(bar_offset + (bar_width*9)); Nminus1_psel_pi->SetBarWidth(bar_width);
    Nminus1_psel_p->SetBarOffset(bar_offset + (bar_width*10)); Nminus1_psel_p->SetBarWidth(bar_width);
    Nminus1_psel_e->SetBarOffset(bar_offset + (bar_width*11)); Nminus1_psel_e->SetBarWidth(bar_width);
    Nminus1_esel_mu->SetBarOffset(bar_offset + (bar_width*12)); Nminus1_esel_mu->SetBarWidth(bar_width);
    Nminus1_esel_pi->SetBarOffset(bar_offset + (bar_width*13)); Nminus1_esel_pi->SetBarWidth(bar_width);
    Nminus1_esel_p->SetBarOffset(bar_offset + (bar_width*14)); Nminus1_esel_p->SetBarWidth(bar_width);
    Nminus1_esel_e->SetBarOffset(bar_offset + (bar_width*15)); Nminus1_esel_e->SetBarWidth(bar_width);*/
    
    Nminus1_musel_mu->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); Nminus1_musel_mu->SetBarWidth(bar_width_sig);
    Nminus1_pisel_pi->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); Nminus1_pisel_pi->SetBarWidth(bar_width_sig);
    Nminus1_psel_p->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); Nminus1_psel_p->SetBarWidth(bar_width_sig);
    Nminus1_esel_e->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); Nminus1_esel_e->SetBarWidth(bar_width_sig);
    
    Nminus1_musel_mu_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*0)); Nminus1_musel_mu_diff->SetBarWidth(bar_width_sig);
    Nminus1_pisel_pi_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*1)); Nminus1_pisel_pi_diff->SetBarWidth(bar_width_sig);
    Nminus1_psel_p_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*2)); Nminus1_psel_p_diff->SetBarWidth(bar_width_sig);
    Nminus1_esel_e_diff->SetBarOffset(bar_offset_sig + (bar_width_sig*3)); Nminus1_esel_e_diff->SetBarWidth(bar_width_sig);
    
    Nminus1_pisel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); Nminus1_pisel_mu->SetBarWidth(bar_width_bkg);
    Nminus1_psel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); Nminus1_psel_mu->SetBarWidth(bar_width_bkg);
    Nminus1_esel_mu->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); Nminus1_esel_mu->SetBarWidth(bar_width_bkg);
    Nminus1_musel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); Nminus1_musel_pi->SetBarWidth(bar_width_bkg);
    Nminus1_psel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); Nminus1_psel_pi->SetBarWidth(bar_width_bkg);
    Nminus1_esel_pi->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); Nminus1_esel_pi->SetBarWidth(bar_width_bkg);
    Nminus1_musel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); Nminus1_musel_p->SetBarWidth(bar_width_bkg);
    Nminus1_pisel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); Nminus1_pisel_p->SetBarWidth(bar_width_bkg);
    Nminus1_esel_p->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); Nminus1_esel_p->SetBarWidth(bar_width_bkg);
    Nminus1_musel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); Nminus1_musel_e->SetBarWidth(bar_width_bkg);
    Nminus1_pisel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); Nminus1_pisel_e->SetBarWidth(bar_width_bkg);
    Nminus1_psel_e->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); Nminus1_psel_e->SetBarWidth(bar_width_bkg);
    
    Nminus1_pisel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*0)); Nminus1_pisel_mu_diff->SetBarWidth(bar_width_bkg);
    Nminus1_psel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*1)); Nminus1_psel_mu_diff->SetBarWidth(bar_width_bkg);
    Nminus1_esel_mu_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*2)); Nminus1_esel_mu_diff->SetBarWidth(bar_width_bkg);
    Nminus1_musel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*3)); Nminus1_musel_pi_diff->SetBarWidth(bar_width_bkg);
    Nminus1_psel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*4)); Nminus1_psel_pi_diff->SetBarWidth(bar_width_bkg);
    Nminus1_esel_pi_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*5)); Nminus1_esel_pi_diff->SetBarWidth(bar_width_bkg);
    Nminus1_musel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*6)); Nminus1_musel_p_diff->SetBarWidth(bar_width_bkg);
    Nminus1_pisel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*7)); Nminus1_pisel_p_diff->SetBarWidth(bar_width_bkg);
    Nminus1_esel_p_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*8)); Nminus1_esel_p_diff->SetBarWidth(bar_width_bkg);
    Nminus1_musel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*9)); Nminus1_musel_e_diff->SetBarWidth(bar_width_bkg);
    Nminus1_pisel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*10)); Nminus1_pisel_e_diff->SetBarWidth(bar_width_bkg);
    Nminus1_psel_e_diff->SetBarOffset(bar_offset_bkg + (bar_width_bkg*11)); Nminus1_psel_e_diff->SetBarWidth(bar_width_bkg);
    /*
    // Momentum
    
    Nminus1_musel_mu->Fill(nminus1varchoices[0],0.927453);
    Nminus1_musel_pi->Fill(nminus1varchoices[0],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[0],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[0],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[0],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[0],0.628748);
    Nminus1_pisel_p->Fill(nminus1varchoices[0],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[0],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[0],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[0],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[0],0.896677);
    Nminus1_psel_e->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[0],0.928894);
    
    // Theta
    
    Nminus1_musel_mu->Fill(nminus1varchoices[1],0.925932);
    Nminus1_musel_pi->Fill(nminus1varchoices[1],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[1],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[1],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[1],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[1],0.635321);
    Nminus1_pisel_p->Fill(nminus1varchoices[1],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[1],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[1],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[1],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[1],0.896522);
    Nminus1_psel_e->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[1],0.937506);
    */
    // FGD1 E/L
    
    Nminus1_musel_mu->Fill(nminus1varchoices[0],0.929003);
    Nminus1_musel_pi->Fill(nminus1varchoices[0],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[0],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[0],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[0],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[0],0.614319);
    Nminus1_pisel_p->Fill(nminus1varchoices[0],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[0],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[0],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[0],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[0],0.86544);
    Nminus1_psel_e->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[0],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[0],0.909265);
    
    // FGD2 E/L
    
    Nminus1_musel_mu->Fill(nminus1varchoices[1],0.924237);
    Nminus1_musel_pi->Fill(nminus1varchoices[1],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[1],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[1],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[1],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[1],0.634808);
    Nminus1_pisel_p->Fill(nminus1varchoices[1],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[1],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[1],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[1],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[1],0.893531);
    Nminus1_psel_e->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[1],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[1],0.92441);
    
    // TPC2 mu
    
    Nminus1_musel_mu->Fill(nminus1varchoices[2],0.929901);
    Nminus1_musel_pi->Fill(nminus1varchoices[2],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[2],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[2],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[2],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[2],0.630169);
    Nminus1_pisel_p->Fill(nminus1varchoices[2],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[2],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[2],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[2],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[2],0.899478);
    Nminus1_psel_e->Fill(nminus1varchoices[2],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[2],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[2],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[2],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[2],0.922806);
    
    // TPC2 pi
    
    Nminus1_musel_mu->Fill(nminus1varchoices[3],0.927685);
    Nminus1_musel_pi->Fill(nminus1varchoices[3],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[3],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[3],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[3],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[3],0.629484);
    Nminus1_pisel_p->Fill(nminus1varchoices[3],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[3],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[3],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[3],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[3],0.899443);
    Nminus1_psel_e->Fill(nminus1varchoices[3],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[3],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[3],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[3],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[3],0.937238);
    
    // TPC2 p
    
    Nminus1_musel_mu->Fill(nminus1varchoices[4],0.929626);
    Nminus1_musel_pi->Fill(nminus1varchoices[4],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[4],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[4],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[4],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[4],0.631983);
    Nminus1_pisel_p->Fill(nminus1varchoices[4],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[4],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[4],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[4],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[4],0.896816);
    Nminus1_psel_e->Fill(nminus1varchoices[4],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[4],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[4],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[4],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[4],0.926162);
    
    // TPC2 e
    
    Nminus1_musel_mu->Fill(nminus1varchoices[5],0.929626);
    Nminus1_musel_pi->Fill(nminus1varchoices[5],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[5],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[5],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[5],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[5],0.629912);
    Nminus1_pisel_p->Fill(nminus1varchoices[5],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[5],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[5],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[5],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[5],0.896695);
    Nminus1_psel_e->Fill(nminus1varchoices[5],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[5],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[5],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[5],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[5],0.894135);
    
    // TPC3 dedx gq
    
    Nminus1_musel_mu->Fill(nminus1varchoices[6],0.94049);
    Nminus1_musel_pi->Fill(nminus1varchoices[6],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[6],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[6],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[6],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[6],0.618034);
    Nminus1_pisel_p->Fill(nminus1varchoices[6],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[6],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[6],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[6],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[6],0.879633);
    Nminus1_psel_e->Fill(nminus1varchoices[6],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[6],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[6],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[6],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[6],0.940401);
    
    // nTPCs
    
    Nminus1_musel_mu->Fill(nminus1varchoices[7],0.93035);
    Nminus1_musel_pi->Fill(nminus1varchoices[7],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[7],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[7],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[7],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[7],0.60316);
    Nminus1_pisel_p->Fill(nminus1varchoices[7],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[7],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[7],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[7],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[7],0.899132);
    Nminus1_psel_e->Fill(nminus1varchoices[7],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[7],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[7],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[7],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[7],0.93314);
    
    // ECal EM energy
    
    Nminus1_musel_mu->Fill(nminus1varchoices[8],0.927337);
    Nminus1_musel_pi->Fill(nminus1varchoices[8],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[8],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[8],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[8],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[8],0.631008);
    Nminus1_pisel_p->Fill(nminus1varchoices[8],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[8],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[8],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[8],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[8],0.890316);
    Nminus1_psel_e->Fill(nminus1varchoices[8],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[8],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[8],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[8],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[8],0.934002);
    
    // ECal E/L
    
    Nminus1_musel_mu->Fill(nminus1varchoices[9],0.92457);
    Nminus1_musel_pi->Fill(nminus1varchoices[9],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[9],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[9],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[9],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[9],0.628149);
    Nminus1_pisel_p->Fill(nminus1varchoices[9],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[9],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[9],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[9],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[9],0.889573);
    Nminus1_psel_e->Fill(nminus1varchoices[9],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[9],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[9],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[9],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[9],0.926652);
    
    // ECal circularity
    
    Nminus1_musel_mu->Fill(nminus1varchoices[10],0.929409);
    Nminus1_musel_pi->Fill(nminus1varchoices[10],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[10],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[10],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[10],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[10],0.627225);
    Nminus1_pisel_p->Fill(nminus1varchoices[10],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[10],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[10],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[10],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[10],0.899253);
    Nminus1_psel_e->Fill(nminus1varchoices[10],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[10],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[10],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[10],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[10],0.929607);
    
    // ECal FBR
    
    Nminus1_musel_mu->Fill(nminus1varchoices[11],0.930307);
    Nminus1_musel_pi->Fill(nminus1varchoices[11],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[11],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[11],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[11],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[11],0.631983);
    Nminus1_pisel_p->Fill(nminus1varchoices[11],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[11],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[11],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[11],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[11],0.895433);
    Nminus1_psel_e->Fill(nminus1varchoices[11],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[11],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[11],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[11],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[11],0.933215);
    
    // ECal TMR
    
    Nminus1_musel_mu->Fill(nminus1varchoices[12],0.92783);
    Nminus1_musel_pi->Fill(nminus1varchoices[12],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[12],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[12],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[12],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[12],0.632103);
    Nminus1_pisel_p->Fill(nminus1varchoices[12],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[12],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[12],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[12],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[12],0.895156);
    Nminus1_psel_e->Fill(nminus1varchoices[12],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[12],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[12],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[12],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[12],0.93173);
    
    // ECal QRMS
    
    Nminus1_musel_mu->Fill(nminus1varchoices[13],0.927815);
    Nminus1_musel_pi->Fill(nminus1varchoices[13],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[13],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[13],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[13],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[13],0.628406);
    Nminus1_pisel_p->Fill(nminus1varchoices[13],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[13],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[13],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[13],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[13],0.895381);
    Nminus1_psel_e->Fill(nminus1varchoices[13],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[13],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[13],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[13],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[13],0.930705);
    
    // nSMRDs
    
    Nminus1_musel_mu->Fill(nminus1varchoices[14],0.920152);
    Nminus1_musel_pi->Fill(nminus1varchoices[14],0.); 
    Nminus1_musel_p->Fill(nminus1varchoices[14],0.);
    Nminus1_musel_e->Fill(nminus1varchoices[14],0.);
    Nminus1_pisel_mu->Fill(nminus1varchoices[14],0.);
    Nminus1_pisel_pi->Fill(nminus1varchoices[14],0.62019);
    Nminus1_pisel_p->Fill(nminus1varchoices[14],0.);
    Nminus1_pisel_e->Fill(nminus1varchoices[14],0.);
    Nminus1_psel_mu->Fill(nminus1varchoices[14],0.);
    Nminus1_psel_pi->Fill(nminus1varchoices[14],0.);
    Nminus1_psel_p->Fill(nminus1varchoices[14],0.900705);
    Nminus1_psel_e->Fill(nminus1varchoices[14],0.);
    Nminus1_esel_mu->Fill(nminus1varchoices[14],0.);
    Nminus1_esel_pi->Fill(nminus1varchoices[14],0.);
    Nminus1_esel_p->Fill(nminus1varchoices[14],0.);
    Nminus1_esel_e->Fill(nminus1varchoices[14],0.928924);
    
    //TCanvas* canvas_Nminus1_choices = new TCanvas("canvas_Nminus1_choices","",200,10,1000,800);
    TCanvas* canvas_Nminus1_choices_sig = new TCanvas("canvas_Nminus1_choices_sig","",200,10,2000,800);
    canvas_Nminus1_choices_sig->Divide(2,1,0.005,0.005);
    canvas_Nminus1_choices_sig->cd(1);
    Nminus1_musel_mu->GetYaxis()->SetRangeUser(-0.045, 0.005);
    Nminus1_musel_mu->GetXaxis()->SetRangeUser(0, 15);
    Nminus1_musel_mu->GetYaxis()->SetTitle("Efficiency");
    Nminus1_musel_mu->GetYaxis()->SetLabelSize(0.025);
    Nminus1_musel_mu->GetYaxis()->SetTitleSize(0.025);
    Nminus1_musel_mu->GetYaxis()->SetTitleOffset(1.2);
    
    Nminus1_musel_mu->Draw("B");
    Nminus1_pisel_pi->Draw("B same");
    Nminus1_psel_p->Draw("B same");
    Nminus1_esel_e->Draw("B same");
    
    //canvas_Nminus1_choices->BuildLegend();
    //canvas_Nminus1_choices_sig->cd(1)->BuildLegend();
    TLegend *legend_sig = new TLegend(0.55,0.65,0.76,0.82);
    legend_sig->AddEntry(Nminus1_musel_mu,"#mu^{+} identified as #mu^{+}","f");
    legend_sig->AddEntry(Nminus1_pisel_pi,"#pi^{+} identified as #pi^{+}","f");
    legend_sig->AddEntry(Nminus1_psel_p,"p identified as p","f");
    legend_sig->AddEntry(Nminus1_esel_e,"e^{+} identified as e^{+}","f");
    legend_sig->Draw();
    
    //TCanvas* canvas_Nminus1_choices_bkg = new TCanvas("canvas_Nminus1_choices_bkg","",200,10,1000,800);
    TCanvas* canvas_Nminus1_choices_bkg = new TCanvas("canvas_Nminus1_choices_bkg","",200,10,2000,800);
    canvas_Nminus1_choices_bkg->Divide(2,1,0.005,0.005);
    canvas_Nminus1_choices_bkg->cd(1);
    Nminus1_pisel_mu->GetYaxis()->SetRangeUser(0, 0.5);
    Nminus1_pisel_mu->GetXaxis()->SetRangeUser(0, 15);
    Nminus1_pisel_mu->GetYaxis()->SetTitle("Efficiency");
    Nminus1_pisel_mu->GetYaxis()->SetLabelSize(0.025);
    Nminus1_pisel_mu->GetYaxis()->SetTitleSize(0.025);
    Nminus1_pisel_mu->GetYaxis()->SetTitleOffset(1.4);
    
    Nminus1_pisel_mu->Draw("B");
    Nminus1_psel_mu->Draw("B same");
    Nminus1_esel_mu->Draw("B same");
    Nminus1_musel_pi->Draw("B same");
    Nminus1_psel_pi->Draw("B same");
    Nminus1_esel_pi->Draw("B same");
    Nminus1_musel_p->Draw("B same");
    Nminus1_pisel_p->Draw("B same");
    Nminus1_esel_p->Draw("B same");
    Nminus1_musel_e->Draw("B same");
    Nminus1_pisel_e->Draw("B same");
    Nminus1_psel_e->Draw("B same");

    //canvas_Nminus1_choices_bkg->BuildLegend();
    //canvas_Nminus1_choices_bkg->cd(1)->BuildLegend();
    TLegend *legend_bkg = new TLegend(0.55,0.65,0.76,0.82);
    legend_bkg->AddEntry(Nminus1_pisel_mu,"#mu^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(Nminus1_psel_mu,"#mu^{+} identified as p","f");
    legend_bkg->AddEntry(Nminus1_esel_mu,"#mu^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(Nminus1_musel_pi,"#pi^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(Nminus1_psel_pi,"#pi^{+} identified as p","f");
    legend_bkg->AddEntry(Nminus1_esel_pi,"#pi^{+} identified as e^{+}","f");
    legend_bkg->AddEntry(Nminus1_musel_p,"p identified as #mu^{+}","f");
    legend_bkg->AddEntry(Nminus1_pisel_p,"p identified as #pi^{+}","f");
    legend_bkg->AddEntry(Nminus1_esel_p,"p identified as e^{+}","f");
    legend_bkg->AddEntry(Nminus1_musel_e,"e^{+} identified as #mu^{+}","f");
    legend_bkg->AddEntry(Nminus1_pisel_e,"e^{+} identified as #pi^{+}","f");
    legend_bkg->AddEntry(Nminus1_psel_e,"e^{+} identified as p","f");
    legend_bkg->Draw();
    
    for (int i=0; i < 15; i++) 
    {
        Nminus1_musel_mu_diff->Fill(nminus1varchoices[i], 0.928829-Nminus1_musel_mu->GetBinContent(i+1) );
        Nminus1_musel_pi_diff->Fill(nminus1varchoices[i], Nminus1_musel_pi->GetBinContent(i+1)-0. ); 
        Nminus1_musel_p_diff->Fill(nminus1varchoices[i], Nminus1_musel_p->GetBinContent(i+1)-0. );
        Nminus1_musel_e_diff->Fill(nminus1varchoices[i], Nminus1_musel_e->GetBinContent(i+1)-0. );
        Nminus1_pisel_mu_diff->Fill(nminus1varchoices[i], Nminus1_pisel_mu->GetBinContent(i+1)-0. );
        Nminus1_pisel_pi_diff->Fill(nminus1varchoices[i], 0.634636-Nminus1_pisel_pi->GetBinContent(i+1) );
        Nminus1_pisel_p_diff->Fill(nminus1varchoices[i], Nminus1_pisel_p->GetBinContent(i+1)-0. );
        Nminus1_pisel_e_diff->Fill(nminus1varchoices[i], Nminus1_pisel_e->GetBinContent(i+1)-0. );
        Nminus1_psel_mu_diff->Fill(nminus1varchoices[i], Nminus1_psel_mu->GetBinContent(i+1)-0. );
        Nminus1_psel_pi_diff->Fill(nminus1varchoices[i], Nminus1_psel_pi->GetBinContent(i+1)-0. );
        Nminus1_psel_p_diff->Fill(nminus1varchoices[i], 0.898458-Nminus1_psel_p->GetBinContent(i+1) );
        Nminus1_psel_e_diff->Fill(nminus1varchoices[i], Nminus1_psel_e->GetBinContent(i+1)-0. );
        Nminus1_esel_mu_diff->Fill(nminus1varchoices[i], Nminus1_esel_mu->GetBinContent(i+1)-0. );
        Nminus1_esel_pi_diff->Fill(nminus1varchoices[i], Nminus1_esel_pi->GetBinContent(i+1)-0. );
        Nminus1_esel_p_diff->Fill(nminus1varchoices[i], Nminus1_esel_p->GetBinContent(i+1)-0. );
        Nminus1_esel_e_diff->Fill(nminus1varchoices[i], 0.932428-Nminus1_esel_e->GetBinContent(i+1) );
    }
    
    
    
    TCanvas* canvas_Nminus1_choices_diff = new TCanvas("canvas_Nminus1_choices_diff","",200,10,1000,800);
    //canvas_Nminus1_choices_sig->cd(2);
    Nminus1_musel_mu_diff->GetYaxis()->SetRangeUser(-0.015, 0.04);
    Nminus1_musel_mu_diff->GetXaxis()->SetRangeUser(0, 17);
    Nminus1_musel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency (all variables - variable removed)");
    Nminus1_musel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    Nminus1_musel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    Nminus1_musel_mu_diff->GetYaxis()->SetTitleOffset(1.6);
    
    Nminus1_musel_mu_diff->Draw("B");
    Nminus1_pisel_pi_diff->Draw("B same");
    Nminus1_psel_p_diff->Draw("B same");
    Nminus1_esel_e_diff->Draw("B same");
    
    //canvas_Nminus1_choices_diff->BuildLegend();
    legend_sig->Draw();
    
    //TCanvas* canvas_Nminus1_choices_bkg_diff = new TCanvas("canvas_Nminus1_choices_bkg_diff","",200,10,1000,800);
    canvas_Nminus1_choices_bkg->cd(2);
    Nminus1_pisel_mu_diff->GetYaxis()->SetRangeUser(-0.1, 0.1);
    Nminus1_pisel_mu_diff->GetXaxis()->SetRangeUser(0, 18);
    Nminus1_pisel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
    Nminus1_pisel_mu_diff->GetYaxis()->SetLabelSize(0.025);
    Nminus1_pisel_mu_diff->GetYaxis()->SetTitleSize(0.025);
    Nminus1_pisel_mu_diff->GetYaxis()->SetTitleOffset(1.5);
    
    Nminus1_pisel_mu_diff->Draw("B");
    Nminus1_psel_mu_diff->Draw("B same");
    Nminus1_esel_mu_diff->Draw("B same");
    Nminus1_musel_pi_diff->Draw("B same");
    Nminus1_psel_pi_diff->Draw("B same");
    Nminus1_esel_pi_diff->Draw("B same");
    Nminus1_musel_p_diff->Draw("B same");
    Nminus1_pisel_p_diff->Draw("B same");
    Nminus1_esel_p_diff->Draw("B same");
    Nminus1_musel_e_diff->Draw("B same");
    Nminus1_pisel_e_diff->Draw("B same");
    Nminus1_psel_e_diff->Draw("B same");
    
    //canvas_Nminus1_choices_bkg_diff->BuildLegend();

}
