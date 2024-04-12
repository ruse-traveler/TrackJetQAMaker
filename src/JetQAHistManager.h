// ----------------------------------------------------------------------------
// 'JetQAHistManager.h'
// Derek Anderson
// 03.26.2024
//
// A submodule for the TracksInJetsQAMaker module
// to generate QA plots for track jets
// ----------------------------------------------------------------------------

#ifndef TRACKSINJETSQAMAKER_JETQAHISTMANAGER_H
#define TRACKSINJETSQAMAKER_JETQAHISTMANAGER_H

// c++ utilities
#include <limits>
#include <vector>
#include <utility>
#include <optional>
// root libraries
#include <TH1.h>
#include <TH2.h>
// jet libraries
#include <jetbase/Jet.h>
// tracking libraries
#include <trackbase_historic/SvtxTrack.h>
// submodule definitions
#include "BaseQAHistManager.h"



// JetQAHistManager definition ------------------------------------------------

class JetQAHistManager : public BaseQAHistManager {

  public:

    // histogram accessors
    enum Type {All};
    enum H1D  {Eta, Phi, Pt, NTrk, PtSum};
    enum H2D  {PtVsEta, PtSumVsPt};

    // histogram content
    struct JetQAContent {
      double eta   = std::numeric_limits<double>::max();
      double phi   = std::numeric_limits<double>::max();
      double pt    = std::numeric_limits<double>::max();
      double nTrk  = std::numeric_limits<double>::max();
      double ptSum = std::numeric_limits<double>::max();
    };

    // ctor/dtor
    JetQAHistManager() : BaseQAHistManager() {};
    ~JetQAHistManager() {};

    // external methods
    void GetInfo(Jet* jet, std::optional<std::vector<SvtxTrack*>> tracks = std::nullopt);

  private:

    // internal methods
    void FillHistograms(const int type, JetQAContent& content);

    // inherited interal methods
    void DefineHistograms() override;

};  // end JetQAHistManager

#endif

// end ------------------------------------------------------------------------
