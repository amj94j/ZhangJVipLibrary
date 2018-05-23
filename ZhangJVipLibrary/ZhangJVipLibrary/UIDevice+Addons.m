//
//  UIDevice+Addons.m
//  Shangyi
//
//  Created by Lvwy on 15/6/22.
//  Copyright (c) 2015年 liuyue. All rights reserved.
//

#import "UIDevice+Addons.h"
#import <objc/runtime.h>

@implementation UIDevice (Addons)

#pragma mark - system version

- (NSUInteger)deviceSystemMajorVersion {
    static NSUInteger _deviceSystemMajorVersion = -1;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _deviceSystemMajorVersion =
        [[[[[UIDevice currentDevice] systemVersion]
           componentsSeparatedByString:@"."] objectAtIndex:0] intValue];
    });
    
    return _deviceSystemMajorVersion;
}

@end
