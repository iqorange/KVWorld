//
//  testC.c
//  KVApp
//
//  Created by Mike Green on 2020/7/24.
//  Copyright © 2020 KV. All rights reserved.
//

#include "testC.h"
void test(){
    printf("This is a C function\n");
    
    // 音视频设备上下文
    AVFormatContext *fmt_ctx;
    // 打开音视频设备的方式
    // [[video device]:[audio device]]
    char *devicename = ":0";
    // 设备参数，暂时为空
    AVDictionary *options = NULL;
    // 状态值 成功=0 不成功<0
    int ret = 0;
    // 错误信息容器
    char errors[1024];
    
    // 注册所有设备
    avdevice_register_all();
    // 获得格式解析
    AVInputFormat *iformat = av_find_input_format("avfoundation");
    // 打开设备
    if ((ret = avformat_open_input(&fmt_ctx, devicename, iformat, &options)) < 0) {
        // 出错的情况
        av_strerror(ret, errors, 1024);
        printf(stderr, "Failed to open audio device, error code: [%d], error message: %s\n", ret, errors);
        return;
    }
    
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "Hello AVUtil~\n");
    return;
}
