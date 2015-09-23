//
//  IWXOMessage.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/11.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>





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





#import "IYWMessage.h"
#import "WXOPerson.h"
#import "WXOMessageBody.h"

/**
 * 消息发送状态
 */
typedef NS_ENUM(NSUInteger, WXOMessageSendStatusDef) {
    /// 待发送
    WXOMessageSendStatusPending = YWMessageSendStatusPending,
    /// 发送消息内容
    WXOMessageSendStatusSendingContent = YWMessageSendStatusSendingContent,
    /// 发送消息信息
    WXOMessageSendStatusSendingMsg = YWMessageSendStatusSendingMsg,
    /// 发送成功
    WXOMessageSendStatusSuccess = YWMessageSendStatusSuccess,
    /// 发送失败
    WXOMessageSendStatusFailed = YWMessageSendStatusFailed
};

#define WXOMessageSendStatus    YWMessageSendStatus

@protocol IWXOMessage <IYWMessage>

/**
 *  消息Id
 */
@property (nonatomic, copy, readonly) NSString *messageId;

/**
 * 发送者
 */
@property (nonatomic, strong, readonly) WXOPerson *messageFromPerson;

/**
 * 接收者
 */
@property (nonatomic, strong, readonly) WXOPerson *messageToPerson;

/**
 * 消息发送状态
 */
@property (nonatomic, assign, readonly) WXOMessageSendStatus messageSendStatus;


/**
 * 所属会话
 */
@property (nonatomic, copy, readonly) NSString *conversationId;


/**
 * 消息内容
 */
@property (nonatomic, strong, readonly) WXOMessageBody *messageBody;

/**
 * 消息发送的时间
 */
@property (nonatomic, strong, readonly) NSDate *time;

/**
 * 消息是否是对外发送
 */
@property (nonatomic, assign, readonly) BOOL outgoing;

/**
 * 消息是否已读
 */
@property (nonatomic, assign, readonly) BOOL hasReaded;

@end
