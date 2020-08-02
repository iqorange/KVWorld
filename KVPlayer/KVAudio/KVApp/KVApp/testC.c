//
//  testC.c
//  KVApp
//
//  Created by Mike Green on 2020/7/24.
//  Copyright © 2020 KV. All rights reserved.
//

#include "testC.h"
// 录制状态
static int rec_status = 0;

void set_status(int status){
    rec_status = status;
}

void record_audio(){
//    printf("This is a C function\n");
    
    // ***** 对象构建 *****
    /**
     Context
     */
    // 音视频设备上下文
    AVFormatContext *fmt_ctx;
    // 设备参数，暂时为空
    AVDictionary *options = NULL;
    
    // 打开音视频设备的方式
    // [[video device]:[audio device]]
    char *devicename = ":0";
    
    // set log level
    av_log_set_level(AV_LOG_DEBUG);
    
    // Start Rec
    rec_status = 1;
        
    /**
     packet
     */
    // 循环计数器
    int count = 0;
    // 栈空间中注册数据包
    AVPacket pkt;
    
    // 状态值 成功=0 不成功<0
    int ret = 0;
    // 错误信息容器
    char errors[1024] = {0, };
    // ********************
    
    /**
     Open device
     */
    // 注册所有设备
    avdevice_register_all();
    // 初始化数据包
    av_init_packet(&pkt);
    // 获得格式解析
    AVInputFormat *iformat = av_find_input_format("avfoundation");
    
    // 打开设备
    if ((ret = avformat_open_input(&fmt_ctx, devicename, iformat, &options)) < 0) {
        // 出错的情况
        av_strerror(ret, errors, 1024);
        printf(stderr, "Failed to open audio device, error code: [%d], error message: %s\n", ret, errors);
        return;
    }
    
    // 创建文件
    // read: r, write: w, binary: b, create file: +
    char *path = "../avbase/audio.pcm";
    FILE *outfile = fopen(path, "wb+");
    
    /**
     Read data from device
     */
    // 循环读取音频包
    while ((ret = av_read_frame(fmt_ctx, &pkt)) == 0 && rec_status) {
        // file write
        fwrite(pkt.data, pkt.size, 1, outfile);
        // 写入磁盘
        if(count % 10 == 0){
            fflush(outfile);
        }
        
        av_log(NULL, AV_LOG_INFO, "Packet size is %d(%p), count = %d \n", pkt.size, pkt.data, count);
        printf("pkt size is %d \n", pkt.size);
        // 释放数据包
        av_packet_unref(&pkt);
    }
    
    // close file
    fclose(outfile);
    
    // 释放上下文 Close device and release context
    avformat_close_input(&fmt_ctx);
    
    av_log(NULL, AV_LOG_DEBUG, "Finish AVUtil~\n");
    return;
    // ffplay -ar 44100 -ac 2 -f f32le audio.pcm
}
