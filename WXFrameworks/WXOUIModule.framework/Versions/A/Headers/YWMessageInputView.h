//
//  WXOMessageInputView.h
//  testFreeOpenIM
//
//  Created by Jai Chen on 15/1/13.
//  Copyright (c) 2015年 taobao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "YWInputViewPlugin.h"

#define kWXOMessageInputViewMinRecordLenght        1.0

@interface YWMessageInputView : UIView

/**
 *  输入框文本
 */
@property (nonatomic, readwrite)   NSString *text;

/**
 *  more面板容器View，可往里添加自定义pluginView
 *  @note 一般不要直接添加子view，如果希望添加子view，请使用下面的push和pop函数
 */
@property (nonatomic, readonly) UIView  *morePanelContentView;


@property (nonatomic, readonly) UIViewController *controllerRef;

#pragma mark - plugin

// 加载移除pluginContentView

/**
 *  添加子view
 */
- (void)pushContentViewOfPlugin:(id <YWInputViewPluginProtocol>)plugin;
/**
 *  移除子view
 */
- (void)popContentViewOfPlugin:(id <YWInputViewPluginProtocol>)plugin;

// 往更多面板中添加与删除item

/**
 *  在最后添加新的item
 */
- (void)addPlugin:(id <YWInputViewPluginProtocol>)plugin;

/**
 *  移除某个item
 */
- (void)removePlugin:(id <YWInputViewPluginProtocol>)plugin;

/**
 *  移除所有item，包含前置插件
 */
- (void)removeAllPlugins;

/**
 *  获取plugin列表，包含前置插件
 */
- (NSArray *)allPluginList;

/**
 *  刷新
 */
- (void)reloadPluginData;

@end
