/*
	SOUND DRIVER
	Author:   Mamiya (mamiya@proc.org.tohoku.ac.jp)
	Language: ANSI-C
	License:  PDS
*/

/* ANSI/Windows standard headers */
/* Libraries headers */
/* Project headers */
#include "snddrv/snddrv.h"


SOUNDDEVICE *CreateSoundDevice(SOUNDDEVICEINITDATA *psdid)
{
#ifdef _WIN32
//	extern SOUNDDEVICE *CreateSoundDeviceDX3(SOUNDDEVICEINITDATA *psdid);
//	return CreateSoundDeviceDX3(psdid);
	extern SOUNDDEVICE *CreateSoundDeviceMMS(SOUNDDEVICEINITDATA *psdid);
	return CreateSoundDeviceMMS(psdid);
#else
	return 0;
#endif
}

SOUNDDEVICE *CreateSoundDeviceDX(SOUNDDEVICEINITDATA *psdid)
{
#ifdef _WIN32
	extern SOUNDDEVICE *CreateSoundDeviceDX3(SOUNDDEVICEINITDATA *psdid);
	return CreateSoundDeviceDX3(psdid);
//	extern SOUNDDEVICE *CreateSoundDeviceMMS(SOUNDDEVICEINITDATA *psdid);
//	return CreateSoundDeviceMMS(psdid);
#else
	return 0;
#endif
}
