//
//  IWXOConversationService.h
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








#import "IYWConversationService.h"

#import "WXOServiceDef.h"
#import "WXOConversationServiceDef.h"

#import "WXOConversation.h"
#import "WXOP2PConversation.h"

#import "IWXOMessage.h"
#import "WXOMessageBody.h"
#import "WXOMessageBodyText.h"
#import "WXOMessageBodyImage.h"
#import "WXOMessageBodyVoice.h"
#import "WXOMessageBodyLocation.h"
#import "WXOMessageBodyCustomize.h"
#import "WXOMessageBodyTemplate.h"
#import "WXOMessageBodySystemNotify.h"
#import "WXOMessageBodyTribeSystem.h"
#import "WXOMessageBodyUnsupported.h"
#import "WXOPerson.h"


#pragma mark - 常量定义

/**
 *  会话服务错误定义
 */
typedef NS_ENUM(NSUInteger, WXOConversationErrorCodeDef) {
    /// 操作失败
    WXOConversationErrorCodeOperationFailed = YWConversationErrorCodeOperationFailed,
    /// 参数不正确
    WXOConversationErrorCodeParamInvalid = YWConversationErrorCodeParamInvalid,
    
    /// 数据库操作错误
    WXOConversationErrorCodeDBError = YWConversationErrorCodeDBError,
};

#define WXOConversationErrorCode       YWConversationErrorCode

/// 错误域
#define WXOConversationServiceDomain    YWConversationServiceDomain



#pragma mark - 服务接口提供

/**
 * 会话管理服务提供
 */

@protocol IWXOConversationService <IYWConversationService>

#pragma mark - 会话管理

/**
 *  获取某个本地会话
 *  @param aConversationId 会话Id
 *  @return 需要获取的会话，则返回nil
 */
- (WXOConversation *)fetchConversationByConversationId:(NSString *)aConversationId;

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
#define WXOFetchConversationsCompletion YWFetchConversationsCompletion
/**
 * 异步加载所有会话
 * @param aCompletionBlock 结果回调
 */
- (void)asyncFetchAllConversationsWithCompletionBlock:(WXOFetchConversationsCompletion)aCompletionBlock;

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
#define WXOConversationChangedBlock     YWConversationChangedBlock

/// 设置会话变更的回调
- (void)addConversationChangedBlock:(WXOConversationChangedBlock)conversationChangedBlock forKey:(NSString *)aKey ofPriority:(WXOBlockPriority)aPriority;
/// 移除会话变更的回调
- (void)removeConversationChangedBlockForKey:(NSString *)aKey;

/**
 *  总的未读数变更的回调
 *  @param aCount 总的未读数
 */
#define WXOConversationTotalUnreadChangedBlock      YWConversationTotalUnreadChangedBlock

/// 设置总的未读数变更的回调
- (void)addConversationTotalUnreadChangedBlock:(WXOConversationTotalUnreadChangedBlock)conversationTotalUnreadChangedBlock forKey:(NSString *)aKey ofPriority:(WXOBlockPriority)aPriority;
/// 移除未读数变更的回调
- (void)removeConversationTotalUnreadChangedBlockForKey:(NSString *)aKey;


// 设置收到新消息的回调
- (void)addOnNewMessageBlock:(WXOConversationOnNewMessageBlock)onNewMessageBlock forKey:(NSString *)aKey ofPriority:(WXOBlockPriority)aPriority;
/// 移除收到新消息的回调
- (void)removeOnNewMessageBlockForKey:(NSString *)aKey;

@end



