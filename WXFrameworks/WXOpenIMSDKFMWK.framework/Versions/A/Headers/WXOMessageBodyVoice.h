//
//  WXOMessageBodyVoice.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/11.
//  Copyright (c) 2014年 taobao. All rights reserved.
//




/*********************************************************************************
 *********************************************************************************
 *********************************************************************************
 *********************************************************************************
 
 * 注意点：所有WXO或者IWXO开头命名的类、接口、类型、常量等都已废弃，请使用YW或者IYW开头的定义 *
 
 *********************************************************************************
 *********************************************************************************
 *********************************************************************************
 *********************************************************************************
 ********************************************************************************/






#import "YWMessageBodyVoice.h"

#define WXOGetVoiceProgressBlock        YWGetVoiceProgressBlock
#define WXOGetVoiceCompletionBlock      YWGetVoiceCompletionBlock

/**
 * 语音消息体
 */

__deprecated_msg("请使用YWMessageBodyVoice替代") @interface WXOMessageBodyVoice : YWMessageBodyVoice

/// 初始化
- (instancetype)initWithMessageVoiceData:(NSData *)voiceData duration:(NSTimeInterval)aDuration;

/// 音频时长
@property (nonatomic, assign, readonly) NSTimeInterval messageVoiceDuration;

/**
 *  异步下载音频数据
 *  @param progress 下载进度回调
 *  @param completion 下载结束回调
 */
- (void)asyncGetVoiceDataWithProgress:(WXOGetVoiceProgressBlock)progress
                           completion:(WXOGetVoiceCompletionBlock)completion;
@end
