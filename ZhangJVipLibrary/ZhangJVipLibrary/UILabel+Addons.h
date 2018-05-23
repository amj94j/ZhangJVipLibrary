//
//  UILabel+Addons.h
//
//  Created by apple on 16/5/11.
//  Copyright © 2016年 ZhangJ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (Addons)

/**
 *  创建一个UILabel
 *
 *  @param frame         设置UILabel的frame
 *  @param text          内容
 *  @param color         字体颜色
 *  @param font          字体大小
 *  @param textAlignment 对齐方式
 *
 *  @return 返回一个UILabel
 */
+ (UILabel *)commonLabelWithFrame:(CGRect)frame
                             text:(NSString *)text
                            color:(UIColor *)color
                             font:(UIFont *)font
                    textAlignment:(NSTextAlignment)textAlignment;

/**
 *  创建一个动态高度的UILabel
 *
 *  @param pointX        Label的横坐标
 *  @param pointY        Label的纵坐标
 *  @param width         Label的宽度
 *  @param strContent    内容
 *  @param color         字体颜色
 *  @param font          字体大小
 *  @param textAlignmeng 对齐方式
 *
 *  @return 返回一个UILabel
 */
+ (UILabel *)dynamicHeightLabelWithPointX:(CGFloat)pointX
                                   pointY:(CGFloat)pointY
                                    width:(CGFloat)width
                               strContent:(NSString *)strContent
                                    color:(UIColor *)color
                                     font:(UIFont *)font
                            textAlignmeng:(NSTextAlignment)textAlignmeng;

/**
 *  设置label的行间距
 *
 *  @param label        label
 *  @param labelSpacing 间距
 */
- (void)labelLineSpacingWith:(UILabel *)label
                labelSpacing:(int)labelSpacing;

+ (CGFloat)getHeightByWidth:(CGFloat)width title:(NSString *)title font:(UIFont*)font;

+ (CGFloat)getWidthWithTitle:(NSString *)title font:(UIFont *)font;



@end
