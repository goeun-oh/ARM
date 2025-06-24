/*
 * Presenter.h
 *
 *  Created on: Jun 24, 2025
 *      Author: kccistc
 */

#ifndef AP_PRESENTER_H_
#define AP_PRESENTER_H_

#include "Model_Watch.h"
#include "FND.h"

void Presenter_OutData(watch_t watchData);
void Presenter_Excute();
void Presenter_DispFndTimeWatch(watch_t watchData);
void Presenter_DispFndStopWatch(watch_t watchData);
void Presenter_DispMonitorTimeWatch(watch_t watchData);
void Presenter_DispMonitorStopWatch(watch_t watchData);

#endif /* AP_PRESENTER_H_ */
