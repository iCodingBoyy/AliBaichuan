//
//  WXOConversation.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/17.
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





#import <Foundation/Foundation.h>

#import "YWConversation.h"
#import "WXOServiceDef.h"
#import "WXOConversationServiceDef.h"

@protocol IWXOMessage;

@class WXOMessageBody;
@class WXOBaseContext;


/**
 * 会话基类
 */

__deprecated_msg("请使用YWConversation替代") @interface WXOConversation : YWConversation

#pragma mark - 会话基本信息

/**
 *  @virtual
 *  会话Id
 */
@property (nonatomic, readonly) NSString *conversationId;

/**
 *  @virtual
 *  会话最后消息
 */
@property (nonatomic, readonly) NSString *conversationLatestMessageContent;

/**
 *  @virtual
 *  会话最后消息
 */
@property (nonatomic, readonly) id<IWXOMessage> conversationLatestMessage;

/**
 *  @virtual
 *  会话最后消息时间
 */
@property (nonatomic, readonly) NSDate *conversationLatestMessageTime;

/**
 *  @virtual
 *  会话未读消息数
 */
@property (nonatomic, readonly) NSNumber *conversationUnreadMessagesCount;

#pragma mark - 会话操作

/**
 * 将会话标记为已读
 */
- (void)markConversationAsRead;

/**
 *  类方法，获取一个Conversation
 *  @param aConversationId 会话Id
 *  @param aCreateIfNotExsit 如果会话不存在，是否创建会话。如果不存在且不创建，则返回nil
 *  @param aBaseContext 用户上下文对象。
 */

+ (instancetype)fetchConversationByConversationId:(NSString *)aConversationId
                                  creatIfNotExist:(BOOL)aCreateIfNotExist
                                      baseContext:(WXOBaseContext *)aBaseContext;
#pragma mark - 消息发送

/**
 *  @virtual
 *  异步发送一条消息
 *  @param aMessageBody 消息体
 *  @param aProgress 消息发送进度的回调
 *  @param aCompletion 消息发送结束的回调
 */

- (void)asyncSendMessageBody:(WXOMessageBody *)aMessageBody
                               progress:(WXOMessageSendingProgressBlock)aProgress
                             completion:(WXOMessageSendingCompletionBlock)aCompletion;

/**
 *  @virtual
 *  异步重发一条消息
 *  @param aMessage 需要重发的消息
 *  @param aProgress 消息发送进度的回调
 *  @param aCompletion 消息发送结束的回调
 */
- (void)asyncResendMessage:(id<IWXOMessage>)aMessage
                  progress:(WXOMessageSendingProgressBlock)aProgress
                completion:(WXOMessageSendingCompletionBlock)aCompletion;

/**
 *  @virtual
 *  异步转发一条消息到本会话
 *  @param aMessage 需要转发的消息
 *  @param aProgress 消息发送进度的回调
 *  @param aCompletion 消息发送结束的回调
 */
- (void)asyncForwardMessage:(id<IWXOMessage>)aMessage
                   progress:(WXOMessageSendingProgressBlock)aProgress
                 completion:(WXOMessageSendingCompletionBlock)aCompletion;



/**
 *  @virtual
 *  删除某一条消息
 */
- (void)removeMessageWithMessageId:(NSString *)aMessageId;

#pragma mark - 消息管理

/// 会话消息加载完成的回调，通过参数返回是否还存在更多消息
typedef void(^WXOConversationLoadMessagesCompletion)(BOOL existMore);

/**
 *  加载消息
 *  加载消息同时增加内容变更的监听，当不再需要监听内容变更时需要调用 -[WXOConversation clearContentChangeBlocks] 取消监听
 *  @param moreCount  额外加载的消息条目数，根据当先加载的消息数量加上 moreCount 为最终加载的条目数，该方法加载后会全量重新加载数据
 *  @param completion 完成回调 block，通过参数返回是否还存在更多消息
 */
- (void)loadMoreMessages:(NSUInteger)moreCount completion:(WXOConversationLoadMessagesCompletion)completion;

/**
 *  清除 willChangeContentBlock、didChangeContentBlock、objectDidChangeBlock，停止内容变更的监听
 */
- (void)clearContentChangeBlocks;

/**
 *  当前所加载的消息，最近一次调用 -[WXOConversation loadMoreMessages:completion:] 所加载的数据
 */
@property (readonly, nonatomic) NSMutableArray *fetchedObjects;

/**
 *  fetchedObjects 与 indexPath 间的映射关系，
 */
- (id)objectAtIndexPath:(NSIndexPath *)indexPath;

/**
 *  fetchedObjects 与 indexPath 间的映射关系
 */
- (NSIndexPath *)indexPathForObject:(id)object;

/**
 *  内容即将发生变更时的回调 block
 */
@property (copy, nonatomic) WXOContentChangeBlock willChangeContentBlock;

/**
 *  具体消息变更的回调 block
 */
@property (copy, nonatomic) WXOContentChangeBlock didChangeContentBlock;

/**
 *  内容已经完成变更的回调 block
 */
@property (copy, nonatomic) WXOObjectChangeBlock objectDidChangeBlock;

/**
 *  @virtual
 *  标识某消息为已读
 */
- (void)markMessageAsReadWithMessageIds:(NSArray *)messageIds;

#pragma mark - 事件监听

@property (nonatomic, copy, readonly) WXOConversationOnNewMessageBlock onNewMessageBlock;
/// 设置新消息回调
- (void)setOnNewMessageBlock:(WXOConversationOnNewMessageBlock)onNewMessageBlock;

@end
