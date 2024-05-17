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

@class GIDAuthFlow;
@class GIDConfiguration;
@class OIDAuthorizationResponse;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GIDFlowName) {
  SignIn,
  Verify,
};

@interface GIDAuthorizationResponseHelper : NSObject

@property(nonatomic, strong, nullable) GIDConfiguration *configuration;

- (instancetype)initWithAuthorizationResponse:(OIDAuthorizationResponse *)authFlow
                                   emmSupport:emmSupport
                                     flowName:(GIDFlowName)flowName
                                configuration:(GIDConfiguration *)config;

- (GIDAuthFlow *)processWithError:(NSError *)error;

- (void)maybeFetchToken:(GIDAuthFlow *)authFlow;

@end

NS_ASSUME_NONNULL_END
