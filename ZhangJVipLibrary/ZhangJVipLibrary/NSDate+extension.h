//
//  NSDate+extension.h
//  ZhangJVipLibrary
//
//  Created by apple on 2017/12/19.
//  Copyright © 2017年 ZhangJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@class  JYChatMessageModel;

@interface NSDate (extension)

// 判断时间戳是否为当天,昨天,一周内,年月日
+ (NSString *)timeStringWithTimeInterval:(NSString *)timeInterval;

/**
 计算时间差 1h19m
 
 @param beginTime 开始时间
 @param endTime 结束时间
 @return 剩余时间
 */
+ (NSString *)getCountDownStringWithBeginTime:(NSString *)beginTime EndTime:(NSString *)endTime;

// 时间戳转换为时间 北京时间 格式yyyy-MM-dd HH:mm:ss 
+ (NSString *)timeWithTimeIntervalString:(NSString *)timeString;

@end
