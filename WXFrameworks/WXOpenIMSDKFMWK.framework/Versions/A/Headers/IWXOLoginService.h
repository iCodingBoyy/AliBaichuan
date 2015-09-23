//
//  IWXLoginService.h
//  WXOpenIMSDK
//
//  Created by huanglei on 14/12/11.
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





#import "IYWLoginService.h"

#import "WXOServiceDef.h"
#import "WXOLoginServiceDef.h"
#import "WXOPerson.h"

#pragma mark - 服务接口定义

/**
 * 登录相关服务提供
 */
@protocol IWXOLoginService <IYWLoginService>

/**
 *  当前IM是否已登录
 */
@property (nonatomic, assign, readonly) BOOL isCurrentLogined;

/**
 *  当前登录Id
 */
@property (nonatomic, readonly) NSString *currentLoginedUserId;

/**
 *  当前登录用户的显示名称
 */
@property (nonatomic, readonly) NSString *currentLoginedUserDisplayName;

/**
 *  当前登录的用户
 */
- (WXOPerson *)currentLoginedUser;

#define WXOFetchLoginInfoBlock      YWFetchLoginInfoBlock
#define WXOFetchLoginInfoBlockV2    YWFetchLoginInfoBlockV2
/**
 *  设置登录能力
 */
- (void)setFetchLoginInfoBlock:(WXOFetchLoginInfoBlock)fetchLoginInfoBlock;
- (void)setFetchLoginInfoBlockV2:(WXOFetchLoginInfoBlockV2)fetchLoginInfoBlock;

/**
 *  获取最后一次连接时的Error信息，如果为nil，则表示还没有连接过或者连接为成功
 */
@property (nonatomic, copy, readonly) NSError *lastConnectionError;

/**
 *  设置固定的登录额外信息。例如与TAE SDK等集成使用时，可以传递额外信息。
 *  一般来说，ISV不需要特别关注这个字段。
 */
@property (nonatomic, copy) NSDictionary *defaultLoginClientData;

/// 设置IM长连接状态变更回调
- (void)addConnectionStatusChangedBlock:(WXOIMConnectionStatusChangedBlock)connectionStatusChangedBlock forKey:(NSString *)aKey ofPriority:(WXOBlockPriority)aPriority;
/// 移除IM长连接状态变更回调
- (void)removeConnectionStatusChangedBlockForKey:(NSString *)aKey;

/**
 *  发起异步登录
 *  @param aCompletionBlock 登录结果回调，如果成功则aError返回nil
 *  @return 如果没能发起登陆请求，则直接返回NO
 */
- (BOOL)asyncLoginWithCompletionBlock:(WXOCompletionBlock)aCompletionBlock;

/**
 * 异步登出
 * @param aCompletionBlock 登出结果回调，如果成功则aError返回nil
 */
- (void)asyncLogoutWithCompletionBlock:(WXOCompletionBlock)aCompletionBlock;

@end


