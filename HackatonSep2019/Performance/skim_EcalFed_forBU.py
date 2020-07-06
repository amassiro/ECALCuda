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
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_096p5_ls_046-056.root',                                          
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_097p2_ls_062-072.root',                                         
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_099p8_ls_125-135.root',                                          
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_101p3_ls_097-107.root',                                          
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/310//00000/pileup_103p7_ls_090-100.root',                                          
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_111p3_ls_062-072.root',                                         
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_112p9_ls_046-056.root',                                         
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_115p7_ls_046-056.root',                                         
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_115p8_ls_081-090.root',                                         
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_116p7_ls_046-056.root',                                         
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_117p4_ls_062-072.root',                                         
         'file:/gpu_data/store/data/Run2018D/HighPUSkim/RAW/v1/000/325/308//00000/pileup_119p6_ls_125-135.root'  
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
process.EvFDaqDirector.baseDir   = '/data/user/amassiro/data'
process.EvFDaqDirector.buBaseDir = '/data/user/amassiro/data'
process.EvFDaqDirector.runNumber = 325308

# 
# mkdir -p /mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/open/
# touch /mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/open/fu.lock
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



#
# filter feds and output
#

process.rawDataSelector = cms.EDProducer( "EvFFEDSelector",
    inputTag = cms.InputTag( "rawDataCollector" ),
    fedList = cms.vuint32(
        # SCAL
          735,
        # TCDS FED
         1024,
        # ECAL 601 -> 664
         601,  602,  603,  604,  605,  606,  607,  608,  609,  610,  611,  612,  613,  614,  615,
         616,  617,  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,
         631,  632,  633,  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,  645, 
         646,  647,  648,  649,  650,  651,  652,  653,  654,  655,  656,  657,  658,  659,  660, 
         661,  662,  663,  664
    )
)

print process.rawDataSelector.fedList
    
process.path = cms.Path(process.rawDataSelector)

process.rawStreamFileWriterForBU.ProductLabel = "rawDataSelector"

