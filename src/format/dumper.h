
#ifndef __SRC_FORMAT_DUMPER_H_
#define __SRC_FORMAT_DUMPER_H_

#include "kmz80/kmtypes.h"
extern Uint32 (*ioview_ioread_DEV_SN76489)(Uint32 a);
extern Uint32 (*ioview_ioread_DEV_AY8910)(Uint32 a);
extern Uint32 (*ioview_ioread_DEV_SN76489)(Uint32 a);
extern Uint32 (*ioview_ioread_DEV_SCC)(Uint32 a);
extern Uint32 (*ioview_ioread_DEV_OPL)(Uint32 a);
extern Uint32 (*ioview_ioread_DEV_OPLL)(Uint32 a);
extern Uint32 (*ioview_ioread_DEV_ADPCM)(Uint32 a);
extern Uint32 (*ioview_ioread_DEV_ADPCM2)(Uint32 a);

extern Uint32 (*dump_MEM_GB)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_MEM_PCE)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_MEM_MSX)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_AY8910)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_OPLL)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_SN76489)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_SCC)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_OPL)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_ADPCM)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_N106)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_VRC6)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_MMC5)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_FDS)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_DEV_2A03)(Uint32 a, unsigned char *mem);
extern Uint32 (*dump_MEM_FC)(Uint32 a, unsigned char *mem);
#endif
