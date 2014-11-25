/* Mednafen - Multi-system Emulator
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __MDFN_CDROM_CDROMIF_H
#define __MDFN_CDROM_CDROMIF_H

#include "CDUtility.h"

//#include <queue>

typedef CDUtility_TOC CD_TOC;

class CDIF
{
public:

   CDIF(){}
   virtual ~CDIF(){}

   inline void ReadTOC(CDUtility_TOC* read_target)
   {
      *read_target = disc_toc;
   }

   virtual void HintReadSector(uint32 lba) = 0;
   virtual bool ReadRawSector(uint8* buf, uint32 lba) = 0;

   // Utility/Wrapped functions
   // Reads mode 1 and mode2 form 1 sectors(2048 bytes per sector returned)
   // Will return the type(1, 2) of the first sector read to the buffer supplied, 0 on error
   int ReadSector(uint8* pBuf, uint32 lba, uint32 nSectors);

protected:
   CDUtility_TOC disc_toc;
};

CDIF* CDIF_Open(const char* path);

#endif
