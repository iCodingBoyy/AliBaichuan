//
//  IYWConversationService.h
//  
//
//  Created by huanglei on 14/12/11.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "YWServiceDef.h"
#import "YWConversationServiceDef.h"

#import "YWConversation.h"
#import "YWP2PConversation.h"

#import "IYWMessage.h"
#import "YWMessageBody.h"
#import "YWMessageBodyText.h"
#import "YWMessageBodyImage.h"
#import "YWMessageBodyVoice.h"
#import "YWMessageBodyLocation.h"
#import "YWMessageBodyCustomize.h"
#import "YWMessageBodyTemplate.h"
#import "YWMessageBodySystemNotify.h"
#import "YWMessageBodyTribeSystem.h"
#import "YWMessageBodyUnsupported.h"
#import "YWPerson.h"


#pragma mark - 常量定义

/**
 *  会话服务错误定义
 */
typedef NS_ENUM(NSUInteger, YWConversationErrorCode) {
    /// 操作失败
    YWConversationErrorCodeOperationFailed = 1,
    /// 参数不正确
    YWConversationErrorCodeParamInvalid,
    
    /// 数据库操作错误
    YWConversationErrorCodeDBError,
};

/// 错误域
FOUNDATION_EXTERN NSString *const YWConversationServiceDomain;



#pragma mark - 服务接口提供

/**
 * 会话管理服务提供
 */

@protocol IYWConversationService <NSObject>

#pragma mark - 会话管理

/**
 *  获取某个本地会话
 *  @param aConversationId 会话Id
 *  @return 需要获取的会话，则返回nil
 */
- (YWConversation *)fetchConversationByConversationId:(NSString *)aConversationId;

/**
 * 删除单个会话
 * @param aConversationId 需要删除的会话Id
 * @param aError 错误信息
 */
- (BOOL)removeConversationByConversationId:(NSString *)aConversationId error:(NSError **)aError;

/**
 *  异步获取所有本地会话的回调
 *  @param aConversationsArray 包含所有会话对象的NSArray
 */
typedef void(^YWFetchConversationsCompletion)(NSArray *aConversationsArray);

/**
 * 异步加载所有会话
 * @param aCompletionBlock 结果回调
 */
- (void)asyncFetchAllConversationsWithCompletionBlock:(YWFetchConversationsCompletion)aCompletionBlock;

/**
 * 同步加载所有会话
 * @param aCompletionBlock 结果回调
 */
- (NSArray *)fetchAllConversation;

/**
 所有会话的未读消息数
 */
@property (nonatomic, readonly) NSUInteger countOfUnreadMessages;


#pragma mark - 事件监听


/**
 *  会话变更的回调
 *  @param aConversationsArray 会话数组
 */
typedef void(^YWConversationChangedBlock)(NSArray *aConversationsArray);

/// 设置会话变更的回调
/// @param aKey 用来区分不同的监听者，一般可以使用监听对象的description
/// @param aPriority 有多个监听者时，调用的优先次序。开发者一般设置：YWBlockPriority
- (void)addConversationChangedBlock:(YWConversationChangedBlock)conversationChangedBlock forKey:(NSString *)aKey ofPriority:(YWBlockPriority)aPriority;
/// 移除会话变更的回调
- (void)removeConversationChangedBlockForKey:(NSString *)aKey;

/**
 *  总的未读数变更的回调
 *  @param aCount 总的未读数
 */
typedef void(^YWConversationTotalUnreadChangedBlock)(NSUInteger aCount);

/// 设置总的未读数变更的回调
/// @param aKey 用来区分不同的监听者，一般可以使用监听对象的description
/// @param aPriority 有多个监听者时，调用的优先次序。开发者一般设置：YWBlockPriority
- (void)addConversationTotalUnreadChangedBlock:(YWConversationTotalUnreadChangedBlock)conversationTotalUnreadChangedBlock forKey:(NSString *)aKey ofPriority:(YWBlockPriority)aPriority;
/// 移除未读数变更的回调
- (void)removeConversationTotalUnreadChangedBlockForKey:(NSString *)aKey;


// 设置收到新消息的回调，V1版本，没有是否离线消息的标记
/// @param aKey 用来区分不同的监听者，一般可以使用监听对象的description
/// @param aPriority 有多个监听者时，调用的优先次序。开发者一般设置：YWBlockPriority
- (void)addOnNewMessageBlock:(YWConversationOnNewMessageBlock)onNewMessageBlock forKey:(NSString *)aKey ofPriority:(YWBlockPriority)aPriority;
/// 移除收到新消息的回调
- (void)removeOnNewMessageBlockForKey:(NSString *)aKey;

// 设置收到新消息的回调，V2版本，带有是否离线消息的标记
/// @param aKey 用来区分不同的监听者，一般可以使用监听对象的description
/// @param aPriority 有多个监听者时，调用的优先次序。开发者一般设置：YWBlockPriority
- (void)addOnNewMessageBlockV2:(YWConversationOnNewMessageBlockV2)onNewMessageBlockV2 forKey:(NSString *)aKey ofPriority:(YWBlockPriority)aPriority;
/// 移除收到新消息的回调
- (void)removeOnNewMessageBlockV2ForKey:(NSString *)aKey;


@end



