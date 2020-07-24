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
    av_log_set_level(AV_LOG_DEBUG);
    av_log(NULL, AV_LOG_DEBUG, "Hello AVUtil~\n");
    return;
}
