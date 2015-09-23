//
//  IWXOCacheUtilService.h
//  WXOpenIMSDK
//
//  Created by huanglei on 15/2/11.
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
#import "IYWUtilService4Cache.h"

@protocol IWXOUtilService4Cache <IYWUtilService4Cache>

/**
 *  @param aData 需要存放的数据
 *  @param aKey 使用的key
 */
- (void)storeData:(NSData *)aData forKey:(NSString *)aKey;

/**
 *  @param aKey 需要访问的key
 *  @return 结果NSData对象
 */
- (NSData *)dataForKey:(NSString *)aKey;


/**
 *  @param aData 需要存放的数据
 *  @param aUrlString 该数据的来源URL
 */
- (void)storeData:(NSData *)aData forUrlString:(NSString *)aUrlString;

/**
 *  @param aUrlString 数据的来源URL
 *  @return 如果没有本地存储，则返回nil
 */
- (NSData *)dataForUrlString:(NSString *)aUrlString;

@end
