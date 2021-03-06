AUTOMAKE_OPTIONS = foreign

INCLUDES = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include  \
  -I${G4_MAIN}/include \
  -I${G4_MAIN}/include/Geant4 \
  -I`root-config --incdir` \
  -I$(OFFLINE_MAIN)/include/eigen3

lib_LTLIBRARIES = \
   libg4hough_io.la \
   libg4hough.la

AM_CXXFLAGS = \
 -Wall -Werror -msse2 -DRAVE -DRaveDllExport=

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

libg4hough_io_la_LIBADD = \
  -lphool

libg4hough_la_LDFLAGS = \
  `geant4-config --libs`

libg4hough_la_LIBADD = \
  -lg4detectors \
  -lfun4all \
  -lHelixHough \
  -lFitNewton \
  -lSeamstress \
  -lg4bbc_io \
  -lcemc_io \
  -lgenfit2 \
  -lgenfit2exp \
  -lPHGenFit \
  libg4hough_io.la

pkginclude_HEADERS = \
  SvtxVertex.h \
  SvtxVertex_v1.h \
  SvtxVertexMap.h \
  SvtxVertexMap_v1.h \
  PHG4SvtxDeadArea.h \
  PHG4SvtxThresholds.h \
  PHG4SvtxAddConnectedCells.h \
  PHG4SvtxDigitizer.h \
  PHG4SvtxClusterizer.h \
  SvtxHit.h \
  SvtxHit_v1.h \
  SvtxHitMap.h \
  SvtxHitMap_v1.h \
  SvtxCluster.h \
  SvtxCluster_v1.h \
  SvtxClusterMap.h \
  SvtxClusterMap_v1.h \
  SvtxTrackState.h \
  SvtxTrackState_v1.h \
  SvtxTrack.h \
  SvtxTrack_v1.h \
  SvtxTrackMap.h \
  SvtxTrackMap_v1.h \
  SvtxBeamSpot.h \
  PHG4HoughTransform.h \
  PHG4HoughTransformTPC.h \
  PHG4TrackGhostRejection.h \
  PHG4TrackKalmanFitter.h \
  PHG4SvtxMomentumRecal.h \
  PHG4SvtxTrackProjection.h \
  PHG4SvtxBeamSpotReco.h \
  PHG4TPCClusterizer.h \
  SimpleTrack.h

libg4hough_io_la_SOURCES = \
  SvtxHit.C \
  SvtxHit_Dict.C \
  SvtxHit_v1.C \
  SvtxHit_v1_Dict.C \
  SvtxHitMap.C \
  SvtxHitMap_Dict.C \
  SvtxHitMap_v1.C \
  SvtxHitMap_v1_Dict.C \
  SvtxCluster.C \
  SvtxCluster_Dict.C \
  SvtxCluster_v1.C \
  SvtxCluster_v1_Dict.C \
  SvtxClusterMap.C \
  SvtxClusterMap_Dict.C \
  SvtxClusterMap_v1.C \
  SvtxClusterMap_v1_Dict.C \
  SvtxTrackState.C \
  SvtxTrackState_Dict.C \
  SvtxTrackState_v1.C \
  SvtxTrackState_v1_Dict.C \
  SvtxTrack.C \
  SvtxTrack_Dict.C \
  SvtxTrack_v1.C \
  SvtxTrack_v1_Dict.C \
  SvtxBeamSpot.C \
  SvtxBeamSpot_Dict.C \
  SvtxTrackMap.C \
  SvtxTrackMap_Dict.C \
  SvtxTrackMap_v1.C \
  SvtxTrackMap_v1_Dict.C \
  SvtxVertex.C \
  SvtxVertex_Dict.C \
  SvtxVertex_v1.C \
  SvtxVertex_v1_Dict.C \
  SvtxVertexMap.C \
  SvtxVertexMap_Dict.C \
  SvtxVertexMap_v1.C \
  SvtxVertexMap_v1_Dict.C

libg4hough_la_SOURCES = \
  PHG4SvtxDeadArea.C \
  PHG4SvtxDeadArea_Dict.C \
  PHG4SvtxThresholds.C \
  PHG4SvtxThresholds_Dict.C \
  PHG4SvtxAddConnectedCells.C \
  PHG4SvtxAddConnectedCells_Dict.C \
  PHG4SvtxDigitizer.C \
  PHG4SvtxDigitizer_Dict.C \
  PHG4SvtxClusterizer.C \
  PHG4SvtxClusterizer_Dict.C \
  PHG4TPCClusterizer.C \
  PHG4TPCClusterizer_Dict.C \
  PHG4HoughTransform.C \
  PHG4HoughTransform_Dict.C \
  PHG4HoughTransformTPC.C \
  PHG4HoughTransformTPC_Dict.C \
  PHG4TrackGhostRejection.C \
  PHG4TrackGhostRejection_Dict.C \
  PHG4TrackKalmanFitter.C \
  PHG4TrackKalmanFitter_Dict.C \
  PHG4SvtxMomentumRecal.C \
  PHG4SvtxMomentumRecal_Dict.C \
  PHG4SvtxTrackProjection.C \
  PHG4SvtxTrackProjection_Dict.C \
  PHG4SvtxBeamSpotReco.C \
  PHG4SvtxBeamSpotReco_Dict.C \
  SimpleTrack_Dict.C

# Rule for generating table CINT dictionaries.
%_Dict.C: %.h %LinkDef.h
	rootcint -f $@ -c $(DEFAULT_INCLUDES) $(INCLUDES) $^

%_Dict.cpp: %.h %LinkDef.h
	rootcint -f $@ -c $(DEFAULT_INCLUDES) $(INCLUDES) $^



################################################
# linking tests

noinst_PROGRAMS = testexternals

BUILT_SOURCES = \
  testexternals.C

testexternals_LDADD = \
  libg4hough_io.la \
  libg4hough.la

testexternals.C:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f *Dict*
