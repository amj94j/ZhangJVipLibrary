//
//  NSString+Extend.h
//  Fetion
//
//  Created by lwy on 04/09/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSObject (ObjectEmpty)

+ (BOOL)empty:(NSObject *)o;

@end


@interface NSString (StringExtensions)

- (NSString *)trim;
- (NSString *)subStringBegin:(NSString *)beginStr end:(NSString *)endStr;
- (NSString *)subStringTrimEnd:(NSString *)endStr;
- (NSString *)substringFromString:(NSString *)str;
- (NSString *)substringToString:(NSString *)str;
- (NSString *)encodeSpecialChar;
- (NSString *)unencodeSpecialChar;
+ (NSString *)safeString:(NSString*)srcStr;

- (BOOL)isHTTPContentType:(NSString *)prefixStr;
+ (BOOL)isBlankString:(NSString *)string;
+ (BOOL)isNumber:(NSString *)string;
+ (BOOL)isValidPassword:(NSString *)password;
+ (BOOL)isValidateEmail:(NSString*)email;
+ (BOOL)isValidateMobileNo:(NSString *)phoneNo;

/*!
 Caculate number of size needed within expected parameters.
 
 @param font          expected font
 @param lineBreakMode expected lineBreakMode
 @param width         expected width
 
 @return size needed
 */
- (CGSize)sizeWithFont:(UIFont *)font lineBreakMode:(NSInteger)lineBreakMode width:(CGFloat)width;

/*!
 Caculate number of size needed within expected parameters.
 
 @param font          expected font
 @param lineBreakMode expected lineBreakMode
 @param lineSpacing   expected lineSpacing
 @param width         expected width
 
 @return size needed
 */

- (CGSize)sizeWithFont:(UIFont *)font lineBreakMode:(NSInteger)lineBreakMode lineSpacing:(CGFloat)lineSpacing width:(CGFloat)width;
/*!
 Caculate number of size needed within expected parameters when one line.
 
 @param font          expected font
 
 @return size needed
 */
- (CGSize)sizeForOneLineTextWithFont:(UIFont *)font;

/*!
 Caculate number of line needed within expected parameters.
 
 @param font          expected font
 @param lineBreakMode expected lineBreakMode
 @param width         expected width
 
 @return number of line needed
 */
- (NSInteger)numberOfLineWithFont:(UIFont *)font lineBreakMode:(NSInteger)lineBreakMode width:(CGFloat)width;

@end
