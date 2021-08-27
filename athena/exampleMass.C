#include "DDEve/DDEveEventData.h"

auto momenta_from_reco(const std::vector<eic::ReconstructedParticleData>& parts) {
	std::vector<ROOT::Math::PxPyPzMVector> momenta{parts.size()};
	for(size_t i=0; i<parts.size(); i++) {
		momenta.push_back(ROOT::Math::PxPyPzMVector{parts[i].p.x, parts[i].p.y, parts[i].p.z, parts[i].mass});
	}
	return momenta;
}

auto momenta_from_gen(const std::vector<dd4pod::Geant4ParticleData>& parts) {
	std::vector<ROOT::Math::PxPyPzMVector> momenta{parts.size()};
	for(size_t i=0; i<parts.size(); i++) {
		if(parts[i].g4Parent != 0) continue; // check it's initial generated particle
		momenta.push_back(ROOT::Math::PxPyPzMVector{parts[i].ps.x, parts[i].ps.y, parts[i].ps.z, parts[i].mass});
	}
	return momenta;
}

// compute invariant mass from list of 4-vectors
auto mass(const std::vector<ROOT::Math::PxPyPzMVector>& mom) {
  ROOT::Math::PxPyPzMVector sum, sum2pi, sumJpsi;
  for(uint i=0; i<mom.size(); i++) {
    ROOT::Math::PxPyPzMVector part = mom[i];
    if(fabs(part.M()-0.00051) < 0.01 && part.Theta()<2.9) sumJpsi += part;
    if(fabs(part.M()-0.13957) < 0.01) sum2pi += mom[i];
  }
  sum = sum2pi + sumJpsi;

  return sum.M();
}

void exampleMass() {

	// Create chain of ROOT trees on S3 service
	TChain chain("events");
	TString version = "master"; //"acadia-v1.0-alpha";
	for(int i=1; i<=1; i++) {
		chain.Add(Form("s3https://dtn01.sdcc.bnl.gov:9000/eictest/ATHENA/RECO/%s/SPECTROSCOPY/psi2s_10_100.%04d.root", version.Data(), i));
		//chain.Add(Form("s3https://dtn01.sdcc.bnl.gov:9000/eictest/ATHENA/RECO/%s/SPECTROSCOPY/x_10_100.%04d.root", version.Data(), i));
		//chain.Add(Form("s3https://dtn01.sdcc.bnl.gov:9000/eictest/ATHENA/RECO/%s/SPECTROSCOPY/y_10_100.%04d.root", version.Data(), i));
	}

	// Create data frame with TChain and define new columns with mass function
	ROOT::RDataFrame d(chain);
	auto dframe = d.Filter("ReconstructedParticles.size() == 4").Define("pgen", momenta_from_gen, {"mcparticles2"}).Define("Mgen", mass, {"pgen"}).Define("preco", momenta_from_reco, {"ReconstructedParticles"}).Define("Mreco", mass, {"preco"});
	
	// Plot mass histograms from data frame
	auto hmass = dframe.Fill<double>(TH1D("hmass", "; Reconstructed Mass (GeV); counts", 200, 2.0, 4.5), {"Mreco"});
	hmass->DrawClone("hist");
	
	auto hmass2D = dframe.Fill<double, double>(TH2D("hmass2D", "; Generated Mass (GeV); Reconstructed Mass (GeV)", 200, -0.5, 4.5, 200, -0.5, 4.5), {"Mgen", "Mreco"});
	hmass2D->DrawClone("colz");

	return;
}
