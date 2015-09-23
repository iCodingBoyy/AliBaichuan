//
//  IWXORoamingService.h
//  WXOpenIMSDK
//
//  Created by Jai Chen on 15/2/9.
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






#ifndef WXOpenIMSDK_IWXORoamingService_h
#define WXOpenIMSDK_IWXORoamingService_h
#import "IYWRoamingService.h"

#define WXORoamingAuthenticationChallengeCompletionHandlerBlock     YWRoamingAuthenticationChallengeCompletionHandlerBlock
#define WXODidReceiveRoamingAuthenticationChallengeBlock            YWDidReceiveRoamingAuthenticationChallengeBlock


typedef NS_ENUM(NSInteger, WXORoamingServiceStateDef) {
    /**
     *  漫游服务已关闭
     */
    WXORoamingServiceStateDisable = YWRoamingServiceStateDisable,
    /**
     *  漫游服务已开启
     */
    WXORoamingServiceStateEnable = YWRoamingServiceStateEnable
};

#define WXORoamingServiceState      YWRoamingServiceState

@protocol IWXORoamingService <IYWRoamingService>

/**
 *  查询漫游服务的开启状态
 */
- (void)getRoamingServiceState:(void (^)(WXORoamingServiceState state, NSError *error))completion;

/**
 *  设置漫游服务的开启状态
 */
- (void)setRoamingServiceState:(WXORoamingServiceState)state completion:(void (^)(NSError * error))completion;

/**
 *  漫游要求提供密码进行验证的回调
 *
 *  @param block 将用户所输入的漫游密码作为参数调用该 block 以进行漫游密码授权
 */
- (void)setDidReceiveRoamingAuthenticationChangllengeBlock:(WXODidReceiveRoamingAuthenticationChallengeBlock)block;

@end
#endif
