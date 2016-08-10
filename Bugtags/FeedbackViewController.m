//
//  FeedbackViewController.m
//
//  Created by Bugtags on 2015-08-01.
//
//  Copyright (c) 2016 Bugtags, Inc. All rights reserved.
//

#import "FeedbackViewController.h"
#import <Bugtags/Bugtags.h>

@interface FeedbackViewController ()

@property(nonatomic, weak) IBOutlet UITextField *nameTextField;
@property(nonatomic, weak) IBOutlet UITextView *textView;

@end

@implementation FeedbackViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    self.title = @"Feedback API Demo";
    self.edgesForExtendedLayout = UIRectEdgeNone;
    
    UIBarButtonItem *submitItem = [[UIBarButtonItem alloc] initWithTitle:@"Send"
                                                                   style:UIBarButtonItemStylePlain
                                                                  target:self
                                                                  action:@selector(onSubmitClick)];
    self.navigationItem.rightBarButtonItem = submitItem;
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [self.nameTextField becomeFirstResponder];
}

- (void)onSubmitClick
{
    NSString *name = self.nameTextField.text;
    if (name.length == 0) {
        
        [self.nameTextField becomeFirstResponder];
        return;
    }
    
    NSString *content = [self.textView.text stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
    if (content.length == 0) {
        
        [self.textView becomeFirstResponder];
        return;
    };
    
    BTGLog(@"Feedback API Demo"); // Add a custom log
    [Bugtags setUserData:name forKey:@"name"];
    [Bugtags sendFeedback:content];
    
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:nil
                                                        message:@"Feedback sent successfully"
                                                       delegate:nil
                                              cancelButtonTitle:@"OK"
                                              otherButtonTitles:nil];
    [alertView show];
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
