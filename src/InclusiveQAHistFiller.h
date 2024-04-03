// ----------------------------------------------------------------------------
// 'InclusiveQAHistFiller.h'
// Derek Anderson
// 04.03.2024
//
// A submodule for the TracksInJetsQAMaker F4A module
// to produce QA histograms for tracks and more in
// jets
// ----------------------------------------------------------------------------

#ifndef TRACKSINJETSQAMAKER_INCLUSIVEQAHISTFILLER_H
#define TRACKSINJETSQAMAKER_INCLUSIVEQAHISTFILLER_H

// c+ utilities
#include <string>
// f4a libraries
#include <
// submodule definitions
#include "HitQAMaker.h"
#include "ClustQAMaker.h"
#include "TrackQAMaker.h"
#include "JetQAMaker.h"



// InclusiveQAHistFiller ----------------------------------------------------------

class InclusiveQAHistFiller {

  public:

    enum JetType {Trk, Full, Calo};

    // ctor/dtor
    InclusiveQAHistFiller()  {};
    ~InclusiveQAHistFiller() {};

    // external methods
    Init();
    Fill(PHCompositeNode* topNode);
    End();

  private:

    // submodules to use
    HitQAMaker*   m_hitMaker   = NULL;
    ClustQAMaker* m_clustMaker = NULL;
    TrackQAMaker* m_trackMaker = NULL;
    JetQAMaker*   m_jetMaker   = NULL;

    // internal methods
    /* TODO fill in */

};  // end InclusiveQAHistFiller

#endif

// end ------------------------------------------------------------------------
