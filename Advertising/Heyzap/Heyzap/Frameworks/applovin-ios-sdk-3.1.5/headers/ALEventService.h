//
//  ALEventService.h
//  sdk
//
//  Created by Matt Szaro on 7/10/15.
//
//

#import <Foundation/Foundation.h>
#import "ALEventTypes.h"
#import "ALNullabilityAnnotations.h"

/**
 * @name Event Tracking
 */

/**
 * Service which provides tracking of user post-install events.
 */
@interface ALEventService : NSObject

/**
 * Track an event of a given type.
 *
 * For many event types, it is preferable to provide additional data by using trackEvent:parameters: instead.
 *
 * @param eventType A string describing this event; can one of the predefined kALEventType constants defined in ALEventTypes.h, or a custom string.
 */
-(void) trackEvent: (alnonnull NSString* const) eventType;

/**
 * Track an event of a given type.
 *
 * @param eventType A string describing this event; can one of the predefined kALEventType constants defined in ALEventTypes.h, or a custom string.
 *
 * @param parameters A dictionary containing key-value pairs further describing this event. Particular data points of interest are provided as "suggested keys" in the doc comment for each event type constant in ALEventTypes.h
 */
-(void) trackEvent: (alnonnull NSString* const) eventType parameters: (alnullable NSDictionary*) parameters;

/**
 * Track an in app purchase.
 *
 * @param transactionId Value of SKTransaction's transactionIdentifier property.
 *
 * @param parameters A dictionary containing key-value pairs further describing this event. You should provide, at a minimum, kALEventParameterRevenueAmountKey and kALEventParameterRevenueCurrencyKey. We also recommend passing kALEventParameterProductIdentifierKey.
 *
 * If you pass a value for kALEventParameterStoreKitReceiptKey, it will be used for validation.
 * Otherwise, we will automatically collect [[NSBundle mainBundle] appStoreReceiptURL] and use it for validation.
 */
-(void) trackInAppPurchaseWithTransactionIdentifier: (alnonnull NSString* const) transactionId parameters: (alnullable NSDictionary*) parameters;

/**
 * Track a checkout / standard purchase.
 *
 * @param transactionId An optional unique identifier for this transaction, as generated by you; for Apple Pay transactions, we suggest PKPaymentToken's transactionIdentifier property.
 *
 * @param parameters A dictionary containing key-value pairs further describing this event. You should provide, at a minimum, kALEventParameterRevenueAmountKey and kALEventParameterRevenueCurrencyKey. We also recommend passing kALEventParameterProductIdentifierKey.
 */
-(void) trackCheckoutWithTransactionIdentifier: (alnullable NSString* const) transactionId parameters: (alnullable NSDictionary*) parameters;

- (alnullable id)init __attribute__((unavailable("Don't instantiate ALEventService, access one via [sdk eventService] instead.")));

@end
