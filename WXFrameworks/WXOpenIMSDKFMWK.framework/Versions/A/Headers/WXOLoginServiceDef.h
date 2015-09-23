//
//  WXOLoginServiceDef.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/16.
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
#import "YWLoginServiceDef.h"

/// LoginService的错误域
#define WXOLoginServiceDomain    YWLoginServiceDomain

/**
 * 登录错误定义
 */
typedef NS_ENUM(NSUInteger, WXOLoginErrorCodeDef) {
    /// 没有这个用户
    WXOLoginErrorCodeUserNotExsit = YWLoginErrorCodeUserNotExsit,
    /// 密码错误
    WXOLoginErrorCodePasswordError = YWLoginErrorCodePasswordError,
    /// 账号受限
    WXOLoginErrorCodeAccountLimited = YWLoginErrorCodeAccountLimited,
    /// 版本受限
    WXOLoginErrorCodeVersionLimited = YWLoginErrorCodeVersionLimited,
    /// 版本过老
    WXOLoginErrorCodeVersionTooOld = YWLoginErrorCodeVersionTooOld,
    /// 淘系免登token失效
    WXOLoginErrorCodePasswordInvalid = YWLoginErrorCodePasswordInvalid,
    
    /// 超时
    WXOLoginErrorCodeTimeout = YWLoginErrorCodeTimeout,
    /// 没有设置登陆信息
    WXOLoginErrorCodeLoginInfoInvalid = YWLoginErrorCodeLoginInfoInvalid,
    /// 已有账号保持登录
    WXOLoginErrorCodeAlreadyLogined = YWLoginErrorCodeAlreadyLogined,
    /// 版本需要强制更新
    WXOLoginErrorCodeNeedUpdate = YWLoginErrorCodeNeedUpdate,
    /// 应用信息获取失败
    WXOLoginErrorCodeAppInfoFailed = YWLoginErrorCodeAppInfoFailed,
    /// 其他错误
    WXOLoginErrorCodeOther = YWLoginErrorCodeOther,
};
#define WXOLoginErrorCode       YWLoginErrorCode

/**
 *  IM长连接状态
 */
typedef NS_ENUM(NSUInteger, WXOIMConnectionStatusDef) {
    /// 被踢
    WXOIMConnectionStatusForceLogout = YWIMConnectionStatusForceLogout,
    /// 手动登出
    WXOIMConnectionStatusMannualLogout = YWIMConnectionStatusMannualLogout,
    
    
    /// IM长连接断开
    WXOIMConnectionStatusDisconnected = YWIMConnectionStatusDisconnected,
    /// IM长连接连接中
    WXOIMConnectionStatusConnecting = YWIMConnectionStatusConnecting,
    /// IM长连接连接成功
    WXOIMConnectionStatusConnected = YWIMConnectionStatusConnected,
    /// IM长连接自动连接失败
    WXOIMConnectionStatusAutoConnectFailed = YWIMConnectionStatusAutoConnectFailed
};
#define WXOIMConnectionStatus       YWIMConnectionStatus


#define WXOIMConnectionStatusChangedBlock       YWIMConnectionStatusChangedBlock

/**
 *  登录方式
 */
typedef enum : NSUInteger {
    /// 密码登录
    WXOLoginTypeRawPassword = YWLoginTypeRawPassword,
    /// TrustLogin方式
    WXOLoginTypeTrustLogin = YWLoginTypeTrustLogin,
} WXOLoginTypeDef;
#define WXOLoginType        YWLoginType


#define WXOFetchLoginInfoCompletionBlock        YWFetchLoginInfoCompletionBlock
#define WXOFetchLoginInfoCompletionBlockV2      YWFetchLoginInfoCompletionBlockV2

#define WXOFetchLoginInfoBlock                  YWFetchLoginInfoBlock
#define WXOFetchLoginInfoBlockV2                YWFetchLoginInfoBlockV2


__deprecated_msg("请使用YWLoginServiceDef替代") @interface WXOLoginServiceDef : YWLoginServiceDef

@end
