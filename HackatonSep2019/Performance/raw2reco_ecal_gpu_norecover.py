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


#-----------------------------------------
# CMSSW/ECAL non-DQM Related Module import
#-----------------------------------------

process.load("RecoLocalCalo.EcalRecProducers.ecalUncalibRecHitProducerGPU_cfi")
process.load("EventFilter.EcalRawToDigi.ecalRawToDigiGPU_cfi")
process.load("EventFilter.EcalRawToDigi.ecalElectronicsMappingGPUESProducer_cfi")


process.load("RecoLocalCalo.EcalRecProducers.ecalPedestalsGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalGainRatiosGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalPulseShapesGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalPulseCovariancesGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalSamplesCorrelationGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalTimeBiasCorrectionsGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalTimeCalibConstantsGPUESProducer_cfi")


process.load('HeterogeneousCore.CUDAServices.CUDAService_cfi')



process.load("RecoLuminosity.LumiProducer.bunchSpacingProducer_cfi")


#
# from GPU to CPU
#

#
# ecal rechit GPU
#

process.load("RecoLocalCalo.EcalRecProducers.ecalRechitADCToGeVConstantGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalRechitChannelStatusGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalIntercalibConstantsGPUESProducer_cfi")
    
process.load("RecoLocalCalo.EcalRecProducers.ecalLaserAPDPNRatiosGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalLaserAPDPNRatiosRefGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalLaserAlphasGPUESProducer_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalLinearCorrectionsGPUESProducer_cfi")
    

process.load("RecoLocalCalo.EcalRecProducers.ecalRecHitGPU_cfi")
process.ecalRecHitProducerGPU = process.ecalRecHitGPU.clone()


process.load("RecoLocalCalo.EcalRecProducers.ecalCPURecHitProducer_cfi")


process.ecalRecHitConvertGPU2CPUFormat = cms.EDProducer("EcalRecHitConvertGPU2CPUFormat",
    recHitsLabelGPUEB = cms.InputTag("ecalCPURecHitProducer", "EcalRecHitsEB"),
    recHitsLabelGPUEE = cms.InputTag("ecalCPURecHitProducer", "EcalRecHitsEE"),
    recHitsLabelCPUEB = cms.string("EcalRecHitsEB"),
    recHitsLabelCPUEE = cms.string("EcalRecHitsEE"),
)




process.recoPathGPUall = cms.Path(
#   gpu
    process.ecalUncalibRecHitProducerGPU      # run ECAL local reconstruction and multifit on gpu
    *process.ecalRecHitProducerGPU             # make ECAL calibrated rechits on gpu
    *process.ecalCPURecHitProducer             # copy to host
    *process.ecalRecHitConvertGPU2CPUFormat    # convert to legacy format
)


process.digiPath = cms.Path(
    process.ecalRawToDigiGPU   
)


process.bunchSpacing = cms.Path(
    process.bunchSpacingProducer
)


#process.out = cms.OutputModule(
    #"PoolOutputModule",
    #fileName = cms.untracked.string("test.root")
#)

#process.finalize = cms.EndPath(process.out)


process.schedule = cms.Schedule(
    process.bunchSpacing,
    process.digiPath,
    process.recoPathGPUall,
    #process.finalize
)



