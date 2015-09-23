//
//  IWXOPushService.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/16.
//  Copyright (c) 2014年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>





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





#import "IYWPushService.h"


/// Push服务错误域
#define WXOPushServiceDomain    YWPushServiceDomain

/**
 Push服务
 */

@protocol IWXOPushService <IYWPushService>

/**
 *  登记DeviceToken. ISV需要在获得DeviceToken后设入DeviceToken。
 */
@property (nonatomic, copy, readwrite) NSData *deviceToken;
/**
 *  获取转换后的deviceToken字符串
 */
@property (nonatomic, readonly) NSString *deviceTokenString;


#define WXOPushHandleResultBlock        YWPushHandleResultBlock

/**
 *  处理启动参数
 *  @param aLaunchOptions 启动参数
 *  @param aCompletionBlock 如果OpenIM接受处理该启动参数，在处理完毕后通过此回调返回结果
 *  @return OpenIM是否接受处理该启动参数
 */
- (BOOL)handleLaunchOptions:(NSDictionary *)aLaunchOptions completionBlock:(WXOPushHandleResultBlock)aCompletionBlock;

/**
 *  处理Push消息
 *  @param aPushUserInfo
 *  @param aCompletionBlock
 *  @return OpenIM是否接受处理该Push
 */
- (BOOL)handlePushUserInfo:(NSDictionary *)aPushUserInfo completionBlock:(WXOPushHandleResultBlock)aCompletionBlock;

@end
