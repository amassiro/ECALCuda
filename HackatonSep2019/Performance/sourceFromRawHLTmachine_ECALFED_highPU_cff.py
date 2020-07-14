import FWCore.ParameterSet.Config as cms

# input
FastMonitoringService = cms.Service( "FastMonitoringService",
    filePerFwkStream = cms.untracked.bool( False ),
    fastMonIntervals = cms.untracked.uint32( 2 ),
    sleepTime = cms.untracked.int32( 1 )
)

EvFDaqDirector = cms.Service( "EvFDaqDirector",
    runNumber = cms.untracked.uint32( 325308 ),

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
    runNumber = cms.untracked.uint32( 325308 ),
    getLSFromFilename = cms.untracked.bool(True),
    testModeNoBuilderUnit = cms.untracked.bool(False),
    verifyAdler32 = cms.untracked.bool( True ),
    verifyChecksum = cms.untracked.bool( True ),
    useL1EventID = cms.untracked.bool( False ),         # True
    alwaysStartFromfirstLS = cms.untracked.uint32( 0 ),

    eventChunkBlock = cms.untracked.uint32( 240 ),      # 32
    eventChunkSize = cms.untracked.uint32( 240),        # 32
    maxBufferedFiles = cms.untracked.uint32( 8 ),       #  2
    numBuffers = cms.untracked.uint32( 8 ),             #  2

    fileListMode = cms.untracked.bool( True ),          # False
    fileNames = cms.untracked.vstring(

          '/data/user/amassiro/data/run325308/run325308_ls0046_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0046_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0049_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0049_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0056_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0056_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0051_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0054_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0054_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0055_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0055_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0135_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0135_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0125_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0125_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0132_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0132_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0132_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0134_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0134_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0134_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0129_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0129_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0129_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0127_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0127_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0127_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0133_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0133_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0133_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0128_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0128_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0128_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0131_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0131_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0130_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0130_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0126_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0126_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0126_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0097_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0097_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0099_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0099_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0099_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0099_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0100_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0100_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0100_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0100_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0101_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0101_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0101_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0102_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0102_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0102_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0103_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0103_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0103_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0104_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0104_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0104_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0104_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0105_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0105_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0105_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0090_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0090_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0090_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0091_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0091_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0091_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0092_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0092_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0092_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0093_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0093_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0093_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0094_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0094_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0094_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0095_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0095_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0095_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0096_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0096_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0097_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0097_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0098_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0098_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0098_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0062_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0062_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0063_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0063_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0064_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0064_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0065_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0065_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0066_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0066_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0067_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0067_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0068_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0068_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0047_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0047_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0047_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0047_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0047_index000004.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0047_index000005.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0050_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0050_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0050_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0050_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0050_index000004.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0050_index000005.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0053_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0053_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0053_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0053_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0053_index000004.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0053_index000005.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0053_index000006.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0048_index000000.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0048_index000001.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0048_index000002.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0048_index000003.raw',
          '/data/user/amassiro/data/run325308/run325308_ls0048_index000004.raw',


    ),
)