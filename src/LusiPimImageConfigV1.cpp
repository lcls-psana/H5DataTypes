//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class LusiPimImageConfigV1...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "H5DataTypes/LusiPimImageConfigV1.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
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

LusiPimImageConfigV1::LusiPimImageConfigV1 ( const XtcType& data )
  : xscale(data.xscale())
  , yscale(data.yscale())
{
}

hdf5pp::Type
LusiPimImageConfigV1::stored_type()
{
  return native_type() ;
}

hdf5pp::Type
LusiPimImageConfigV1::native_type()
{
  hdf5pp::CompoundType confType = hdf5pp::CompoundType::compoundType<LusiPimImageConfigV1>() ;
  confType.insert_native<float>( "xscale", offsetof(LusiPimImageConfigV1, xscale) );
  confType.insert_native<float>( "yscale", offsetof(LusiPimImageConfigV1, yscale) );

  return confType ;
}

void
LusiPimImageConfigV1::store( const XtcType& config, hdf5pp::Group grp )
{
  // make scalar data set for main object
  LusiPimImageConfigV1 data ( config ) ;
  storeDataObject ( data, "config", grp ) ;
}

} // namespace H5DataTypes
