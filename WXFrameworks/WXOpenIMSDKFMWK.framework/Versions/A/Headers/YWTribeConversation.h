//
//  YWTribeConversation.h
//  
//
//  Created by Jai Chen on 15/1/21.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "YWConversation.h"
#import "YWTribe.h"

/**
 *  群聊会话
 */
@interface YWTribeConversation : YWConversation

/**
*  获取某群聊会话
*
*  @param tribe            群对象
*  @param createIfNotExist 如果会话还不存在，是否创建新会话
*  @param baseContext      baseContext 对象
*
*  @return 群会话
*/
+ (instancetype)fetchConversationByTribe:(YWTribe *)tribe createIfNotExist:(BOOL)createIfNotExist baseContext:(YWIMCore *)baseContext;

/**
 *  该会话的群对象，由于群名称、群公告等信息需要从服务器中获取，当本地并未存储该群信息的情况下，将返回一个新建的 tribeName 为 tribeId 的 WXOTribe
 */
@property (readonly, nonatomic) YWTribe *tribe;

@end
