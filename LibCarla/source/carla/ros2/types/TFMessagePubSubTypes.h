// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file TFMessagePubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */

#ifndef _FAST_DDS_GENERATED_TF2_MSGS_MSG_TFMESSAGE_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_TF2_MSGS_MSG_TFMESSAGE_PUBSUBTYPES_H_

#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastrtps/utils/md5.h>

#include "TFMessage.h"

#include "TransformStampedPubSubTypes.h"

#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
#error \
    Generated TFMessage is not compatible with current installed Fast DDS. Please, regenerate it with fastddsgen.
#endif  // GEN_API_VER

namespace tf2_msgs
{
    namespace msg
    {

        /*!
         * @brief This class represents the TopicDataType of the type TFMessage defined by the user in the IDL file.
         * @ingroup TFMESSAGE
         */
        class TFMessagePubSubType : public eprosima::fastdds::dds::TopicDataType
        {
        public:
// 定义一个类型别名，将TFMessage定义为此处相关类型的别名，方便后续代码中使用该类型时书写更简洁
            typedef TFMessage type;
    // 以动态链接库导出（eProsima_user_DllExport可能是自定义用于导出函数的宏，具体依赖对应库的定义）的方式声明TFMessagePubSubType函数，
    // 通常用于和发布订阅相关的类型操作（具体功能要看函数实现，大概率是返回TFMessage对应的发布订阅类型相关信息等）
            eProsima_user_DllExport TFMessagePubSubType();
// 以动态链接库导出的方式声明虚析构函数，用于在对象销毁时进行必要的清理操作，
 // override关键字表示这个析构函数是重写了基类中的虚析构函数（确保多态销毁时行为正确）
            eProsima_user_DllExport virtual ~TFMessagePubSubType() override;
// 以动态链接库导出的方式声明序列化函数，该函数用于将给定的数据（通常是自定义类型的数据对象，这里对应void* data指向的数据）
  // 转换为可用于网络传输等用途的序列化形式，并存储到SerializedPayload_t类型的结构中，
  // override关键字表示重写了基类中对应的虚函数
            eProsima_user_DllExport virtual bool serialize(
                    void* data,
                    eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;
// 以动态链接库导出的方式声明反序列化函数，用于将接收到的序列化数据（SerializedPayload_t类型）
    // 转换回原始的数据形式（存储到void* data指向的内存空间），override表示重写基类虚函数
            eProsima_user_DllExport virtual bool deserialize(
                    eprosima::fastrtps::rtps::SerializedPayload_t* payload,
                    void* data) override;
// 以动态链接库导出的方式声明一个函数，该函数返回一个std::function类型对象，
    // 这个对象实际上是一个可调用的函数，其返回值类型为uint32_t，用于获取给定数据（void* data指向的数据）序列化后的大小，
    // override表示重写基类对应虚函数
            eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
                    void* data) override;
// 以动态链接库导出的方式声明获取键值的函数，尝试从给定的数据（void* data指向的数据）中获取一个唯一标识此数据的键，
    // 存储到InstanceHandle_t类型的结构中，用于在发布订阅等场景下进行对象的区分等操作，force_md5参数用于指定是否强制使用MD5相关机制（默认是false），
    // override表示重写基类虚函数
            eProsima_user_DllExport virtual bool getKey(
                    void* data,
                    eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
                    bool force_md5 = false) override;
 // 以动态链接库导出的方式声明创建数据的函数，用于创建对应类型（这里应该和TFMessage相关）的数据对象，
 // 返回创建后的数据对象的指针（以void*类型返回，实际使用时可能需要进行类型转换），override表示重写基类虚函数
            eProsima_user_DllExport virtual void* createData() override;
 // 以动态链接库导出的方式声明删除数据的函数，用于释放由createData函数创建的数据对象所占用的内存资源，
    // 参数data指向要删除的数据对象，override表示重写基类虚函数
            eProsima_user_DllExport virtual void deleteData(
                    void* data) override;

        #ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
            eProsima_user_DllExport inline bool is_bounded() const override
            {
                return false;
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

        #ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
            eProsima_user_DllExport inline bool is_plain() const override
            {
                return false;
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

        #ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
            eProsima_user_DllExport inline bool construct_sample(
                    void* memory) const override
            {
                (void)memory;
                return false;
            }

        #endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
            MD5 m_md5;
            unsigned char* m_keyBuffer;
        };
    }
}

#endif // _FAST_DDS_GENERATED_TF2_MSGS_MSG_TFMESSAGE_PUBSUBTYPES_H_
