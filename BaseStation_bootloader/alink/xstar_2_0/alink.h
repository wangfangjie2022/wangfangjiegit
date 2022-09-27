/** @file
 *	@brief ALINK comm protocol built from xstar_2_0.xml
 *	
 */
#ifndef ALINK_H
#define ALINK_H

#ifndef ALINK_STX
#define ALINK_STX 253
#endif

#ifndef ALINK_ENDIAN
#define ALINK_ENDIAN ALINK_LITTLE_ENDIAN
#endif

#ifndef ALINK_ALIGNED_FIELDS
#define ALINK_ALIGNED_FIELDS 1
#endif

#ifndef ALINK_CRC_EXTRA
#define ALINK_CRC_EXTRA 1
#endif

#include "version.h"
#include "xstar_2_0.h"

#endif // ALINK_H
