//
//  WXOMessageBodyTribeSystem.h
//  WXOpenIMSDK
//
//  Created by Jai Chen on 15/1/26.
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






#import "YWMessageBodyTribeSystem.h"


/**
 *  群系统消息的子类型
 */
typedef NS_ENUM(NSUInteger, WXOMessageBodyTribeSystemTypeDef){
    /**
     *  成员被邀请的消息
     */
    WXOMessageBodyTribeSystemTypeInvited = YWMessageBodyTribeSystemTypeInvited,
    /**
     *  成员加入消息
     */
    WXOMessageBodyTribeSystemTypeJoined = YWMessageBodyTribeSystemTypeJoined,
    /**
     *  成员退出消息
     */
    WXOMessageBodyTribeSystemTypeExited = YWMessageBodyTribeSystemTypeExited,
    /**
     *  成员被踢出消息
     */
    WXOMessageBodyTribeSystemTypeExpelled = YWMessageBodyTribeSystemTypeExpelled,

    /**
     *  群名称或群公告更新消息
     */
    WXOMessageBodyTribeSystemTypeTribeInfoUpdated = YWMessageBodyTribeSystemTypeTribeInfoUpdated

};
#define WXOMessageBodyTribeSystemType       YWMessageBodyTribeSystemType

/**
 *  WXOMessageBodyTribeSystem 中 userInfo 字典的键，用于获取具体信息
 */
#define kWXOMessageBodyTribeSystemUserInfoKeyPerson     kYWMessageBodyTribeSystemUserInfoKeyPerson
#define kWXOMessageBodyTribeSystemUserInfoKeyTribeName  kYWMessageBodyTribeSystemUserInfoKeyTribeName
#define kWXOMessageBodyTribeSystemUserInfoKeyNotice     kYWMessageBodyTribeSystemUserInfoKeyNotice

/**
 * 群系统消息体
 */
__deprecated_msg("请使用YWMessageBodyTribeSystem替代") @interface WXOMessageBodyTribeSystem : YWMessageBodyTribeSystem

/**
 *  群系统消息的子类型
 */
@property (nonatomic, readonly) WXOMessageBodyTribeSystemType tribeSystemType;

/**
 *  提供具体信息的字典
 */
@property (nonatomic, readonly) NSDictionary *userInfo;

@end
