//
//  ZJUtils.h
//
//  Created by apple on 2017/8/16.
//  Copyright © 2017年 ZhangJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZJUtils : NSObject

//验证手机号是否输入正确
+ (BOOL)validateMobile:(NSString *)mobile;

// 验证手机号
+ (BOOL)isMobileNumber:(NSString *)mobileNum;

// 验证邮箱
+ (BOOL)validateEmail:(NSString *)email;

// 验证银行卡号码
+ (BOOL)validateBankCardNumber:(NSString *)bankCardNumber;

// 身份证号
+ (BOOL)validateIdentityCard:(NSString *)identityCard;

// 获取系统版本号
+ (float)getIOSVersion;

+ (NSString *)returnFloatFromStr:(NSString *)str;

+ (void)setNewHealthRadio:(NSDictionary *)dict;

+ (NSDictionary *)getNewHealthRadio;

/**
 *  通过 CAShapeLayer 方式绘制虚线
 *
 *  param lineView:       需要绘制成虚线的view
 *  param lineLength:     虚线的宽度
 *  param lineSpacing:    虚线的间距
 *  param lineColor:      虚线的颜色
 *  param lineDirection   虚线的方向  YES 为水平方向， NO 为垂直方向
 **/
+ (void)drawLineOfDashByCAShapeLayer:(UIView *)lineView lineLength:(int)lineLength lineSpacing:(int)lineSpacing lineColor:(UIColor *)lineColor lineDirection:(BOOL)isHorizonal;

// 将一个View转换成图片
+ (UIImage*)imageWithUIView:(UIView *)view;

#pragma mark - 给view加圆角和边框及颜色
+ (void)setRoundView:(UIView *)view radius:(CGFloat)radius borderWidth:(CGFloat)width color:(UIColor *)color;
@end
