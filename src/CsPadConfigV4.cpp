//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class CsPadConfigV4...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "H5DataTypes/CsPadConfigV4.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <algorithm>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "hdf5pp/ArrayType.h"
#include "hdf5pp/CompoundType.h"
#include "hdf5pp/TypeTraits.h"
#include "H5DataTypes/H5DataUtils.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace H5DataTypes {

CsPadConfigV2QuadReg::CsPadConfigV2QuadReg(const Pds::CsPad::ConfigV2QuadReg& src)
  : readClkSet(src.readClkSet())
  , readClkHold(src.readClkHold())
  , dataMode(src.dataMode())
  , prstSel(src.prstSel())
  , acqDelay(src.acqDelay())
  , intTime(src.intTime())
  , digDelay(src.digDelay())
  , ampIdle(src.ampIdle())
  , injTotal(src.injTotal())
  , rowColShiftPer(src.rowColShiftPer())
  , ampReset(src.ampReset())
  , digCount(src.digCount())
  , digPeriod(src.digPeriod())
  , readOnly(src.ro())
  , digitalPots(src.dp())
  , gainMap(*src.gm())
{
  const uint32_t* p = src.shiftSelect();
  std::copy(p, p+TwoByTwosPerQuad, this->shiftSelect);
  p = src.edgeSelect();
  std::copy(p, p+TwoByTwosPerQuad, this->edgeSelect);
}

hdf5pp::Type
CsPadConfigV2QuadReg::native_type()
{
  hdf5pp::CompoundType quadType = hdf5pp::CompoundType::compoundType<CsPadConfigV2QuadReg>() ;
  quadType.insert_native<uint32_t>( "shiftSelect", offsetof(CsPadConfigV2QuadReg, shiftSelect), TwoByTwosPerQuad) ;
  quadType.insert_native<uint32_t>( "edgeSelect", offsetof(CsPadConfigV2QuadReg, edgeSelect), TwoByTwosPerQuad) ;
  quadType.insert_native<uint32_t>( "readClkSet", offsetof(CsPadConfigV2QuadReg, readClkSet) ) ;
  quadType.insert_native<uint32_t>( "readClkHold", offsetof(CsPadConfigV2QuadReg, readClkHold) ) ;
  quadType.insert_native<uint32_t>( "dataMode", offsetof(CsPadConfigV2QuadReg, dataMode) ) ;
  quadType.insert_native<uint32_t>( "prstSel", offsetof(CsPadConfigV2QuadReg, prstSel) ) ;
  quadType.insert_native<uint32_t>( "acqDelay", offsetof(CsPadConfigV2QuadReg, acqDelay) ) ;
  quadType.insert_native<uint32_t>( "intTime", offsetof(CsPadConfigV2QuadReg, intTime) ) ;
  quadType.insert_native<uint32_t>( "digDelay", offsetof(CsPadConfigV2QuadReg, digDelay) ) ;
  quadType.insert_native<uint32_t>( "ampIdle", offsetof(CsPadConfigV2QuadReg, ampIdle) ) ;
  quadType.insert_native<uint32_t>( "injTotal", offsetof(CsPadConfigV2QuadReg, injTotal) ) ;
  quadType.insert_native<uint32_t>( "rowColShiftPer", offsetof(CsPadConfigV2QuadReg, rowColShiftPer) ) ;
  quadType.insert_native<uint32_t>( "ampReset", offsetof(CsPadConfigV2QuadReg, ampReset) ) ;
  quadType.insert_native<uint32_t>( "digCount", offsetof(CsPadConfigV2QuadReg, digCount) ) ;
  quadType.insert_native<uint32_t>( "digPeriod", offsetof(CsPadConfigV2QuadReg, digPeriod) ) ;
  quadType.insert("readOnly", offsetof(CsPadConfigV2QuadReg, readOnly), CsPadReadOnlyCfg::native_type()) ;
  quadType.insert("digitalPots", offsetof(CsPadConfigV2QuadReg, digitalPots), CsPadDigitalPotsCfg::native_type()) ;
  quadType.insert("gainMap", offsetof(CsPadConfigV2QuadReg, gainMap), CsPadGainMapCfg::native_type()) ;
  return quadType;
}


CsPadConfigV4::CsPadConfigV4 ( const XtcType& data )
  :  concentratorVersion(data.concentratorVersion())
  ,  runDelay(data.runDelay())
  ,  eventCode(data.eventCode())
  ,  protectionEnable(data.protectionEnable())
  ,  inactiveRunMode(data.inactiveRunMode())
  ,  activeRunMode(data.activeRunMode())
  ,  testDataIndex(data.tdi())
  ,  payloadPerQuad(data.payloadSize())
  ,  badAsicMask0(data.badAsicMask0())
  ,  badAsicMask1(data.badAsicMask1())
  ,  asicMask(data.asicMask())
  ,  quadMask(data.quadMask())
{
  for ( int q = 0; q < MaxQuadsPerSensor ; ++ q ) {
    roiMask[q] = data.roiMask(q);
  }
  
  for ( int q = 0; q < MaxQuadsPerSensor ; ++ q ) {
    quads[q] = data.quads()[q];
  }

  for ( int q = 0; q < MaxQuadsPerSensor ; ++ q ) {
    protectionThresholds[q] = data.protectionThresholds()[q];
  }

  // fill the list of active sections from ROI bits
  int ns = 0 ;
  for ( int q = 0; q < MaxQuadsPerSensor ; ++ q ) {
    for ( int s = 0; s < SectionsPerQuad ; ++ s ) {
      sections[q][s] = -1;
      if ( roiMask[q] & (1<<s) ) sections[q][s] = ns++;
    }
  }
  
}

hdf5pp::Type
CsPadConfigV4::stored_type()
{
  return native_type() ;
}

hdf5pp::Type
CsPadConfigV4::native_type()
{
  hsize_t sdims[2] = {MaxQuadsPerSensor, SectionsPerQuad};
  hdf5pp::Type baseSectType = hdf5pp::TypeTraits<int8_t>::native_type();
  hdf5pp::ArrayType sectArrType = hdf5pp::ArrayType::arrayType(baseSectType, 2, sdims);

  hdf5pp::CompoundType confType = hdf5pp::CompoundType::compoundType<CsPadConfigV4>() ;
  confType.insert_native<uint32_t>( "concentratorVersion", offsetof(CsPadConfigV4, concentratorVersion) ) ;
  confType.insert_native<uint32_t>( "runDelay", offsetof(CsPadConfigV4, runDelay) ) ;
  confType.insert_native<uint32_t>( "eventCode", offsetof(CsPadConfigV4, eventCode) ) ;
  confType.insert("protectionThresholds", offsetof(CsPadConfigV4, protectionThresholds), CsPadProtectionSystemThreshold::native_type(), MaxQuadsPerSensor ) ;
  confType.insert_native<uint32_t>( "protectionEnable", offsetof(CsPadConfigV4, protectionEnable) ) ;
  confType.insert_native<uint32_t>( "inactiveRunMode", offsetof(CsPadConfigV4, inactiveRunMode) ) ;
  confType.insert_native<uint32_t>( "activeRunMode", offsetof(CsPadConfigV4, activeRunMode) ) ;
  confType.insert_native<uint32_t>( "testDataIndex", offsetof(CsPadConfigV4, testDataIndex) ) ;
  confType.insert_native<uint32_t>( "payloadPerQuad", offsetof(CsPadConfigV4, payloadPerQuad) ) ;
  confType.insert_native<uint32_t>( "badAsicMask0", offsetof(CsPadConfigV4, badAsicMask0) ) ;
  confType.insert_native<uint32_t>( "badAsicMask1", offsetof(CsPadConfigV4, badAsicMask1) ) ;
  confType.insert_native<uint32_t>( "asicMask", offsetof(CsPadConfigV4, asicMask) ) ;
  confType.insert_native<uint32_t>( "quadMask", offsetof(CsPadConfigV4, quadMask) ) ;
  confType.insert_native<uint32_t>( "roiMask", offsetof(CsPadConfigV4, roiMask) ) ;
  confType.insert("quads", offsetof(CsPadConfigV4, quads), CsPadConfigV2QuadReg::native_type(), MaxQuadsPerSensor ) ;
  confType.insert("sections", offsetof(CsPadConfigV4, sections), sectArrType ) ;

  return confType ;
}

void
CsPadConfigV4::store( const XtcType& config, hdf5pp::Group grp )
{
  // make scalar data set for main object
  CsPadConfigV4 data ( config ) ;
  storeDataObject ( data, "config", grp ) ;
}

} // namespace H5DataTypes
