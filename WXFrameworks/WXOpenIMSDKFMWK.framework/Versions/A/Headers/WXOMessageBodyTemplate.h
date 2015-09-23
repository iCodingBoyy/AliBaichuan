//
//  WXOMessageBodyTemplate.h
//  WXOpenIMSDK
//
//  Created by 慕桥(黄玉坤) on 1/22/15.
//  Copyright (c) 2015 taobao. All rights reserved.
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






#import "YWMessageBodyTemplate.h"

typedef enum : NSUInteger {
    //新模板
    WXOTemplateTypeURL          = YWTemplateTypeURL,     //交易类通知
    WXOTemplateTypeHTML         = YWTemplateTypeHTML,     //交易类通知
    WXOTemplateTypeTEXT         = YWTemplateTypeTEXT,     //交易类通知
    WXOTemplateTypeTrade        = YWTemplateTypeTrade,     //交易类通知
    WXOTemplateTypeFlow         = YWTemplateTypeFlow,     //旺起通用模板
    WXOTemplateTypeAudio        = YWTemplateTypeAudio,     //语音
    WXOTemplateTypeMusic        = YWTemplateTypeMusic,     //音乐
    WXOTemplateTypeVideo        = YWTemplateTypeVideo,     //视频
    WXOTemplateTypeLocation     = YWTemplateTypeLocation,     //地理位置
    WXOTemplateTypeImageTextH   = YWTemplateTypeImageTextH,     //横排单图文
    WXOTemplateTypeImageTextV   = YWTemplateTypeImageTextV,     //竖排单图文
    WXOTemplateTypeImageTextMulti  = YWTemplateTypeImageTextMulti,  //竖排多图文
    WXOTemplateTypeMultiText    = YWTemplateTypeMultiText,     //竖排多文本
} WXOTemplateTypeDef;
#define WXOTemplateType     YWTemplateType


__deprecated_msg("请使用YWMessageBodyTemplate替代") @interface WXOMessageBodyTemplate : YWMessageBodyTemplate

// 标题
@property (nonatomic, strong, readonly) NSString *title;

// 摘要
@property (nonatomic, strong, readonly) NSString *summary;

// 降级文案
@property (nonatomic, strong, readonly) NSString *degradeText;

// 提醒升级
@property (nonatomic, assign, readonly) BOOL needUpgrade;

// 模板ID
@property (nonatomic, assign, readonly) WXOTemplateType templateId;

// 模板数据
@property (nonatomic, strong, readonly) NSDictionary *templateData;

// 业务自定义数据
@property (nonatomic, strong, readonly) NSDictionary *userData;

@end
