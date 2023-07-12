//
//  FrameLayoutBase.h
//  WinDiskWriter GUI
//
//  Created by Macintosh on 14.06.2023.
//  Copyright © 2023 TechUnRestricted. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "FrameLayoutElement.h"

typedef NS_ENUM(NSUInteger, FrameLayoutVerticalAlignment) {
    FrameLayoutVerticalTop,
    FrameLayoutVerticalBottom,
    FrameLayoutVerticalCenter
};

typedef NS_ENUM(NSUInteger, FrameLayoutHorizontalAlignment) {
    FrameLayoutHorizontalLeft,
    FrameLayoutHorizontalRight,
    FrameLayoutHorizontalCenter
};

NS_ASSUME_NONNULL_BEGIN

@interface FrameLayoutBase : NSView

@property (nonatomic, readwrite) CGFloat spacing;

@property (nonatomic, readwrite) FrameLayoutVerticalAlignment verticalAlignment;
@property (nonatomic, readwrite) FrameLayoutHorizontalAlignment horizontalAlignment;

@property (nullable, nonatomic, readwrite /* Can't use weak on 10.6 Target */) FrameLayoutElement *selfViewLimits;

@property (nonatomic, readwrite) BOOL hugWidthFrame /* NS_UNAVAILABLE */;
@property (nonatomic, readwrite) BOOL hugHeightFrame /* NS_UNAVAILABLE */;

@property (nonatomic, readwrite) CGFloat stackableAxisMaxLimitsSum;
@property (nonatomic, readwrite) CGFloat largestUnstackableAxisValue;

@property (nonatomic, strong) NSMutableArray<FrameLayoutElement *> *layoutElementsArray;
@property (nonatomic, strong) NSMutableArray<FrameLayoutElement *> *sortedElementsArray;

@property (nonatomic, readwrite) CGFloat viewsWidthTotal;
@property (nonatomic, readwrite) CGFloat viewsHeightTotal;

- (CGFloat)spaceTakenBySpacing;

- (void)applyHugFrame;

- (void)addView: (NSView * _Nonnull)nsView;

- (void)addView: (NSView * _Nonnull)nsView
       minWidth: (CGFloat)minWidth
       maxWidth: (CGFloat)maxWidth
      minHeight: (CGFloat)minHeight
      maxHeight: (CGFloat)maxHeight;

- (void)addView: (NSView * _Nonnull)nsView
          width: (CGFloat)width
         height: (CGFloat)height;

@end

NS_ASSUME_NONNULL_END
