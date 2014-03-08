#include "debug_printf.h"

///////////////////////////////////////////////////////////////////////////////
FILE* err_logfile = NULL;
///////////////////////////////////////////////////////////////////////////////
void debug_printf(const char * format, ...) {
	char buf[200];
	va_list args;

	va_start(args, format);
	vsnprintf(buf, sizeof(buf), format, args);
	va_end(args);

	// print to screen
	_outtext(buf);

	// print into logfile
	if (err_logfile) {
		fprintf(err_logfile, buf);
		fflush(err_logfile);
	}
};
///////////////////////////////////////////////////////////////////////////////
void open_logfile() {
	assert(err_logfile == NULL);
	err_logfile = fopen("logfile.err", "w");
};
///////////////////////////////////////////////////////////////////////////////
void close_logfile() {
	if (err_logfile) {
		if (fclose(err_logfile) != 0) {
			err_logfile = NULL;
			debug_printf("ERROR: couldn't close logfile.\n");
		}
	}
	err_logfile = NULL;
};
///////////////////////////////////////////////////////////////////////////////

