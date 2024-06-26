/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_VOLD_IDLE_MAINT_H
#define ANDROID_VOLD_IDLE_MAINT_H

#include "android/os/IVoldTaskListener.h"

namespace android {
namespace vold {

void Trim(const android::sp<android::os::IVoldTaskListener>& listener);
int RunIdleMaint(bool needGC, const android::sp<android::os::IVoldTaskListener>& listener);
int AbortIdleMaint(const android::sp<android::os::IVoldTaskListener>& listener);
int32_t GetStorageLifeTime();
int32_t GetStorageRemainingLifetime();
void SetGCUrgentPace(int32_t neededSegments, int32_t minSegmentThreshold, float dirtyReclaimRate,
                     float reclaimWeight, int32_t gcPeriod, int32_t minGCSleepTime,
                     int32_t targetDirtyRatio);
void RefreshLatestWrite();
int32_t GetWriteAmount();

}  // namespace vold
}  // namespace android

#endif
