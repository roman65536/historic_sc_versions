// C++ stub for xspread 
// permits use of fl_ag_file_chooser for file open/save ops

extern "C" {
#include <string.h>
}

#include "fl_ag_file_chooser.H"

extern "C" {
    extern int scmain(int argc, char *argv[]); // in scmain.c
}

extern "C" {
    int
    get_filename(const char *msg, const char *pat, char *fname, 
		 const char *start)
    {
	char *getname;

	getname = fl_ag_file_chooser(msg, pat, start);
	if (getname && getname[0]) {
	    strcpy(fname, getname);
	    return 1;
	} else
	    return 0;
    }
}

int main (int argc, char *argv[])
{
    return scmain(argc, argv);
}



