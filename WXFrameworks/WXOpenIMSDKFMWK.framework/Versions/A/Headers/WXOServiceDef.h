//
//  WXOServiceDef.h
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
#import <UIKit/UIKit.h>
#import "YWServiceDef.h"


#define WXOCompletionBlock                  YWCompletionBlock

#define WXOMessageSendingCompletionBlock    YWMessageSendingCompletionBlock

#define WXOProgressBlock                    YWProgressBlock

#define WXOMessageSendingProgressBlock      YWMessageSendingProgressBlock

/// error的userInfo中，使用这个key来传递错误描述
#define WXOErrorUserInfoKeyDescription      YWErrorUserInfoKeyDescription


/**
 *  Block优先级定义
 */
typedef NS_ENUM(NSUInteger, WXOBlockPriorityDef) {
    /// 开发者的回调
    WXOBlockPriorityDeveloper = YWBlockPriorityDeveloper,
    /// 不同模块的回调
    WXOBlockPriorityOtherModule = YWBlockPriorityOtherModule,
    /// 本模块的回调
    WXOBlockPriorityThisModule = YWBlockPriorityThisModule
};
#define WXOBlockPriority        YWBlockPriority

__deprecated_msg("请使用YWServiceDef替代") @interface WXOServiceDef : YWServiceDef

@end
