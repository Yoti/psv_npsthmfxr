#include <psp2/kernel/threadmgr.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/io/stat.h>
#include <psp2/io/fcntl.h>
#include "debugScreen.h"

#define printf psvDebugScreenPrintf
#define ACT_PATH "tm0:npdrm"
#define ACT_FILE "tm0:npdrm/act.dat"

int main(int argc, char *argv[]) {
	psvDebugScreenInit();
	printf("NPS Themes Fixer v2.0 by Yoti\n");

	sceIoMkdir(ACT_PATH, 0777);

	SceUID fd;
	fd = sceIoOpen(ACT_FILE, SCE_O_RDONLY, 0777);
	if (fd < 0)
		fd = sceIoOpen(ACT_FILE, SCE_O_WRONLY|SCE_O_CREAT, 0777);
	sceIoClose(fd);

	printf("Done\n");
	sceKernelDelayThread(3*1000*1000);
	sceKernelExitProcess(0);
	return 0;
}
