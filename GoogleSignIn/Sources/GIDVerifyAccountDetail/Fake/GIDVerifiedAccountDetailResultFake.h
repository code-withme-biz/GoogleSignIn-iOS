/*
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "GoogleSignIn/Sources/GIDAuthorizationResponse/API/GIDVerifiedAccountDetailResultHandling.h"

NS_ASSUME_NONNULL_BEGIN

@class GIDVerifiedAccountDetailResult;
@class GIDVerifiableAccountDetail;
@class OIDAuthState;
@class OIDTokenResponse;

@interface GIDVerifiedAccountDetailResultFake : NSObject <GIDVerifiedAccountDetailResultHandling>

/// The token response to be updated in the auth state.
@property (nonatomic, nullable) OIDTokenResponse *tokenResponse;

/// The auth state to be used to refresh tokens.
@property (nonatomic, nullable) OIDAuthState *verifiedAuthState;

/// The error to be updated in the auth state.
@property (nonatomic, nullable) NSError *error;

/// A list of verified account details.
@property(nonatomic, copy, readonly) NSArray<GIDVerifiableAccountDetail *>
    *verifiedAccountDetails;


- (instancetype)initWithTokenResponse:(nullable OIDTokenResponse *)tokenResponse
                    verifiedAuthState:(nullable OIDAuthState *)verifiedAuthState
                                error:(nullable NSError *)error;

@end

NS_ASSUME_NONNULL_END
