//
//  YWMessageBodyTribeSystem.h
//  
//
//  Created by Jai Chen on 15/1/26.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import "YWMessageBody.h"


/**
 *  群系统消息的子类型
 */
typedef NS_ENUM(NSUInteger, YWMessageBodyTribeSystemType){
    /**
     *  成员被邀请的消息
     */
    YWMessageBodyTribeSystemTypeInvited = 0x20,
    /**
     *  成员加入消息
     */
    YWMessageBodyTribeSystemTypeJoined = 0x21,
    /**
     *  成员退出消息
     */
    YWMessageBodyTribeSystemTypeExited = 0x22,
    /**
     *  成员被踢出消息
     */
    YWMessageBodyTribeSystemTypeExpelled = 0x23,

    /**
     *  群名称或群公告更新消息
     */
    YWMessageBodyTribeSystemTypeTribeInfoUpdated = 0x26

};

/**
 *  WXOMessageBodyTribeSystem 中 userInfo 字典的键，用于获取具体信息
 */
#define kYWMessageBodyTribeSystemUserInfoKeyPerson      @"person"
#define kYWMessageBodyTribeSystemUserInfoKeyTribeName   @"tribeName"
#define kYWMessageBodyTribeSystemUserInfoKeyNotice      @"notice"

/**
 * 群系统消息体
 */
@interface YWMessageBodyTribeSystem : YWMessageBody

/**
 *  群系统消息的子类型
 */
@property (nonatomic, readonly) YWMessageBodyTribeSystemType tribeSystemType;

/**
 *  提供具体信息的字典
 */
@property (nonatomic, readonly) NSDictionary *userInfo;

@end
