#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>

class Game;

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
    Game* _Game;
}

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet WebView *webView;

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender;

@end
