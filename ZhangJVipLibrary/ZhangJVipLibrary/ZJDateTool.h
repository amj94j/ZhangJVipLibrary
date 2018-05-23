//
//  ZJDateTool.h
//  ZhangJVipLibrary
//
//  Created by apple on 2017/12/17.
//  Copyright © 2017年 ZhangJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZJDateTool : NSObject
/**
 *  获取当天的时间
 *
 *  @return 返回当天时间
 */
+ (NSString *)getDateTime;

/**
 获取当前时间
 
 @return 格式：0000-00-00 00:00:00
 */
+ (NSString *)getDateTimeToS;

/**
 *  获取当前时间戳
 */
+ (NSString *)getTimeFlag;

/**
 *  根据日期返回特定字符串
 *
 *  @return 返回丹田是时间`
 */
+ (NSString *)getDateTimeWithData:(NSDate *)date;

+ (NSString *)getDateTimeForDay;

//根据字符串得到日期
+ (NSDate *)getDateFromString:(NSString *)dateStr;

@end
