//
//  ViewController.m
//
//  Created by Bugtags on 2015-08-01.
//
//  Copyright (c) 2016 Bugtags, Inc. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property(nonatomic, weak) IBOutlet NSLayoutConstraint *topConstraint;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.navigationItem.titleView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"btg_icon_logo"]];
    self.edgesForExtendedLayout = UIRectEdgeNone;
    
    self.topConstraint.constant = 0;
}

- (IBAction)onButtonClick:(UIButton *)sender
{
    switch (sender.tag) {

        case 1000:
            [self performSegueWithIdentifier:@"features" sender:nil];
            break;
        case 1001:
            [self performSegueWithIdentifier:@"integration" sender:nil];
            break;
        case 1002:
            [self performSegueWithIdentifier:@"feedback" sender:nil];
            break;
        case 1003:
        {
            NSMutableArray *array = [NSMutableArray arrayWithCapacity:1];
            NSString *s = nil;
            [array addObject:s];
        }
            break;
        default:
            break;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
