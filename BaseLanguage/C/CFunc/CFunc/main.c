//
//  main.c
//  CFunc
//
//  Created by Mike Green on 2020/7/16.
//  Copyright © 2020 KV. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    int a = 2;
    int b = 5;
    if (a > b) {
        printf("a > b\n");
    }else{
        printf("a <= b\n");
    }
    for (int i=0; i<10;i++) {
        printf("i = %d\n", i);
    }
    while (a < b) {
        a++;
        printf("%d\n", a);
        // 微秒
        usleep(1000000);
    }
    return 0;
}
