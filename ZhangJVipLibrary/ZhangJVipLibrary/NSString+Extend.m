//
//  NSString+Extend.m
//  Fetion
//
//  Created by lwy on 04/09/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.


#import "NSString+Extend.h"
#import "RegexKitLite.h"

#define REGEX_EMAIL @"^([a-z0-9_\.-]+)@([\da-z\.-]+)\.([a-z\.]{2,6})$"
#define REGEX_PASSWORD @"^[a-z0-9_-]{6,16}$"


#define CC_MD5_DIGEST_LENGTH	16			/* digest length in bytes */
#define CC_MD5_BLOCK_BYTES		64			/* block size in bytes */
#define CC_MD5_BLOCK_LONG       (CC_MD5_BLOCK_BYTES / sizeof(CC_LONG))



@implementation NSObject (ObjectEmpty)
+ (BOOL)empty:(NSObject *)o{
	if (o==nil) {
		return YES;
	}
	if (o==NULL) {
		return YES;
	}
	if (o==[NSNull null]) {
		return YES;
	}
	if ([o isKindOfClass:[NSString class]]) {
		return [NSString isBlankString:(NSString *)o];
	}
	if ([o isKindOfClass:[NSData class]]) {
		return [((NSData *)o) length]<=0;
	}
	if ([o isKindOfClass:[NSDictionary class]]) {
		return [((NSDictionary *)o) count]<=0;
	}
	if ([o isKindOfClass:[NSArray class]]) {
		return [((NSArray *)o) count]<=0;
	}
	if ([o isKindOfClass:[NSSet class]]) {
		return [((NSSet *)o) count]<=0;
	}
	return NO;
}
@end



@implementation NSString (StringExtensions)

- (NSString *)trim
{
	NSString *str = [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
	return str;
}

- (NSString *)subStringBegin:(NSString *)beginStr end:(NSString *)endStr{
    NSRange range1 = [self rangeOfString:beginStr options:NSCaseInsensitiveSearch];
	NSRange range2 = [self rangeOfString: endStr options:NSCaseInsensitiveSearch];
	
	if (range1.location == NSNotFound || range2.location == NSNotFound)
	{
		return nil;
	}
	
	NSRange range3 = {range1.location + range1.length, range2.location - range1.location - range1.length };
	NSString *key = [self substringWithRange: range3];
	
	return [key trim];
}

- (NSString *)subStringTrimEnd:(NSString *)endStr{
	NSRange range = [self rangeOfString:endStr options:NSCaseInsensitiveSearch];
	if (range.location == NSNotFound)
	{
		return nil;
	}
	
	NSRange rangeKey = {0, range.location};
	NSString *key = [self substringWithRange:rangeKey];
	
	return [key trim];
}

- (NSString *)substringFromString:(NSString *)str{
    
    NSRange range = [self rangeOfString:str options:NSCaseInsensitiveSearch];
	if (range.location == NSNotFound)
	{
		return nil;
	}
	
    NSInteger tIndex = range.location + range.length;
    
    return [self substringFromIndex:tIndex];
    
}

- (NSString *)substringToString:(NSString *)str{
    
    NSRange range = [self rangeOfString:str options:NSCaseInsensitiveSearch];
	if (range.location == NSNotFound)
	{
		return nil;
	}
	
    NSInteger tIndex = range.location;
    
    if (tIndex < 0) {
        return @"";
    }
    
    return [self substringToIndex:tIndex];
    
}

+ (NSString*)safeString:(NSString*)srcStr{
    
    if ([NSObject empty:srcStr]) {
        return @"";
    }
    return [NSString stringWithFormat:@"%@", srcStr];
}

- (BOOL)isHTTPContentType:(NSString *)prefixStr
{
    BOOL    result;
    NSRange foundRange;
    
    result = NO;
    
    foundRange = [self rangeOfString:prefixStr options:NSAnchoredSearch | NSCaseInsensitiveSearch];
    if (foundRange.location != NSNotFound) {
        assert(foundRange.location == 0);            
        if (foundRange.length == self.length) {
            result = YES;
        } else {
            unichar nextChar;
            
            nextChar = [self characterAtIndex:foundRange.length];
            result = nextChar <= 32 || nextChar >= 127 || (strchr("()<>@,;:\\<>/[]?={}", nextChar) != NULL);
        }
		
    }
    return result;
}

+ (BOOL)isBlankString:(NSString *)string{
    BOOL result = NO;
    
    if (NULL == string || [string isEqual:nil] || [string isEqual:Nil]) 
    {
        result = YES;
    }
    else if ([string isEqual:[NSNull null]])
    {
        result = YES;
    }
    else if (0 == [string length] || 0 == [[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length])
    {
        result = YES;
    }
    else if([string isEqualToString:@"(null)"])
    {
        result = YES;
    }
    
    return result;
}

+ (BOOL)isNumber:(NSString *)string{
	if ([NSString isBlankString:string]) {
		return NO;
	}else {
		if (![NSString isBlankString:[string stringByMatching:@"^\\d+(\\.\\d+)?$"]]){
			return YES;
		}
	}
	return NO;
}


+ (BOOL)isValidPassword:(NSString *)password{
    return [password isMatchedByRegex:REGEX_PASSWORD];
}


//判断邮箱是否合法的代码
+ (BOOL)isValidateEmail:(NSString*)email
{
    if((0 != [email rangeOfString:@"@"].length) &&
       (0 != [email rangeOfString:@"."].length))
    {
        
        NSCharacterSet* tmpInvalidCharSet = [[NSCharacterSet alphanumericCharacterSet] invertedSet];
        NSMutableCharacterSet* tmpInvalidMutableCharSet = [tmpInvalidCharSet mutableCopy];
        [tmpInvalidMutableCharSet removeCharactersInString:@"_-"];
        
        //使用compare option 来设定比较规则，如
        //NSCaseInsensitiveSearch是不区分大小写
        //NSLiteralSearch 进行完全比较,区分大小写
        //NSNumericSearch 只比较定符串的个数，而不比较字符串的字面值
        NSRange range1 = [email rangeOfString:@"@"
                                      options:NSCaseInsensitiveSearch];
        
        //取得用户名部分
        NSString* userNameString = [email substringToIndex:range1.location];
        NSArray* userNameArray   = [userNameString componentsSeparatedByString:@"."];
        
        for(NSString* string in userNameArray)
        {
            NSRange rangeOfInavlidChars = [string rangeOfCharacterFromSet: tmpInvalidMutableCharSet];
            if(rangeOfInavlidChars.length != 0 || [string isEqualToString:@""])
                return NO;
        }
        
        NSString *domainString = [email substringFromIndex:range1.location+1];
        NSArray *domainArray   = [domainString componentsSeparatedByString:@"."];
        
        for(NSString *string in domainArray)
        {
            NSRange rangeOfInavlidChars=[string rangeOfCharacterFromSet:tmpInvalidMutableCharSet];
            if(rangeOfInavlidChars.length !=0 || [string isEqualToString:@""])
                return NO;
        }
        
        return YES;
    }
    else // no ''@'' or ''.'' present
        return NO;
}


+ (BOOL)isValidateMobileNo:(NSString *)phoneNo
{
    return YES;
}

- (CGSize)getAutoSizeSizeWithFont:(NSInteger)limitFontSize withWidth:(NSInteger)limitWidth
{
    CGSize textSize = [self sizeWithFont:[UIFont systemFontOfSize:limitFontSize] constrainedToSize:CGSizeMake(limitWidth, ScreenHeight) lineBreakMode:NSLineBreakByWordWrapping];
    NSInteger lineCount = (0 == (NSInteger)textSize.width%limitWidth) ? (NSInteger)textSize.width/limitWidth : (NSInteger)textSize.width/limitWidth +1;
    NSInteger textWidth = textSize.width > limitWidth ? limitWidth : textSize.width;
    
    return CGSizeMake(textWidth, lineCount*textSize.height);
}

- (id)encodeSpecialChar
{
    NSString *value = [self stringByReplacingOccurrencesOfString:@"<" withString:@"&lt;"];
    value = [value stringByReplacingOccurrencesOfString:@">" withString:@"&gt;"];
    value = [value stringByReplacingOccurrencesOfString:@":" withString:@"&mh;"];
    return value;
}
- (NSString *)unencodeSpecialChar
{
    NSString *value = [self stringByReplacingOccurrencesOfString:@"&lt;" withString:@"<"];
    value = [value stringByReplacingOccurrencesOfString:@"&gt;" withString:@">"];
    value = [value stringByReplacingOccurrencesOfString:@"&mh;" withString:@":"];
    
    return value;
}

- (CGSize)sizeWithFont:(UIFont *)font lineBreakMode:(NSInteger)lineBreakMode width:(CGFloat)width {
    CGSize size = CGSizeZero;
    size = [self boundingRectWithSize:CGSizeMake(width, CGFLOAT_MAX)
                              options:(NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingUsesFontLeading)
                           attributes:@{NSFontAttributeName:font}
                              context:nil].size;
    return size;
}
- (CGSize)sizeWithFont:(UIFont *)font lineBreakMode:(NSInteger)lineBreakMode lineSpacing:(CGFloat)lineSpacing width:(CGFloat)width {
    CGSize size = CGSizeZero;
    size = [self boundingRectWithSize:CGSizeMake(width, CGFLOAT_MAX)
                                  options:(NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingUsesFontLeading)
                               attributes:@{NSFontAttributeName:font}
                                  context:nil].size;
    size.height += (size.height / font.lineHeight - 1.) * lineSpacing;
    
    return size;
}

- (CGSize)sizeForOneLineTextWithFont:(UIFont *)font {
    CGSize size = CGSizeZero;
    size = [self sizeWithAttributes:@{NSFontAttributeName: font}];
    
    return size;
}

- (NSInteger)numberOfLineWithFont:(UIFont *)font lineBreakMode:(NSInteger)lineBreakMode width:(CGFloat)width {
    NSInteger numberOfLine = 1;
    CGSize size = [self sizeWithFont:font lineBreakMode:lineBreakMode width:width];
    
    numberOfLine = ceil(size.height) / font.pointSize;
    
    return numberOfLine;
}


@end

