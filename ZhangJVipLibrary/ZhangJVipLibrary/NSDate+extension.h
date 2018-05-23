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
//判断时间戳是否为当天,昨天,一周内,年月日
+ (NSString *)timeStringWithTimeInterval:(NSString *)timeInterval;

@end
