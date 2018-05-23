//
//  NSDictionary+Addons.h
//
//  Created by Lvwy on 15/6/5.
//  Copyright (c) 2015年 ZhangJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (Addons)

- (id)noneNullObjectForKey:(id)aKey;

- (id)numberNullObjectForKey:(id)aKey;

- (id)objectOrNilForKey:(id)key;

@end


@interface NSMutableDictionary (Addons)

- (void)setObjectOrNil:(id)object forKey:(id)key;

@end


@interface NSDictionary (JsonAddons)

- (NSString *)stringValueForKey:(id)aKey;

- (NSString *)nonEmptyStringValueForKey:(id)aKey;

- (int32_t)int32ValueForKey:(id)aKey;

- (int64_t)int64ValueForKey:(id)aKey;

- (CGFloat)floatValueForKey:(id)aKey;

- (double)doubleValueForKey:(id)aKey;

- (BOOL)boolValueForKey:(id)aKey;

- (NSArray *)arrayValueForKey:(id)aKey;

@end

