//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class TimepixConfigV3...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "H5DataTypes/TimepixConfigV3.h"

//-----------------
// C/C++ Headers --
//-----------------
#include <algorithm>
#include <string.h>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "H5DataTypes/H5DataUtils.h"
#include "hdf5pp/CompoundType.h"
#include "hdf5pp/EnumType.h"

//-----------------------------------------------------------------------
// Local Macros, Typedefs, Structures, Unions and Forward Declarations --
//-----------------------------------------------------------------------

//		----------------------------------------
// 		-- Public Function Member Definitions --
//		----------------------------------------

namespace H5DataTypes {

//----------------
// Constructors --
//----------------
TimepixConfigV3::TimepixConfigV3 ( const Pds::Timepix::ConfigV3& data )
  : readoutSpeed(data.readoutSpeed())
  , timepixMode(data.timepixMode())
  , timepixSpeed(data.timepixSpeed())
  , dac0Ikrum(data.dac0Ikrum())
  , dac0Disc(data.dac0Disc())
  , dac0Preamp(data.dac0Preamp())
  , dac0BufAnalogA(data.dac0BufAnalogA())
  , dac0BufAnalogB(data.dac0BufAnalogB())
  , dac0Hist(data.dac0Hist())
  , dac0ThlFine(data.dac0ThlFine())
  , dac0ThlCourse(data.dac0ThlCourse())
  , dac0Vcas(data.dac0Vcas())
  , dac0Fbk(data.dac0Fbk())
  , dac0Gnd(data.dac0Gnd())
  , dac0Ths(data.dac0Ths())
  , dac0BiasLvds(data.dac0BiasLvds())
  , dac0RefLvds(data.dac0RefLvds())
  , dac1Ikrum(data.dac1Ikrum())
  , dac1Disc(data.dac1Disc())
  , dac1Preamp(data.dac1Preamp())
  , dac1BufAnalogA(data.dac1BufAnalogA())
  , dac1BufAnalogB(data.dac1BufAnalogB())
  , dac1Hist(data.dac1Hist())
  , dac1ThlFine(data.dac1ThlFine())
  , dac1ThlCourse(data.dac1ThlCourse())
  , dac1Vcas(data.dac1Vcas())
  , dac1Fbk(data.dac1Fbk())
  , dac1Gnd(data.dac1Gnd())
  , dac1Ths(data.dac1Ths())
  , dac1BiasLvds(data.dac1BiasLvds())
  , dac1RefLvds(data.dac1RefLvds())
  , dac2Ikrum(data.dac2Ikrum())
  , dac2Disc(data.dac2Disc())
  , dac2Preamp(data.dac2Preamp())
  , dac2BufAnalogA(data.dac2BufAnalogA())
  , dac2BufAnalogB(data.dac2BufAnalogB())
  , dac2Hist(data.dac2Hist())
  , dac2ThlFine(data.dac2ThlFine())
  , dac2ThlCourse(data.dac2ThlCourse())
  , dac2Vcas(data.dac2Vcas())
  , dac2Fbk(data.dac2Fbk())
  , dac2Gnd(data.dac2Gnd())
  , dac2Ths(data.dac2Ths())
  , dac2BiasLvds(data.dac2BiasLvds())
  , dac2RefLvds(data.dac2RefLvds())
  , dac3Ikrum(data.dac3Ikrum())
  , dac3Disc(data.dac3Disc())
  , dac3Preamp(data.dac3Preamp())
  , dac3BufAnalogA(data.dac3BufAnalogA())
  , dac3BufAnalogB(data.dac3BufAnalogB())
  , dac3Hist(data.dac3Hist())
  , dac3ThlFine(data.dac3ThlFine())
  , dac3ThlCourse(data.dac3ThlCourse())
  , dac3Vcas(data.dac3Vcas())
  , dac3Fbk(data.dac3Fbk())
  , dac3Gnd(data.dac3Gnd())
  , dac3Ths(data.dac3Ths())
  , dac3BiasLvds(data.dac3BiasLvds())
  , dac3RefLvds(data.dac3RefLvds())
  , dacBias(data.dacBias())
  , flags(data.flags())
  , chipCount(data.chipCount())
  , driverVersion(data.driverVersion())
  , firmwareVersion(data.firmwareVersion())
  , pixelThreshSize(data.pixelThreshSize())
  , chip0ID(data.chip0ID())
  , chip1ID(data.chip1ID())
  , chip2ID(data.chip2ID())
  , chip3ID(data.chip3ID())
{
  const ndarray<const uint8_t, 1>& pixelThresh = data.pixelThresh();
  std::copy(pixelThresh.begin(), pixelThresh.end(), this->pixelThresh);

  const char* name = data.chip0Name();
  int len = strlen(name)+1;
  this->chip0Name = new char[len];
  std::copy(name, name+len, this->chip0Name);

  name = data.chip1Name();
  len = strlen(name)+1;
  this->chip1Name = new char[len];
  std::copy(name, name+len, this->chip1Name);

  name = data.chip2Name();
  len = strlen(name)+1;
  this->chip2Name = new char[len];
  std::copy(name, name+len, this->chip2Name);

  name = data.chip3Name();
  len = strlen(name)+1;
  this->chip3Name = new char[len];
  std::copy(name, name+len, this->chip3Name);
}

TimepixConfigV3::~TimepixConfigV3()
{
  delete [] chip0Name;
  delete [] chip1Name;
  delete [] chip2Name;
  delete [] chip3Name;
}


hdf5pp::Type
TimepixConfigV3::stored_type()
{
  return native_type() ;
}

hdf5pp::Type
TimepixConfigV3::native_type()
{
  hdf5pp::EnumType<uint8_t> speedEnum = hdf5pp::EnumType<uint8_t>::enumType() ;
  speedEnum.insert ( "ReadoutSpeed_Slow", Pds::Timepix::ConfigV3::ReadoutSpeed_Slow ) ;
  speedEnum.insert ( "ReadoutSpeed_Fast", Pds::Timepix::ConfigV3::ReadoutSpeed_Fast ) ;

  hdf5pp::EnumType<uint8_t> timepixModeEnum = hdf5pp::EnumType<uint8_t>::enumType() ;
  timepixModeEnum.insert ( "TimepixMode_Counting", Pds::Timepix::ConfigV3::TimepixMode_Counting ) ;
  timepixModeEnum.insert ( "TimepixMode_TOT", Pds::Timepix::ConfigV3::TimepixMode_TOT ) ;

  hdf5pp::CompoundType confType = hdf5pp::CompoundType::compoundType<TimepixConfigV3>() ;
  confType.insert("readoutSpeed", offsetof(TimepixConfigV3, readoutSpeed), speedEnum);
  confType.insert("timepixMode", offsetof(TimepixConfigV3, timepixMode), timepixModeEnum);
  confType.insert_native<int32_t>("timepixSpeed", offsetof(TimepixConfigV3, timepixSpeed));
  confType.insert_native<int32_t>("dac0Ikrum", offsetof(TimepixConfigV3, dac0Ikrum));
  confType.insert_native<int32_t>("dac0Disc", offsetof(TimepixConfigV3, dac0Disc));
  confType.insert_native<int32_t>("dac0Preamp", offsetof(TimepixConfigV3, dac0Preamp));
  confType.insert_native<int32_t>("dac0BufAnalogA", offsetof(TimepixConfigV3, dac0BufAnalogA));
  confType.insert_native<int32_t>("dac0BufAnalogB", offsetof(TimepixConfigV3, dac0BufAnalogB));
  confType.insert_native<int32_t>("dac0Hist", offsetof(TimepixConfigV3, dac0Hist));
  confType.insert_native<int32_t>("dac0ThlFine", offsetof(TimepixConfigV3, dac0ThlFine));
  confType.insert_native<int32_t>("dac0ThlCourse", offsetof(TimepixConfigV3, dac0ThlCourse));
  confType.insert_native<int32_t>("dac0Vcas", offsetof(TimepixConfigV3, dac0Vcas));
  confType.insert_native<int32_t>("dac0Fbk", offsetof(TimepixConfigV3, dac0Fbk));
  confType.insert_native<int32_t>("dac0Gnd", offsetof(TimepixConfigV3, dac0Gnd));
  confType.insert_native<int32_t>("dac0Ths", offsetof(TimepixConfigV3, dac0Ths));
  confType.insert_native<int32_t>("dac0BiasLvds", offsetof(TimepixConfigV3, dac0BiasLvds));
  confType.insert_native<int32_t>("dac0RefLvds", offsetof(TimepixConfigV3, dac0RefLvds));
  confType.insert_native<int32_t>("dac1Ikrum", offsetof(TimepixConfigV3, dac1Ikrum));
  confType.insert_native<int32_t>("dac1Disc", offsetof(TimepixConfigV3, dac1Disc));
  confType.insert_native<int32_t>("dac1Preamp", offsetof(TimepixConfigV3, dac1Preamp));
  confType.insert_native<int32_t>("dac1BufAnalogA", offsetof(TimepixConfigV3, dac1BufAnalogA));
  confType.insert_native<int32_t>("dac1BufAnalogB", offsetof(TimepixConfigV3, dac1BufAnalogB));
  confType.insert_native<int32_t>("dac1Hist", offsetof(TimepixConfigV3, dac1Hist));
  confType.insert_native<int32_t>("dac1ThlFine", offsetof(TimepixConfigV3, dac1ThlFine));
  confType.insert_native<int32_t>("dac1ThlCourse", offsetof(TimepixConfigV3, dac1ThlCourse));
  confType.insert_native<int32_t>("dac1Vcas", offsetof(TimepixConfigV3, dac1Vcas));
  confType.insert_native<int32_t>("dac1Fbk", offsetof(TimepixConfigV3, dac1Fbk));
  confType.insert_native<int32_t>("dac1Gnd", offsetof(TimepixConfigV3, dac1Gnd));
  confType.insert_native<int32_t>("dac1Ths", offsetof(TimepixConfigV3, dac1Ths));
  confType.insert_native<int32_t>("dac1BiasLvds", offsetof(TimepixConfigV3, dac1BiasLvds));
  confType.insert_native<int32_t>("dac1RefLvds", offsetof(TimepixConfigV3, dac1RefLvds));
  confType.insert_native<int32_t>("dac2Ikrum", offsetof(TimepixConfigV3, dac2Ikrum));
  confType.insert_native<int32_t>("dac2Disc", offsetof(TimepixConfigV3, dac2Disc));
  confType.insert_native<int32_t>("dac2Preamp", offsetof(TimepixConfigV3, dac2Preamp));
  confType.insert_native<int32_t>("dac2BufAnalogA", offsetof(TimepixConfigV3, dac2BufAnalogA));
  confType.insert_native<int32_t>("dac2BufAnalogB", offsetof(TimepixConfigV3, dac2BufAnalogB));
  confType.insert_native<int32_t>("dac2Hist", offsetof(TimepixConfigV3, dac2Hist));
  confType.insert_native<int32_t>("dac2ThlFine", offsetof(TimepixConfigV3, dac2ThlFine));
  confType.insert_native<int32_t>("dac2ThlCourse", offsetof(TimepixConfigV3, dac2ThlCourse));
  confType.insert_native<int32_t>("dac2Vcas", offsetof(TimepixConfigV3, dac2Vcas));
  confType.insert_native<int32_t>("dac2Fbk", offsetof(TimepixConfigV3, dac2Fbk));
  confType.insert_native<int32_t>("dac2Gnd", offsetof(TimepixConfigV3, dac2Gnd));
  confType.insert_native<int32_t>("dac2Ths", offsetof(TimepixConfigV3, dac2Ths));
  confType.insert_native<int32_t>("dac2BiasLvds", offsetof(TimepixConfigV3, dac2BiasLvds));
  confType.insert_native<int32_t>("dac2RefLvds", offsetof(TimepixConfigV3, dac2RefLvds));
  confType.insert_native<int32_t>("dac3Ikrum", offsetof(TimepixConfigV3, dac3Ikrum));
  confType.insert_native<int32_t>("dac3Disc", offsetof(TimepixConfigV3, dac3Disc));
  confType.insert_native<int32_t>("dac3Preamp", offsetof(TimepixConfigV3, dac3Preamp));
  confType.insert_native<int32_t>("dac3BufAnalogA", offsetof(TimepixConfigV3, dac3BufAnalogA));
  confType.insert_native<int32_t>("dac3BufAnalogB", offsetof(TimepixConfigV3, dac3BufAnalogB));
  confType.insert_native<int32_t>("dac3Hist", offsetof(TimepixConfigV3, dac3Hist));
  confType.insert_native<int32_t>("dac3ThlFine", offsetof(TimepixConfigV3, dac3ThlFine));
  confType.insert_native<int32_t>("dac3ThlCourse", offsetof(TimepixConfigV3, dac3ThlCourse));
  confType.insert_native<int32_t>("dac3Vcas", offsetof(TimepixConfigV3, dac3Vcas));
  confType.insert_native<int32_t>("dac3Fbk", offsetof(TimepixConfigV3, dac3Fbk));
  confType.insert_native<int32_t>("dac3Gnd", offsetof(TimepixConfigV3, dac3Gnd));
  confType.insert_native<int32_t>("dac3Ths", offsetof(TimepixConfigV3, dac3Ths));
  confType.insert_native<int32_t>("dac3BiasLvds", offsetof(TimepixConfigV3, dac3BiasLvds));
  confType.insert_native<int32_t>("dac3RefLvds", offsetof(TimepixConfigV3, dac3RefLvds));
  confType.insert_native<uint8_t>("dacBias", offsetof(TimepixConfigV3, dacBias));
  confType.insert_native<uint8_t>("flags", offsetof(TimepixConfigV3, flags));
  confType.insert_native<int32_t>("chipCount", offsetof(TimepixConfigV3, chipCount));
  confType.insert_native<int32_t>("driverVersion", offsetof(TimepixConfigV3, driverVersion));
  confType.insert_native<uint32_t>("firmwareVersion", offsetof(TimepixConfigV3, firmwareVersion));
  confType.insert_native<uint32_t>("pixelThreshSize", offsetof(TimepixConfigV3, pixelThreshSize));
  confType.insert_native<uint8_t>("pixelThresh", offsetof(TimepixConfigV3, pixelThresh), XtcType::PixelThreshMax);
  confType.insert_native<const char*>("chip0Name", offsetof(TimepixConfigV3, chip0Name));
  confType.insert_native<const char*>("chip1Name", offsetof(TimepixConfigV3, chip1Name));
  confType.insert_native<const char*>("chip2Name", offsetof(TimepixConfigV3, chip2Name));
  confType.insert_native<const char*>("chip3Name", offsetof(TimepixConfigV3, chip3Name));
  confType.insert_native<int32_t>("chip0ID", offsetof(TimepixConfigV3, chip0ID));
  confType.insert_native<int32_t>("chip1ID", offsetof(TimepixConfigV3, chip1ID));
  confType.insert_native<int32_t>("chip2ID", offsetof(TimepixConfigV3, chip2ID));
  confType.insert_native<int32_t>("chip3ID", offsetof(TimepixConfigV3, chip3ID));

  return confType ;
}

void
TimepixConfigV3::store( const Pds::Timepix::ConfigV3& config, hdf5pp::Group grp )
{
  // make scalar data set for main object
  TimepixConfigV3 data ( config ) ;
  storeDataObject ( data, "config", grp ) ;
}


} // namespace H5DataTypes
