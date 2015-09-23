//
//  WXOBaseContext.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/11.
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

#import "YWIMCore.h"
#import "WXOServiceDef.h"
#import "WXOSdk.h"

@protocol IWXOLoginService, IWXOConversationService;
@protocol IWXOExtensionService;

@protocol IWXOUIService;

@protocol IWXOTribeService;

@protocol IWXORoamingService;

#pragma mark - 常量定义

/**
 *  SDK类型
 */
typedef enum : NSUInteger {
    /// 淘宝账号体系（与旺旺消息互通）
    WXOSDKTypeTaobao = YWSDKTypeTaobao,
    /// 自由账号体系（App之间消息隔离）
    WXOSDKTypeFree = YWSDKTypeFree,
} WXOSDKTypeDef;
#define WXOSDKType      YWSDKType

/**
 *  用户上下文，可以从上下文中获得服务
 */
__deprecated_msg("请使用YWIMCore替代") @interface WXOBaseContext : YWIMCore



#pragma mark - prepare

/**
 *  WXOBaseContext对象在使用之前需要先进行初始化。
 *  @param aSDKType SDK类型，根据使用的账号体系不同，详见：WXOSDKType 的定义
 */
- (void)prepareWithSdkType:(WXOSDKType)aSDKType;

#define WXOBaseContextPreparedBlock     YWBaseContextPreparedBlock

/**
 *  监听一个BaseContext prepared完成
 */
- (void)addBaseContextPreparedBlock:(WXOBaseContextPreparedBlock)aBlock forKey:(NSString *)aKey priority:(WXOBlockPriority)aPriority;

/**
 *  移除一个BaseContext prepared完成的监听
 */
- (void)removeBaseContextPreparedBlockForKey:(NSString *)aKey;


#pragma mark - 获取服务

/**
 *  获取长连接服务
 */
- (id<IWXOLoginService>)getLoginService;

/**
 *  获取会话相关服务
 */
- (id<IWXOConversationService>)getConversationService;

/**
 *  获取扩展服务
 */
- (id<IWXOExtensionService>)getExtensionService;

/**
 *  UI服务
 */
- (id<IWXOUIService>)getUIService;

/**
 *  群相关服务
 */
- (id<IWXOTribeService>)getTribeService;

/**
 *  漫游相关服务
 */
- (id<IWXORoamingService>)getRoamingService;

#pragma mark - 状态读取

/// SDK类型
@property (nonatomic, assign, readonly) WXOSDKType sdkType;

@end

@protocol IWXOPushService;

@interface WXOBaseContext ()

#pragma mark - deprecated 已废弃


+ (instancetype)sharedInstance __attribute__((unavailable("通过WXOSdk的fetchNewBaseContext来获取，详见该函数注释")));

- (void)prepareWithAppKey:(NSString *)aAppKey
       networkEnvironment:(WXOEnvironment)aNetworkEnvironment
                  sdkType:(WXOSDKType)aSDKType __attribute__((unavailable("use prepareWithSdkType: instead")));

- (id<IWXOPushService>)getPushService __attribute__((unavailable("use WXOSdk的getGlobalPushService方法")));

@end
