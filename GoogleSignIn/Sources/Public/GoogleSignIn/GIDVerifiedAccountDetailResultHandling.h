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

@class GIDVerifiableAccountDetail;
@class GIDVerifiedAccountDetailResult;
@class OIDAuthState;
@class OIDTokenResponse;

NS_ASSUME_NONNULL_BEGIN

@protocol GIDVerifiedAccountDetailResultHandling

/// Initialize a `GIDVerifiedAccountDetailResultHandling` object by specifying all available properties.
///
/// @param tokenResponse The last token response with expiration date, access token, and refresh token.
/// @param accountDetails A list of verified account details.
/// @param authState An updated to update the token response or authorization error.
///
/// @return An initialized `GIDVerifiedAccountDetailResultHandling` instance with expiration date, access token, and refresh token.
- (instancetype)initWithLastTokenResponse:(OIDTokenResponse *)tokenResponse
                           accountDetails:(NSArray<GIDVerifiableAccountDetail *> *)accountDetails
                                authState:(OIDAuthState *)authState;

/// Refresh the access token and refresh token with the current authorization state.
///
/// @param completion A completion block called when the refresh operation completes with the new result or error.
- (void)refreshTokensWithCompletion:(nullable void (^)(GIDVerifiedAccountDetailResult *,
                                                      NSError *))completion;

@end

NS_ASSUME_NONNULL_END
