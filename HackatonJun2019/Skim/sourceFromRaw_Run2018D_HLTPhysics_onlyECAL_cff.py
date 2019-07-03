import FWCore.ParameterSet.Config as cms

# input
FastMonitoringService = cms.Service( "FastMonitoringService",
    filePerFwkStream = cms.untracked.bool( False ),
    fastMonIntervals = cms.untracked.uint32( 2 ),
    sleepTime = cms.untracked.int32( 1 )
)

EvFDaqDirector = cms.Service( "EvFDaqDirector",
    runNumber = cms.untracked.uint32( 323775 ),

    baseDir = cms.untracked.string( "tmp" ),
    buBaseDir = cms.untracked.string( "tmp" ),

    useFileBroker = cms.untracked.bool( False ),
    fileBrokerKeepAlive = cms.untracked.bool( True ),
    fileBrokerPort = cms.untracked.string( "8080" ),
    fileBrokerUseLocalLock = cms.untracked.bool( True ),
    fuLockPollInterval = cms.untracked.uint32( 2000 ),

    requireTransfersPSet = cms.untracked.bool( False ),
    selectedTransferMode = cms.untracked.string( "" ),
    mergingPset = cms.untracked.string( "" ),

    outputAdler32Recheck = cms.untracked.bool( False ),
)

source = cms.Source( "FedRawDataInputSource",
    runNumber = cms.untracked.uint32( 321177 ),
    getLSFromFilename = cms.untracked.bool(True),
    testModeNoBuilderUnit = cms.untracked.bool(False),
    verifyAdler32 = cms.untracked.bool( True ),
    verifyChecksum = cms.untracked.bool( True ),
    alwaysStartFromfirstLS = cms.untracked.uint32( 0 ),

    useL1EventID = cms.untracked.bool( False ),         # True for MC, True/False for data
    eventChunkBlock = cms.untracked.uint32( 240 ),      # from 32
    eventChunkSize = cms.untracked.uint32( 240),        # from 32
    maxBufferedFiles = cms.untracked.uint32( 8 ),       # from  2
    numBuffers = cms.untracked.uint32( 8 ),             # from  2

    fileListMode = cms.untracked.bool( True ),          # False
    fileNames = cms.untracked.vstring( *(

         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0154_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0154_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0154_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0154_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0155_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0155_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0155_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0156_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0156_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0156_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0157_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0157_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0157_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0157_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0158_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0158_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0158_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0159_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0159_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0159_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0159_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0160_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0160_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0160_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0160_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0161_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0161_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0161_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0161_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0162_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0162_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0162_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0162_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0163_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0163_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0163_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0163_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0164_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0164_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0164_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0164_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0165_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0165_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0165_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0165_index000003.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0166_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0166_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0166_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0167_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0167_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0167_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0168_index000000.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0168_index000001.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0168_index000002.raw',
         '/mnt/home/amassironi/cmssw_releases/v2/CMSSW_10_6_0_Patatrack/src/data/run321177/run321177_ls0168_index000003.raw',

    ) ),
)
