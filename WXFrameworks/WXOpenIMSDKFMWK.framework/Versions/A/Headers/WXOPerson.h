//
//  WXOPerson.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/28.
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
#import "YWPerson.h"

@class WXOBaseContext;

__deprecated_msg("请使用YWPerson替代") @interface WXOPerson : YWPerson
<NSCoding, NSCopying>

/**
 *  初始化，生成默认的App内聊天对象
 *  @param aPersonId personId
 *  @return WXOPerson对象
 */
- (instancetype)initWithPersonId:(NSString *)aPersonId;

/**
 *  初始化，可以指定聊天对象所属App
 *  @param aPersonId 对象id
 *  @param aAppKey 聊天对象所属App
 */
- (instancetype)initWithPersonId:(NSString *)aPersonId appKey:(NSString *)aAppKey;


/**
 *  该聊天对象的personId
 */
@property (nonatomic, copy, readonly) NSString *personId;

/**
 *  该聊天对象所属appkey
 */
@property (nonatomic, copy, readonly) NSString *appKey;

/**
 *  检查与 aPerson 是否表示同一对象
 */
- (BOOL)isEqualToPerson:(WXOPerson *)aPerson;

@end
