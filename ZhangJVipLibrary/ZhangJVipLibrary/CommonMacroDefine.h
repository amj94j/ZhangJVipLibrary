//
//  CommonMacroDefine.h
//
//  Created by apple on 16/5/10.
//  Copyright © 2016年 zhangjie. All rights reserved.
//

#ifndef CommonMacroDefine_h
#define CommonMacroDefine_h
#define Macro_AppDelegate   ((AppDelegate *)[UIApplication sharedApplication].delegate)
#define Macro_TopAppDelegate  ([[UIApplication sharedApplication] keyWindow])
#define ScreenWidth ([[UIScreen mainScreen] bounds].size.width)
#define ScreenHeight ([[UIScreen mainScreen] bounds].size.height)
#define PXChange(r) ((ScreenWidth/750.f)*(r))
#define Macro_RGB(r,g,b)             [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0f]

#define Macro_RGBA(r,g,b,a)          [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]

#define Macro_HexColor(rgbValue)     [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:\
((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0

#define Macro_IsIOS7OrLater() ([[UIDevice currentDevice] deviceSystemMajorVersion] >= 7)

#ifdef DEBUG

#define NSSLog(FORMAT, ...) fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);

#else

#define NSSLog(...)

#endif

#define isFivePointFiveOrBiggerInchesScreen ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && (((double)[[UIScreen mainScreen] bounds ].size.height - (double)736) >= 0 || isFivePointFiveInchesScreen))

#define isFivePointFiveInchesScreen ((UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone) && ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )736 ) < DBL_EPSILON ))


#define FloatIsEqual(float1,float2) ((fabs(float1 - float2) < FLT_EPSILON) ? YES : NO)
#define DoubleIsEqual(double1,double2) ((fabs(double1 - double2) < DBL_EPSILON) ? YES : NO)

#define WSNotNilOrDefault(value, default) (value ? value : default)
#define SafeEmptyStatement do{} while(0)


#define LUDebugLog(...)         SafeEmptyStatement

#define dispatch_async_on_main_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}


#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_8_0
#define CompileSDK8OrLater(statement)   {statement}
#else // __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_8_0
#define CompileSDK8OrLater(statement)   SafeEmptyStatement
#endif // __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_8_0

#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_8_0
#define CompileSDK8Earlier(statement) {statement}
#else // __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_8_0
#define CompileSDK8Earlier(statement)   SafeEmptyStatement
#endif // __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_8_0



#ifdef __OBJC__

#if !__has_feature(objc_arc)

// Safe releases
#define WSInvalidateTimer(__TIMER) { [__TIMER invalidate]; [__TIMER release]; __TIMER = nil; }
#define WSReleaseSafely(__POINTER) { [__POINTER release]; __POINTER = nil; }

#define WSBlockWeakObject(obj, wobj)  __block __typeof__((__typeof__(obj))obj) wobj = obj
#define WSBlockStrongObject(obj, sobj) __typeof__((__typeof__(obj))obj) sobj = [[obj retain] autorelease]

#else // !__has_feature(objc_arc)

// Safe releases
#define WSInvalidateTimer(__TIMER) { [__TIMER invalidate]; __TIMER = nil; }
#define WSReleaseSafely(__POINTER) { __POINTER = nil; }

#define WSBlockWeakObject(obj, wobj)  __weak __typeof__((__typeof__(obj))obj) wobj = obj
#define WSBlockStrongObject(obj, sobj) __typeof__((__typeof__(obj))obj) sobj = obj
#endif // !__has_feature(objc_arc)


#define CreateCategoryPropertyForNSObject($objectType$, $objectName$, $setterName$, $propertyType$) \
char $objectName$##Key; \
- (id) $objectName$ { \
id localObject = objc_getAssociatedObject(self, & $objectName$##Key ); \
if (!localObject) { \
localObject = [[$objectType$ alloc] init]; \
self.$objectName$ = localObject; \
} \
return localObject; \
} \
\
- (void)set##$setterName$:(id)localObject { \
objc_setAssociatedObject(self, & $objectName$##Key, localObject, $propertyType$ ); \
}

#define CreateCategoryPropertyForBlock($objectType$, $objectName$, $setterName$) \
char $objectName$##Key; \
- ($objectType$) $objectName$ { \
return objc_getAssociatedObject(self, & $objectName$##Key); \
} \
\
- (void)set##$setterName$:($objectType$)localObject { \
objc_setAssociatedObject(self, & $objectName$##Key, localObject, OBJC_ASSOCIATION_COPY); \
}

#endif // __OBJC__


#define WSDefaultInstanceForClassHeader(CLASSNAME) + (CLASSNAME *)defaultInstance
#define WSDefaultInstanceForClass(CLASSNAME) WSDefaultInstanceForClassMethod(CLASSNAME, defaultInstance)
#define WSDefaultInstanceForClassMethodHeader(CLASSNAME, METHODNAME) + (CLASSNAME *) METHODNAME
#define WSDefaultInstanceForClassMethod(CLASSNAME, METHODNAME) \
+ (CLASSNAME *) METHODNAME {    \
static CLASSNAME *METHODNAME##_;\
static dispatch_once_t predicate;\
dispatch_once(&predicate, ^{\
METHODNAME##_ = [[self alloc] init];\
SEL setupSelector = NSSelectorFromString(@"setup");\
if ([METHODNAME##_ respondsToSelector:setupSelector]) {\
IMP imp = [METHODNAME##_ methodForSelector:setupSelector]; \
void (*func)(id, SEL) = (void *)imp; \
func(METHODNAME##_, setupSelector); \
}\
});\
return METHODNAME##_;\
}


#endif /* CommonMacroDefine_h */
