//
//  WXOInputViewPlugin.h
//  WXOpenIMUIKit
//
//  Created by Zhiqiang Bao on 15-2-3.
//  Copyright (c) 2015年 www.alibaba.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class YWMessageInputView;
@class YWEmoticon;

/*
 * 实现一个插件可以选择实现 WXOInputViewPluginProtocol
 * 或者继承自 WXOInputViewPlugin 重写其中的方法
 */

/********** WXOInputViewPluginProtocol **********/

@protocol YWInputViewPluginProtocol <NSObject>

@optional

// 是否在面板关闭时popPluginContentView，默认是YES
- (BOOL)shouldPopPluginContentViewWhenMorePanelClose;

// 是否显示在前置而板（输入文本框右边），只在加载时判断一次，默认是NO
- (BOOL)isPrepositionPlugin;

// 前置插件按钮普通状态的图标
- (UIImage *)prepositionPluginNormalIcon;

// 前置插件按钮按下时的图标（若未设置以normal展示）
- (UIImage *)prepositionPluginPressedIcon;

// 前置插件选中时的图标
- (UIImage *)prepositionPluginSelectedIcon;

// 前置插件是否打开更多面板，默认为NO
- (BOOL)shouldOpenMorePanel;

@required

// 加载该插件的inputView
@property (nonatomic, weak) YWMessageInputView *inputViewRef;

// 插件图标
- (UIImage *)pluginIconImage;

// 插件名称
- (NSString *)pluginName;

// 插件对应的view，会被加载到inputView上
- (UIView *)pluginContentView;

// 插件被选中运行
- (void)pluginDidClicked;

@end

/************ WXOInputViewPlugin ************/

@interface YWInputViewPlugin : NSObject <YWInputViewPluginProtocol>

@property (nonatomic, weak) YWMessageInputView *inputViewRef;

@property (nonatomic, strong, readonly) NSString *pluginName;
@property (nonatomic, strong, readonly) UIImage  *pluginIconImage;
@property (nonatomic, strong, readonly) UIView   *pluginContentView;

- (instancetype)initWithPluginName:(NSString *)pluginName
                   pluginIconImage:(UIImage *)pluginIconImage;

@end
