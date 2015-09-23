//
//  YWMessageBodyText.h
//  
//
//  Created by huanglei on 14/12/11.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import "YWMessageBody.h"

/**
 * 文本消息体
 */

@interface YWMessageBodyText : YWMessageBody

/// 初始化
- (instancetype)initWithMessageText:(NSString *)aMessageText;

/// 消息内容
@property (nonatomic, copy, readonly) NSString *messageText;

@end
