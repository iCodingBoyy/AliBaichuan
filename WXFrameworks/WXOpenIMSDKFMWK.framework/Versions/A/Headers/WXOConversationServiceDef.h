//
//  WXOConversationServiceDef.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/18.
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
#import "YWConversationServiceDef.h"

/**
 *  收到新消息的回调
 *  @param aMessages 收到的新消息
 */
#define WXOConversationOnNewMessageBlock    YWConversationOnNewMessageBlock

/// 对象变更方式
typedef enum : NSUInteger {
    /// 对象被插入
    WXOObjectChangeTypeInsert = YWObjectChangeTypeInsert,
    /// 对象被删除
    WXOObjectChangeTypeDelete = YWObjectChangeTypeDelete,
    /// 对象被移动
    WXOObjectChangeTypeMove = YWObjectChangeTypeMove,
    /// 对象被修改
    WXOObjectChangeTypeUpdate = YWObjectChangeTypeUpdate
} WXOObjectChangeTypeDef;
#define WXOObjectChangeType     YWObjectChangeType

#define WXOContentChangeBlock   YWContentChangeBlock
#define WXOObjectChangeBlock    YWObjectChangeBlock

__deprecated_msg("请使用YWConversationServiceDef替代") @interface WXOConversationServiceDef : YWConversationServiceDef

@end
