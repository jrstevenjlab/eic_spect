//
//  plotMass.c
//  
//
//  Created by Justin Stevens on 3/18/20.
//

void plotMass(int Ee = 10, int Ep = 100, TString sample = "zc_pythia") {

    gStyle->SetOptStat(0);

    TFile *file[3];
    TFile *filePythia[3];
    TString samplePythia = "ep_lowQ2";

    TString detectors[3] = {"handbook", "beast", "jleic"};
    TString detectorLabel[3] = {"Handbook", "BeAST", "JLEIC"};
    int color[3] = {1,2,4};

    const int num1D = 2; const int numLabels = 4;
    TString name1D[num1D] = {"MassElePos","MassJpsiPion"};
    TString labels[numLabels] = {"All","1sig","2sig","3sig"};
    TString epi[numLabels] = {"No","1#sigma","2#sigma","3#sigma"};

    TH1F *h1[3];
    TH1F *h1Zc[3];
    TH1F *h1Pythia[3];
    double zc_sigma = 50e-9; // units barns
    double scale = zc_sigma * 0.05 / 10000 * 10e6 / 10e-6; // zc_sigma * BR(J/psi->ee) / Nzc * Npyt / pythia sigma
    int rebin = 2;

    TCanvas *cc = new TCanvas("cc", "cc", 1000, 350); cc->Divide(4,1);
    
    // process data from each detector in series
    for(int i=0; i<1; i++) {
        cout<<"Plotting detector: "<<detectors[i].Data()<<endl;
        file[i] = TFile::Open(Form("../outHist/output_%s_%s_%d_%d.root", sample.Data(), detectors[i].Data(), Ee, Ep));
	filePythia[i] = TFile::Open(Form("../outHist/output_%s_%s_%d_%d.root", samplePythia.Data(), detectors[i].Data(), Ee, Ep));
    }
    
    TLine ln[3];
    for(int j=0; j<num1D; j++) { // 1D plot names
      for(int k=0; k<numLabels; k++) { // e/pi cut labels
	 for(int i=0; i<1; i++) { // detector
	    cc->cd(k+1);
            
	    h1Zc[i] = (TH1F*)file[i]->Get(name1D[j]+labels[k]);
	    h1Pythia[i] = (TH1F*)filePythia[i]->Get(name1D[j]+labels[k]);

	    // histogram settings
	    h1Zc[i]->Rebin(rebin);
	    h1Pythia[i]->Rebin(rebin);
	    h1Zc[i]->SetLineColor(kBlue);
	    h1Pythia[i]->SetLineColor(kRed);

	    // combine signal and background with weight
	    h1[i] = (TH1F*)h1Pythia[i]->Clone();
	    h1[i]->Add(h1Zc[i], scale);

	    h1[i]->SetLineColor(kBlack);
	    h1[i]->SetMinimum(0);
            h1[i]->Draw();
	    h1Pythia[i]->Draw("same");
            //else h1[i]->Draw("same");
	    
            // add labels and lines to plot
            double vertical = h1[i]->GetMaximum()*0.2;
            double vertical_offset2 = h1[i]->GetMaximum() * 0.07;
	    double vertical_offset3 = h1[i]->GetMaximum() * 0.14;
            double horizontal = 2.75;
            ln[i] = TLine(3.1,0,3.1,h1[i]->GetMaximum());
            if(j>0) {
		vertical = h1[i]->GetMaximum()*0.85;
                horizontal = 4.25;
                ln[i] = TLine(3.9,0,3.9,h1[i]->GetMaximum());
	    }
	    
	    auto *th1 = new TText(horizontal,vertical,Form("%d x %d", Ee, Ep));
            th1->SetTextAlign(21); th1->SetTextSize(0.07);
            auto *th2 = new TText(horizontal,vertical-vertical_offset2,Form("%s", detectorLabel[i].Data()));
            th2->SetTextAlign(21); th2->SetTextSize(0.07);
	    auto *th3 = new TLatex(horizontal,vertical-vertical_offset3,Form("%s e/#pi", epi[k].Data()));
            th3->SetTextAlign(21); th3->SetTextSize(0.07);
            th1->Draw("same"); th2->Draw("same"); th3->Draw("same");
            
            //ln[i].SetLineColor(color[i]);
            //ln[i].SetLineStyle(kDashed);
            //ln[i].Draw("same");
        }
      }
      cc->Print(Form("plots/%s_%s_%d_%d.pdf",name1D[j].Data(),sample.Data(),Ee,Ep));
    }        

    return;
}
