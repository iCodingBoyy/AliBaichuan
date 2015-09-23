//
//  WXOSdk.h
//  WXOpenIMSDK
//
//  Created by huanglei on 15/1/12.
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






#import <Foundation/Foundation.h>
#import "YWAPI.h"

#import "WXOServiceDef.h"

@protocol IWXOPushService;
@protocol IWXOExtensionService;
@protocol IYWLogService;

@protocol IWXOUtilService4Cache, IWXOUtilService4Network, IWXOUtilService4Security;

@protocol IWXOUTService, IWXOSecurityService;

@class WXOBaseContext;

/**
 *  开发环境
 */
typedef enum {
    WXOEnvironmentRelease = YWEnvironmentRelease, // 开发者的线上环境
    WXOEnvironmentPreRelease = YWEnvironmentPreRelease, // 阿里巴巴内网预发环境
    WXOEnvironmentDailyForTester = YWEnvironmentDailyForTester, // 阿里巴巴内网87环境，稳定
    WXOEnvironmentDailyForDeveloper = YWEnvironmentDailyForDeveloper, // 阿里巴巴内网88环境，开发中
    WXOEnvironmentSandBox = YWEnvironmentSandBox, // 开发者的沙箱环境
}WXOEnvironmentDef;
#define WXOEnvironment      YWEnvironment

/**
 *  WXOSdk错误域
 */
#define WXOSdkDomain        YWSdkDomain

typedef NS_ENUM(NSUInteger, WXOSdkInitErrorCodeDef) {
    /// 已经被初始化
    WXOSdkInitErrorCodeAlreadyInited = YWSdkInitErrorCodeAlreadyInited,
    /// 获取AppInfo失败
    WXOSdkInitErrorCodeGetAppInfoFailed = YWSdkInitErrorCodeGetAppInfoFailed,
};
#define WXOSdkInitErrorCode     YWSdkInitErrorCode

__deprecated_msg("请使用YWAPI替代") @interface WXOSdk : YWAPI

/**
 *  异步初始化
 *  @param aOwnAppKey 自身的appkey
 *  @param aInteractedAppKeys 需要进行互通的AppKey字符串数组。
 *  @param aCompletionBlock 初始化结果，错误的类型见 WXOSdkErrorCode 定义
 */
- (void)asyncInitWithOwnAppKey:(NSString *)aOwnAppKey
             interactedAppKeys:(NSArray *)aInteractedAppKeys
               completionBlock:(WXOCompletionBlock)aCompletionBlock;


/**
 *  appkey
 */
@property (nonatomic, copy, readonly) NSString *appKey;


/**
 *  旺信域的AppKey
 */
#define WXOSdkAppkeyWangxin     YWSDKAppKey


@end

#pragma mark - UserContext

@interface WXOSdk ()

/**
 *  获取一个新的BaseContext对象。
 *  建议在获取一个WXOBaseContext后，将其保存为全局单例使用。
 *  目前暂不支持多个WXOBaseContext对象并存使用。
 */
- (WXOBaseContext *)fetchNewBaseContext;

/// BaseContext被新建的通知
#define WXOSdkBaseContextCreatedBlock   YWSDKIMCoreCreatedBlock

/**
 *  监听新的BaseContext被生成
 */
- (void)addBaseContextCreatedBlock:(WXOSdkBaseContextCreatedBlock)aBlock forKey:(NSString *)aKey priority:(WXOBlockPriority)aPriority;

- (void)removeBaseContextCreatedBlockForKey:(NSString *)aKey;


@end


@interface WXOSdk (GlobalServices)

/**
 *  获取PushService
 */
- (id<IWXOPushService>)getGlobalPushService;

/**
 *  获取ExtensionService
 */
- (id<IWXOExtensionService>)getGlobalExtensionService;

@end

@interface WXOSdk (OpenUtilServices)

/**
 *  获取cacheService
 */
- (id<IWXOUtilService4Cache>)getGlobalUtilService4Cache;

/**
 *  获取UtilService4Network
 */
- (id<IWXOUtilService4Network>)getGlobalUtilService4Network;

/**
 *  获取UtilService4Security
 */
- (id<IWXOUtilService4Security>)getGlobalUtilService4Security;

@end


#pragma mark - 配置信息

@interface WXOSdk ()

/**
 *  OpenIM SDK版本信息
 */
@property (nonatomic, readonly) NSString *openIMSdkIdentifier;

/**
 *  网络环境，可以通过这个属性，在初始化WXOSdk之前设置网络环境的初始值
 *  热切换网络环境功能暂时不支持。（即如果已经初始化Sdk，则无法切换）
 */
@property (nonatomic, assign, readwrite) WXOEnvironment environment;

/**
 *  切换网络环境，此功能暂不支持。
 *  如果需要不同的网络环境，需要在初始化Sdk之前，设置上面的environment属性。
 */
- (void)changeEnvironment:(WXOEnvironment)aEnvironment;


/// 网络环境切换的回调（暂不支持）
#define WXOSdkEnvironmentChangedBlock   YWSdkEnvironmentChangedBlock

/**
 *  添加网络环境切换的监听（暂不支持）
 */
- (void)addEnvironmentChangedBlock:(WXOSdkEnvironmentChangedBlock)aBlock forKey:(NSString *)aKey ofPriority:(WXOBlockPriority)aPriority;

/**
 *  移除网络环境切换的监听（暂不支持）
 */
- (void)removeEnvironmentChangedBlockForKey:(NSString *)aKey;

/**
 *  日志开关
 */
@property (nonatomic, readwrite) BOOL logEnabled;

@end

