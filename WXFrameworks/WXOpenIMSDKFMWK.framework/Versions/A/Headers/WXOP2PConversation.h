//
//  WXOP2PConversation.h
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






#import "YWP2PConversation.h"


@class WXOPerson;
@class WXOBaseContext;
/**
 单聊会话
 */
__deprecated_msg("请使用YWP2PConversation替代") @interface WXOP2PConversation : YWP2PConversation

/**
 *  获取某个单聊会话
 *  @param WXOPerson 会话对象
 *  @param aCreateIfNotExist 如果还不存在，则创建会话
 *  @return 需要获取的会话。如果本地不存在该会话且不需要新建，则返回nil
 */
+ (instancetype)fetchConversationByPerson:(WXOPerson *)person creatIfNotExist:(BOOL)aCreateIfNotExist baseContext:(WXOBaseContext *)aBaseContext;

/**
 *  该单聊会话的person对象
 */
@property (nonatomic, strong, readonly) WXOPerson *person;

@end
