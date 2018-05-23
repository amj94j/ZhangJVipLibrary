//
//  UITableViewCell+Addons.m
//  Shangyi
//
//  Created by Lvwy on 15/6/22.
//  Copyright (c) 2015年 liuyue. All rights reserved.
//

#import "UITableViewCell+Addons.h"
#import "UIColor+Addons.h"

@implementation UITableViewCell (Addons)

+ (NSString *)reuseIdentifier {
    return NSStringFromClass(self.class);
}

- (void)setSelectedBackgroundColorWithHexString:(NSString *)hexString {
    UIView *view = [[UIView alloc] init];
    view.backgroundColor = [UIColor colorWithHexString:hexString];
    self.selectedBackgroundView = view;
}

@end
