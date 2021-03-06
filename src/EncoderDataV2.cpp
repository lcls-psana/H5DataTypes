//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class EncoderDataV2...
//
// Author List:
//      Andrei Salnikov
//
//------------------------------------------------------------------------

//-----------------------
// This Class's Header --
//-----------------------
#include "H5DataTypes/EncoderDataV2.h"

//-----------------
// C/C++ Headers --
//-----------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "hdf5pp/CompoundType.h"
#include "hdf5pp/TypeTraits.h"

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
EncoderDataV2::EncoderDataV2 ( const XtcType& data )
  : _33mhz_timestamp(data.timestamp())
{
  const ndarray<const uint32_t, 1>& in_encoder_count = data.encoder_count();
  encoder_count[0] = in_encoder_count[0] ;
  encoder_count[1] = in_encoder_count[1] ;
  encoder_count[2] = in_encoder_count[2] ;
}

hdf5pp::Type
EncoderDataV2::stored_type()
{
  return native_type() ;
}

hdf5pp::Type
EncoderDataV2::native_type()
{
  hdf5pp::CompoundType type = hdf5pp::CompoundType::compoundType<EncoderDataV2>() ;
  type.insert_native<uint32_t>( "_33mhz_timestamp", offsetof(EncoderDataV2, _33mhz_timestamp) ) ;
  type.insert_native<uint32_t>( "encoder_count", offsetof(EncoderDataV2, encoder_count), 3 ) ;

  return type;
}

} // namespace H5DataTypes
