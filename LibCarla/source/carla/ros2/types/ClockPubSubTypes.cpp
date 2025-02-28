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
 * @file ClockPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */

#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include "ClockPubSubTypes.h"

using SerializedPayload_t = eprosima::fastrtps::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastrtps::rtps::InstanceHandle_t;

// 引入了fastcdr库中的FastBuffer.h和Cdr.h头文件，以及自定义的ClockPubSubTypes.h头文件。
// 同时定义了两个类型别名SerializedPayload_t和InstanceHandle_t，分别对应特定的类型，用于后续处理序列化数据和实例句柄相关操作。

namespace rosgraph {
    namespace msg {
        ClockPubSubType::ClockPubSubType()
        {
            setName("rosgraph_msgs::msg::dds_::Clock_");
            // 设置这个类型的名称为 "rosgraph_msgs::msg::dds_::Clock_"，可能用于在发布/订阅系统等场景中标识该类型。

            auto type_size = Clock::getMaxCdrSerializedSize();
            // 获取Clock类型数据最大的CDR（一种数据序列化格式相关概念）序列化大小，并赋值给type_size变量。

            type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
            // 对type_size变量增加通过eprosima::fastcdr::Cdr::alignment函数计算得到的值，此处注释“可能的子消息对齐”表示这是为了让序列化后的子消息按照一定规则（可能与内存对齐等相关，便于后续处理）进行对齐，以符合数据格式要求，传入的参数是type_size和4。

            m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
            // 将调整后的type_size转换为uint32_t类型后再加上4赋值给m_typeSize变量，注释“封装”意味着这增加的4字节与数据封装相关，比如在整个数据结构序列化时额外添加用于标识封装边界等的字节，保障数据传输或存储时的完整性与可识别性。

            m_isGetKeyDefined = Clock::isKeyDefined();
            // 根据Clock类型中是否定义了获取键（Key）的相关机制，来初始化m_isGetKeyDefined变量，后续用于判断能否获取该类型数据对应的键。

            size_t keyLength = Clock::getKeyMaxCdrSerializedSize() > 16?
                    Clock::getKeyMaxCdrSerializedSize() : 16;
            // 根据Clock类型获取键的最大CDR序列化大小来确定keyLength变量的值，如果该大小大于16，则keyLength就等于这个最大序列化大小，否则keyLength取值为16，以便后续分配合适大小的缓冲区来存储键相关的数据。

            m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
            // 通过malloc函数分配keyLength字节大小的内存空间，并将其转换为unsigned char*类型指针赋值给m_keyBuffer，用于存储与键相关的数据。

            memset(m_keyBuffer, 0, keyLength);
            // 将刚刚分配的m_keyBuffer所指向的内存空间的每个字节都初始化为0，确保其初始状态正确。
        }

        ClockPubSubType::~ClockPubSubType()
        {
            if (m_keyBuffer!= nullptr)
            {
                free(m_keyBuffer);
            }
            // 这是ClockPubSubType类的析构函数，当对象被销毁时执行。如果m_keyBuffer指针不为空（即之前成功分配了内存），就通过free函数释放它所指向的内存空间，防止内存泄漏，也就是回收之前在构造函数中为存储键相关数据而分配的内存。
        }

        bool ClockPubSubType::serialize(
                void* data,
                SerializedPayload_t* payload)
        {
            Clock* p_type = static_cast<Clock*>(data);
            // 将传入的void*类型的data指针强制转换为Clock*类型指针，方便后续针对Clock类型数据进行特定操作。

            // Object that manages the raw buffer.
            eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
            // 定义一个eprosima::fastcdr::FastBuffer类型的对象fastbuffer，它用于管理原始缓冲区，缓冲区的数据来源是payload->data，其最大容量由payload->max_size指定，后续序列化操作会基于此缓冲区进行数据的读写等操作。

            // Object that serializes the data.
            eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
            // 创建一个eprosima::fastcdr::Cdr类型的对象ser，它负责对数据进行序列化操作，会按照特定的字节序（由DEFAULT_ENDIAN指定，并且符合DDS_CDR相关要求）将内存中的数据结构转换为可传输或存储的序列化格式，使用之前定义的fastbuffer所管理的缓冲区。

            payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS? CDR_BE : CDR_LE;
            // 根据ser对象的字节序（endianness）情况来设置payload的封装格式（encapsulation），如果是大端字节序（BIG_ENDIANNESS）就设置为CDR_BE，否则设置为CDR_LE。

            try
            {
                // Serialize encapsulation
                ser.serialize_encapsulation();
                // 调用ser对象的serialize_encapsulation方法对数据的封装部分进行序列化，例如添加一些头部、尾部等标识信息，使数据符合相应的封装格式要求，方便后续在接收端进行解包（反序列化）操作时能正确还原数据。

                // Serialize the object.
                p_type->serialize(ser);
                // 调用Clock类型对象（p_type）的serialize方法，通过ser对象将Clock类型的数据进行序列化，将其转换为符合格式要求的序列化数据存放在之前定义的缓冲区中。
            }
            catch (eprosima::fastcdr::exception::Exception& /*exception*/)
            {
                return false;
                // 捕获eprosima::fastcdr::exception命名空间下的Exception异常（此处注释掉了异常对象名），如果在序列化Clock对象过程中出现异常情况，函数直接返回false，表示序列化操作失败。
            }

            // Get the serialized length
            payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
            // 获取经过序列化后的数据长度（字节数），并将其赋值给payload的length成员变量，用于记录序列化数据的实际长度。

            return true;
            // 如果序列化过程没有出现异常情况，函数正常返回true，表示序列化操作成功完成。
        }

        bool ClockPubSubType::deserialize(
                SerializedPayload_t* payload,
                void* data)
        {
            try
            {
                // Convert DATA to pointer of your type
                Clock* p_type = static_cast<Clock*>(data);
                // 将传入的void*类型的data指针强制转换为Clock*类型指针，目的是为了后续能够针对Clock类型的数据进行特定的反序列化操作，确保操作的类型安全性和正确性。

                // Object that manages the raw buffer.
                eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);
                // 定义一个eprosima::fastcdr::FastBuffer类型的对象fastbuffer，用于管理原始缓冲区，不过此时缓冲区的数据长度由payload->length指定，也就是要处理的已经序列化后的数据的实际长度，与序列化时使用最大长度payload->max_size有所不同，该缓冲区包含了待反序列化的数据。

                // Object that deserializes the data.
                eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
                // 创建一个eprosima::fastcdr::Cdr类型的对象deser，它负责按照指定的字节序（由DEFAULT_ENDIAN指定，并且符合DDS_CDR相关要求）将缓冲区中的序列化数据还原为原本的Clock类型的数据结构，即执行反序列化操作，使用由fastbuffer管理的缓冲区数据。

                // Deserialize encapsulation.
                deser.read_encapsulation();
                // 调用deser对象的read_encapsulation方法对之前序列化时添加的封装部分进行解析，比如读取头部、尾部等相关标识信息，以便后续能准确无误地还原出原始的Clock类型的数据，这是反序列化过程中一个关键的步骤，用于处理数据的封装结构。

                payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS? CDR_BE : CDR_LE;
                // 根据deser对象的字节序（endianness）情况来更新payload的封装格式（encapsulation），如果是大端字节序（BIG_ENDIANNESS）就设置为CDR_BE，否则设置为CDR_LE。

                // Deserialize the object.
                p_type->deserialize(deser);
                // 调用Clock类型对象（p_type）的deserialize方法，通过deser对象将缓冲区中的序列化数据还原为Clock类型的原始数据结构，完成反序列化操作。
            }
            catch (eprosima::fastcdr::exception::Exception& /*exception*/)
            {
                return false;
                // 捕获eprosima::fastcdr::exception命名空间下的Exception异常（此处注释掉了异常对象名），如果在反序列化Clock对象过程中出现异常情况，函数直接返回false，表示反序列化操作失败。
            }

            return true;
            // 如果反序列化过程没有出现异常情况，函数正常返回true，表示反序列化操作成功完成。
        }

        std::function<uint32_t()> ClockPubSubType::getSerializedSizeProvider(
                void* data)
        {
            return [data]() -> uint32_t
                   {
                       return static_cast<uint32_t>(type::getCdrSerializedSize(*static_cast<Clock*>(data))) +
                              4u /*encapsulation*/;
                   };
            // 返回一个lambda表达式，该表达式返回Clock类型数据序列化后的大小（字节数）。具体是先获取Clock类型对象（通过将传入的void*类型指针转换为Clock*类型指针来获取对应对象）的CDR序列化大小，然后加上4字节（注释“封装”表示这是考虑到数据封装所占用的额外空间，与前面提到的封装概念对应，在获取序列化数据总大小时需把封装部分字节数算在内），最终返回这个总大小作为序列化后的数据长度。
        }

        void* ClockPubSubType::createData()
        {
            return reinterpret_cast<void*>(new Clock());
            // 创建一个Clock类型的对象，并将其指针转换为void*类型返回。通常用于在需要准备该类型数据（比如后续要进行序列化等操作）时获取相应的数据内存空间。
        }

        void ClockPubSubType::deleteData(
                void* data)
        {
            delete(reinterpret_cast<Clock*>(data));
            // 释放之前通过createData函数等方式动态分配的Clock类型对象所占用的内存空间。通过将传入的void*类型指针强制转换回Clock*类型指针，然后调用delete操作符来完成内存的释放，避免出现内存泄漏等问题。
        }

        bool ClockPubSubType::getKey(
                void* data,
                InstanceHandle_t* handle,
                bool force_md5)
        {
            if (!m_isGetKeyDefined)
            {
                return false;
            }
            // 如果没有定义获取键（Key）的相关机制（通过m_isGetKeyDefined变量判断），则直接返回false，表示无法获取键。

            Clock* p_type = static_cast<Clock*>(data);
            // 将传入的void*类型的data指针强制转换为Clock*类型指针，方便后续针对Clock类型数据进行获取键相关的操作。

            // Object that manages the raw buffer.
            eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
                    Clock::getKeyMaxCdrSerializedSize());
            // 定义一个eprosima::fastcdr::FastBuffer类型的对象fastbuffer，它用于管理原始缓冲区，这里缓冲区的数据来源是m_keyBuffer，其大小由Clock::getKeyMaxCdrSerializedSize()确定，后续会基于这个缓冲区进行与获取键（Key）相关的数据操作。

            // Object that serializes the data.
            eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
            // 创建一个eprosima::fastcdr::Cdr类型的对象ser，它会按照大端字节序（BIG_ENDIANNESS）对数据进行序列化操作，特别是针对用于生成键的数据进行序列化，以便后续根据情况生成合适的键值。

            p_type->serializeKey(ser);
            // 调用Clock类型对象（p_type）的serializeKey方法，通过ser对象对用于生成键的数据进行序列化操作，将相关数据按照指定字节序等要求转换为合适格式存放在缓冲区中。

            if (force_md5 || Clock::getKeyMaxCdrSerializedSize() > 16)
            {
                m_md5.init();
                m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
                m_md5.finalize();
                for (uint8_t i = 0; i < 16; ++i)
                {
                    handle->value[i] = m_md5.digest[i];
                }
            }
            else
            {
                for (uint8_t i = 0; i < 16; ++i)
                {
                    handle->value[i] = m_keyBuffer[i];
                }
            }
            // 根据条件判断，如果force_md5为真或者Clock类型获取键的最大CDR序列化大小大于16，就使用MD5算法相关操作来生成键值。先初始化m_md5对象，然后用它对缓冲区中的数据（其长度由ser对象获取的序列化数据长度确定）进行更新操作，最后完成MD5计算并将生成的16字节的摘要（digest）赋值给handle对象的value数组，作为键值。
            // 否则，直接将缓冲区（m_keyBuffer）中的前16个字节数据赋值给handle对象的value数组，作为键值。

            return true;
            // 表示成功获取键值（前提是前面的操作都顺利执行，没有因条件不满足等导致无法获取的情况），函数返回true。
        }
    } //End of namespace msg
} //End of namespace rosgraph
