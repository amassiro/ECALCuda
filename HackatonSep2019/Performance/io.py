import FWCore.ParameterSet.Config as cms
from Configuration.StandardSequences.Eras import eras
import os

process = cms.Process('RECO',eras.Run2_2018)

#-----------------------------------
# Standard CMSSW Imports/Definitions
#-----------------------------------

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = '101X_dataRun2_Prompt_v11'
#process.GlobalTag.globaltag = '111X_dataRun2_Prompt_v2'

# load data using the DAQ source                                                                                                                                                                  
import sys, os, inspect
sys.path.append(os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe()))))
#process.load('sourceFromRaw_cff')
process.load('sourceFromRawHLTmachine_cff')


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

#-----------
# Log output
#-----------
process.load("FWCore.MessageService.MessageLogger_cfi")
#process.MessageLogger.cout.threshold = "DEBUG"
process.MessageLogger.cerr.threshold = 'DEBUG'
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.MessageLogger.debugModules = cms.untracked.vstring("*")

process.options = cms.untracked.PSet(
    numberOfThreads = cms.untracked.uint32(1),
    numberOfStreams = cms.untracked.uint32(1),
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    wantSummary = cms.untracked.bool(True)
)


#
#
#

process.load("RecoLuminosity.LumiProducer.bunchSpacingProducer_cfi")

process.bunchSpacing = cms.Path(
    process.bunchSpacingProducer
)

#
#
#



#process.out = cms.OutputModule(
    #"PoolOutputModule",
    #fileName = cms.untracked.string("test.root")
#)

#process.finalize = cms.EndPath(process.out)


process.schedule = cms.Schedule(
    process.bunchSpacing,
    #process.digiPath,
    #process.recoPathCPUall,
    #process.finalize
)
