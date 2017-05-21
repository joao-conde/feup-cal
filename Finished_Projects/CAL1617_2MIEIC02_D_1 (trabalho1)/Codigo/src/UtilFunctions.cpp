#include "UtilFunctions.h"
#include <time.h>
#include <sys/timeb.h>
#include <sstream>

using namespace std;

/*
 * Print time
 */
// Something like GetTickCount but portable
// It rolls over every ~ 12.1 days (0x100000/24/60/60)
// Use GetMilliSpan to correct for rollover

int GetMilliCount() {
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int GetMilliSpan(int nTimeStart) {
	int nSpan = GetMilliCount() - nTimeStart;
	if (nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

string floatToString(float i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

string intToString(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

string doubleToString(double i) {
	stringstream ss;
	ss << i;
	return ss.str();
}
