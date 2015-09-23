//
//  IWXOUtilService4Security.h
//  WXOpenIMSDK
//
//  Created by huanglei on 15/3/12.
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
#import "IYWUtilService4Security.h"

@protocol IWXOUtilService4Security <IYWUtilService4Security>

/// MD5
- (NSString *)md5OfData:(NSData *)aInputData;

/// Base64解码
- (NSData *)Base64Decode:(NSString *)aInputString;

/// Base64编码
- (NSString *)Base64Encode:(NSData *)aInputData;


/// AES256加密
- (NSData *)AES256EncryptData:(NSData *)aInputData withKey:(NSString *)aKey;

/// AES256解密
- (NSData *)AES256DecryptData:(NSData *)aInputData withKey:(NSString *)aKey;

/// 使用RSA公钥加密
- (NSData *)RSAPubEncryptData:(NSData *)aInputData withKeyData:(NSData *)aKeyData;

/// 使用RSA公钥验证
- (BOOL)RSAPubVerityData:(NSData *)aSignedData inputData:(NSData *)aInputData withKeyData:(NSData *)aKeyData;

@end
