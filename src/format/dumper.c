#include "dumper.h"
Uint32 (*dump_MEM_GB)(Uint32 a, unsigned char *mem);
Uint32 (*dump_MEM_PCE)(Uint32 a, unsigned char *mem);
Uint32 (*dump_MEM_MSX)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_AY8910)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_OPLL)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_SN76489)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_SCC)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_OPL)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_ADPCM)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_N106)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_VRC6)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_MMC5)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_FDS)(Uint32 a, unsigned char *mem);
Uint32 (*dump_DEV_2A03)(Uint32 a, unsigned char *mem);
Uint32 (*dump_MEM_FC)(Uint32 a, unsigned char *mem);