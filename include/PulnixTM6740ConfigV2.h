#ifndef H5DATATYPES_PULNIXTM6740CONFIGV2_H
#define H5DATATYPES_PULNIXTM6740CONFIGV2_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class PulnixTM6740ConfigV2.
//
//------------------------------------------------------------------------

//-----------------
// C/C++ Headers --
//-----------------

//----------------------
// Base Class Headers --
//----------------------

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
#include "hdf5pp/Group.h"
#include "pdsdata/pulnix/TM6740ConfigV2.hh"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace H5DataTypes {

//
// Helper type for Pds::Pulnix::TM6740ConfigV2
//
struct PulnixTM6740ConfigV2_Data {
  uint16_t vref_a;
  uint16_t vref_b;
  uint16_t gain_a;
  uint16_t gain_b;
  uint8_t gain_balance;
  uint8_t output_resolution;
  uint8_t output_resolution_bits;
  uint8_t horizontal_binning;
  uint8_t vertical_binning;
  uint8_t lookuptable_mode;
};

class PulnixTM6740ConfigV2  {
public:

  typedef Pds::Pulnix::TM6740ConfigV2 XtcType ;

  PulnixTM6740ConfigV2 () {}
  PulnixTM6740ConfigV2 ( const XtcType& config ) ;

  static hdf5pp::Type stored_type() ;
  static hdf5pp::Type native_type() ;

  static void store ( const XtcType& config, hdf5pp::Group location ) ;

  static size_t xtcSize( const XtcType& xtc ) { return sizeof xtc ; }

private:
  PulnixTM6740ConfigV2_Data m_data ;
};

} // namespace H5DataTypes

#endif // H5DATATYPES_PULNIXTM6740CONFIGV2_H