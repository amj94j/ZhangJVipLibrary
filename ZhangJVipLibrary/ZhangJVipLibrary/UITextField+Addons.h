//
//  UITextField+Addons.h
//  XHDoctor
//
//  Created by apple on 17/6/30.
//  Copyright © 2017年 XH. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (Addons)
+ (UITextField *)commonTextFieldWithFrame:(CGRect)frame
                                     text:(NSString *)text
                                    color:(UIColor *)color
                                     font:(UIFont *)font
                            textAlignment:(NSTextAlignment)textAlignment;
@end
