#include "processing.h"

int getMaxTime(const CONFERENCE& r) { // вычисление в минутах
    int sh = (r.start[0] - '0') * 10 + (r.start[1] - '0');
    int sm = (r.start[3] - '0') * 10 + (r.start[4] - '0');
    int eh = (r.end[0] - '0') * 10 + (r.end[1] - '0');
    int em = (r.end[3] - '0') * 10 + (r.end[4] - '0');
    return (eh * 60 + em) - (sh * 60 + sm);
}

int process(const vector <CONFERENCE>& reports) { // заглушка
    if (reports.empty()) {
        return 0;
    }
    int Max = getMaxTime(reports[0]);
    for (int i = 0; i < reports.size(); i++) {
        int time = getMaxTime(reports[i]);
        if (time > Max) {
            Max = time;
        }
    }

	return Max;
}
