//
//  testC.h
//  KVApp
//
//  Created by Mike Green on 2020/7/24.
//  Copyright © 2020 KV. All rights reserved.
//

#ifndef testC_h
#define testC_h

#include <stdio.h>
// 加载ffmpeg源码
#include "libavutil/avutil.h"
// 注册设备
#include "libavdevice/avdevice.h"
// 格式化解析
#include "libavformat/avformat.h"
// 设备中读取音频包
#include "libavcodec/avcodec.h"

void test(void);

#endif /* testC_h */
