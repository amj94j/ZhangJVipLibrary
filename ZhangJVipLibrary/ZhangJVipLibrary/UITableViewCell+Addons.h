//
//  UITableViewCell+Addons.h
//  Shangyi
//
//  Created by Lvwy on 15/6/22.
//  Copyright (c) 2015年 liuyue. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableViewCell (Addons)

+ (NSString *)reuseIdentifier;

- (void)setSelectedBackgroundColorWithHexString:(NSString *)hexString;

@end
