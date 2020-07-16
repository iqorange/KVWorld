//
//  main.c
//  CFunc
//
//  Created by Mike Green on 2020/7/16.
//  Copyright © 2020 KV. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

int func(int a){
    printf("a = %d\n", a);
    return 0;
}

int funcc(int b){
    printf("b = %d\n", b + 5);
    return 0;
}

void operateFile(char *fileName){
    // 打开文件
    FILE* file = fopen(fileName, "w");
    if (!file) {
        printf("Failed to create file(%s)\n", fileName);
        return;
    }
    // 写数据
    size_t len = fwrite("Hello", 1, 5, file);
    if (len != 5) {
        printf("failed to write file, (%zu)", len);
        fclose(file);
        return;
    }
    printf("Successed towrite file\n");
    fclose(file);
    printf("Successed to create file\n");
}

void readData(char *fileName){
    char buffer[1024] = {0,};
    // 打开文件
    FILE* file = fopen(fileName, "w");
    if (!file) {
        printf("Failed to create file(%s)\n", fileName);
        return;
    }
    // 读取数据
    size_t len = fread(buffer, 1, 10, file);
    if (len > 0) {
        printf("readData: %s\n", buffer);
    }else{
        printf("Failed to read file!\n");
    }
    fclose(file);
    return;
}

int main(int argc, const char * argv[]) {
    // 逻辑操作语句
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
    
    // 函数指针（多态）
    int (*f)(int);
    f = func;
    f(2);
    f = funcc;
    f(3);
    
    // 函数调用
    //func(2);
    //funcc(3);
    
    // 文件读写
    operateFile("./1.txt");
    readData("./2.txt");
    return 0;
}
