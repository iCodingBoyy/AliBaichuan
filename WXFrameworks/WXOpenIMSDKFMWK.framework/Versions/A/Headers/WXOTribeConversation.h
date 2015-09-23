//
//  WXOTribeConversation.h
//  WXOpenIMSDK
//
//  Created by Jai Chen on 15/1/21.
//  Copyright (c) 2015年 taobao. All rights reserved.
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





#import "YWTribeConversation.h"
#import "WXOConversation.h"
#import "WXOTribe.h"

/**
 *  群聊会话
 */
__deprecated_msg("请使用YWTribeConversation替代") @interface WXOTribeConversation : YWTribeConversation

/**
*  获取某群聊会话
*
*  @param tribe            群对象
*  @param createIfNotExist 如果会话还不存在，是否创建新会话
*  @param baseContext      baseContext 对象
*
*  @return 群会话
*/
+ (instancetype)fetchConversationByTribe:(WXOTribe *)tribe createIfNotExist:(BOOL)createIfNotExist baseContext:(WXOBaseContext *)baseContext;

/**
 *  该会话的群对象，由于群名称、群公告等信息需要从服务器中获取，当本地并未存储该群信息的情况下，将返回一个新建的 tribeName 为 tribeId 的 WXOTribe
 */
@property (readonly, nonatomic) WXOTribe *tribe;

@end
