#include <nds.h>
#include "dldi_handler.h"

extern FN_MEDIUM_STARTUP _DLDI_startup_ptr;
extern FN_MEDIUM_READSECTORS _DLDI_readSectors_ptr;
extern FN_MEDIUM_WRITESECTORS _DLDI_writeSectors_ptr;

bool dldi_handler_init()
{
	return _DLDI_startup_ptr();
}

void dldi_handler_read_sectors(sec_t sector, sec_t numSectors, void* buffer)
{
	_DLDI_readSectors_ptr(sector, numSectors, buffer);
}

void dldi_handler_write_sectors(sec_t sector, sec_t numSectors, const void* buffer)
{
	_DLDI_writeSectors_ptr(sector, numSectors, buffer);
}