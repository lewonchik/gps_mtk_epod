#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
// #include "gps_mtk_epod.h"

int main(void) {

	pid_t pid, sid;

	pid = fork();

	if (pid < 0) {
		exit(EXIT_FAILURE);
	}

	if (pid > 0) {
		exit(EXIT_SUCCESS);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while(1) {
		// this is really dirty, barebones implimentation
		system("wget http://epodownload.mediatek.com/EPO.DAT /data/misc/");
		system("wget http://epodownload.mediatek.com/EPO.MD5 /data/misc/");
		sleep(3600); // downloads epo every 1 hour
	}

	exit(EXIT_SUCCESS);

}