#import "ViewController.h"
#import "NativeInterface.h"

@interface ViewController ()
{
    NativeInterface* i;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    i = [[NativeInterface alloc]init];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
