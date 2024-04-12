// ----------------------------------------------------------------------------
// 'JetQAHistManager.cc'
// Derek Anderson
// 03.25.2024
//
// A submodule for the TracksInJetsQAMaker module
// to generate QA plots for track jets
// ----------------------------------------------------------------------------

#define TRACKSINJETSQAMAKER_JETQAHISTMANAGER_CC

// submodule definition
#include "JetQAHistManager.h"



// external methods -----------------------------------------------------------

void JetQAHistManager::GetInfo(
  Jet* jet,
  std::optional<std::vector<SvtxTrack*>> tracks
) {

  // collect jet info
  JetQAContent jetContent {
    .eta    = jet -> get_eta(),
    .phi    = jet -> get_phi(),
    .pt     = jet -> get_pt(),
    .nTrk   = 0,
    .ptSum  = 0.
  };

  // if tracks are available, do calculations 
  if (tracks.has_value()) {
    for (SvtxTrack* track : tracks.value()) {

      jetContent.nTrk++;
      jetContent.ptSum += track -> get_pt();

    }  // end track loop
  }  // end if tracks.has_value

  // fill histograms
  FillHistograms(Type::All, jetContent);
  return;

}  // end 'Process(PHCompositeNode*)'



// internal methods -----------------------------------------------------------

void JetQAHistManager::FillHistograms(const int type, JetQAContent& content) {

  // fill 1d histograms
  m_vecHist1D.at(type).at(H1D::Eta)   -> Fill(content.eta);
  m_vecHist1D.at(type).at(H1D::Phi)   -> Fill(content.phi);
  m_vecHist1D.at(type).at(H1D::Pt)    -> Fill(content.pt);
  m_vecHist1D.at(type).at(H1D::NTrk)  -> Fill(content.nTrk);
  m_vecHist1D.at(type).at(H1D::PtSum) -> Fill(content.ptSum);

  // fill 2d histograms
  m_vecHist2D.at(type).at(H2D::PtVsEta)   -> Fill(content.eta, content.pt);
  m_vecHist2D.at(type).at(H2D::PtSumVsPt) -> Fill(content.pt, content.ptSum);
  return;

}  //  end 'FillHistograms(Type, JetQAContent&)'



void JetQAHistManager::DefineHistograms() {

  // grab binning schemes
  std::vector<BinDef> vecBins = m_hist.GetVecHistBins();

  // histogram labels
  m_vecHistTypes.push_back( "All" );

  // 1d histogram definitions
  m_vecHistDef1D.push_back( std::make_tuple( "JetEta",   vecBins.at(TracksInJetsQAMakerHistDef::Var::Eta) ));
  m_vecHistDef1D.push_back( std::make_tuple( "JetPhi",   vecBins.at(TracksInJetsQAMakerHistDef::Var::Phi) ));
  m_vecHistDef1D.push_back( std::make_tuple( "JetPt",    vecBins.at(TracksInJetsQAMakerHistDef::Var::Ene) ));
  m_vecHistDef1D.push_back( std::make_tuple( "JetNTrks", vecBins.at(TracksInJetsQAMakerHistDef::Var::Num) ));
  m_vecHistDef1D.push_back( std::make_tuple( "SumTrkPt", vecBins.at(TracksInJetsQAMakerHistDef::Var::Ene) ));

  // 2d histogram definitions
  m_vecHistDef2D.push_back(
    std::make_tuple(
      "JetPtVsEta",
      vecBins.at(TracksInJetsQAMakerHistDef::Var::Eta),
      vecBins.at(TracksInJetsQAMakerHistDef::Var::Ene)
    )
  );
  m_vecHistDef2D.push_back(
    std::make_tuple(
      "SumTrkVsJetPt",
      vecBins.at(TracksInJetsQAMakerHistDef::Var::Ene),
      vecBins.at(TracksInJetsQAMakerHistDef::Var::Ene)
    )
  );
  return;

}  // end 'DefineHistograms()'

// end ------------------------------------------------------------------------


