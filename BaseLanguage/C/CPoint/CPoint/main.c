//
//  main.c
//  CPoint
//
//  Created by Mike Green on 2020/7/16.
//  Copyright © 2020 KV. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // 指针
    // 分配内存空间
    char* p = (char*)malloc(10);
    *p = 'a';
    *(p+1) = 'b';
    *(p+2) = 'c';
    printf("%s\n", p);
    // 释放堆空间资源
    free(p); p = NULL;
    return 0;
}
