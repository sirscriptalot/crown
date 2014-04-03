/*
Copyright (c) 2013 Daniele Bartolini, Michele Rossi
Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Types.h"
#include "DynamicString.h"

#pragma once

namespace crown
{

/// @defgroup JSON

/// Enumerates JSON value types.
///
/// @ingroup JSON
struct JSONType
{
	enum Enum
	{
		OBJECT,
		ARRAY,
		STRING,
		NUMBER,
		BOOL,
		NIL
	};
};

/// Represents a key-value pair in a JSON document.
///
/// @ingroup JSON
struct JSONPair
{
	const char* key;
	const char* val;
};

/// Functions to parse JSON-encoded strings.
///
/// @ingroup JSON
namespace json
{
	/// Returns the data type of the JSON string @a s. 
	JSONType::Enum type(const char* s);

	/// Parses the JSON string @a s ad puts it into @a str.
	void parse_string(const char* s, DynamicString& str);

	/// Returns the JSON number @a s as double. 
	double parse_number(const char* s);

	/// Returns the JSON number @a s as int.
	int32_t parse_int(const char* s);

	/// Returns the JSON number @a s as float.
	float parse_float(const char* s);

	/// Returns the JSON boolean @a s as bool.
	bool parse_bool(const char* s);

	/// Parses the JSON array @a s and puts it into @a array as pointers to
	/// the corresponding items into the original @a s string.
	void parse_array(const char* s, Array<const char*>& array);

	/// Parses the @a s JSON object and puts it into @a object as pointers to
	/// the corresponding key/value pairs into the original @a s string.
	void parse_object(const char* s, Array<JSONPair>& object);
} // namespace json
} // namespace crown
