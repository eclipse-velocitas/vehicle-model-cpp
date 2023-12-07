# Copyright (c) 2022-2023 Contributors to the Eclipse Foundation
#
# This program and the accompanying materials are made available under the
# terms of the Apache License, Version 2.0 which is available at
# https://www.apache.org/licenses/LICENSE-2.0.
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.
#
# SPDX-License-Identifier: Apache-2.0

file(GLOB_RECURSE VMDL_SRC . *.cpp)

set(TARGET_NAME "vehicle-model")

add_library(${TARGET_NAME} STATIC
    ${VMDL_SRC}
)

add_dependencies(${TARGET_NAME}
    vehicle-app-sdk
    vehicle-model-generated-grpc
)

include_directories(
    ${CMAKE_BINARY_DIR}/gens
    ${PROJECT_SOURCE_DIR}/sdk/sdk/include
    .
    )

target_link_libraries(${TARGET_NAME}
    vehicle-app-sdk
    vehicle-model-generated-grpc
)
