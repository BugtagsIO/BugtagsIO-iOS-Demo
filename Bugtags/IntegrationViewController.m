//
//  IntegrationViewController.m
//
//  Created by Bugtags on 2015-08-01.
//
//  Copyright (c) 2016 Bugtags, Inc. All rights reserved.
//

#import "IntegrationViewController.h"

@interface IntegrationViewController ()

@property(nonatomic, weak) IBOutlet UIWebView *webView;
@end

@implementation IntegrationViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"Integration";
    self.edgesForExtendedLayout = UIRectEdgeNone;
    
    [self.webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"https://docs.bugtags.io/start/integrate/ios/"]]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
