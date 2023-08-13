//
//  AutoScrollTextView.h
//  WinDiskWriter GUI
//
//  Created by Macintosh on 10.08.2023.
//  Copyright © 2023 TechUnRestricted. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "VibrantTextView.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString *ASLogType NS_TYPED_ENUM;
extern ASLogType const ASLogTypeLog;
extern ASLogType const ASLogTypeSuccess;
extern ASLogType const ASLogTypeWarning;
extern ASLogType const ASLogTypeError;
extern ASLogType const ASLogTypeFatal;
extern ASLogType const ASLogTypeAssertionError;

@interface AutoScrollTextView : NSScrollView

@property (nonatomic, strong, readonly) VibrantTextView *textViewInstance;

- (void)appendLine:(NSString *)message;

- (void)appendTimestampedLine: (NSString *)message
                      logType: (ASLogType)logType;
- (void)clear;

@end

NS_ASSUME_NONNULL_END
