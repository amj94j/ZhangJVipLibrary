//
//  DefineHeader.h
//
//  Created by mac on 16/6/7.
//  Copyright © 2016年 zhangjie. All rights reserved.
//

#ifndef DefineHeader_h
#define DefineHeader_h


#define MARGIN_KEYBOARD 10
#import "ZYKeyboardUtil.h"

#pragma mark=====颜色设置=======
#define kColor_BaseBGColor @"f4f4f4"
#define kColor_BlueBGColor @"#399aff"
#define kColor_BaseTitleBGColor @"#999999"
#define kColor_BaseMainTitleColor @"#666666"

#define kColor_MAIN @"#12b7f5"
#define KColor_lineColor @"#e5e5e5"
#define kColor_TotalLineColor @"#c8c7cc"
#define kFont_AlternateGothic2BT @"AlternateGothic2 BT"
#define kFont_PingFangSC @"PingFangSC-Regular"
#define kFont_PingFangSCSemibold @"PingFangSC-Semibold"


#pragma mark=====全局字段========

//这个是在Xcode8之后 用于控制台的输出  升级之后在真机调试的时候就不会对nslog打印信息 进行打印
#ifdef DEBUG
#define CLLog(format, ...) printf("[%s] %s [第%d行] %s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ## __VA_ARGS__] UTF8String]);
#else
#define NSLog(format, ...)
#endif
#endif /* DefineHeader_h */
