#ifndef H5DATATYPES_LUSIDIODEFEXCONFIGV1_H
#define H5DATATYPES_LUSIDIODEFEXCONFIGV1_H

//--------------------------------------------------------------------------
// File and Version Information:
// 	$Id$
//
// Description:
//	Class LusiDiodeFexConfigV1.
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

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
#include "hdf5pp/Group.h"
#include "pdsdata/psddl/lusi.ddl.h"

//		---------------------
// 		-- Class Interface --
//		---------------------

namespace H5DataTypes {

//
// Helper type for Pds::Lusi::DiodeFexConfigV1
//
class LusiDiodeFexConfigV1  {
public:

  typedef Pds::Lusi::DiodeFexConfigV1 XtcType ;

  LusiDiodeFexConfigV1 () {}
  LusiDiodeFexConfigV1 ( const XtcType& data ) ;

  static hdf5pp::Type stored_type() ;
  static hdf5pp::Type native_type() ;

  // store single config object at specified location
  static void store( const XtcType& config, hdf5pp::Group location ) ;

  static size_t xtcSize( const XtcType& xtc ) { return sizeof(xtc) ; }

private:

  enum { NRANGES = Pds::Lusi::DiodeFexConfigV1::NRANGES };
  float base [NRANGES];
  float scale[NRANGES];

};

} // namespace H5DataTypes

#endif // H5DATATYPES_LUSIDIODEFEXCONFIGV1_H
