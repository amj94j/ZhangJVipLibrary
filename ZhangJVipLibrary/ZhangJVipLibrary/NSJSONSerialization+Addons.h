//
//  NSJSONSerialization+Addons.h
//  Shangyi
//
//  Created by Lvwy on 15/6/5.
//  Copyright (c) 2015年 liuyue. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSJSONSerialization (Addons)

extern NSData * JSONEncode(id object, NSError **error);
extern id JSONDecode(NSData *data, NSError **error);

@end

@interface NSString (NSJSONSerialization)

- (id)objectFromJSONString;

@end

@interface NSDictionary (NSJSONSerialization)

- (NSString *)JSONString;

@end
