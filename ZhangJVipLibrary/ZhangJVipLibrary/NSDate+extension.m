//
//  NSDate+extension.m
//  ZhangJVipLibrary
//
//  Created by apple on 2017/12/19.
//  Copyright © 2017年 ZhangJ. All rights reserved.
//

#import "NSDate+extension.h"

@implementation NSDate (extension)

+ (NSString *)timeStringWithTimeInterval:(NSString *)timeInterval
{
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:timeInterval.longLongValue/1000]; //此处根据项目需求,选择是否除以1000 , 如果时间戳精确到秒则去掉1000
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    
    // 今天
    if ([date isToday]) {
        
        formatter.dateFormat = @"HH:mm";
        
        return [formatter stringFromDate:date];
    } else {
        
        // 昨天
        if ([date isYesterday]) {
            
            formatter.dateFormat = @"昨天HH:mm";
            return [formatter stringFromDate:date];
            
            // 一周内 [date weekdayStringFromDate]
        } else if ([date isSameWeek]) {
            
            formatter.dateFormat = [NSString stringWithFormat:@"%@%@",[date weekdayStringFromDate],@"HH:mm"];
            return [formatter stringFromDate:date];
            
            // 直接显示年月日
        } else {
            
            formatter.dateFormat = @"yy-MM-dd  HH:mm";
            return [formatter stringFromDate:date];
        }
    }
    return nil;
}

//是否在同一周
- (BOOL)isSameWeek
{
    NSCalendar *calendar = [NSCalendar currentCalendar];
    int unit = NSCalendarUnitWeekday | NSCalendarUnitMonth | NSCalendarUnitYear ;
    
    // 1.获得当前时间的 年月日
    NSDateComponents *nowCmps = [calendar components:unit fromDate:[NSDate date]];
    
    // 2.获得self
    NSDateComponents *selfCmps = [calendar components:unit fromDate:self];
    
    return (selfCmps.year == nowCmps.year) && (selfCmps.month == nowCmps.month) && (selfCmps.day == nowCmps.day);
}


// 根据日期求星期几
- (NSString *)weekdayStringFromDate {
    
    NSArray *weekdays = [NSArray arrayWithObjects: [NSNull null], @"星期天", @"星期一", @"星期二", @"星期三", @"星期四", @"星期五", @"星期六", nil];
    
    NSCalendar *calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSTimeZone *timeZone = [[NSTimeZone alloc] initWithName:@"Asia/Beijing"];
    
    [calendar setTimeZone: timeZone];
    
    NSCalendarUnit calendarUnit = NSCalendarUnitWeekday;
    
    NSDateComponents *theComponents = [calendar components:calendarUnit fromDate:self];
    
    return [weekdays objectAtIndex:theComponents.weekday];
    
}

// 是否为今天
- (BOOL)isToday
{
    //now: 2015-09-05 11:23:00
    //self 调用这个方法的对象本身
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    int unit = NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear ;
    
    //1.获得当前时间的 年月日
    NSDateComponents *nowCmps = [calendar components:unit fromDate:[NSDate date]];
    
    //2.获得self
    NSDateComponents *selfCmps = [calendar components:unit fromDate:self];
    
    return (selfCmps.year == nowCmps.year) && (selfCmps.month == nowCmps.month) && (selfCmps.day == nowCmps.day);
}

// 是否为昨天
- (BOOL)isYesterday
{
    NSDate *nowDate = [[NSDate date] dateWithYMD];
    
    NSDate *selfDate = [self dateWithYMD];
    
    //获得nowDate和selfDate的差距
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *cmps = [calendar components:NSCalendarUnitDay fromDate:selfDate toDate:nowDate options:0];
    
    return cmps.day == 1;
}

//格式化
- (NSDate *)dateWithYMD
{
    NSDateFormatter *fmt = [[NSDateFormatter alloc] init];
    fmt.dateFormat = @"yyyy-MM-dd";
    NSString *selfStr = [fmt stringFromDate:self];
    return [fmt dateFromString:selfStr];
}

// 时间戳转换为时间
+ (NSString *)timeWithTimeIntervalString:(NSString *)timeString
{
    // 格式化时间
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    formatter.timeZone = [NSTimeZone timeZoneWithName:@"Asia/Beijing"];
    [formatter setDateStyle:NSDateFormatterMediumStyle];
    [formatter setTimeStyle:NSDateFormatterShortStyle];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    
    // 毫秒值转化为秒
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:[timeString doubleValue]/1000.0];
    NSString *dateString = [formatter stringFromDate:date];
    return dateString;
}

// 计算时间差
+ (NSString *)getCountDownStringWithBeginTime:(NSString *)beginTime EndTime:(NSString *)endTime {
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    
    NSDate *now = [dateFormatter dateFromString:beginTime];
    NSTimeZone *zone = [NSTimeZone systemTimeZone]; // 设置时区
    NSInteger interval = [zone secondsFromGMTForDate: now];
    NSDate *localDate = [now  dateByAddingTimeInterval: interval];
    NSDate *endDate = [dateFormatter dateFromString:endTime];
    NSInteger endInterval = [zone secondsFromGMTForDate: endDate];
    NSDate *end = [endDate dateByAddingTimeInterval: endInterval];
    NSTimeInterval voteCountTime = [end timeIntervalSinceDate:localDate];
    NSUInteger hTime = (int)voteCountTime/3600;
    NSUInteger mTime = ((int)voteCountTime%3600)/60;
    NSString *timeStr = @"";
    if (mTime>0) {
        timeStr = [NSString stringWithFormat:@"%luh%lum", (unsigned long)hTime,(unsigned long)mTime];
    } else {
        timeStr = [NSString stringWithFormat:@"%luh", (unsigned long)hTime];
    }
    return timeStr;
}




@end
