//
//  plotZc.c
//  
//
//  Created by Justin Stevens on 3/18/20.
//

void plotZc(int Ee = 10, int Ep = 100) {

    TFile *file[3];
    TString detectors[3] = {"beast", "jleic", "ephenix"};
    TString detectorLabel[3] = {"BeAST", "JLEIC", "ePHENIX"};
    int color[3] = {1,2,4};

    const int num1D = 2; const int num2D = 6;
    TString name1D[num1D] = {"MassElePos","MassJpsiPion"};
    TString name2D[num2D] = {"DeltaPOverPVsEtaEle","DeltaPOverPVsEtaPos","DeltaPOverPVsEtaPion","PVsEtaEle","PVsEtaPos","PVsEtaPion"};
    TH1F *h1[3];
    TH2F *h2[3];
    
    TCanvas *cc = new TCanvas("cc", "cc", 900, 400); cc->Divide(3,1);
    TCanvas *dd = new TCanvas("dd", "dd", 900, 400); dd->Divide(3,1);
    
    // process data from each detector in series
    for(int i=0; i<3; i++) {
        cout<<"Plotting detector: "<<detectors[i].Data()<<endl;
        file[i] = TFile::Open(Form("../outHist/output_%s_%d_%d.root", detectors[i].Data(), Ee, Ep));
    }
    
    TLine ln[3];
    for(int j=0; j<num1D; j++) {
        for(int i=0; i<3; i++) {
            cc->cd(i+1);
            
            h1[i] = (TH1F*)file[i]->Get(name1D[j]);
            h1[i]->SetLineColor(color[i]);
            h1[i]->Draw();
            //else h1[i]->Draw("same");
            
            // add labels and lines to plot
            double vertical = h1[i]->GetMaximum()*0.75;
            double vertical_offset = vertical * 0.1;
            double horizontal = 2.4;
            ln[i] = TLine(3.1,0,3.1,h1[i]->GetMaximum());
            if(j>0) {
                horizontal = 3.4;
                ln[i] = TLine(3.9,0,3.9,h1[i]->GetMaximum());
            }
            
            auto *th1 = new TText(horizontal,vertical,Form("%s", detectorLabel[i].Data()));
            th1->SetTextAlign(21); th1->SetTextSize(0.07);
            auto *th2 = new TText(horizontal,vertical-vertical_offset,Form("%d x %d", Ee, Ep));
            th2->SetTextAlign(21); th2->SetTextSize(0.07);
            th1->Draw("same"); th2->Draw("same");
            
            ln[i].SetLineColor(color[i]);
            ln[i].SetLineStyle(kDashed);
            ln[i].Draw("same");
        }
        
        cc->Print(Form("plots/%s_%d_%d.pdf",name1D[j].Data(),Ee,Ep));
    }
            
    for(int j=0; j<num2D; j++) {
        for(int i=0; i<3; i++) {
            dd->cd(i+1);
            
            h2[i] = (TH2F*)file[i]->Get(name2D[j]);
            h2[i]->Draw("colz");
        
            // add labels to plot
            double vertical = 0.07;
            double vertical_offset = 0.015;
            if(j>2) {
                vertical = 16;
                vertical_offset = 1.5;
            }
            auto *th1 = new TText(0.5,vertical,Form("%s", detectorLabel[i].Data()));
            th1->SetTextAlign(21); th1->SetTextSize(0.07);
            auto *th2 = new TText(0.5,vertical-vertical_offset,Form("%d x %d", Ee, Ep));
            th2->SetTextAlign(21); th2->SetTextSize(0.07);
            th1->Draw("same"); th2->Draw("same");
        }
        
        dd->Print(Form("plots/%s_%d_%d.pdf",name2D[j].Data(),Ee,Ep));
    }
        
    return;
}
