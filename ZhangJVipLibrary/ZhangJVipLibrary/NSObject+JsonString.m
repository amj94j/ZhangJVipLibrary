//
//  NSObject+JsonString.m
//  Shangyi
//
//  Created by Lvwy on 15/6/5.
//  Copyright (c) 2015年 liuyue. All rights reserved.
//

#import "NSObject+JsonString.h"
#import "NSJSONSerialization+Addons.h"

@implementation NSObject (JsonString)
- (NSString *)JsonString {
    NSError *error = nil;
    NSData *body = JSONEncode(self, &error);
    NSString *jsonString = [[NSString alloc] initWithData:body encoding:NSUTF8StringEncoding];
    return jsonString;
}

- (id)jsonObject {
    id jsonObject = nil;
    if ([NSJSONSerialization isValidJSONObject:self]) {
        jsonObject = JSONEncode(self, nil);
    }
    return jsonObject ? jsonObject : self;
}

/*!
 解析json对象
 @return 解析后的对象
 */
- (id)jsonValue {
    NSData *_data = nil;
    if ([self isKindOfClass:[NSData class]]) {
        _data = (NSData *)self;
    } else if ([self isKindOfClass:[NSString class]]) {
        NSString *dataString = (NSString *)self;
        _data = [dataString dataUsingEncoding:NSUTF8StringEncoding];
    }
    
    if (_data) {
        return JSONDecode(_data, nil);
    }
    
    return nil;
}

/*!
 生成不包含显示格式的json字符串
 @return 生成的json字符串
 */
- (NSString *)compactJsonString {
    NSError *error = nil;
    NSString *jsonString = nil;
    if ([NSJSONSerialization isValidJSONObject:self]) {
        NSData *body = [NSJSONSerialization dataWithJSONObject:self options:0 error:&error];
        jsonString = [[NSString alloc] initWithData:body encoding:NSUTF8StringEncoding];
    }
    return jsonString;
}

@end
