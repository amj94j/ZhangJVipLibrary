//
//  NSObject+JsonString.h
//  Shangyi
//
//  Created by Lvwy on 15/6/5.
//  Copyright (c) 2015年 liuyue. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (JsonString)

- (NSString *)JsonString;

/*!
 编码成JSON对象
 @note 如果失败，则返回自身
 
 @return 编码后的JSON对象
 */
- (id)jsonObject;

/*!
 解析json对象
 @return 解析后的对象
 */
- (id)jsonValue;

/*!
 生成不包含显示格式的json字符串
 @return 生成的json字符串
 */
- (NSString *)compactJsonString;


@end
