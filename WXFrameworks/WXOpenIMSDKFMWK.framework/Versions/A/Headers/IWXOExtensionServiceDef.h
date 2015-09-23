//
//  IWXOExtensionServiceDef.h
//  WXOpenIMSDK
//
//  Created by huanglei on 15/3/10.
//  Copyright (c) 2015年 taobao. All rights reserved.
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





#import "IYWExtensionServiceDef.h"


/**
 *  扩展类型定义
 */
typedef enum : NSUInteger {
    /// 全局扩展
    WXOExtensionTypeGlobal = 1,
    /// WXOBaseContext内部扩展
    WXOExtensionTypeContext,
} WXOExtensionType;

/**
 *  定义扩展的文件名，这个文件必须位于MainBundle
 *  这个文件中声明了所有被引入App的OpenIM扩展，是一个NSArray对象
 *  每个item是一个包含下面三个key的NSDictionary对象
 */
#define WXOExtensionPlistFileName       YWExtensionPlistFileName

/**
 *  扩展的plist中，extension的加载器名称
 */
#define WXOExtensionPlistKeyLoaderName  YWExtensionPlistKeyLoaderName

/**
 *  扩展的plist中，extension的类型
 */
#define WXOExtensionPlistKeyType        YWExtensionPlistKeyType


/**
 *  每一个扩展必须遵循这个协议
 */

@protocol IWXOExtension <IYWExtension>

/**
 *  该扩展是否被启用
 */
- (BOOL)enable;

@end

/**
 *  每一个扩展必须有一个加载器类，遵循这个协议
 */
@protocol IWXOExtensionLoader <IYWExtensionLoader>

/**
 *  每一个加载器类必须实现这个方法，并返回扩展的具体对象。
 *  @param aContext 如果是全局扩展，被加载时此参数为nil；如果是Context内部扩展，被加载时此参数为WXOBaseContext对象
 */
+ (id<IWXOExtension>)loadExtensionWithContext:(id)aContext;

@end



@interface IWXOExtensionServiceDef : IYWExtensionServiceDef

@end