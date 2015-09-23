//
//  IYWSettingService.h
//  WXOpenIMSDK
//
//  Created by huanglei on 15/6/5.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol IYWSettingService <NSObject>

#pragma mark - 消息提醒设置

/**
 *  PC在线时消息是否推送
 */

/// 读取PC在线时消息是否推送
- (BOOL)messagePushWhenPCOnline;

/// 异步设置服务器的值
- (void)asyncSetMessagePushWhenPCOnline:(BOOL)aNeedPush completion:(YWCompletionBlock)aCompletion;

@end
