/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_getRecordingAudioBufferCurrentSize.h>

// Constructor with field values
return_getRecordingAudioBufferCurrentSize::return_getRecordingAudioBufferCurrentSize(const yarp::dev::ReturnValue& ret,
                                                                                     const yarp::sig::AudioBufferSize& bufsize) :
        WirePortable(),
        ret(ret),
        bufsize(bufsize)
{
}

// Read structure on a Wire
bool return_getRecordingAudioBufferCurrentSize::read(yarp::os::idl::WireReader& reader)
{
    if (!nested_read_ret(reader)) {
        return false;
    }
    if (!nested_read_bufsize(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool return_getRecordingAudioBufferCurrentSize::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    if (!read(reader)) {
        return false;
    }
    return true;
}

// Write structure on a Wire
bool return_getRecordingAudioBufferCurrentSize::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!nested_write_ret(writer)) {
        return false;
    }
    if (!nested_write_bufsize(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool return_getRecordingAudioBufferCurrentSize::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    if (!write(writer)) {
        return false;
    }
    return true;
}

// Convert to a printable string
std::string return_getRecordingAudioBufferCurrentSize::toString() const
{
    yarp::os::Bottle b;
    if (!yarp::os::Portable::copyPortable(*this, b)) {
        return {};
    }
    return b.toString();
}

// read ret field
bool return_getRecordingAudioBufferCurrentSize::read_ret(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.read(ret)) {
        reader.fail();
        return false;
    }
    return true;
}

// write ret field
bool return_getRecordingAudioBufferCurrentSize::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.write(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_getRecordingAudioBufferCurrentSize::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readNested(ret)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) ret field
bool return_getRecordingAudioBufferCurrentSize::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeNested(ret)) {
        return false;
    }
    return true;
}

// read bufsize field
bool return_getRecordingAudioBufferCurrentSize::read_bufsize(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.read(bufsize)) {
        reader.fail();
        return false;
    }
    return true;
}

// write bufsize field
bool return_getRecordingAudioBufferCurrentSize::write_bufsize(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.write(bufsize)) {
        return false;
    }
    return true;
}

// read (nested) bufsize field
bool return_getRecordingAudioBufferCurrentSize::nested_read_bufsize(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readNested(bufsize)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) bufsize field
bool return_getRecordingAudioBufferCurrentSize::nested_write_bufsize(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeNested(bufsize)) {
        return false;
    }
    return true;
}
