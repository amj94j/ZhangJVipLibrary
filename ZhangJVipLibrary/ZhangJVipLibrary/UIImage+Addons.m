//
//  UIImage+Addons.m
//  Yuesao
//
//  Created by apple on 16/5/11.
//  Copyright © 2016年 zhangjie. All rights reserved.
//

#import "UIImage+Addons.h"

@implementation UIImage (Addons)
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size {
    return [UIImage imageWithColor:color strokeColor:nil size:size radius:0.f];
}

+ (UIImage *)imageWithColor:(UIColor *)color strokeColor:(UIColor *)strokeColor size:(CGSize)size {
    return [UIImage imageWithColor:color strokeColor:strokeColor size:size radius:0.f];
}

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size radius:(CGFloat)radius {
    return [UIImage imageWithColor:color strokeColor:nil size:size radius:radius];
}

+ (UIImage *)imageWithColor:(UIColor *)color strokeColor:(UIColor *)strokeColor size:(CGSize)size radius:(CGFloat)radius {
    return [UIImage imageWithColor:color
                       strokeColor:strokeColor
                              size:size
                      roundCorners:UIRectCornerAllCorners
                             radii:CGSizeMake(radius, radius)];
}

+ (UIImage *)imageWithColor:(UIColor *)color
                strokeColor:(UIColor *)strokeColor
                       size:(CGSize)size
               roundCorners:(UIRectCorner)corners
                      radii:(CGSize)radii {
    UIGraphicsBeginImageContextWithOptions(size, NO, 0);
    
    CGRect rect = CGRectMake(0, 0, size.width, size.height);
    UIBezierPath *path =
    [UIBezierPath bezierPathWithRoundedRect:rect
                          byRoundingCorners:corners
                                cornerRadii:radii];
    [path addClip];
    
    [color setFill];
    [path fill];
    
    if (strokeColor) {
        path.lineWidth = 1. * [UIScreen mainScreen].scale;
        [strokeColor setStroke];
        [path stroke];
    }
    
    UIImage *roundedImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return roundedImage;
}

+ (UIImage *)imageInMainBundleNamed:(NSString *)name {
    NSString *filePath = [[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:name];
    return [self imageWithContentsOfFile:filePath];
}

//http://stackoverflow.com/questions/6141298/how-to-scale-down-a-uiimage-and-make-it-crispy-sharp-at-the-same-time-instead/7775470#7775470
+ (UIImage *)resizeImage:(UIImage*)image newSize:(CGSize)newSize {
    CGRect newRect = CGRectIntegral(CGRectMake(0, 0, newSize.width, newSize.height));
    CGImageRef imageRef = image.CGImage;
    
    UIGraphicsBeginImageContext(newSize);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    // Set the quality level to use when rescaling
    CGContextSetInterpolationQuality(context, kCGInterpolationHigh);
    CGAffineTransform flipVertical = CGAffineTransformMake(1, 0, 0, -1, 0, newSize.height);
    
    CGContextConcatCTM(context, flipVertical);
    // Draw into the context; this scales the image
    CGContextDrawImage(context, newRect, imageRef);
    
    // Get the resized image from the context and a UIImage
    CGImageRef newImageRef = CGBitmapContextCreateImage(context);
    UIImage *newImage = [UIImage imageWithCGImage:newImageRef];
    
    CGImageRelease(newImageRef);
    UIGraphicsEndImageContext();
    
    return newImage;
}

#if 0
//http://stackoverflow.com/questions/3521261/make-an-image-black-and-white
- (UIImage *)grayImage {
    DebugLog(@"note:this does not work well with transparent images");
    CGImageRef cgImage = [self CGImage];
    CGColorSpaceRef colorSapce = CGColorSpaceCreateDeviceGray();
    CGContextRef context = CGBitmapContextCreate(nil, self.size.width, self.size.height, 8, self.size.width, colorSapce, kCGImageAlphaNone);
    CGContextSetInterpolationQuality(context, kCGInterpolationHigh);
    CGContextSetShouldAntialias(context, NO);
    CGContextDrawImage(context, CGRectMake(0, 0, self.size.width, self.size.height), cgImage);
    
    CGImageRef bwImage = CGBitmapContextCreateImage(context);
    CGContextRelease(context);
    CGColorSpaceRelease(colorSapce);
    
    UIImage *resultImage = [UIImage imageWithCGImage:bwImage]; // This is result B/W image.
    CGImageRelease(bwImage);
    return resultImage;
}

#else

typedef enum {
    ALPHA = 0,
    BLUE = 1,
    GREEN = 2,
    RED = 3
} PIXELS;

//https://github.com/andrelieb/UIImage-Grayscale/blob/master/UIImage%2BGrayscale.m
- (UIImage *)grayImage {
    CGFloat scale = [[UIScreen mainScreen] scale];
    
    CGSize size = [self size];
    int width = size.width *scale;
    int height = size.height *scale;
    
    // the pixels will be painted to this array
    uint32_t *pixels = (uint32_t *) malloc(width * height * sizeof(uint32_t));
    
    // clear the pixels so any transparency is preserved
    memset(pixels, 0, width * height * sizeof(uint32_t));
    
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    
    // create a context with RGBA pixels
    CGContextRef context = CGBitmapContextCreate(pixels, width, height, 8, width * sizeof(uint32_t), colorSpace,
                                                 kCGBitmapByteOrder32Little | kCGImageAlphaPremultipliedLast);
    
    // paint the bitmap to our context which will fill in the pixels array
    CGContextDrawImage(context, CGRectMake(0, 0, width, height), [self CGImage]);
    
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            uint8_t *rgbaPixel = (uint8_t *) &pixels[y * width + x];
            
            // convert to grayscale using recommended method: http://en.wikipedia.org/wiki/Grayscale#Converting_color_to_grayscale
            uint32_t gray = 0.3 * rgbaPixel[RED] + 0.59 * rgbaPixel[GREEN] + 0.11 * rgbaPixel[BLUE];
            
            // set the pixels to gray
            rgbaPixel[RED] = gray;
            rgbaPixel[GREEN] = gray;
            rgbaPixel[BLUE] = gray;
        }
    }
    
    // create a new CGImageRef from our context with the modified pixels
    CGImageRef image = CGBitmapContextCreateImage(context);
    
    // we're done with the context, color space, and pixels
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);
    free(pixels);
    
    // make a new UIImage to return
    UIImage *resultUIImage = [UIImage imageWithCGImage:image scale:scale orientation:UIImageOrientationUp];
    
    // we're done with image now too
    CGImageRelease(image);
    
    return resultUIImage;
}
#endif

//http://stackoverflow.com/questions/158914/cropping-a-uiimage
- (UIImage *)cropWithRect:(CGRect)rect {
    
    rect = CGRectMake(rect.origin.x*self.scale,
                      rect.origin.y*self.scale,
                      rect.size.width*self.scale,
                      rect.size.height*self.scale);
    
    CGImageRef imageRef = CGImageCreateWithImageInRect([self CGImage], rect);
    UIImage *result = [UIImage imageWithCGImage:imageRef
                                          scale:self.scale
                                    orientation:self.imageOrientation];
    CGImageRelease(imageRef);
    return result;
}

- (UIImage *)imageInNewSize:(CGSize)newSize edgaeInsets:(UIEdgeInsets)edgeInsets backgroundColor:(UIColor *)backgroundColor{
    UIGraphicsBeginImageContextWithOptions(newSize, NO, 0.0);
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    UIBezierPath *path = [UIBezierPath bezierPathWithRect:CGRectMake(0, 0, newSize.width, newSize.height)];
    CGContextSetFillColorWithColor(context, [backgroundColor CGColor]);
    CGContextAddPath(context, path.CGPath);
    CGContextFillPath(context);
    
    CGAffineTransform flipVertical = CGAffineTransformMake(1, 0, 0, -1, 0, newSize.height);
    CGContextConcatCTM(context, flipVertical);
    
    // Draw into the context;
    CGSize imageSize = self.size;
    CGRect frame = CGRectMake(edgeInsets.left + (newSize.width - edgeInsets.left - edgeInsets.right - imageSize.width ) / 2, edgeInsets.bottom + (newSize.height - edgeInsets.top - edgeInsets.bottom - imageSize.height) / 2, imageSize.width, imageSize.height);
    CGContextDrawImage(context, frame, self.CGImage);
    
    // Get the resized image from the context and a UIImage
    CGImageRef newImageRef = CGBitmapContextCreateImage(context);
    UIImage *newImage = [UIImage imageWithCGImage:newImageRef];
    
    CGImageRelease(newImageRef);
    UIGraphicsEndImageContext();
    
    return newImage;
}

- (UIImage *)resizable {
    UIEdgeInsets middleEdge = UIEdgeInsetsMake(floorf(self.size.height / 3.),
                                               floorf(self.size.width / 3.),
                                               floorf(self.size.height / 3.),
                                               floorf(self.size.width / 3.));
    
    return [self resizableImageWithCapInsets:middleEdge];
}

+ (UIImage *)imageWithView:(UIView *)view {
    return [self imageWithView:view size:view.bounds.size];
}

+ (UIImage *)imageWithView:(UIView *)view size:(CGSize)size {
    UIGraphicsBeginImageContextWithOptions(size, NO, 0.0);
    [view.layer renderInContext:UIGraphicsGetCurrentContext()];
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees {
    CGFloat width = CGImageGetWidth(self.CGImage);
    CGFloat height = CGImageGetHeight(self.CGImage);
    
    CGSize rotatedSize;
    
    rotatedSize.width = width;
    rotatedSize.height = height;
    
    UIGraphicsBeginImageContextWithOptions(rotatedSize, NO, 1.0);
    CGContextRef bitmap = UIGraphicsGetCurrentContext();
    CGContextTranslateCTM(bitmap, rotatedSize.width / 2, rotatedSize.height / 2);
    CGContextRotateCTM(bitmap, degrees * M_PI / 180);
    CGContextRotateCTM(bitmap, M_PI);
    CGContextScaleCTM(bitmap, -1.0, 1.0);
    CGRect drawRect = CGRectMake(-rotatedSize.width / 2,
                                 -rotatedSize.height / 2,
                                 rotatedSize.width,
                                 rotatedSize.height);
    CGContextDrawImage(bitmap, drawRect, self.CGImage);
    UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return newImage;
}


- (UIImage *)imageClippedInCircleWithMaxRadius:(CGFloat)radius {
    CGFloat imageWidth = CGImageGetWidth(self.CGImage);
    CGFloat imageHeight = CGImageGetHeight(self.CGImage);
    CGFloat diameter = (imageHeight > imageWidth) ? imageWidth : imageHeight ;
    if (radius > 0 && radius < diameter / 2) {
        diameter = radius * 2;
    }
    CGRect imageRect = CGRectMake(0, 0, diameter, diameter);
    CGFloat scaleRatio = (imageHeight > imageWidth) ? (diameter / imageWidth) : (diameter / imageHeight);
    
    imageWidth *= scaleRatio;
    imageHeight *= scaleRatio;
    
    CGFloat xPos = (diameter - imageWidth) / 2 ;
    CGFloat yPos = (diameter - imageHeight) / 2 ;
    
    UIGraphicsBeginImageContextWithOptions(imageRect.size, NO, [UIScreen mainScreen].scale);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSaveGState(context);
    
    // 抗锯齿 设置截取区域
    CGContextSetAllowsAntialiasing(context, YES);
    CGContextAddEllipseInRect(context, imageRect);
    CGContextClip(context);
    [self drawInRect:CGRectMake(xPos, yPos, imageWidth, imageHeight)];
    CGContextRestoreGState(context);
    
    // 从当前context中创建一个改变大小后的图片
    UIImage* circleImage = UIGraphicsGetImageFromCurrentImageContext();
    
    // 使当前的context出堆栈
    UIGraphicsEndImageContext();
    
    return circleImage;
}


//指定宽度按比例缩放

+ (UIImage *) imageCompressForWidth:(UIImage *)sourceImage targetWidth:(CGFloat)defineWidth {
    
    
    UIImage *newImage = nil;
    
    CGSize imageSize = sourceImage.size;
    
    CGFloat width = imageSize.width;
    
    CGFloat height = imageSize.height;
    
    CGFloat targetWidth = defineWidth;
    
    CGFloat targetHeight = height / (width / targetWidth);
    
    CGSize size = CGSizeMake(targetWidth, targetHeight);
    
    CGFloat scaleFactor = 0.0;
    
    CGFloat scaledWidth = targetWidth;
    
    CGFloat scaledHeight = targetHeight;
    
    CGPoint thumbnailPoint = CGPointMake(0.0, 0.0);
    
    
    if(CGSizeEqualToSize(imageSize, size) == NO){
        
        
        CGFloat widthFactor = targetWidth / width;
        
        CGFloat heightFactor = targetHeight / height;
        
        
        if(widthFactor > heightFactor){
            
            scaleFactor = widthFactor;
            
        }
        
        else{
            
            scaleFactor = heightFactor;
            
        }
        
        scaledWidth = width * scaleFactor;
        
        scaledHeight = height * scaleFactor;
        
        
        if(widthFactor > heightFactor){
            
            
            thumbnailPoint.y = (targetHeight - scaledHeight) * 0.5;
            
            
        }else if(widthFactor < heightFactor){
            
            
            thumbnailPoint.x = (targetWidth - scaledWidth) * 0.5;
            
        }
        
    }
    
    
    UIGraphicsBeginImageContext(size);
    
    
    CGRect thumbnailRect = CGRectZero;
    
    thumbnailRect.origin = thumbnailPoint;
    
    thumbnailRect.size.width = scaledWidth;
    
    thumbnailRect.size.height = scaledHeight;
    
    
    [sourceImage drawInRect:thumbnailRect];
    
    
    newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    
    if(newImage == nil){
        
        
        NSLog(@"scale image fail");
        
    }
    
    UIGraphicsEndImageContext();
    
    return newImage;
    
}

@end
