//
//  NSJSONSerialization+Addons.m
//  Shangyi
//
//  Created by Lvwy on 15/6/5.
//  Copyright (c) 2015年 liuyue. All rights reserved.
//

#import "NSJSONSerialization+Addons.h"

@implementation NSJSONSerialization (Addons)

NSData * JSONEncode(id object, NSError **error) {
    return [NSJSONSerialization dataWithJSONObject:object options:NSJSONWritingPrettyPrinted error:error];
}

id JSONDecode(NSData *data, NSError **error) {
    return [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:error];
}

@end

@implementation NSString (NSJSONSerialization)

- (id)objectFromJSONString {
    return JSONDecode([self dataUsingEncoding:NSUTF8StringEncoding], nil);
}

@end

@implementation NSDictionary (NSJSONSerialization)

- (NSString *)JSONString {
    return [[NSString alloc] initWithData:JSONEncode(self, nil)
                                 encoding:NSUTF8StringEncoding];
}


@end
