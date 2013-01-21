//
//  SettingsMenuViewController.h
//  FlyingSwallow
//
//  Created by koupoo on 12-12-21. Email: koupoo@126.com
//  Copyright (c) 2012年 www.angeleyes.it. All rights reserved.
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License V2
//  as published by the Free Software Foundation.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import <UIKit/UIKit.h>
#import "SettingsMenuViewController.h"
#import "FSSlider.h"
#import "Settings.h"
#import "ChannelSettingsViewController.h"

#define kNotificationDismissSettingsMenuView @"NotificationDissmissAboutUsView"

@class SettingsMenuViewController;

@protocol SettingMenuViewControllerDelegate <NSObject>

- (void)settingsMenuViewController:(SettingsMenuViewController *)ctrl interfaceOpacityValueDidChange:(float)newValue;
- (void)settingsMenuViewController:(SettingsMenuViewController *)ctrl leftHandedValueDidChange:(BOOL)enabled;
- (void)settingsMenuViewController:(SettingsMenuViewController *)ctrl ppmPolarityReversed:(BOOL)enabled;

@end

enum SwitchButtonStatus{
    SWITCH_BUTTON_UNCHECKED = 0,
    SWITCH_BUTTON_CHECKED,
};

enum ChannelListTableViewSection {
    ChannelListTableViewSectionChannels = 0,
};


@interface SettingsMenuViewController : UIViewController <UIScrollViewDelegate, UITableViewDelegate, UITableViewDataSource, UIWebViewDelegate>{
    IBOutlet UILabel *pageTitleLabel;
    
    IBOutlet UIView *personalSettingsPageView;
    IBOutlet UIView *channelSetttingsPageView;
    IBOutlet UIView *modeSettingsPageView;
    IBOutlet UIView *aboutPageView;
    
    IBOutlet UIScrollView *settingsPageScrollView;
    
    IBOutlet UIButton *previousPageButton;
    IBOutlet UIButton *nextPageButton;
    
    IBOutlet UIButton *okButton;
    
    IBOutlet UIPageControl *pageControl;
    
    IBOutlet UILabel *leftHandedTitleLabel;
    IBOutlet UIButton *leftHandedSwitchButton;
    
    IBOutlet UILabel *interfaceOpacityTitleLabel;
    IBOutlet FSSlider *interfaceOpacitySlider;
    IBOutlet UILabel *interfaceOpacityLabel;
    
    IBOutlet UITableView *channelListTableView;
    
    IBOutlet UILabel *ppmPolarityReversedTitleLabel;
    IBOutlet UIButton *ppmPolarityReversedSwitchButton;
    
    IBOutlet UIButton *defaultSettingsButton;
    
    IBOutlet UILabel *takeOffThrottleTitleLabel;
    IBOutlet FSSlider *takeOffThrottleSlider;
    IBOutlet UILabel *takeOffThrottleLabel;
    
    IBOutlet UILabel *aileronElevatorDeadBandTitleLabel;
    IBOutlet FSSlider *aileronElevatorDeadBandSlider;
    IBOutlet UILabel *aileronElevatorDeadBandLabel;
    
    IBOutlet UILabel *rudderDeadBandTitleLabel;
    IBOutlet FSSlider *rudderDeadBandSlider;
    IBOutlet UILabel *rudderDeadBandLabel;
    IBOutlet UIWebView *aboutWebView;
}

@property(nonatomic, assign) NSObject<SettingMenuViewControllerDelegate> *delegate;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil settings:(Settings *)settings;

- (IBAction)buttonClick:(id)sender;
- (IBAction)switchButtonClick:(id)sender;

- (IBAction)sliderRelease:(id)sender;
- (IBAction)sliderValueChanged:(id)sender;



@end



