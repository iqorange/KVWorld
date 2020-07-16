//
//  main.c
//  CStart
//
//  Created by Mike Green on 2020/7/16.
//  Copyright © 2020 KB. All rights reserved.
//

#include <stdio.h>
struct st{
    int a;
    float b;
};
enum em{
    RColor = 0,
    GColor,// 1
    BColor = 100
};
int main(int argc, const char * argv[]) {
    int a = 100;
    float b = 122.5;
    printf("a+b=%f\n", a*b);
    
    int arr[10] = {2, 3, 4, 5, 6};
    /*
     arr[0] = 1;
     arr[1] = 2;
     */
    printf("%d, %d, %d\n", arr[0], arr[1], arr[9]);
    
    struct st ss;
    ss.a = 12345;
    ss.b = 4.567;
    printf("%d, %f\n", ss.a, ss.b);
    
    enum em ee;
    ee = BColor;
    ee = GColor;
    printf("enum: %d\n", ee);
    
    return 0;
}
