import os
import FWCore.ParameterSet.Config as cms

process = cms.Process("FED")

# conditions
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '103X_dataRun2_HLT_v1', '')

# services
process.load('FWCore.MessageService.MessageLogger_cfi')


# input
#import sys, os, inspect
#sys.path.append(os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe()))))
#process.load('sourceFromRaw_Run2018D_HLTPhysics_cff')
## process.load('sourceFromRaw_Run2018D_JetHT_cff')


#process.source = cms.Source("PoolSource",
    #fileNames = cms.untracked.vstring('/store/data/Run2018D/EphemeralHLTPhysics1/RAW/v1/000/323/775/00000/A27DFA33-8FCB-BE42-A2D2-1A396EEE2B6E.root')
#)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
          'file:/mnt/ceph/users/fwyzard/store/data/Run2018D/HLTPhysics/RAW/v1/000/321/177/00000/6225A60D-B99E-E811-AAF2-FA163E33DDD7.root',
          'file:/mnt/ceph/users/fwyzard/store/data/Run2018D/HLTPhysics/RAW/v1/000/321/177/00000/C2AAE6DA-B69E-E811-84AC-FA163E712D83.root',
          )
)

#
# https://cmsoms.cern.ch/cms/runs/report?cms_run=321177
#

#
#process.load('EventFilter.Utilities.EvFDaqDirector_cfi')
#process.EvFDaqDirector.baseDir   = '/data/store/data/Run2018D/EphemeralHLTPhysics1/FED/v1'
#process.EvFDaqDirector.buBaseDir = '/data/store/data/Run2018D/EphemeralHLTPhysics1/FED/v1'
#process.EvFDaqDirector.runNumber = 323775
#
#mkdir -p /data/store/data/Run2018D/EphemeralHLTPhysics1/FED/v1/run323775/open
#touch /data/store/data/Run2018D/EphemeralHLTPhysics1/FED/v1/run323775/open/fu.lock
#



process.load('EventFilter.Utilities.EvFDaqDirector_cfi')
process.EvFDaqDirector.baseDir   = '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data_all'
process.EvFDaqDirector.buBaseDir = '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data_all'
process.EvFDaqDirector.runNumber = 321177

# 
# mkdir -p /mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data_all/run321177/open/
# touch /mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data_all/run321177/open/fu.lock
# 



process.rawStreamFileWriterForBU = cms.OutputModule("RawStreamFileWriterForBU",
    ProductLabel = cms.untracked.string("rawDataCollector"),
    numEventsPerFile = cms.untracked.uint32(100),
    jsonDefLocation = cms.untracked.string(os.path.expandvars('$CMSSW_RELEASE_BASE/src/EventFilter/Utilities/plugins/budef.jsd')),
    debug = cms.untracked.bool(False),
)

process.endpath = cms.EndPath(process.rawStreamFileWriterForBU)

process.load('FWCore.MessageService.MessageLogger_cfi')
process.MessageLogger.cerr.FwkReport.reportEvery = 5




