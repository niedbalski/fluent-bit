/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit
 *  ==========
 *  Copyright (C) 2015-2024 The Fluent Bit Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <fluent-bit/flb_info.h>
#include <fluent-bit/flb_http_client.h>
#include <fluent-bit/flb_aws_credentials.h>

#ifdef FLB_HAVE_SIGNV4

#ifndef FLB_SIGNV4_NG_H
#define FLB_SIGNV4_NG_H

#ifndef S3_MODE_NONE
/* Request is not Amazon S3 PutObject */
#define S3_MODE_NONE             0
#endif

#ifndef S3_MODE_SIGNED_PAYLOAD
/* Set the x-amz-content-sha256 header with the sha value */
#define S3_MODE_SIGNED_PAYLOAD   1
#endif

#ifndef S3_MODE_UNSIGNED_PAYLOAD
/* Set the x-amz-content-sha256 header with the value UNSIGNED-PAYLOAD */
#define S3_MODE_UNSIGNED_PAYLOAD 2
#endif

flb_sds_t flb_signv4_ng_do(struct flb_http_request *request,
                           int normalize_uri,
                           int amz_date,
                           time_t t_now,
                           char *region, char *service,
                           int s3_mode,
                           struct mk_list *unsigned_headers,  /* flb_slist */
                           struct flb_aws_provider *provider);

#endif
#endif /* FLB_HAVE_SIGNV4 */
