//
//  IWXOUtilService4Network.h
//  WXOpenIMSDK
//
//  Created by huanglei on 15/3/11.
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
#import "IYWUtilService4Network.h"

/**
 *  HTTP方法定义
 */
typedef enum : NSUInteger {
    /// Get方法
    WXOHttpRequestMethodGet = YWHttpRequestMethodGet,
    /// Post方法
    WXOHttpRequestMethodPost = YWHttpRequestMethodPost,
} WXOHttpRequestMethodDef;
#define WXOHttpRequestMethod        YWHttpRequestMethod

/// 用于WebRequest
#define kWXOHttpRequestParamKeyForWebRequest    kYWHttpRequestParamKeyForWebRequest

#define WXOHttpRequestSuccessBlock  YWHttpRequestSuccessBlock
#define WXOHttpRequestFailedBlock   YWHttpRequestFailedBlock

@class WXOBaseContext;

@protocol IWXOUtilService4Network <IYWUtilService4Network>

/**
 *  发起一个HTTP请求
 */
- (BOOL)sendHttpRequestWithURLString:(NSString *)aURLString
                              method:(WXOHttpRequestMethod)aMethod
                             timeout:(NSTimeInterval)aTimeout
                              params:(NSDictionary *)aParams
                             isAsync:(BOOL)aIsAsync
                        successBlock:(WXOHttpRequestSuccessBlock)aSuccessBlock
                         failedBlock:(WXOHttpRequestFailedBlock)aFailedBlock
                       inBaseContext:(WXOBaseContext *)aBaseContext;

/**
 *  下载数据
 */
- (BOOL)downloadDataWithURLString:(NSString *)aURLString
                           method:(WXOHttpRequestMethod)aMethod
                          timeout:(NSTimeInterval)aTimeout
                           params:(NSDictionary *)aParams
                          isAsync:(BOOL)aIsAsync
                      enableCache:(BOOL)aEnableCache
                     successBlock:(WXOHttpRequestSuccessBlock)aSuccessBlock
                      failedBlock:(WXOHttpRequestFailedBlock)aFailedBlock
                    inBaseContext:(WXOBaseContext *)aBaseContext;


@end
