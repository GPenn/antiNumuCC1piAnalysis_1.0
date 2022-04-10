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
    
    const char *nminus1varchoices[16] = {"Momentum","Angle","FGD1 E/L","FGD2 E/L","TPC2 mu-like","TPC2 pi-like","TPC2 p-like","TPC2 e-like",
                                   "TPC3 dE/dx","ECal EM energy","ECal E/L", "ECal circularity","ECal FBR", "ECal TMR", "ECal QRMS", "nSMRDs"};
    
    TH1F* Nminus1_musel_mu = new TH1F("Nminus1_musel_mu","#mu^{+} identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_musel_pi = new TH1F("Nminus1_musel_pi","#pi^{+} identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_musel_p = new TH1F("Nminus1_musel_p","p identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_musel_e = new TH1F("Nminus1_musel_e","e^{+} identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_pisel_mu = new TH1F("Nminus1_pisel_mu","#mu^{+} identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_pisel_pi = new TH1F("Nminus1_pisel_pi","#pi^{+} identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_pisel_p = new TH1F("Nminus1_pisel_p","p identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_pisel_e = new TH1F("Nminus1_pisel_e","e^{+} identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_psel_mu = new TH1F("Nminus1_psel_mu","#mu^{+} identified as p",4,0,4);
    TH1F* Nminus1_psel_pi = new TH1F("Nminus1_psel_pi","#pi^{+} identified as p",4,0,4);
    TH1F* Nminus1_psel_p = new TH1F("Nminus1_psel_p","p identified as p",4,0,4);
    TH1F* Nminus1_psel_e = new TH1F("Nminus1_psel_e","e^{+} identified as p",4,0,4);
    TH1F* Nminus1_esel_mu = new TH1F("Nminus1_esel_mu","#mu^{+} identified as e^{+}",4,0,4);
    TH1F* Nminus1_esel_pi = new TH1F("Nminus1_esel_pi","#pi^{+} identified as e^{+}",4,0,4);
    TH1F* Nminus1_esel_p = new TH1F("Nminus1_esel_p","p identified as e^{+}",4,0,4);
    TH1F* Nminus1_esel_e = new TH1F("Nminus1_esel_e","e^{+} identified as e^{+}",4,0,4);
    
    TH1F* Nminus1_musel_mu_diff = new TH1F("Nminus1_musel_mu_diff","#mu^{+} identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_musel_pi_diff = new TH1F("Nminus1_musel_pi_diff","#pi^{+} identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_musel_p_diff = new TH1F("Nminus1_musel_p_diff","p identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_musel_e_diff = new TH1F("Nminus1_musel_e_diff","e^{+} identified as #mu^{+}",4,0,4);
    TH1F* Nminus1_pisel_mu_diff = new TH1F("Nminus1_pisel_mu_diff","#mu^{+} identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_pisel_pi_diff = new TH1F("Nminus1_pisel_pi_diff","#pi^{+} identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_pisel_p_diff = new TH1F("Nminus1_pisel_p_diff","p identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_pisel_e_diff = new TH1F("Nminus1_pisel_e_diff","e^{+} identified as #pi^{+}",4,0,4);
    TH1F* Nminus1_psel_mu_diff = new TH1F("Nminus1_psel_mu_diff","#mu^{+} identified as p",4,0,4);
    TH1F* Nminus1_psel_pi_diff = new TH1F("Nminus1_psel_pi_diff","#pi^{+} identified as p",4,0,4);
    TH1F* Nminus1_psel_p_diff = new TH1F("Nminus1_psel_p_diff","p identified as p",4,0,4);
    TH1F* Nminus1_psel_e_diff = new TH1F("Nminus1_psel_e_diff","e^{+} identified as p",4,0,4);
    TH1F* Nminus1_esel_mu_diff = new TH1F("Nminus1_esel_mu_diff","#mu^{+} identified as e^{+}",4,0,4);
    TH1F* Nminus1_esel_pi_diff = new TH1F("Nminus1_esel_pi_diff","#pi^{+} identified as e^{+}",4,0,4);
    TH1F* Nminus1_esel_p_diff = new TH1F("Nminus1_esel_p_diff","p identified as e^{+}",4,0,4);
    TH1F* Nminus1_esel_e_diff = new TH1F("Nminus1_esel_e_diff","e^{+} identified as e^{+}",4,0,4);
    
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
    
    // Momentum
    
    Nminus1_musel_mu->Fill(nminus1varchoices[0],0.928925);
    Nminus1_musel_pi->Fill(nminus1varchoices[0],0.375533); 
    Nminus1_musel_p->Fill(nminus1varchoices[0],0.0321147);
    Nminus1_musel_e->Fill(nminus1varchoices[0],0.0291757);
    Nminus1_pisel_mu->Fill(nminus1varchoices[0],0.0638082);
    Nminus1_pisel_pi->Fill(nminus1varchoices[0],0.593661);
    Nminus1_pisel_p->Fill(nminus1varchoices[0],0.0655526);
    Nminus1_pisel_e->Fill(nminus1varchoices[0],0.102137);
    Nminus1_psel_mu->Fill(nminus1varchoices[0],0.00697722);
    Nminus1_psel_pi->Fill(nminus1varchoices[0],0.0290292);
    Nminus1_psel_p->Fill(nminus1varchoices[0],0.88832);
    Nminus1_psel_e->Fill(nminus1varchoices[0],0.272434);
    Nminus1_esel_mu->Fill(nminus1varchoices[0],0.000289511);
    Nminus1_esel_pi->Fill(nminus1varchoices[0],0.00177623);
    Nminus1_esel_p->Fill(nminus1varchoices[0],0.0140131);
    Nminus1_esel_e->Fill(nminus1varchoices[0],0.596253);
    
    // Theta
    
    Nminus1_musel_mu->Fill(nminus1varchoices[1],0.934165);
    Nminus1_musel_pi->Fill(nminus1varchoices[1],0.364754); 
    Nminus1_musel_p->Fill(nminus1varchoices[1],0.0273136);
    Nminus1_musel_e->Fill(nminus1varchoices[1],0.0399711);
    Nminus1_pisel_mu->Fill(nminus1varchoices[1],0.0593063);
    Nminus1_pisel_pi->Fill(nminus1varchoices[1],0.607366);
    Nminus1_pisel_p->Fill(nminus1varchoices[1],0.0665705);
    Nminus1_pisel_e->Fill(nminus1varchoices[1],0.11685);
    Nminus1_psel_mu->Fill(nminus1varchoices[1],0.00619554);
    Nminus1_psel_pi->Fill(nminus1varchoices[1],0.0258076);
    Nminus1_psel_p->Fill(nminus1varchoices[1],0.895716);
    Nminus1_psel_e->Fill(nminus1varchoices[1],0.214628);
    Nminus1_esel_mu->Fill(nminus1varchoices[1],0.000332938);
    Nminus1_esel_pi->Fill(nminus1varchoices[1],0.00207227);
    Nminus1_esel_p->Fill(nminus1varchoices[1],0.0103995);
    Nminus1_esel_e->Fill(nminus1varchoices[1],0.628551);
    
    // FGD1 E/L
    
    Nminus1_musel_mu->Fill(nminus1varchoices[2],0.93431);
    Nminus1_musel_pi->Fill(nminus1varchoices[2],0.37623); 
    Nminus1_musel_p->Fill(nminus1varchoices[2],0.0340657);
    Nminus1_musel_e->Fill(nminus1varchoices[2],0.0373201);
    Nminus1_pisel_mu->Fill(nminus1varchoices[2],0.0584378);
    Nminus1_pisel_pi->Fill(nminus1varchoices[2],0.593731);
    Nminus1_pisel_p->Fill(nminus1varchoices[2],0.075545);
    Nminus1_pisel_e->Fill(nminus1varchoices[2],0.120944);
    Nminus1_psel_mu->Fill(nminus1varchoices[2],0.00703512);
    Nminus1_psel_pi->Fill(nminus1varchoices[2],0.0286809);
    Nminus1_psel_p->Fill(nminus1varchoices[2],0.876631);
    Nminus1_psel_e->Fill(nminus1varchoices[2],0.256602);
    Nminus1_esel_mu->Fill(nminus1varchoices[2],0.000217133);
    Nminus1_esel_pi->Fill(nminus1varchoices[2],0.00135829);
    Nminus1_esel_p->Fill(nminus1varchoices[2],0.0137586);
    Nminus1_esel_e->Fill(nminus1varchoices[2],0.585134);
    
    // FGD2 E/L
    
    Nminus1_musel_mu->Fill(nminus1varchoices[3],0.925234);
    Nminus1_musel_pi->Fill(nminus1varchoices[3],0.374471); 
    Nminus1_musel_p->Fill(nminus1varchoices[3],0.0284672);
    Nminus1_musel_e->Fill(nminus1varchoices[3],0.0375263);
    Nminus1_pisel_mu->Fill(nminus1varchoices[3],0.0672245);
    Nminus1_pisel_pi->Fill(nminus1varchoices[3],0.596587);
    Nminus1_pisel_p->Fill(nminus1varchoices[3],0.0676733);
    Nminus1_pisel_e->Fill(nminus1varchoices[3],0.117086);
    Nminus1_psel_mu->Fill(nminus1varchoices[3],0.0071654);
    Nminus1_psel_pi->Fill(nminus1varchoices[3],0.0266957);
    Nminus1_psel_p->Fill(nminus1varchoices[3],0.891407);
    Nminus1_psel_e->Fill(nminus1varchoices[3],0.246322);
    Nminus1_esel_mu->Fill(nminus1varchoices[3],0.000376364);
    Nminus1_esel_pi->Fill(nminus1varchoices[3],0.00224641);
    Nminus1_esel_p->Fill(nminus1varchoices[3],0.0124523);
    Nminus1_esel_e->Fill(nminus1varchoices[3],0.599066);
    
    // TPC2 mu-like
    
    Nminus1_musel_mu->Fill(nminus1varchoices[4],0.936539);
    Nminus1_musel_pi->Fill(nminus1varchoices[4],0.366112); 
    Nminus1_musel_p->Fill(nminus1varchoices[4],0.0274324);
    Nminus1_musel_e->Fill(nminus1varchoices[4],0.0503395);
    Nminus1_pisel_mu->Fill(nminus1varchoices[4],0.0570771);
    Nminus1_pisel_pi->Fill(nminus1varchoices[4],0.607436);
    Nminus1_pisel_p->Fill(nminus1varchoices[4],0.0679108);
    Nminus1_pisel_e->Fill(nminus1varchoices[4],0.109192);
    Nminus1_psel_mu->Fill(nminus1varchoices[4],0.0059784);
    Nminus1_psel_pi->Fill(nminus1varchoices[4],0.0245538);
    Nminus1_psel_p->Fill(nminus1varchoices[4],0.894037);
    Nminus1_psel_e->Fill(nminus1varchoices[4],0.220121);
    Nminus1_esel_mu->Fill(nminus1varchoices[4],0.000405315);
    Nminus1_esel_pi->Fill(nminus1varchoices[4],0.00189813);
    Nminus1_esel_p->Fill(nminus1varchoices[4],0.0106201);
    Nminus1_esel_e->Fill(nminus1varchoices[4],0.620348);
    
    // TPC2 pi-like
    
    Nminus1_musel_mu->Fill(nminus1varchoices[5],0.937755);
    Nminus1_musel_pi->Fill(nminus1varchoices[5],0.364423); 
    Nminus1_musel_p->Fill(nminus1varchoices[5],0.0276699);
    Nminus1_musel_e->Fill(nminus1varchoices[5],0.0376294);
    Nminus1_pisel_mu->Fill(nminus1varchoices[5],0.0560638);
    Nminus1_pisel_pi->Fill(nminus1varchoices[5],0.606948);
    Nminus1_pisel_p->Fill(nminus1varchoices[5],0.0681313);
    Nminus1_pisel_e->Fill(nminus1varchoices[5],0.181269);
    Nminus1_psel_mu->Fill(nminus1varchoices[5],0.00584812);
    Nminus1_psel_pi->Fill(nminus1varchoices[5],0.0265912);
    Nminus1_psel_p->Fill(nminus1varchoices[5],0.89307);
    Nminus1_psel_e->Fill(nminus1varchoices[5],0.201299);
    Nminus1_esel_mu->Fill(nminus1varchoices[5],0.000332938);
    Nminus1_esel_pi->Fill(nminus1varchoices[5],0.00203744);
    Nminus1_esel_p->Fill(nminus1varchoices[5],0.011129);
    Nminus1_esel_e->Fill(nminus1varchoices[5],0.579802);
    
    // TPC2 p-like
    
    Nminus1_musel_mu->Fill(nminus1varchoices[6],0.936858);
    Nminus1_musel_pi->Fill(nminus1varchoices[6],0.365451); 
    Nminus1_musel_p->Fill(nminus1varchoices[6],0.0277377);
    Nminus1_musel_e->Fill(nminus1varchoices[6],0.0388518);
    Nminus1_pisel_mu->Fill(nminus1varchoices[6],0.0564691);
    Nminus1_pisel_pi->Fill(nminus1varchoices[6],0.606043);
    Nminus1_pisel_p->Fill(nminus1varchoices[6],0.0659259);
    Nminus1_pisel_e->Fill(nminus1varchoices[6],0.119162);
    Nminus1_psel_mu->Fill(nminus1varchoices[6],0.00635477);
    Nminus1_psel_pi->Fill(nminus1varchoices[6],0.0266957);
    Nminus1_psel_p->Fill(nminus1varchoices[6],0.89497);
    Nminus1_psel_e->Fill(nminus1varchoices[6],0.265689);
    Nminus1_esel_mu->Fill(nminus1varchoices[6],0.000318462);
    Nminus1_esel_pi->Fill(nminus1varchoices[6],0.00181106);
    Nminus1_esel_p->Fill(nminus1varchoices[6],0.0113665);
    Nminus1_esel_e->Fill(nminus1varchoices[6],0.576297);
    
    // TPC2 e-like
    
    Nminus1_musel_mu->Fill(nminus1varchoices[7],0.936062);
    Nminus1_musel_pi->Fill(nminus1varchoices[7],0.364876); 
    Nminus1_musel_p->Fill(nminus1varchoices[7],0.0278734);
    Nminus1_musel_e->Fill(nminus1varchoices[7],0.0396471);
    Nminus1_pisel_mu->Fill(nminus1varchoices[7],0.0570481);
    Nminus1_pisel_pi->Fill(nminus1varchoices[7],0.607);
    Nminus1_pisel_p->Fill(nminus1varchoices[7],0.0686911);
    Nminus1_pisel_e->Fill(nminus1varchoices[7],0.11872);
    Nminus1_psel_mu->Fill(nminus1varchoices[7],0.00636924);
    Nminus1_psel_pi->Fill(nminus1varchoices[7],0.0257031);
    Nminus1_psel_p->Fill(nminus1varchoices[7],0.892391);
    Nminus1_psel_e->Fill(nminus1varchoices[7],0.259577);
    Nminus1_esel_mu->Fill(nminus1varchoices[7],0.00052112);
    Nminus1_esel_pi->Fill(nminus1varchoices[7],0.00242055);
    Nminus1_esel_p->Fill(nminus1varchoices[7],0.0110442);
    Nminus1_esel_e->Fill(nminus1varchoices[7],0.582056);
    
    // TPC3 dE/dx
    
    Nminus1_musel_mu->Fill(nminus1varchoices[8],0.943777);
    Nminus1_musel_pi->Fill(nminus1varchoices[8],0.381106); 
    Nminus1_musel_p->Fill(nminus1varchoices[8],0.0303503);
    Nminus1_musel_e->Fill(nminus1varchoices[8],0.0196026);
    Nminus1_pisel_mu->Fill(nminus1varchoices[8],0.0483483);
    Nminus1_pisel_pi->Fill(nminus1varchoices[8],0.57468);
    Nminus1_pisel_p->Fill(nminus1varchoices[8],0.0570871);
    Nminus1_pisel_e->Fill(nminus1varchoices[8],0.0185422);
    Nminus1_psel_mu->Fill(nminus1varchoices[8],0.00555861);
    Nminus1_psel_pi->Fill(nminus1varchoices[8],0.0259469);
    Nminus1_psel_p->Fill(nminus1varchoices[8],0.860429);
    Nminus1_psel_e->Fill(nminus1varchoices[8],0.0394557);
    Nminus1_esel_mu->Fill(nminus1varchoices[8],0.00231609);
    Nminus1_esel_pi->Fill(nminus1varchoices[8],0.0182673);
    Nminus1_esel_p->Fill(nminus1varchoices[8],0.0521333);
    Nminus1_esel_e->Fill(nminus1varchoices[8],0.922399);
    
    // ECal EM energy
    
    Nminus1_musel_mu->Fill(nminus1varchoices[9],0.935931);
    Nminus1_musel_pi->Fill(nminus1varchoices[9],0.366461); 
    Nminus1_musel_p->Fill(nminus1varchoices[9],0.0290101);
    Nminus1_musel_e->Fill(nminus1varchoices[9],0.0403393);
    Nminus1_pisel_mu->Fill(nminus1varchoices[9],0.0569468);
    Nminus1_pisel_pi->Fill(nminus1varchoices[9],0.604876);
    Nminus1_pisel_p->Fill(nminus1varchoices[9],0.0662143);
    Nminus1_pisel_e->Fill(nminus1varchoices[9],0.117748);
    Nminus1_psel_mu->Fill(nminus1varchoices[9],0.00676008);
    Nminus1_psel_pi->Fill(nminus1varchoices[9],0.0266086);
    Nminus1_psel_p->Fill(nminus1varchoices[9],0.893681);
    Nminus1_psel_e->Fill(nminus1varchoices[9],0.245556);
    Nminus1_esel_mu->Fill(nminus1varchoices[9],0.000361889);
    Nminus1_esel_pi->Fill(nminus1varchoices[9],0.00205485);
    Nminus1_esel_p->Fill(nminus1varchoices[9],0.0110951);
    Nminus1_esel_e->Fill(nminus1varchoices[9],0.596356);
    
    // ECal E/L
    
    Nminus1_musel_mu->Fill(nminus1varchoices[10],0.932168);
    Nminus1_musel_pi->Fill(nminus1varchoices[10],0.36754); 
    Nminus1_musel_p->Fill(nminus1varchoices[10],0.0415981);
    Nminus1_musel_e->Fill(nminus1varchoices[10],0.0374969);
    Nminus1_pisel_mu->Fill(nminus1varchoices[10],0.0592919);
    Nminus1_pisel_pi->Fill(nminus1varchoices[10],0.603936);
    Nminus1_pisel_p->Fill(nminus1varchoices[10],0.0656375);
    Nminus1_pisel_e->Fill(nminus1varchoices[10],0.114508);
    Nminus1_psel_mu->Fill(nminus1varchoices[10],0.00822211);
    Nminus1_psel_pi->Fill(nminus1varchoices[10],0.0262603);
    Nminus1_psel_p->Fill(nminus1varchoices[10],0.88245);
    Nminus1_psel_e->Fill(nminus1varchoices[10],0.252154);
    Nminus1_esel_mu->Fill(nminus1varchoices[10],0.000318462);
    Nminus1_esel_pi->Fill(nminus1varchoices[10],0.00226382);
    Nminus1_esel_p->Fill(nminus1varchoices[10],0.0103147);
    Nminus1_esel_e->Fill(nminus1varchoices[10],0.595841);
    
    // ECal circularity
    
    Nminus1_musel_mu->Fill(nminus1varchoices[11],0.936684);
    Nminus1_musel_pi->Fill(nminus1varchoices[11],0.368306); 
    Nminus1_musel_p->Fill(nminus1varchoices[11],0.0280601);
    Nminus1_musel_e->Fill(nminus1varchoices[11],0.0420036);
    Nminus1_pisel_mu->Fill(nminus1varchoices[11],0.0567152);
    Nminus1_pisel_pi->Fill(nminus1varchoices[11],0.603222);
    Nminus1_pisel_p->Fill(nminus1varchoices[11],0.0668589);
    Nminus1_pisel_e->Fill(nminus1varchoices[11],0.115687);
    Nminus1_psel_mu->Fill(nminus1varchoices[11],0.00625344);
    Nminus1_psel_pi->Fill(nminus1varchoices[11],0.0266434);
    Nminus1_psel_p->Fill(nminus1varchoices[11],0.89424);
    Nminus1_psel_e->Fill(nminus1varchoices[11],0.246822);
    Nminus1_esel_mu->Fill(nminus1varchoices[11],0.000347413);
    Nminus1_esel_pi->Fill(nminus1varchoices[11],0.00182847);
    Nminus1_esel_p->Fill(nminus1varchoices[11],0.0108406);
    Nminus1_esel_e->Fill(nminus1varchoices[11],0.595487);
    
    // ECal FBR
    
    Nminus1_musel_mu->Fill(nminus1varchoices[12],0.936655);
    Nminus1_musel_pi->Fill(nminus1varchoices[12],0.363761); 
    Nminus1_musel_p->Fill(nminus1varchoices[12],0.0279243);
    Nminus1_musel_e->Fill(nminus1varchoices[12],0.0407075);
    Nminus1_pisel_mu->Fill(nminus1varchoices[12],0.0566139);
    Nminus1_pisel_pi->Fill(nminus1varchoices[12],0.607384);
    Nminus1_pisel_p->Fill(nminus1varchoices[12],0.0654848);
    Nminus1_pisel_e->Fill(nminus1varchoices[12],0.111239);
    Nminus1_psel_mu->Fill(nminus1varchoices[12],0.00635477);
    Nminus1_psel_pi->Fill(nminus1varchoices[12],0.026626);
    Nminus1_psel_p->Fill(nminus1varchoices[12],0.895598);
    Nminus1_psel_e->Fill(nminus1varchoices[12],0.230372);
    Nminus1_esel_mu->Fill(nminus1varchoices[12],0.000376364);
    Nminus1_esel_pi->Fill(nminus1varchoices[12],0.00222899);
    Nminus1_esel_p->Fill(nminus1varchoices[12],0.0109933);
    Nminus1_esel_e->Fill(nminus1varchoices[12],0.617682);
    
    // ECal TMR
    
    Nminus1_musel_mu->Fill(nminus1varchoices[13],0.936771);
    Nminus1_musel_pi->Fill(nminus1varchoices[13],0.363936); 
    Nminus1_musel_p->Fill(nminus1varchoices[13],0.0282976);
    Nminus1_musel_e->Fill(nminus1varchoices[13],0.040251);
    Nminus1_pisel_mu->Fill(nminus1varchoices[13],0.0564836);
    Nminus1_pisel_pi->Fill(nminus1varchoices[13],0.607384);
    Nminus1_pisel_p->Fill(nminus1varchoices[13],0.0672322);
    Nminus1_pisel_e->Fill(nminus1varchoices[13],0.124612);
    Nminus1_psel_mu->Fill(nminus1varchoices[13],0.00638372);
    Nminus1_psel_pi->Fill(nminus1varchoices[13],0.0267479);
    Nminus1_psel_p->Fill(nminus1varchoices[13],0.893256);
    Nminus1_psel_e->Fill(nminus1varchoices[13],0.258045);
    Nminus1_esel_mu->Fill(nminus1varchoices[13],0.000361889);
    Nminus1_esel_pi->Fill(nminus1varchoices[13],0.00193296);
    Nminus1_esel_p->Fill(nminus1varchoices[13],0.0112138);
    Nminus1_esel_e->Fill(nminus1varchoices[13],0.577092);
    
    // ECal QRMS
    
    Nminus1_musel_mu->Fill(nminus1varchoices[14],0.936293);
    Nminus1_musel_pi->Fill(nminus1varchoices[14],0.368028); 
    Nminus1_musel_p->Fill(nminus1varchoices[14],0.031487);
    Nminus1_musel_e->Fill(nminus1varchoices[14],0.0402804);
    Nminus1_pisel_mu->Fill(nminus1varchoices[14],0.0567876);
    Nminus1_pisel_pi->Fill(nminus1varchoices[14],0.60296);
    Nminus1_pisel_p->Fill(nminus1varchoices[14],0.0662482);
    Nminus1_pisel_e->Fill(nminus1varchoices[14],0.117881);
    Nminus1_psel_mu->Fill(nminus1varchoices[14],0.00655742);
    Nminus1_psel_pi->Fill(nminus1varchoices[14],0.0270962);
    Nminus1_psel_p->Fill(nminus1varchoices[14],0.891356);
    Nminus1_psel_e->Fill(nminus1varchoices[14],0.25398);
    Nminus1_esel_mu->Fill(nminus1varchoices[14],0.000361889);
    Nminus1_esel_pi->Fill(nminus1varchoices[14],0.00191554);
    Nminus1_esel_p->Fill(nminus1varchoices[14],0.0109085);
    Nminus1_esel_e->Fill(nminus1varchoices[14],0.587858);
    
    // nSMRDs
    
    Nminus1_musel_mu->Fill(nminus1varchoices[15],0.928057);
    Nminus1_musel_pi->Fill(nminus1varchoices[15],0.377588); 
    Nminus1_musel_p->Fill(nminus1varchoices[15],0.0279583);
    Nminus1_musel_e->Fill(nminus1varchoices[15],0.0411935);
    Nminus1_pisel_mu->Fill(nminus1varchoices[15],0.0641412);
    Nminus1_pisel_pi->Fill(nminus1varchoices[15],0.593922);
    Nminus1_pisel_p->Fill(nminus1varchoices[15],0.0658071);
    Nminus1_pisel_e->Fill(nminus1varchoices[15],0.10956);
    Nminus1_psel_mu->Fill(nminus1varchoices[15],0.00746938);
    Nminus1_psel_pi->Fill(nminus1varchoices[15],0.0265216);
    Nminus1_psel_p->Fill(nminus1varchoices[15],0.895835);
    Nminus1_psel_e->Fill(nminus1varchoices[15],0.242478);
    Nminus1_esel_mu->Fill(nminus1varchoices[15],0.000332938);
    Nminus1_esel_pi->Fill(nminus1varchoices[15],0.00196778);
    Nminus1_esel_p->Fill(nminus1varchoices[15],0.0103995);
    Nminus1_esel_e->Fill(nminus1varchoices[15],0.606769);
    
    //TCanvas* canvas_Nminus1_choices = new TCanvas("canvas_Nminus1_choices","",200,10,1000,800);
    TCanvas* canvas_Nminus1_choices_sig = new TCanvas("canvas_Nminus1_choices_sig","",200,10,2000,800);
    canvas_Nminus1_choices_sig->Divide(2,1,0.005,0.005);
    canvas_Nminus1_choices_sig->cd(1);
    Nminus1_musel_mu->GetYaxis()->SetRangeUser(0, 1);
    Nminus1_musel_mu->GetXaxis()->SetRangeUser(0, 17);
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
    Nminus1_pisel_mu->GetXaxis()->SetRangeUser(0, 17);
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
    
    for (int i=0; i < 16; i++) 
    {
        Nminus1_musel_mu_diff->Fill(nminus1varchoices[i], Nminus1_musel_mu->GetBinContent(i+1)-0.936612 );
        Nminus1_musel_pi_diff->Fill(nminus1varchoices[i], Nminus1_musel_pi->GetBinContent(i+1)-0.363204 ); 
        Nminus1_musel_p_diff->Fill(nminus1varchoices[i], Nminus1_musel_p->GetBinContent(i+1)-0.0277038 );
        Nminus1_musel_e_diff->Fill(nminus1varchoices[i], Nminus1_musel_e->GetBinContent(i+1)-0.0397502 );
        Nminus1_pisel_mu_diff->Fill(nminus1varchoices[i], Nminus1_pisel_mu->GetBinContent(i+1)-0.0570192 );
        Nminus1_pisel_pi_diff->Fill(nminus1varchoices[i], Nminus1_pisel_pi->GetBinContent(i+1)-0.609055 );
        Nminus1_pisel_p_diff->Fill(nminus1varchoices[i], Nminus1_pisel_p->GetBinContent(i+1)-0.0665875 );
        Nminus1_pisel_e_diff->Fill(nminus1varchoices[i], Nminus1_pisel_e->GetBinContent(i+1)-0.112491 );
        Nminus1_psel_mu_diff->Fill(nminus1varchoices[i], Nminus1_psel_mu->GetBinContent(i+1)-0.00602183 );
        Nminus1_psel_pi_diff->Fill(nminus1varchoices[i], Nminus1_psel_pi->GetBinContent(i+1)-0.025825 );
        Nminus1_psel_p_diff->Fill(nminus1varchoices[i], Nminus1_psel_p->GetBinContent(i+1)-0.894885 );
        Nminus1_psel_e_diff->Fill(nminus1varchoices[i], Nminus1_psel_e->GetBinContent(i+1)-0.232448 );
        Nminus1_esel_mu_diff->Fill(nminus1varchoices[i], Nminus1_esel_mu->GetBinContent(i+1)-0.000347413 );
        Nminus1_esel_pi_diff->Fill(nminus1varchoices[i], Nminus1_esel_pi->GetBinContent(i+1)-0.00191554 );
        Nminus1_esel_p_diff->Fill(nminus1varchoices[i], Nminus1_esel_p->GetBinContent(i+1)-0.0108236 );
        Nminus1_esel_e_diff->Fill(nminus1varchoices[i], Nminus1_esel_e->GetBinContent(i+1)-0.615311 );
    }
    
    
    
    TCanvas* canvas_Nminus1_choices_diff = new TCanvas("canvas_Nminus1_choices_diff","",200,10,1000,800);
    //canvas_Nminus1_choices_sig->cd(2);
    Nminus1_musel_mu_diff->GetYaxis()->SetRangeUser(-0.05, 0.45);
    Nminus1_musel_mu_diff->GetXaxis()->SetRangeUser(0, 17);
    Nminus1_musel_mu_diff->GetYaxis()->SetTitle("Difference in efficiency");
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
    Nminus1_pisel_mu_diff->GetYaxis()->SetRangeUser(-0.02, 0.07);
    Nminus1_pisel_mu_diff->GetXaxis()->SetRangeUser(0, 17);
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
