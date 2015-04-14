//
//  TWRDownloadObject.h
//  DownloadManager
//
//  Created by Michelangelo Chasseur on 26/07/14.
//  Copyright (c) 2014 Touchware. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class TWRDownloadObject;

typedef void(^TWRDownloadRemainingTimeBlock)(NSUInteger seconds);
typedef void(^TWRDownloadProgressBlock)(CGFloat progress);
typedef void(^TWRDownloadCompletionBlock)(BOOL completed);

@interface TWRDownloadObject : NSObject

@property (copy, nonatomic) TWRDownloadProgressBlock progressBlock;
@property (copy, nonatomic) TWRDownloadCompletionBlock completionBlock;
@property (copy, nonatomic) TWRDownloadRemainingTimeBlock remainingTimeBlock;

@property (strong, nonatomic) NSURLSessionDownloadTask *downloadTask;
@property (copy, nonatomic) NSString *fileName;
@property (copy, nonatomic) NSString *directoryName;
@property (copy, nonatomic) NSDate *startDate;
@property (strong, nonatomic) NSError *error;

- (instancetype)initWithDownloadTask:(NSURLSessionDownloadTask *)downloadTask
                       progressBlock:(TWRDownloadProgressBlock)progressBlock
                       remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock
                     completionBlock:(TWRDownloadCompletionBlock)completionBlock;

@end
