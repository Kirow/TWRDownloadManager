//
//  TWRDownloadManager.h
//  DownloadManager
//
//  Created by Michelangelo Chasseur on 25/07/14.
//  Copyright (c) 2014 Touchware. All rights reserved.
//

#import "TWRDownloadObject.h"

FOUNDATION_EXPORT NSString *const TWRBackgroundDownloadIdentifier;

@interface TWRDownloadManager : NSObject

@property (nonatomic, strong) void(^backgroundTransferCompletionHandler)();

@property (strong, nonatomic) NSMutableDictionary *downloads;

+ (instancetype)sharedManager;

- (TWRDownloadObject*)downloadFileForURL:(NSString *)url withName:(NSString *)fileName inDirectoryNamed:(NSString *)directory
             progressBlock:(TWRDownloadProgressBlock)progressBlock completionBlock:(TWRDownloadCompletionBlock)completionBlock
      enableBackgroundMode:(BOOL)backgroundMode;

- (TWRDownloadObject*)downloadFileForURL:(NSString *)url inDirectoryNamed:(NSString *)directory progressBlock:(TWRDownloadProgressBlock)progressBlock
           completionBlock:(TWRDownloadCompletionBlock)completionBlock enableBackgroundMode:(BOOL)backgroundMode;

- (TWRDownloadObject*)downloadFileForURL:(NSString *)url progressBlock:(TWRDownloadProgressBlock)progressBlock
           completionBlock:(TWRDownloadCompletionBlock)completionBlock
      enableBackgroundMode:(BOOL)backgroundMode;

#pragma mark - Download with estimated time

- (TWRDownloadObject*)downloadFileForURL:(NSString *)url withName:(NSString *)fileName inDirectoryNamed:(NSString *)directory
             progressBlock:(TWRDownloadProgressBlock)progressBlock remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock
           completionBlock:(TWRDownloadCompletionBlock)completionBlock enableBackgroundMode:(BOOL)backgroundMode;

- (TWRDownloadObject*)downloadFileForURL:(NSString *)url inDirectoryNamed:(NSString *)directory progressBlock:(TWRDownloadProgressBlock)progressBlock
             remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock completionBlock:(TWRDownloadCompletionBlock)completionBlock
      enableBackgroundMode:(BOOL)backgroundMode;

- (TWRDownloadObject*)downloadFileForURL:(NSString *)url progressBlock:(TWRDownloadProgressBlock)progressBlock remainingTime:(TWRDownloadRemainingTimeBlock)remainingTimeBlock
           completionBlock:(TWRDownloadCompletionBlock)completionBlock enableBackgroundMode:(BOOL)backgroundMode;

- (void)cancelAllDownloads;
- (TWRDownloadObject*)cancelDownloadForUrl:(NSString *)fileIdentifier;

- (NSString *)localPathForFile:(NSString *)fileIdentifier;
- (NSString *)localPathForFile:(NSString *)fileIdentifier inDirectory:(NSString *)directoryName;

- (BOOL)fileExistsForUrl:(NSString *)urlString;
- (BOOL)fileExistsForUrl:(NSString *)urlString inDirectory:(NSString *)directoryName;
- (BOOL)fileExistsWithName:(NSString *)fileName;
- (BOOL)fileExistsWithName:(NSString *)fileName inDirectory:(NSString *)directoryName;

- (BOOL)deleteFileForUrl:(NSString *)urlString;
- (BOOL)deleteFileForUrl:(NSString *)urlString inDirectory:(NSString *)directoryName;
- (BOOL)deleteFileWithName:(NSString *)fileName;
- (BOOL)deleteFileWithName:(NSString *)fileName inDirectory:(NSString *)directoryName;

@end
